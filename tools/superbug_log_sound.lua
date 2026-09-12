-- Log every CPU write to the Super Bug sound registers, so the values our core
-- latches can be compared against the reference.
--
-- Run from mame/:
--   SBSND_UNTIL=900 ./mame -window -nothrottle -sound none -video none \
--     -seconds_to_run 16 -autoboot_script ../tools/superbug_log_sound.lua superbug

local until_frame = tonumber(os.getenv("SBSND_UNTIL") or "900")
local cpu  = manager.machine.devices[":maincpu"]
local space = cpu.spaces["program"]

local names = { [0x0280]="MOTSND", [0x02a0]="CRSHSD", [0x02c0]="SKDSND",
                [0x0160]="SKDRST", [0x0220]="TNEOUT", [0x0260]="OUTLAT" }
local counts, lastval = {}, {}
for a,_ in pairs(names) do counts[a]=0; lastval[a]=-1 end

for addr, name in pairs(names) do
    space:install_write_tap(addr, addr + 0x1f, "sbsnd_" .. name,
        function(offset, data, mask)
            counts[addr] = counts[addr] + 1
            lastval[addr] = data
            return data
        end)
end

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if f % 200 == 0 then
        local parts = {}
        for addr, name in pairs(names) do
            parts[#parts+1] = string.format("%s n=%d last=0x%02X",
                name, counts[addr], lastval[addr] & 0xff)
        end
        table.sort(parts)
        io.stderr:write(string.format("[sbsnd] frame=%d %s\n", f, table.concat(parts, "  ")))
    end
    if f >= until_frame then manager.machine:exit() end
end)
