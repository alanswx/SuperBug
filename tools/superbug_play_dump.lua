-- Drive a game with a fixed input script and dump the playfield RAM, scroll
-- registers and car rotation at chosen frames, in the same layout the
-- Verilator harness prints, so the two can be diffed during play.
local frames_env = os.getenv("SBPD_FRAMES") or "240,280"
local want = {}
for tok in string.gmatch(frames_env, "[^,]+") do want[tonumber(tok)] = true end

local ioport = manager.machine.ioport
local function field(tag, name)
    local p = ioport.ports[tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do if f.name == name then return f end end
end
local coin  = field(":BIT_7", "Coin 1")
local start = field(":BIT_7", "1 Player Start")
local gas   = field(":BIT_0", "Gas")

local function share(n)
    return manager.machine.memory.shares[":" .. n] or manager.machine.memory.shares[n]
end

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 140 and f <= 180) and 1 or 0) end
    if gas   then gas:set_value((f >= 220) and 1 or 0) end
    if want[f] then
        local pf = share("playfield_ram")
        local sx, sy = share("scroll_x"), share("scroll_y")
        local cr = share("car_rot")
        io.stderr:write(string.format(
            "frame=%d ScrollX=%02X ScrollY=%02X CarRot=%02X\n",
            f, sx:read_u8(0), sy:read_u8(0), cr:read_u8(0)))
        local space = manager.machine.devices[":maincpu"].spaces["program"]
        io.stderr:write(string.format("=== CPU scratchpad RAM ($0000-$00FF) at frame %d ===\n", f))
        for i = 0, 255, 16 do
            local parts = {}
            for j = 0, 15 do parts[#parts+1] = string.format(" %02X", space:read_u8(i + j)) end
            io.stderr:write(table.concat(parts) .. "\n")
        end
        io.stderr:write(string.format("=== playfield RAM at frame %d ===\n", f))
        for i = 0, 255, 16 do
            local parts = {}
            for j = 0, 15 do parts[#parts+1] = string.format(" %02X", pf:read_u8(i + j)) end
            io.stderr:write(table.concat(parts) .. "\n")
        end
        want[f] = nil
        local left = 0
        for _, _ in pairs(want) do left = left + 1 end
        if left == 0 then manager.machine:exit() end
    end
end)
