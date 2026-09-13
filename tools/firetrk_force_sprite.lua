-- Render chosen values of Fire Truck's vehicle registers, so states the game
-- cannot be driven into can still be compared against this core.
--
-- The program stores to these registers every vertical blank, so no amount of
-- writing from a frame callback wins the race. Blank the store instructions
-- instead: STAA extended is B7 followed by the address, and 01 is NOP. With
-- nothing writing a register, a value poked into it stays put.
--
--   FR_OUT=/tmp/x FR_ROT=16 FR_DX=220 FR_DY=135 FR_DROT=6 FR_SNAP=200 \
--     ./mame -window -nothrottle -sound none -video none -seconds_to_run 10 \
--            -autoboot_script ../tools/firetrk_force_sprite.lua firetrk
--
-- Super Bug has only the car, and puts its rotation register at 0x0180 rather
-- than 0x1080, so set FR_CAR_ADDR=384 for that game. It has no trailer, so the
-- three trailer variables do not apply.
local out  = os.getenv("FR_OUT")
local snap = tonumber(os.getenv("FR_SNAP") or "200")
local name = os.getenv("FR_NAME")
os.execute("mkdir -p " .. out)

-- address, environment variable
local car_addr = tonumber(os.getenv("FR_CAR_ADDR") or "4224")   -- 0x1080
local regs = {
    { car_addr, os.getenv("FR_ROT")  },   -- car rotation
    { 0x1460, os.getenv("FR_DX")   },   -- trailer horizontal position
    { 0x1480, os.getenv("FR_DY")   },   -- trailer vertical position
    { 0x14a0, os.getenv("FR_DROT") },   -- trailer rotation
}

local rgn = manager.machine.memory.regions[":maincpu"]
local blanked = 0
for _, reg in ipairs(regs) do
    if reg[2] then
        local hi, lo = (reg[1] >> 8) & 0xff, reg[1] & 0xff
        for a = 0, rgn.size - 3 do
            if rgn:read_u8(a) == 0xB7 and rgn:read_u8(a+1) == hi and rgn:read_u8(a+2) == lo then
                rgn:write_u8(a, 0x01); rgn:write_u8(a+1, 0x01); rgn:write_u8(a+2, 0x01)
                blanked = blanked + 1
            end
        end
    end
end
io.stderr:write(string.format("[force] blanked %d store(s)\n", blanked))

local space = manager.machine.devices[":maincpu"].spaces["program"]
emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    for _, reg in ipairs(regs) do
        if reg[2] then space:write_u8(reg[1], tonumber(reg[2])) end
    end
    if f == snap then
        manager.machine.screens[":screen"]:snapshot(
            string.format("%s/%s.png", out, name or "shot"))
    end
    if f >= snap + 5 then manager.machine:exit() end
end)
