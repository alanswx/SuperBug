#include <verilated.h>
#include "Vemu.h"
#include "Vemu___024root.h"

#include "imgui.h"
#include "implot.h"
#ifndef _MSC_VER
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#else
#define WIN32
#include <dinput.h>
#endif

#include "sim_console.h"
#include "sim_bus.h"
#include "sim_blkdevice.h"
#include "sim_video.h"
#include "sim_audio.h"
#include "sim_input.h"
#include "sim_clock.h"

#include "../imgui/imgui_memory_editor.h"
#include "../imgui/ImGuiFileDialog.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "sim/stb_image_write.h"

#include "sim_disasm6800.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <sys/stat.h>
#include <string>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

// Simulation control
// ------------------
int initialReset = 48;
bool run_enable = 1;
bool adam_mode= 1;
int batchSize = 150000;
//int batchSize = 100;
bool single_step = 0;
bool multi_step = 0;
int multi_step_amount = 1024;

// Debug GUI 
// ---------
const char* windowTitle = "Verilator Sim: IIgs";
const char* windowTitle_Control = "Simulation control";
const char* windowTitle_DebugLog = "Debug log";
const char* windowTitle_Video = "VGA output";
const char* windowTitle_Audio = "Audio output";
bool showDebugLog = true;
DebugConsole console;
MemoryEditor mem_edit;
char pc_breakpoint[10] = "";
bool pc_break_enabled;

// HPS emulator
// ------------
SimBus bus(console);
SimBlockDevice blockdevice(console);

// Input handling
// --------------
SimInput input(13, console);
const int input_right = 0;
const int input_left = 1;
const int input_down = 2;
const int input_up = 3;
const int input_a = 4;
const int input_b = 5;
const int input_x = 6;
const int input_y = 7;
const int input_l = 8;
const int input_r = 9;
const int input_select = 10;
const int input_start = 11;
const int input_menu = 12;

// Video
// -----
// Buffer must be tall enough to fit the rotated TV image. Pre-rotation
// content is ~256 wide × ~240 tall; ROT270 = 90° CCW maps original-X to
// display-Y, so display-Y range needs to cover original-X range (256).
// Use 320×320 to be safe.
#define VGA_WIDTH 320
#define VGA_HEIGHT 320
#define VGA_ROTATE -1  // 90 degrees clockwise; matches MAME's ROT270 for superbug (vertical cabinet)
#define VGA_SCALE_X vga_scale
#define VGA_SCALE_Y vga_scale
SimVideo video(VGA_WIDTH, VGA_HEIGHT, VGA_ROTATE);
float vga_scale = 2.5;

// Verilog module
// --------------
Vemu* top = NULL;

vluint64_t main_time = 0;	// Current simulation time.
double sc_time_stamp() {	// Called by $time in Verilog.
	return main_time;
}

int clk_sys_freq = 24000000;
SimClock clk_sys(1);

int soft_reset=0;
vluint64_t soft_reset_time=0;



// Audio
// -----
//#define DISABLE_AUDIO
#ifndef DISABLE_AUDIO
SimAudio audio(clk_sys_freq, false);

// --audio-wav <path>: decimate AUDIO_L to 44.1 kHz and write a real WAV on
// exit. The existing file writer emits raw floats under a .wav name, which no
// tool will open, and without a capture path the sound channels can only be
// judged by ear.
std::string audio_wav_path;

// --switch-pc-trace: collect the distinct (switch address, program counter)
// pairs the CPU uses to read the coin, start and gear switches, so the code
// path can be compared against the same trace taken from MAME.
bool switch_pc_trace = false;
// --code-trace LO HI: record which ROM addresses the CPU fetches inside a
// range, so the executed code can be set-compared against the same range
// captured from MAME.
int code_trace_lo = -1, code_trace_hi = -1;
// --watch-read ADDR FROM TO: print every read of one address between two
// frames, with the program counter and the byte returned.
int watch_addr = -1, watch_from = 0, watch_to = 0;
static int watch_prev_match = 0;
static std::set<uint32_t> code_seen;
static std::set<uint32_t> switch_pc_seen;
static std::vector<int16_t> audio_samples;
static int audio_decimate = 0;

static void write_wav(const std::string& path, const std::vector<int16_t>& pcm, int rate) {
	FILE* f = fopen(path.c_str(), "wb");
	if (!f) { fprintf(stderr, "audio: cannot write %s\n", path.c_str()); return; }
	uint32_t data_bytes = (uint32_t)(pcm.size() * 2);
	uint32_t riff = 36 + data_bytes;
	uint32_t byte_rate = (uint32_t)rate * 2;
	uint16_t u16;
	uint32_t u32;
	fwrite("RIFF", 1, 4, f); fwrite(&riff, 4, 1, f); fwrite("WAVE", 1, 4, f);
	fwrite("fmt ", 1, 4, f); u32 = 16;  fwrite(&u32, 4, 1, f);
	u16 = 1; fwrite(&u16, 2, 1, f);          // PCM
	u16 = 1; fwrite(&u16, 2, 1, f);          // mono
	u32 = (uint32_t)rate; fwrite(&u32, 4, 1, f);
	fwrite(&byte_rate, 4, 1, f);
	u16 = 2;  fwrite(&u16, 2, 1, f);         // block align
	u16 = 16; fwrite(&u16, 2, 1, f);         // bits per sample
	fwrite("data", 1, 4, f); fwrite(&data_bytes, 4, 1, f);
	fwrite(pcm.data(), 2, pcm.size(), f);
	fclose(f);
	fprintf(stderr, "audio: wrote %s, %zu samples at %d Hz\n",
	        path.c_str(), pcm.size(), rate);
}
#endif

// Reset simulation variables and clocks
void resetSim() {
	main_time = 0;
	top->reset = 1;
	clk_sys.Reset();
}

// Screenshot support
// ------------------
std::vector<int> screenshot_frames;
bool screenshot_mode = false;
std::string screenshot_name_override;
// --screenshot-dir writes one PNG per captured frame into a directory, which
// is what the multi-frame comparison script needs; --screenshot-name writes a
// single fixed path and only makes sense for one frame.
std::string screenshot_dir;
int stop_at_frame = -1;
bool headless_mode = false;
bool service_mode = false;  // --service: hold the self-test switch active

// --input: a scripted button timeline, so gameplay can be exercised in batch
// mode. Without it only attract mode is reachable and the car never leaves its
// resting rotation, which makes the sprite path impossible to verify.
//
//   --input "60:coin, 90:start, 120-900:gas, 200-260:left, 400-460:right"
//
// A bare frame number presses the button for one frame; a range holds it.
// Names match the joystick bits sim.v decodes.
struct ScriptedPress { int from; int to; uint32_t mask; };
std::vector<ScriptedPress> input_script;

static uint32_t button_mask(const std::string& name) {
	//                                        bit
	if (name == "right")     return 1u << 0;
	if (name == "left")      return 1u << 1;
	if (name == "gas")       return 1u << 4;
	if (name == "gearup")    return 1u << 5;
	if (name == "geardown")  return 1u << 6;
	if (name == "nexttrack") return 1u << 7;
	if (name == "start")     return 1u << 8;
	if (name == "start2")    return 1u << 9;
	if (name == "coin")      return 1u << 10;
	fprintf(stderr, "--input: unknown button '%s'\n", name.c_str());
	return 0;
}

static void parse_input_script(const char* spec) {
	std::string s(spec);
	size_t pos = 0;
	while (pos < s.size()) {
		size_t comma = s.find(',', pos);
		std::string item = s.substr(pos, comma == std::string::npos ? std::string::npos : comma - pos);
		pos = (comma == std::string::npos) ? s.size() : comma + 1;
		// strip spaces
		std::string t;
		for (char c : item) if (!isspace((unsigned char)c)) t += c;
		if (t.empty()) continue;
		size_t colon = t.find(':');
		if (colon == std::string::npos) {
			fprintf(stderr, "--input: expected FRAME:BUTTON in '%s'\n", t.c_str());
			continue;
		}
		std::string when = t.substr(0, colon);
		std::string what = t.substr(colon + 1);
		int from, to;
		size_t dash = when.find('-');
		if (dash == std::string::npos) {
			from = to = atoi(when.c_str());
		} else {
			from = atoi(when.substr(0, dash).c_str());
			to   = atoi(when.substr(dash + 1).c_str());
		}
		uint32_t m = button_mask(what);
		if (m) input_script.push_back({from, to, m});
	}
}

static uint32_t scripted_buttons(int frame) {
	uint32_t m = 0;
	for (const auto& p : input_script)
		if (frame >= p.from && frame <= p.to) m |= p.mask;
	return m;
}
int dump_ram_at_frame = -1;
// --raster-probe N: on frame N, report where the playfield window and the car
// sprite window open and close, measured in visible-raster pixels so the
// numbers line up directly with MAME's playfield_window rectangle.
int raster_probe_frame = -1;
static int rp_line = 140;          // scanline to sample, mid-screen by default
static int rp_pf_first = -1, rp_pf_last = -1;
static int rp_car_first = -1, rp_car_last = -1;
static int rp_h_at_x0 = -1;
static bool rp_done = false;

// CPU trace
std::string trace_path;
FILE*       trace_fp = nullptr;
int         trace_max = 0;       // 0 = unlimited
int         trace_count = 0;

void save_screenshot(int frame_number) {
	if (!output_ptr) {
		fprintf(stderr, "screenshot: output_ptr null\n");
		return;
	}
	char filename[512];
	if (!screenshot_dir.empty()) {
		mkdir(screenshot_dir.c_str(), 0755);   // harmless if it already exists
		snprintf(filename, sizeof(filename), "%s/v_frame_%04d.png",
		         screenshot_dir.c_str(), frame_number);
	} else if (!screenshot_name_override.empty()) {
		snprintf(filename, sizeof(filename), "%s", screenshot_name_override.c_str());
	} else {
		snprintf(filename, sizeof(filename), "screenshot_frame_%04d.png", frame_number);
	}

	// Use the SimVideo instance dimensions, not the file-scope globals in
	// sim_video.cpp (those keep their default 512x512 because the constructor
	// shadows them with class members of the same name).
	// Buffer is video.output_width × video.output_height. With ROT270 the
	// content occupies a smaller sub-region inside that buffer (content
	// width = original-TV-height, content height = original-TV-width).
	// Crop to actual content extent so the saved PNG doesn't have a wide
	// grey strip on the right.
	int buf_w = video.output_width;
	int buf_h = video.output_height;
	int w, h;
	if (video.output_rotate == -1 || video.output_rotate == 1) {
		// Rotated 90°: content extent is the swap of the original render
		// dimensions. Use stats_yMax (tracks the highest count_line which
		// became x_display under -1 rotation) to crop to content width.
		w = video.stats_yMax > 0 ? video.stats_yMax : buf_h;
		h = buf_h;
	} else {
		w = buf_w;
		h = buf_h;
	}
	if (w > buf_w) w = buf_w;
	if (h > buf_h) h = buf_h;

	uint8_t* rgb = (uint8_t*)malloc(w * h * 3);
	if (!rgb) { fprintf(stderr, "screenshot: malloc failed\n"); return; }

	// video.Clock writes pixels as 0xFF000000 | B<<16 | G<<8 | R (ABGR-in-uint32).
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			uint32_t p = output_ptr[y * buf_w + x];   // stride = buffer width
			int di = (y * w + x) * 3;
			rgb[di + 0] = (p >> 0)  & 0xFF;
			rgb[di + 1] = (p >> 8)  & 0xFF;
			rgb[di + 2] = (p >> 16) & 0xFF;
		}
	}
	int ok = stbi_write_png(filename, w, h, 3, rgb, w * 3);
	free(rgb);
	fprintf(stderr, ok ? "screenshot: saved %s (%dx%d)\n" : "screenshot: FAILED %s\n",
	        filename, w, h);
}

// Parse "100,200,300" into screenshot_frames; also accepts a single number.
static void parse_screenshot_frames(const char* arg) {
	const char* p = arg;
	while (*p) {
		char* end = nullptr;
		long n = strtol(p, &end, 10);
		if (end == p) break;
		screenshot_frames.push_back((int)n);
		p = end;
		while (*p == ',' || *p == ' ') p++;
	}
}

int verilate() {

	if (!Verilated::gotFinish()) {
		if (soft_reset){
			fprintf(stderr,"soft_reset.. in gotFinish\n");
			top->soft_reset = 1;
			soft_reset=0;
			soft_reset_time=0;
			fprintf(stderr,"turning on %x\n",top->soft_reset);
		}
		if (clk_sys.IsRising()) {
			soft_reset_time++;
		}
		if (soft_reset_time==initialReset) {
			top->soft_reset = 0; 
			fprintf(stderr,"turning off %x\n",top->soft_reset);
			fprintf(stderr,"soft_reset_time %ld initialReset %x\n",soft_reset_time,initialReset);
		} 

		// Assert reset during startup
		if (main_time < initialReset) { top->reset = 1; }
		// Deassert reset after startup
		if (main_time == initialReset) { top->reset = 0; }

		// Clock dividers
		clk_sys.Tick();

		// Set system clock in core
		top->clk_sys = clk_sys.clk;
		top->adam = adam_mode;

		// Simulate both edges of system clock
		if (clk_sys.clk != clk_sys.old) {
			if (clk_sys.IsRising() && *bus.ioctl_download!=1	) blockdevice.BeforeEval(main_time);
			if (clk_sys.clk) {
				input.BeforeEval();
				bus.BeforeEval();
			}
			top->eval();
			if (clk_sys.clk) { bus.AfterEval(); blockdevice.AfterEval(); }

			// CPU instruction trace: emit one line per *opcode latch* event,
			// i.e. each time op_code changes (cpu68 latches a new opcode in
			// state_type_fetch_state). The pc at that instant is the address
			// of the byte *following* the opcode, so the instruction PC is
			// pc-1.
			if (trace_fp) {
				// One line per executed instruction. Strategy: while
				// dbg_op_fetch is high, latch the *last seen* dbg_addr (the
				// pc presented during the fetch cycle). On the falling
				// edge of dbg_op_fetch the cpu68 negedge has just updated
				// op_code; read dbg_opcode and emit (latched_addr, opcode).
				// This works even for runs of repeated identical opcodes,
				// which the simpler "op_code changed" trigger collapsed.
				static bool     last_fetch  = false;
				static uint16_t fetch_addr  = 0;
				bool fetch = top->dbg_op_fetch;
				if (fetch) {
					fetch_addr = top->dbg_addr;
				}
				if (!fetch && last_fetch) {
					uint8_t op_byte = top->dbg_opcode;
					char line[128];
					Op6800 d = disasm6800_table(op_byte);
					snprintf(line, sizeof line,
					         "%04X: %02X  %-4s A=%02X B=%02X CC=%02X",
					         fetch_addr, op_byte, d.mnem,
					         top->dbg_acca, top->dbg_accb, top->dbg_cc);
					fprintf(trace_fp, "%s\n", line);
					if (trace_max && ++trace_count >= trace_max) {
						fclose(trace_fp); trace_fp = nullptr;
						fprintf(stderr, "trace: hit limit %d, closed\n", trace_max);
					}
				}
				last_fetch = fetch;
			}
		}

#ifndef DISABLE_AUDIO
		if (clk_sys.IsRising())
		{
			audio.Clock(top->AUDIO_L, top->AUDIO_R);
			if (!audio_wav_path.empty()) {
				// clk_sys_freq / 44100, rounded
				if (++audio_decimate >= (clk_sys_freq / 44100)) {
					audio_decimate = 0;
					// the core emits unsigned PCM; centre it for the WAV
					audio_samples.push_back((int16_t)((int)top->AUDIO_L - 32768));
				}
			}
		}
#endif

		// Output pixels on rising edge of pixel clock
		if (clk_sys.IsRising() && top->CE_PIXEL ) {
			uint32_t colour = 0xFF000000 | top->VGA_B << 16 | top->VGA_G << 8 | top->VGA_R;
			static int prev_frame = 0;
			video.Clock(top->VGA_HB, top->VGA_VB, top->VGA_HS, top->VGA_VS, colour);
			if (watch_addr >= 0 && video.count_frame >= watch_from &&
			    video.count_frame <= watch_to) {
				int match = (top->dbg_addr == (unsigned)watch_addr);
				if (match && !watch_prev_match)
					fprintf(stderr, "[watch] frame=%d addr=%04X PC=%04X data=%02X\n",
					        video.count_frame, watch_addr,
					        (unsigned)top->dbg_pc, (unsigned)top->dbg_din);
				watch_prev_match = match;
			}
			if (code_trace_lo >= 0) {
				uint32_t a = top->dbg_addr;
				if ((int)a >= code_trace_lo && (int)a <= code_trace_hi)
					code_seen.insert(a);
			}
			if (switch_pc_trace) {
				uint32_t a = top->dbg_addr;
				if (a >= 0x0200 && a <= 0x0207) {
					uint32_t key = (a << 16) | top->dbg_pc;
					if (switch_pc_seen.insert(key).second)
						fprintf(stderr, "[swpc] read %04X at PC=%04X\n",
						        a, (unsigned)top->dbg_pc);
				}
			}

			if (raster_probe_frame >= 0 && !rp_done &&
			    video.count_frame == raster_probe_frame &&
			    video.count_line == rp_line && !top->VGA_HB && !top->VGA_VB) {
				int x = video.count_pixel - 1;      // 0 at the first visible pixel
				if (x == 0) rp_h_at_x0 = top->dbg_hcount;
				if (top->dbg_pfwndo) {
					if (rp_pf_first < 0) rp_pf_first = x;
					rp_pf_last = x;
				}
				if (top->dbg_carena) {
					if (rp_car_first < 0) rp_car_first = x;
					rp_car_last = x;
				}
			}
			if (raster_probe_frame >= 0 && !rp_done && rp_pf_first >= 0 &&
			    video.count_line > rp_line) {
				fprintf(stderr,
				        "[raster] frame=%d line=%d  hcount at x=0 is %d\n"
				        "[raster]   playfield window x=%d..%d  (width %d)\n"
				        "[raster]   car window       x=%d..%d  (width %d)\n"
				        "[raster]   MAME reference: playfield window x=42..277 (width 236)\n",
				        raster_probe_frame, rp_line, rp_h_at_x0,
				        rp_pf_first, rp_pf_last, rp_pf_last - rp_pf_first + 1,
				        rp_car_first, rp_car_last, rp_car_last - rp_car_first + 1);
				rp_done = true;
			}
			if (video.frame_complete && video.completed_frame != prev_frame) {
				fprintf(stderr, "[frame] %d (t=%llu)\n",
				        video.completed_frame, (unsigned long long)main_time);
				prev_frame = video.completed_frame;
				if (screenshot_mode) {
					auto it = std::find(screenshot_frames.begin(), screenshot_frames.end(), video.completed_frame);
					if (it != screenshot_frames.end()) {
						fprintf(stderr, "[car_rot] frame=%d value=0x%02X\n",
					        video.completed_frame, (unsigned)top->dbg_car_rot);
					{
						unsigned sd = top->dbg_sound;
						fprintf(stderr,
						        "[sound]   frame=%d joy=0x%X speed=%u crash=%u skid=%u tone=%u"
						        "  inputs bit7=0x%02X bit0=0x%02X reads=%u"
						        "  strobes motor=%u crash=%u  last bus bytes motor=0x%02X crash=0x%02X\n",
						        video.completed_frame, (unsigned)top->joystick_0, sd & 0xF, (sd >> 4) & 0xF,
						        (sd >> 8) & 1, (sd >> 9) & 1,
						        (unsigned)((top->dbg_inputs >> 8) & 0xFF),
						        (unsigned)(top->dbg_inputs & 0xFF),
						        (unsigned)top->dbg_in_count,
						        (unsigned)(top->dbg_snd_strobes & 0xFF),
						        (unsigned)((top->dbg_snd_strobes >> 8) & 0xFF),
						        (unsigned)((top->dbg_snd_strobes >> 16) & 0xFF),
						        (unsigned)((top->dbg_snd_strobes >> 24) & 0xFF));
					}
					save_screenshot(video.completed_frame);
						screenshot_frames.erase(it);
					}
				}
				if (dump_ram_at_frame >= 0 && video.completed_frame == dump_ram_at_frame) {
					auto* root = top->rootp;
					fprintf(stderr,
					        "stats_xMax=%d stats_yMax=%d (visible region per scanline x lines per frame)\n",
					        video.stats_xMax, video.stats_yMax);
					fprintf(stderr,
					        "Flash=%d Attract=%d PHP=%02X PVP=%02X "
					        "ScrollX=%02X ScrollY=%02X\n",
					        root->emu__DOT__superbug__DOT__Flash,
					        root->emu__DOT__superbug__DOT__Attract,
					        root->emu__DOT__superbug__DOT__Playfield__DOT__PHP,
					        root->emu__DOT__superbug__DOT__Playfield__DOT__PVP,
					        root->emu__DOT__superbug__DOT__CPU__DOT__scroll_x_dbg,
					        root->emu__DOT__superbug__DOT__CPU__DOT__scroll_y_dbg);
					fprintf(stderr,
					        "scroll_x writes since reset = %u, scroll_y writes = %u\n",
					        root->emu__DOT__superbug__DOT__CPU__DOT__scroll_x_writes,
					        root->emu__DOT__superbug__DOT__CPU__DOT__scroll_y_writes);
					fprintf(stderr, "=== alpha-num RAM (P3, 128 bytes, 32 used) at frame %d ===\n", dump_ram_at_frame);
					for (int i = 0; i < 32; i++) {
						fprintf(stderr, " %02X", root->emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem[i]);
						if ((i & 15) == 15) fprintf(stderr, "\n");
					}
					fprintf(stderr, "=== playfield RAM (E6 high nibble | F6 low nibble, 256 bytes) at frame %d ===\n", dump_ram_at_frame);
					for (int i = 0; i < 256; i++) {
						uint8_t hi = root->emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem[i] & 0xF;
						uint8_t lo = root->emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem[i] & 0xF;
						fprintf(stderr, " %02X", (hi << 4) | lo);
						if ((i & 15) == 15) fprintf(stderr, "\n");
					}
					// The 6800's scratchpad at $0000-$00FF, where all the game
					// state lives. Two 256x4 rams, N1 the high nibble and M1
					// the low. This is what to compare against MAME when the
					// two cores read the same switches but behave differently.
					fprintf(stderr, "=== CPU scratchpad RAM ($0000-$00FF) at frame %d ===\n", dump_ram_at_frame);
					for (int i = 0; i < 256; i++) {
						uint8_t hi = root->emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem[i] & 0xF;
						uint8_t lo = root->emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem[i] & 0xF;
						fprintf(stderr, " %02X", (hi << 4) | lo);
						if ((i & 15) == 15) fprintf(stderr, "\n");
					}
					dump_ram_at_frame = -1;  // once
				}
				if (stop_at_frame >= 0 && video.completed_frame >= stop_at_frame) {
					fprintf(stderr, "stop-at-frame %d reached, exiting\n", stop_at_frame);
					if (!audio_wav_path.empty()) write_wav(audio_wav_path, audio_samples, 44100);
					if (code_trace_lo >= 0)
						for (uint32_t a : code_seen)
							fprintf(stderr, "[code] %04X\n", a);
					exit(0);
				}
				video.frame_complete = false;
			}
		}

		if (clk_sys.IsRising()) {




			main_time++;
		}
		return 1;
	}

	// Stop verilating and cleanup
	top->final();
	delete top;
	exit(0);
	return 0;
}

unsigned char mouse_clock = 0;
unsigned char mouse_clock_reduce = 0;
unsigned char mouse_buttons = 0;
unsigned char mouse_x = 0;
unsigned char mouse_y = 0;

char spinner_toggle = 0;

int main(int argc, char** argv, char** env) {

	// Parse our CLI args before handing the rest to Verilator.
	for (int i = 1; i < argc; i++) {
		if ((!strcmp(argv[i], "--screenshot") || !strcmp(argv[i], "-screenshot")) && i + 1 < argc) {
			screenshot_mode = true;
			parse_screenshot_frames(argv[++i]);
		} else if (!strcmp(argv[i], "--screenshot-name") && i + 1 < argc) {
			screenshot_name_override = argv[++i];
		} else if (!strcmp(argv[i], "--screenshot-dir") && i + 1 < argc) {
			screenshot_dir = argv[++i];
		} else if (!strcmp(argv[i], "--stop-at-frame") && i + 1 < argc) {
			stop_at_frame = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "--headless")) {
			headless_mode = true;
		} else if (!strcmp(argv[i], "--trace") && i + 1 < argc) {
			trace_path = argv[++i];
		} else if (!strcmp(argv[i], "--trace-max") && i + 1 < argc) {
			trace_max = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "--dump-ram") && i + 1 < argc) {
			dump_ram_at_frame = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "--raster-probe") && i + 1 < argc) {
			raster_probe_frame = atoi(argv[++i]);
			if (i + 1 < argc && argv[i + 1][0] != '-') rp_line = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "--input") && i + 1 < argc) {
			parse_input_script(argv[++i]);
		} else if (!strcmp(argv[i], "--audio-wav") && i + 1 < argc) {
			audio_wav_path = argv[++i];
		} else if (!strcmp(argv[i], "--code-trace") && i + 2 < argc) {
			code_trace_lo = (int)strtol(argv[++i], nullptr, 0);
			code_trace_hi = (int)strtol(argv[++i], nullptr, 0);
		} else if (!strcmp(argv[i], "--watch-read") && i + 3 < argc) {
			watch_addr = (int)strtol(argv[++i], nullptr, 0);
			watch_from = atoi(argv[++i]);
			watch_to   = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "--switch-pc-trace")) {
			switch_pc_trace = true;
		} else if (!strcmp(argv[i], "--service")) {
			service_mode = true;
		} else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
			printf("Super Bug Verilator sim\n"
			       "  --screenshot <frames>     comma-separated frame numbers\n"
			       "  --screenshot-name <path>  override output path (single shot)\n"
			       "  --screenshot-dir <dir>    one PNG per frame into <dir>\n"
			       "  --audio-wav <path>        capture audio to a 44.1 kHz WAV\n"
			       "  --input <script>          scripted buttons, e.g.\n"
			       "                            \"60:coin, 90:start, 120-900:gas\"\n"
			       "  --stop-at-frame <n>       exit after frame n\n"
			       "  --service                 hold self-test switch active (matches MAME selftest.avi)\n"
			       "  --headless                hint for batch mode (still opens window)\n");
			return 0;
		}
	}

	if (!trace_path.empty()) {
		trace_fp = fopen(trace_path.c_str(), "w");
		if (!trace_fp) {
			fprintf(stderr, "trace: could not open %s for write\n", trace_path.c_str());
			return 1;
		}
		fprintf(stderr, "trace: writing to %s%s\n", trace_path.c_str(),
		        trace_max ? " (capped)" : "");
	}

	// Create core and initialise
	top = new Vemu();
	Verilated::commandArgs(argc, argv);



#ifdef WIN32
	// Attach debug console to the verilated code
	//Verilated::setDebug(console);
#endif

#ifdef CPU_DEBUG
        // Load debug opcodes
        loadOpcodes();

        // Load debug trace
        std::string line;
        std::ifstream fin(tracefilename);
        while (getline(fin, line)) {
                log_mame.push_back(line);
        }
#endif

	// Attach bus
	bus.ioctl_addr = &top->ioctl_addr;
	bus.ioctl_index = &top->ioctl_index;
	bus.ioctl_wait = &top->ioctl_wait;
	bus.ioctl_download = &top->ioctl_download;
	//bus.ioctl_upload = &top->ioctl_upload;
	bus.ioctl_wr = &top->ioctl_wr;
	bus.ioctl_dout = &top->ioctl_dout;
	//bus.ioctl_din = &top->ioctl_din;
	input.ps2_key = &top->ps2_key;

	// hookup blk device
	blockdevice.sd_lba[0] = &top->sd_lba[0];
	blockdevice.sd_lba[1] = &top->sd_lba[1];
	blockdevice.sd_rd = &top->sd_rd;
	blockdevice.sd_wr = &top->sd_wr;
	blockdevice.sd_ack = &top->sd_ack;
	blockdevice.sd_buff_addr= &top->sd_buff_addr;
	blockdevice.sd_buff_dout= &top->sd_buff_dout;
	blockdevice.sd_buff_din[0]= &top->sd_buff_din[0];
	blockdevice.sd_buff_din[1]= &top->sd_buff_din[1];
	blockdevice.sd_buff_wr= &top->sd_buff_wr;
	blockdevice.img_mounted= &top->img_mounted;
	blockdevice.img_readonly= &top->img_readonly;
	blockdevice.img_size= &top->img_size;


#ifndef DISABLE_AUDIO
	audio.Initialise();
#endif

	// Set up input module
	input.Initialise();
#ifdef WIN32
	input.SetMapping(input_up, DIK_UP);
	input.SetMapping(input_right, DIK_RIGHT);
	input.SetMapping(input_down, DIK_DOWN);
	input.SetMapping(input_left, DIK_LEFT);
	input.SetMapping(input_a, DIK_Z); // A
	input.SetMapping(input_b, DIK_X); // B
	input.SetMapping(input_x, DIK_A); // X
	input.SetMapping(input_y, DIK_S); // Y
	input.SetMapping(input_l, DIK_Q); // L
	input.SetMapping(input_r, DIK_W); // R
	input.SetMapping(input_select, DIK_1); // Select
	input.SetMapping(input_start, DIK_2); // Start
	input.SetMapping(input_menu, DIK_M); // System menu trigger

#else
	input.SetMapping(input_up, SDL_SCANCODE_UP);
	input.SetMapping(input_right, SDL_SCANCODE_RIGHT);
	input.SetMapping(input_down, SDL_SCANCODE_DOWN);
	input.SetMapping(input_left, SDL_SCANCODE_LEFT);
	input.SetMapping(input_a, SDL_SCANCODE_A);
	input.SetMapping(input_b, SDL_SCANCODE_B);
	input.SetMapping(input_x, SDL_SCANCODE_X);
	input.SetMapping(input_y, SDL_SCANCODE_Y);
	input.SetMapping(input_l, SDL_SCANCODE_L);
	input.SetMapping(input_r, SDL_SCANCODE_E);
	input.SetMapping(input_start, SDL_SCANCODE_1);
	input.SetMapping(input_select, SDL_SCANCODE_2);
	input.SetMapping(input_menu, SDL_SCANCODE_M);
#endif

	if (headless_mode) {
		output_ptr = (uint32_t*)malloc(video.output_width * video.output_height * 4);
		if (!output_ptr) {
			fprintf(stderr, "headless: video buffer allocation failed\n");
			return 1;
		}
		memset(output_ptr, 0xAA, video.output_width * video.output_height * 4);
		top->joystick_0 = 0;
		top->joystick_1 = 0;
		top->service_mode = service_mode ? 1 : 0;
		while (true) {
			for (int step = 0; step < batchSize; step++) {
				top->service_mode = service_mode ? 1 : 0;
				top->joystick_0 = scripted_buttons(video.count_frame);
				top->joystick_1 = top->joystick_0;
				verilate();
			}
		}
	}

	// Setup video output
	if (video.Initialise(windowTitle) == 1) { return 1; }

        //bus.QueueDownload("floppy.nib",1,0);
	//blockdevice.MountDisk("floppy.nib",0);
	//blockdevice.MountDisk("hd.hdv",1);

#ifdef WIN32
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
#else
	bool done = false;
	while (!done)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				done = true;
		}
#endif
		video.StartFrame();

		input.Read();


		// Draw GUI
		// --------
		ImGui::NewFrame();

		// Simulation control window
		ImGui::Begin(windowTitle_Control);
		ImGui::SetWindowPos(windowTitle_Control, ImVec2(0, 0), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Control, ImVec2(500, 150), ImGuiCond_Once);
		if (ImGui::Button("Reset simulation")) { resetSim(); } ImGui::SameLine();
		if (ImGui::Button("Start running")) { run_enable = 1; } ImGui::SameLine();
		if (ImGui::Button("Stop running")) { run_enable = 0; } ImGui::SameLine();
		ImGui::Checkbox("RUN", &run_enable);
		//ImGui::PopItemWidth();
		ImGui::SliderInt("Run batch size", &batchSize, 1, 250000);
		if (single_step == 1) { single_step = 0; }
		if (ImGui::Button("Single Step")) { run_enable = 0; single_step = 1; }
		ImGui::SameLine();
		if (multi_step == 1) { multi_step = 0; }
		if (ImGui::Button("Multi Step")) { run_enable = 0; multi_step = 1; }
		//ImGui::SameLine();
		ImGui::SliderInt("Multi step amount", &multi_step_amount, 8, 1024);
		ImGui::SameLine();
//		if (ImGui::Button("Load ROM"))
    //ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".rom", ".");

		//if (ImGui::Button("Soft Reset")) { fprintf(stderr,"soft reset\n"); soft_reset=1; } ImGui::SameLine();

		ImGui::End();

		// Debug log window
		console.Draw(windowTitle_DebugLog, &showDebugLog, ImVec2(500, 700));
		ImGui::SetWindowPos(windowTitle_DebugLog, ImVec2(0, 160), ImGuiCond_Once);

		// Memory / CPU debug windows disabled — hierarchy is from a
		// different core. TODO: re-wire to Super Bug signals via
		// /*verilator public*/ on cpu68 internals if needed.
		//ImGui::Spacing();


		int windowX = 550;
		int windowWidth = (VGA_WIDTH * VGA_SCALE_X) + 24;
		int windowHeight = (VGA_HEIGHT * VGA_SCALE_Y) + 90;

		// Video window
		ImGui::Begin(windowTitle_Video);
		ImGui::SetWindowPos(windowTitle_Video, ImVec2(windowX, 0), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Video, ImVec2(windowWidth, windowHeight), ImGuiCond_Once);

		ImGui::SliderFloat("Zoom", &vga_scale, 1, 8); ImGui::SameLine();
		ImGui::SliderInt("Rotate", &video.output_rotate, -1, 1); ImGui::SameLine();
		ImGui::Checkbox("Flip V", &video.output_vflip);
		ImGui::Text("main_time: %ld frame_count: %d sim FPS: %f", main_time, video.count_frame, video.stats_fps);
		//ImGui::Text("pixel: %06d line: %03d", video.count_pixel, video.count_line);

		// Draw VGA output
		ImGui::Image(video.texture_id, ImVec2(video.output_width * VGA_SCALE_X, video.output_height * VGA_SCALE_Y));
		ImGui::End();

  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
  {
    // action if OK
    if (ImGuiFileDialog::Instance()->IsOk())
    {
      std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
      // action
fprintf(stderr,"filePathName: %s\n",filePathName.c_str());
fprintf(stderr,"filePath: %s\n",filePath.c_str());
     bus.QueueDownload(filePathName, 1,1);
    }
   
    // close
    ImGuiFileDialog::Instance()->Close();
  }


#ifndef DISABLE_AUDIO

		ImGui::Begin(windowTitle_Audio);
		ImGui::SetWindowPos(windowTitle_Audio, ImVec2(windowX, windowHeight), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Audio, ImVec2(windowWidth, 250), ImGuiCond_Once);

		
		//float vol_l = ((signed short)(top->AUDIO_L) / 256.0f) / 256.0f;
		//float vol_r = ((signed short)(top->AUDIO_R) / 256.0f) / 256.0f;
		//ImGui::ProgressBar(vol_l + 0.5f, ImVec2(200, 16), 0); ImGui::SameLine();
		//ImGui::ProgressBar(vol_r + 0.5f, ImVec2(200, 16), 0);

		int ticksPerSec = (24000000 / 60);
		if (run_enable) {
			audio.CollectDebug((signed short)top->AUDIO_L, (signed short)top->AUDIO_R);
		}
		int channelWidth = (windowWidth / 2)  -16;
		ImPlot::CreateContext();
		if (ImPlot::BeginPlot("Audio - L", ImVec2(channelWidth, 220), ImPlotFlags_NoLegend | ImPlotFlags_NoMenus | ImPlotFlags_NoTitle)) {
			ImPlot::SetupAxes("T", "A", ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks);
			ImPlot::SetupAxesLimits(0, 1, -1, 1, ImPlotCond_Once);
			ImPlot::PlotStairs("", audio.debug_positions, audio.debug_wave_l, audio.debug_max_samples, audio.debug_pos);
			ImPlot::EndPlot();
		}
		ImGui::SameLine();
		if (ImPlot::BeginPlot("Audio - R", ImVec2(channelWidth, 220), ImPlotFlags_NoLegend | ImPlotFlags_NoMenus | ImPlotFlags_NoTitle)) {
			ImPlot::SetupAxes("T", "A", ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks);
			ImPlot::SetupAxesLimits(0, 1, -1, 1, ImPlotCond_Once);
			ImPlot::PlotStairs("", audio.debug_positions, audio.debug_wave_r, audio.debug_max_samples, audio.debug_pos);
			ImPlot::EndPlot();
		}
		ImPlot::DestroyContext();
		ImGui::End();
#endif

		video.UpdateTexture();


		// Pass inputs to sim

		top->menu = input.inputs[input_menu];

		top->joystick_0 = 0;
		for (int i = 0; i < input.inputCount; i++)
		{
			if (input.inputs[i]) { top->joystick_0 |= (1 << i); }
		}
		top->joystick_0 |= scripted_buttons(video.count_frame);
		top->joystick_1 = top->joystick_0;
		top->service_mode = service_mode ? 1 : 0;

		/*top->joystick_analog_0 += 1;
		top->joystick_analog_0 -= 256;*/
		//top->paddle_0 += 1;
		//if (input.inputs[0] || input.inputs[1]) {
		//	spinner_toggle = !spinner_toggle;
		//	top->spinner_0 = (input.inputs[0]) ? 16 : -16;
		//	for (char b = 8; b < 16; b++) {
		//		top->spinner_0 &= ~(1UL << b);
		//	}
		//	if (spinner_toggle) { top->spinner_0 |= 1UL << 8; }
		//}

		mouse_buttons = 0;
		mouse_x = 0;
		mouse_y = 0;
		if (input.inputs[input_left]) { mouse_x = -2; }
		if (input.inputs[input_right]) { mouse_x = 2; }
		if (input.inputs[input_up]) { mouse_y = 2; }
		if (input.inputs[input_down]) { mouse_y = -2; }

		if (input.inputs[input_a]) { mouse_buttons |= (1UL << 0); }
		if (input.inputs[input_b]) { mouse_buttons |= (1UL << 1); }

		unsigned long mouse_temp = mouse_buttons;
		mouse_temp += (mouse_x << 8);
		mouse_temp += (mouse_y << 16);
		if (mouse_clock) { mouse_temp |= (1UL << 24); }
		mouse_clock = !mouse_clock;

		top->ps2_mouse = mouse_temp;
		top->ps2_mouse_ext = mouse_x + (mouse_buttons << 8);

		// Run simulation
		if (run_enable) {
			for (int step = 0; step < batchSize; step++) { 
				verilate();
			}
		}
		else {
			if (single_step) { verilate(); }
			if (multi_step) {
				for (int step = 0; step < multi_step_amount; step++) { verilate(); }
			}
		}
	}

	// Clean up before exit
	// --------------------

#ifndef DISABLE_AUDIO
	audio.CleanUp();
#endif 
	video.CleanUp();
	input.CleanUp();

	return 0;
}
