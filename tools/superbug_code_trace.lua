-- Record which ROM addresses the CPU fetches inside a range, while driving a
-- coin-and-start sequence. Pair with the Verilator harness's --code-trace to
-- find where two cores stop executing the same code.
local lo = tonumber(os.getenv("SBCODE_LO") or "0x1700")
local hi = tonumber(os.getenv("SBCODE_HI") or "0x17FF")
local until_frame = tonumber(os.getenv("SBCODE_UNTIL") or "450")
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

local seen = {}
space:install_read_tap(lo, hi, "sbcode", function(offset, data, mask)
    seen[offset] = true
    return data
end)

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if gas   then gas:set_value((f >= 220) and 1 or 0) end
    if f >= until_frame then
        local list = {}
        for a,_ in pairs(seen) do list[#list+1] = a end
        table.sort(list)
        for _,a in ipairs(list) do io.stderr:write(string.format("[code] %04X\n", a)) end
        manager.machine:exit()
    end
end)
