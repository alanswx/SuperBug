-- Hold the throttle in one gear and report how fast the forward scroll
-- advances, so the effect of each gear can be compared between cores.
--   SBG_GEAR=1..4 ./mame ... -autoboot_script ../tools/superbug_gear_test.lua superbug
local gear_n = tonumber(os.getenv("SBG_GEAR") or "1")
local ioport = manager.machine.ioport
local function field(tag, name)
    local p = ioport.ports[tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do if f.name == name then return f end end
end
local coin  = field(":BIT_7", "Coin 1")
local start = field(":BIT_7", "1 Player Start")
local gas   = field(":BIT_0", "Gas")
local gears = { field(":GEAR","Gear 1"), field(":GEAR","Gear 2"),
                field(":GEAR","Gear 3"), field(":GEAR","Gear 4") }
local function share(n)
    return manager.machine.memory.shares[":"..n] or manager.machine.memory.shares[n]
end
local samples = {}
emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if gas   then gas:set_value((f >= 220) and 1 or 0) end
    for i, g in ipairs(gears) do
        if g then g:set_value((i == gear_n and f >= 190 and f <= 210) and 1 or 0) end
    end
    if f == 400 or f == 600 then
        samples[f] = share("scroll_x"):read_u8(0)
    end
    if f > 600 then
        local d = (samples[600] - samples[400]) % 256
        io.stderr:write(string.format(
            "[gear] gear %d: scroll_x %02X -> %02X, %d units over 200 frames, %.2f per frame\n",
            gear_n, samples[400], samples[600], d, d / 200.0))
        manager.machine:exit()
    end
end)
