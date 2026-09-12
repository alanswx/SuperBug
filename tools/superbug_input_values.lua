-- Log the distinct values the program reads from each switch address during a
-- frame window, while driving coin, start and gas. Pair with the Verilator
-- harness's --watch-read to compare the two cores offset by offset.
local lo_f = tonumber(os.getenv("SBIV_FROM") or "300")
local hi_f = tonumber(os.getenv("SBIV_TO") or "340")
local cpu = manager.machine.devices[":maincpu"]
local space = cpu.spaces["program"]
local ioport = manager.machine.ioport
local function field(tag, name)
    local p = ioport.ports[tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do if f.name == name then return f end end
end
local coin  = field(":BIT_7", "Coin 1")
local start = field(":BIT_7", "1 Player Start")
local gas   = field(":BIT_0", "Gas")

local frame = 0
local seen = {}
space:install_read_tap(0x0200, 0x0207, "sbiv", function(offset, data, mask)
    if frame >= lo_f and frame <= hi_f then
        local key = string.format("%04X %02X", offset, data & 0xff)
        seen[key] = (seen[key] or 0) + 1
    end
    return data
end)

emu.register_frame_done(function()
    frame = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((frame >= 60  and frame <= 100) and 1 or 0) end
    if start then start:set_value((frame >= 140 and frame <= 180) and 1 or 0) end
    if gas   then gas:set_value((frame >= 220) and 1 or 0) end
    if frame > hi_f then
        local keys = {}
        for k,_ in pairs(seen) do keys[#keys+1] = k end
        table.sort(keys)
        for _,k in ipairs(keys) do io.stderr:write(string.format("[sbiv] %s x%d\n", k, seen[k])) end
        manager.machine:exit()
    end
end)
