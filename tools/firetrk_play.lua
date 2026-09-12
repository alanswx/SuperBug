-- Drive Fire Truck through coin, start and throttle, and snapshot chosen
-- frames, so gameplay can be compared against the Verilator harness driven
-- with the same timings.
--
--   FTP_OUT=/tmp/ft FTP_SNAPS="250,400,401,600" FTP_UNTIL=650 \
--     ./mame -window -nothrottle -sound none -video none -seconds_to_run 15 \
--            -autoboot_script ../tools/firetrk_play.lua firetrk
local out_dir = os.getenv("FTP_OUT") or "/tmp/firetrk_play"
local until_frame = tonumber(os.getenv("FTP_UNTIL") or "650")
local snaps = {}
for tok in string.gmatch(os.getenv("FTP_SNAPS") or "", "[^,]+") do snaps[tonumber(tok)] = true end
os.execute("mkdir -p " .. out_dir)

local ioport = manager.machine.ioport
local function field(tag, name)
    local p = ioport.ports[tag]
    if not p then return nil end
    for _, f in pairs(p.fields) do if f.name == name then return f end end
end
local coin  = field(":BIT_7", "Coin 1")
local start = field(":BIT_6", "Front Player Start")
local gas   = field(":BIT_0", "Gas")

io.stderr:write(string.format("[ftp] coin=%s start=%s gas=%s\n",
    tostring(coin ~= nil), tostring(start ~= nil), tostring(gas ~= nil)))

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if coin  then coin:set_value((f >= 60  and f <= 100) and 1 or 0) end
    if start then start:set_value((f >= 130 and f <= 400) and 1 or 0) end
    if gas   then gas:set_value((f >= 200) and 1 or 0) end
    if snaps[f] then
        manager.machine.screens[":screen"]:snapshot(string.format("%s/f%04d.png", out_dir, f))
    end
    if f >= until_frame then manager.machine:exit() end
end)
