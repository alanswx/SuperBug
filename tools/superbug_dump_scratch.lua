-- Dump the 6800 scratchpad ($0000-$00FF) at a chosen frame while driving a
-- coin-and-start sequence, in the same layout the Verilator harness prints for
-- --dump-ram, so the two can be diffed directly.
local at = tonumber(os.getenv("SBSCR_AT") or "400")
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

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if gas   then gas:set_value((f >= 220) and 1 or 0) end
    if f == at then
        io.stderr:write(string.format("=== CPU scratchpad RAM ($0000-$00FF) at frame %d ===\n", f))
        for i = 0, 255, 16 do
            local parts = {}
            for j = 0, 15 do
                parts[#parts+1] = string.format(" %02X", space:read_u8(i + j))
            end
            io.stderr:write(table.concat(parts) .. "\n")
        end
        manager.machine:exit()
    end
end)
