-- Log the program counter at each read of the coin and start switches, and at
-- each write to the alpha-numeric RAM, while a coin-and-start sequence is
-- driven. Used to find where a core that sees the same switch values still
-- fails to credit a game.
local out_until = tonumber(os.getenv("SBCT_UNTIL") or "400")
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

local seen = {}
space:install_read_tap(0x0200, 0x0207, "sbct", function(offset, data, mask)
    local pc = cpu.state["PC"].value
    local key = string.format("%04X:%d", pc, offset)
    if not seen[key] then
        seen[key] = true
        io.stderr:write(string.format("[sbct] read offset=%d at PC=%04X\n", offset, pc))
    end
    return data
end)

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if f >= out_until then manager.machine:exit() end
end)
