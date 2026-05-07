-- superbug_force_render.lua — let the CPU boot Super Bug for some frames,
-- then PAUSE the machine and overwrite playfield_ram, alpha_num_ram,
-- scroll_x, scroll_y, blink, flash, and car_rot with values from a
-- pattern file. After advancing one frame so the screen reflects the
-- forced state, snapshot the screen and exit.
--
-- This lets us drive both MAME and our verilator with byte-identical
-- inputs and PNG-diff their renders.
--
-- Run from inside mame/:
--   SBFR_PATTERN=../tools/patterns/uniform_pylon.txt \
--   SBFR_OUT=/tmp/mame_render.png \
--   SBFR_BOOT_FRAMES=60 \
--   ./mame -window -nothrottle -sound none -seconds_to_run 8 \
--          -autoboot_script ../tools/superbug_force_render.lua superbug
--
-- The pattern file format is a sequence of `key value` lines:
--   playfield_ram <space-separated 256 hex bytes, row-major>
--   alpha_num_ram <space-separated 32 hex bytes>
--   scroll_x <hex byte>
--   scroll_y <hex byte>
--   blink <0|1>
--   flash <0|1>
--   car_rot <hex byte>      (0..0x1f, used only for the "include car" subset)

local pattern_path = os.getenv("SBFR_PATTERN")
local out_path     = os.getenv("SBFR_OUT") or "/tmp/mame_render.png"
local boot_frames  = tonumber(os.getenv("SBFR_BOOT_FRAMES") or "60")

if not pattern_path then
    io.stderr:write("[sbfr] SBFR_PATTERN env var must point at a pattern file\n")
    return
end

-- Parse pattern file
local pattern = {}
local fp = io.open(pattern_path, "r")
if not fp then
    io.stderr:write(string.format("[sbfr] could not open %s\n", pattern_path))
    return
end
for line in fp:lines() do
    line = line:gsub("^%s+", ""):gsub("%s+$", "")
    if line ~= "" and line:sub(1,1) ~= "#" then
        local key, rest = line:match("^(%S+)%s+(.+)$")
        if key then
            pattern[key] = rest
        end
    end
end
fp:close()

local function find_share(name)
    return manager.machine.memory.shares[":" .. name]
        or manager.machine.memory.shares[name]
end

local function parse_bytes(s)
    local out = {}
    for tok in string.gmatch(s, "%S+") do
        local v = tonumber(tok, 16)
        if v then out[#out+1] = v end
    end
    return out
end

local function force_state()
    local pf = find_share("playfield_ram")
    local an = find_share("alpha_num_ram")
    local sx = find_share("scroll_x")
    local sy = find_share("scroll_y")
    local bl = find_share("blink")
    local cr = find_share("car_rot")

    if pattern.playfield_ram and pf then
        local bytes = parse_bytes(pattern.playfield_ram)
        for i = 0, math.min(255, #bytes - 1) do
            pf:write_u8(i, bytes[i + 1])
        end
    end
    if pattern.alpha_num_ram and an then
        local bytes = parse_bytes(pattern.alpha_num_ram)
        for i = 0, math.min(31, #bytes - 1) do
            an:write_u8(i, bytes[i + 1])
        end
    end
    if pattern.scroll_x and sx then
        sx:write_u8(0, tonumber(pattern.scroll_x, 16) or 0)
    end
    if pattern.scroll_y and sy then
        sy:write_u8(0, tonumber(pattern.scroll_y, 16) or 0)
    end
    if pattern.blink and bl then
        bl:write_u8(0, tonumber(pattern.blink) or 0)
    end
    if pattern.car_rot and cr then
        cr:write_u8(0, tonumber(pattern.car_rot, 16) or 0)
    end
end

local snap_done = false
local override_armed = false
local taps = {}

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if f < boot_frames then
        return
    end
    if not override_armed then
        -- Suppress CPU writes to the scroll registers and the
        -- playfield/alpha RAM areas so our forced values are stable
        -- across screen_update. The taps consume the write (callback
        -- returns nothing → write proceeds) but we use the special
        -- form `install_write_tap` with a callback that DOESN'T pass
        -- the value through. Most MAME versions allow blocking by
        -- explicitly nulling — if not supported here, we still apply
        -- in frame_done as a fallback.
        local prog = manager.machine.devices[":maincpu"].spaces["program"]
        local function block(offset, data, mask)
            -- no-op: we don't propagate the write. (Many lua bindings
            -- consider write_tap an observer-only hook though, so this
            -- might not actually block the underlying handler. We
            -- still apply force_state() each frame_done as a backstop.)
            return data
        end
        -- Don't try to block playfield_ram / alpha_num_ram writes —
        -- the CPU writes those legitimately and we want the forced
        -- pattern to come from our explicit override only.
        for _, range in ipairs({
            {0x0100, 0x011f},  -- scroll_y mirror
            {0x0120, 0x013f},  -- scroll_x mirror
            {0x0500, 0x05ff},  -- playfield_ram
            {0x0400, 0x041f},  -- alpha_num_ram
        }) do
            local ok, tap = pcall(function()
                return prog:install_write_tap(range[1], range[2], "sbfr_block", block)
            end)
            if ok then
                taps[#taps+1] = tap
            else
                io.stderr:write(string.format(
                    "[sbfr] install_write_tap not available (%s) — relying on frame_done overrides only\n",
                    tostring(tap)))
                break
            end
        end
        force_state()
        io.stderr:write(string.format(
            "[sbfr] override armed at frame %d\n", f))
        override_armed = true
    end
    force_state()
    if not snap_done and f >= boot_frames + 3 then
        manager.machine.screens[":screen"]:snapshot(out_path)
        io.stderr:write(string.format(
            "[sbfr] snapshot saved to %s at frame %d\n", out_path, f))
        snap_done = true
        manager.machine:exit()
    end
end)
