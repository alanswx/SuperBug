-- Drive Fire Truck all the way into a running game and steer both wheels, so
-- the trailer can be watched through its eight rotation frames and compared
-- against the Verilator harness driven with the same timings.
--
-- Fire Truck's cabinet DIP defaults to the two-player machine, where the front
-- player's own start button does not begin a game. "Both Players Start" does.
--
--   FTD_OUT=/tmp/ft FTD_SNAPS="300,400,500" FTD_UNTIL=900 \
--     FTD_STEER2="400-700:+3" \
--     ./mame -window -nothrottle -sound none -video none -seconds_to_run 30 \
--            -autoboot_script ../tools/firetrk_drive.lua firetrk
local out_dir     = os.getenv("FTD_OUT")   or "/tmp/firetrk_drive"
local until_frame = tonumber(os.getenv("FTD_UNTIL") or "900")
local coin_to     = tonumber(os.getenv("FTD_COIN")  or "80")
local start_from  = tonumber(os.getenv("FTD_START") or "150")
local gas_from    = tonumber(os.getenv("FTD_GAS")   or "250")
local snaps = {}
for tok in string.gmatch(os.getenv("FTD_SNAPS") or "", "[^,]+") do snaps[tonumber(tok)] = true end

-- "400-700:+3" turns the back wheel by +3 per frame over that window.
local function parse_steer(env)
    local list = {}
    for tok in string.gmatch(os.getenv(env) or "", "[^,]+") do
        local a, b, d = string.match(tok, "(%d+)%-(%d+):([+-]?%d+)")
        if a then list[#list + 1] = { from = tonumber(a), to = tonumber(b), delta = tonumber(d) } end
    end
    return list
end
local steer1 = parse_steer("FTD_STEER1")
local steer2 = parse_steer("FTD_STEER2")
os.execute("mkdir -p " .. out_dir)

local ioport = manager.machine.ioport
local function field(tag, name)
    local p = ioport.ports[tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do if f.name == name then return f end end
end
local coin   = field(":BIT_7", "Coin 1")
local start3 = field(":BIT_6", "Both Players Start")
local gas    = field(":BIT_0", "Gas")
local dial1  = field(":STEER_1", "Dial")
local dial2  = field(":STEER_2", "Dial 2")

io.stderr:write(string.format("[ftd] coin=%s start3=%s gas=%s dial2=%s\n",
    tostring(coin ~= nil), tostring(start3 ~= nil), tostring(gas ~= nil), tostring(dial2 ~= nil)))

local pos1, pos2 = 0, 0
emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin   then coin:set_value((f >= 60 and f <= coin_to) and 1 or 0) end
    if start3 then start3:set_value((f >= start_from and f <= start_from + 60) and 1 or 0) end
    if gas    then gas:set_value((f >= gas_from) and 1 or 0) end
    if dial1 then
        for _, s in ipairs(steer1) do
            if f >= s.from and f <= s.to then pos1 = (pos1 + s.delta) % 256 end
        end
        dial1:set_value(pos1)
    end
    if dial2 then
        for _, s in ipairs(steer2) do
            if f >= s.from and f <= s.to then pos2 = (pos2 + s.delta) % 256 end
        end
        dial2:set_value(pos2)
    end
    if snaps[f] then
        manager.machine.screens[":screen"]:snapshot(string.format("%s/f%04d.png", out_dir, f))
    end
    if f >= until_frame then manager.machine:exit() end
end)
