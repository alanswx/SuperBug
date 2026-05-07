-- Take MAME snapshots at specified frame_numbers (since machine reset)
-- so we can verify whether startup.avi's "frame N" corresponds to
-- MAME's frame_number=N or has an offset.
--
-- Run from mame/:
--   SBSF_FRAMES="10,30,60,100" SBSF_OUT=/tmp/mame_snap \
--     ./mame -window -nothrottle -sound none -seconds_to_run 4 \
--            -autoboot_script ../tools/superbug_snap_frames.lua superbug

local frames_env = os.getenv("SBSF_FRAMES") or "10,30,60,100"
local out_dir    = os.getenv("SBSF_OUT")    or "/tmp/mame_snap"

os.execute("mkdir -p " .. out_dir)

local want = {}
for tok in string.gmatch(frames_env, "[^,]+") do
    local n = tonumber(tok)
    if n then want[n] = true end
end
local n_remaining = 0
for _ in pairs(want) do n_remaining = n_remaining + 1 end

emu.register_frame_done(function()
    local f = manager.machine.screens[":screen"]:frame_number()
    if want[f] then
        local path = string.format("%s/f%04d.png", out_dir, f)
        manager.machine.screens[":screen"]:snapshot(path)
        io.stderr:write(string.format("[sbsf] saved %s\n", path))
        want[f] = nil
        n_remaining = n_remaining - 1
        if n_remaining == 0 then
            manager.machine:exit()
        end
    end
end)
