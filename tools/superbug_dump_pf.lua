-- superbug_dump_pf.lua — dump Super Bug's playfield + alpha RAM at chosen
-- frame numbers, then exit. Output goes to stdout in the same format the
-- verilator harness uses for `--dump-ram`, so the two can be diffed
-- directly.
--
-- Run from inside the mame/ directory:
--   ./mame -window -nothrottle -nosound -seconds_to_run 12 \
--          -autoboot_script ../tools/superbug_dump_pf.lua superbug
--
-- Frames to capture and where to write the dump file are picked up from
-- two environment variables:
--   SBDUMP_FRAMES   comma-separated frame numbers (default: 1,30,61,100)
--   SBDUMP_OUT      output path (default: /tmp/mame_pf_dump.txt)

local frames_env = os.getenv("SBDUMP_FRAMES") or "1,30,61,100,200,300"
local out_path   = os.getenv("SBDUMP_OUT")    or "/tmp/mame_pf_dump.txt"

local want = {}
for tok in string.gmatch(frames_env, "[^,]+") do
    local n = tonumber(tok)
    if n then want[n] = true end
end
local n_remaining = 0
for _ in pairs(want) do n_remaining = n_remaining + 1 end

local fp = io.open(out_path, "w")
if not fp then
    io.stderr:write(string.format("[sbdump] could not open %s\n", out_path))
    return
end
io.stderr:write(string.format(
    "[sbdump] writing dumps for frames {%s} -> %s\n", frames_env, out_path))

local function find_share(name)
    -- Memory shares show up under both `:name` and bare `name` in
    -- different MAME versions; try both.
    return manager.machine.memory.shares[":" .. name]
        or manager.machine.memory.shares[name]
end

local function dump_at(frame)
    local pf = find_share("playfield_ram")
    local an = find_share("alpha_num_ram")
    if not pf or not an then
        fp:write(string.format(
            "frame=%d ERROR: missing memory share (pf=%s, an=%s)\n",
            frame, tostring(pf), tostring(an)))
        return
    end

    -- Pull the live scroll/blink/flash registers too; verilator prints
    -- PHP/PVP/PD as a one-liner so mirror that.
    local sx_share = find_share("scroll_x")
    local sy_share = find_share("scroll_y")
    local blink_share = find_share("blink")
    local sx = sx_share and sx_share:read_u8(0) or -1
    local sy = sy_share and sy_share:read_u8(0) or -1
    local blink = blink_share and blink_share:read_u8(0) or -1

    fp:write(string.format(
        "Frame=%d ScrollX=%02X ScrollY=%02X Blink=%02X\n",
        frame, sx, sy, blink))

    -- Alpha-num: 32 bytes the game actually uses ($0400..$041F).
    fp:write(string.format(
        "=== alpha-num RAM (32 bytes) at frame %d ===\n", frame))
    for row = 0, 1 do
        local parts = {}
        for col = 0, 15 do
            parts[#parts + 1] = string.format("%02X", an:read_u8(row*16 + col))
        end
        fp:write(" " .. table.concat(parts, " ") .. "\n")
    end

    -- Playfield: full 256 bytes laid out 16x16 to match verilator's dump.
    fp:write(string.format(
        "=== playfield RAM (256 bytes) at frame %d ===\n", frame))
    for row = 0, 15 do
        local parts = {}
        for col = 0, 15 do
            parts[#parts + 1] = string.format("%02X", pf:read_u8(row*16 + col))
        end
        fp:write(" " .. table.concat(parts, " ") .. "\n")
    end
    fp:flush()
end

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if want[f] then
        dump_at(f)
        want[f] = nil
        n_remaining = n_remaining - 1
        if n_remaining == 0 then
            fp:close()
            io.stderr:write(string.format(
                "[sbdump] all frames captured, exiting\n"))
            manager.machine:exit()
        end
    end
end)
