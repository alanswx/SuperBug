-- Drive Super Bug into a crash and snapshot the sequence, so the crash screen
-- can be compared against the same sequence from the Verilator harness.
-- Steers with the dial until the car hits the scenery.
--
--   SBCR_OUT=/tmp/mc SBCR_STEER=1 ./mame -window -nothrottle -sound none \
--     -video none -seconds_to_run 12 -autoboot_script ../tools/superbug_crash.lua superbug
local out_dir = os.getenv("SBCR_OUT") or "/tmp/superbug_crash"
local steer_from = tonumber(os.getenv("SBCR_STEER_FROM") or "240")
local until_frame = tonumber(os.getenv("SBCR_UNTIL") or "420")
os.execute("mkdir -p " .. out_dir)

local ioport = manager.machine.ioport
local function field(tag, name)
    local p = ioport.ports[tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do if f.name == name then return f end end
end
local coin  = field(":BIT_7", "Coin 1")
local start = field(":BIT_7", "1 Player Start")
local gas   = field(":BIT_0", "Gas")
local dial
for _, f in pairs(ioport.ports[":STEER_1"].fields) do dial = f end

local cpu = manager.machine.devices[":maincpu"]
local space = cpu.spaces["program"]
local crash_frames = {}
space:install_write_tap(0x02a0, 0x02bf, "sbcr", function(offset, data, mask)
    local f = manager.machine.screens[":screen"]:frame_number()
    if (data & 0xf0) ~= 0xf0 then crash_frames[f] = true end
    return data
end)

local pos = 0
emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if gas   then gas:set_value((f >= 220) and 1 or 0) end
    if dial and f >= steer_from then pos = pos + tonumber(os.getenv("SBCR_RATE") or "3"); dial:set_value(pos & 0xff) end
    if f >= 240 and f % 6 == 0 then
        manager.machine.screens[":screen"]:snapshot(string.format("%s/f%04d.png", out_dir, f))
    end
    if crash_frames[f] then io.stderr:write(string.format("[sbcr] crash sound at frame %d\n", f)) end
    if f >= until_frame then manager.machine:exit() end
end)
