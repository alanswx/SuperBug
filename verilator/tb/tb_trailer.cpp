// Exercise rtl/trailer.v through all eight rotation frames and both flips,
// and compare every rendered sprite against the trailer ROM decoded the way
// the reference driver's gfx layout says it should be.
#include "Vtrailer.h"
#include "verilated.h"
#include <cstdio>
#include <cstring>
#include <vector>

static Vtrailer* dut;
static void tick() { dut->Clk6 = 0; dut->eval(); dut->Clk6 = 1; dut->eval(); }

static const int W = 320, H = 256;
static std::vector<unsigned char> fb;

// Latch a value into one of the three position registers: the module latches
// on the falling edge of the active-low strobe.
static void latch(unsigned char val, int which) {
    dut->BD = val;
    dut->DroneX_n = 1; dut->DroneY_n = 1; dut->DroneRot_n = 1;
    tick();
    if (which == 0) dut->DroneX_n = 0;
    if (which == 1) dut->DroneY_n = 0;
    if (which == 2) dut->DroneRot_n = 0;
    tick(); tick();
    dut->DroneX_n = 1; dut->DroneY_n = 1; dut->DroneRot_n = 1;
    tick();
}

static void render() {
    fb.assign(W * H, 0);
    for (int v = 0; v < H; v++) {
        dut->VCount = v;
        // The horizontal counter runs 224..511 then 128..159 across a line.
        for (int step = 0; step < 320; step++) {
            int hc = (step < 288) ? (224 + step) : (128 + (step - 288));
            dut->HCount = hc;
            tick();
            // pos_x for the CURRENT hc, as the display sees it
            int h2 = (hc + 2) & 0x1ff;
            int px = (h2 >= 224) ? (h2 - 224) : (h2 + 160);
            if (px >= 0 && px < W) fb[v * W + px] = dut->TrailerVideo;
        }
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    dut = new Vtrailer;
    dut->Game = 1;
    dut->dn_wr = 0; dut->dn_addr = 0; dut->dn_data = 0; dut->dn_clk = 0;
    dut->BD = 0; dut->DroneX_n = 1; dut->DroneY_n = 1; dut->DroneRot_n = 1;
    dut->HCount = 0; dut->VCount = 0;
    for (int i = 0; i < 20; i++) tick();

    // The trailer ROM, decoded per the reference gfx layout: each frame is
    // 512 bytes, 64 rows of 8 bytes, leftmost pixel in the most significant bit.
    unsigned char rom[4096];
    FILE* f = fopen("../roms/hex/firetrk_trailer.hex", "r");
    if (!f) { fprintf(stderr, "cannot open trailer hex\n"); return 2; }
    for (int i = 0; i < 4096; i++) { unsigned v; if (fscanf(f, "%x", &v) != 1) { fprintf(stderr,"short rom at %d\n", i); return 2; } rom[i] = v; }
    fclose(f);

    const int dx = 129, dy = 135;
    int failures = 0;
    for (int fr = 0; fr < 8; fr++)
    for (int fx = 0; fx < 2; fx++)
    for (int fy = 0; fy < 2; fy++) {
        unsigned char rot = fr | (fx ? 0x08 : 0) | (fy ? 0x10 : 0);
        latch(dx, 0); latch(dy, 1); latch(rot, 2);
        render();

        int ox = (fx ? dx - 63 : 192 - dx) + 36;
        int oy = (fy ? dy - 63 : 192 - dy);

        // Expected bitmap straight from the ROM.
        unsigned char exp[64][64];
        for (int y = 0; y < 64; y++)
            for (int x = 0; x < 64; x++) {
                int sy = fy ? 63 - y : y, sx = fx ? 63 - x : x;
                exp[y][x] = (rom[fr * 512 + sy * 8 + (sx >> 3)] >> (7 - (sx & 7))) & 1;
            }

        // Best alignment within a few pixels, then exact-match check there.
        int best = 1 << 30, bdx = 0, bdy = 0;
        for (int sy = -3; sy <= 3; sy++)
        for (int sx = -3; sx <= 3; sx++) {
            int m = 0;
            for (int y = 0; y < 64; y++)
            for (int x = 0; x < 64; x++) {
                int py = oy + y + sy, px = ox + x + sx;
                unsigned char got = (py >= 0 && py < H && px >= 0 && px < W) ? fb[py * W + px] : 0;
                if (got != exp[y][x]) m++;
            }
            if (m < best) { best = m; bdx = sx; bdy = sy; }
        }
        int lit_total = 0;
        for (int i = 0; i < W * H; i++) lit_total += fb[i];
        int lit_exp = 0;
        for (int y = 0; y < 64; y++) for (int x = 0; x < 64; x++) lit_exp += exp[y][x];
        const char* verdict = (best == 0 && lit_total == lit_exp) ? "ok" : "MISMATCH";
        if (strcmp(verdict, "ok")) failures++;
        printf("rot=%2u frame=%d flipx=%d flipy=%d  mismatch=%4d at (dx=%+d,dy=%+d)  lit drawn=%4d expected=%4d  %s\n",
               rot, fr, fx, fy, best, bdx, bdy, lit_total, lit_exp, verdict);
    }
    printf("\n%s: %d of 32 combinations mismatched\n", failures ? "FAIL" : "PASS", failures);
    delete dut;
    return failures ? 1 : 0;
}
