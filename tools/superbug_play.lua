-- Drive Super Bug through a coin-and-start sequence in MAME, log the sound
-- register writes, and snapshot some frames. Gives a reference for what a real
-- game looks like at the register level.
--
-- Run from mame/:
--   SBPLAY_OUT=/tmp/mp ./mame -window -nothrottle -sound none -video none \
--     -seconds_to_run 30 -autoboot_script ../tools/superbug_play.lua superbug

local out_dir = os.getenv("SBPLAY_OUT") or "/tmp/superbug_play"
local until_frame = tonumber(os.getenv("SBPLAY_UNTIL") or "1200")
os.execute("mkdir -p " .. out_dir)

local ioport = manager.machine.ioport
local function field(port_tag, field_name)
    local p = ioport.ports[port_tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do
        if f.name == field_name then return f end
    end
    return nil
end

-- superbug puts coin, start and gas on these ports; names come from the driver
local coin  = field(":BIT_7", "Coin 1")
local start = field(":BIT_7", "1 Player Start")
local gas   = field(":BIT_0", "Gas")
local gear1 = field(":GEAR",  "Gear 1")

io.stderr:write(string.format("[sbplay] coin=%s start=%s gas=%s gear1=%s\n",
    tostring(coin ~= nil), tostring(start ~= nil), tostring(gas ~= nil), tostring(gear1 ~= nil)))
if not coin then
    for tag, p in pairs(ioport.ports) do
        for _, f in pairs(p.fields) do
            io.stderr:write(string.format("[sbplay] port %s field '%s'\n", tag, f.name))
        end
    end
end

local cpu = manager.machine.devices[":maincpu"]
local space = cpu.spaces["program"]
local last_motor, n_motor = -1, 0
space:install_write_tap(0x0280, 0x029f, "sbplay_mot", function(offset, data, mask)
    n_motor = n_motor + 1; last_motor = data; return data
end)

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if gas   then gas:set_value((f >= 220) and 1 or 0) end
    if gear1 then gear1:set_value((f >= 200) and 1 or 0) end

    if f % 200 == 0 then
        io.stderr:write(string.format("[sbplay] frame=%d motor writes=%d last=0x%02X\n",
            f, n_motor, last_motor & 0xff))
        manager.machine.screens[":screen"]:snapshot(string.format("%s/f%04d.png", out_dir, f))
    end
    if f >= until_frame then manager.machine:exit() end
end)
