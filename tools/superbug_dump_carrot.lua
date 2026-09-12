-- Print car_rot (and the derived MAME sprite selection) at chosen frames.
-- car_rot is write-only from the CPU's point of view, so it never shows up in
-- a RAM dump; this reads MAME's memory share directly.
--
-- Run from mame/:
--   SBCR_FRAMES="300,400" ./mame -window -nothrottle -sound none -video none \
--     -seconds_to_run 9 -autoboot_script ../tools/superbug_dump_carrot.lua superbug

local frames_env = os.getenv("SBCR_FRAMES") or "300,400"

local want = {}
local n_remaining = 0
for tok in string.gmatch(frames_env, "[^,]+") do
    local n = tonumber(tok)
    if n then want[n] = true; n_remaining = n_remaining + 1 end
end

local function find_share(name)
    return manager.machine.memory.shares[":" .. name]
        or manager.machine.memory.shares[name]
end

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if want[f] then
        local cr_share = find_share("car_rot")
        local cr = cr_share and cr_share:read_u8(0) or -1
        -- Mirrors superbug_state::draw_car
        local code   = (~cr) & 0x03
        local bank   = ((cr & 0x10) ~= 0) and 2 or 1
        local flip_x = ((cr & 0x04) ~= 0) and 1 or 0
        local flip_y = ((cr & 0x08) ~= 0) and 1 or 0
        io.stderr:write(string.format(
            "[sbcr] frame=%d car_rot=0x%02X  code=%d bank=layout%d flip_x=%d flip_y=%d  nibble_bit=%d\n",
            f, cr, code, bank, flip_x, flip_y, 3 - code))
        want[f] = nil
        n_remaining = n_remaining - 1
        if n_remaining == 0 then manager.machine:exit() end
    end
end)
