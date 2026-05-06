// Minimal Motorola 6800 disassembler.
// Returns the mnemonic and addressing-mode operand-byte count for a given
// opcode. For the trace path we don't need to render the full operand bytes
// — knowing the mnemonic at each PC is enough to diff against MAME's
// 'trace cpu0,trace.log' output up to the first divergence.
//
// Reference: Motorola M6800 Programming Reference Manual.

#pragma once

#include <cstdint>
#include <cstdio>

struct Op6800 {
    const char* mnem;
    uint8_t     mode;   // 0=inh,1=imm8,2=imm16,3=dir,4=ext,5=ind,6=rel
    uint8_t     bytes;  // total instruction bytes including opcode
};

static inline const Op6800 disasm6800_table(uint8_t op) {
    static const Op6800 t[256] = {
        // 0x00..0x0F
        {"ILL",0,1},{"NOP",0,1},{"ILL",0,1},{"ILL",0,1},
        {"ILL",0,1},{"ILL",0,1},{"TAP",0,1},{"TPA",0,1},
        {"INX",0,1},{"DEX",0,1},{"CLV",0,1},{"SEV",0,1},
        {"CLC",0,1},{"SEC",0,1},{"CLI",0,1},{"SEI",0,1},
        // 0x10..0x1F
        {"SBA",0,1},{"CBA",0,1},{"ILL",0,1},{"ILL",0,1},
        {"ILL",0,1},{"ILL",0,1},{"TAB",0,1},{"TBA",0,1},
        {"ILL",0,1},{"DAA",0,1},{"ILL",0,1},{"ABA",0,1},
        {"ILL",0,1},{"ILL",0,1},{"ILL",0,1},{"ILL",0,1},
        // 0x20..0x2F  branches (relative)
        {"BRA",6,2},{"ILL",0,1},{"BHI",6,2},{"BLS",6,2},
        {"BCC",6,2},{"BCS",6,2},{"BNE",6,2},{"BEQ",6,2},
        {"BVC",6,2},{"BVS",6,2},{"BPL",6,2},{"BMI",6,2},
        {"BGE",6,2},{"BLT",6,2},{"BGT",6,2},{"BLE",6,2},
        // 0x30..0x3F
        {"TSX",0,1},{"INS",0,1},{"PULA",0,1},{"PULB",0,1},
        {"DES",0,1},{"TXS",0,1},{"PSHA",0,1},{"PSHB",0,1},
        {"ILL",0,1},{"RTS",0,1},{"ILL",0,1},{"RTI",0,1},
        {"ILL",0,1},{"ILL",0,1},{"WAI",0,1},{"SWI",0,1},
        // 0x40..0x4F  ACC A inherent
        {"NEGA",0,1},{"ILL",0,1},{"ILL",0,1},{"COMA",0,1},
        {"LSRA",0,1},{"ILL",0,1},{"RORA",0,1},{"ASRA",0,1},
        {"ASLA",0,1},{"ROLA",0,1},{"DECA",0,1},{"ILL",0,1},
        {"INCA",0,1},{"TSTA",0,1},{"ILL",0,1},{"CLRA",0,1},
        // 0x50..0x5F  ACC B inherent
        {"NEGB",0,1},{"ILL",0,1},{"ILL",0,1},{"COMB",0,1},
        {"LSRB",0,1},{"ILL",0,1},{"RORB",0,1},{"ASRB",0,1},
        {"ASLB",0,1},{"ROLB",0,1},{"DECB",0,1},{"ILL",0,1},
        {"INCB",0,1},{"TSTB",0,1},{"ILL",0,1},{"CLRB",0,1},
        // 0x60..0x6F  indexed
        {"NEG",5,2},{"ILL",0,1},{"ILL",0,1},{"COM",5,2},
        {"LSR",5,2},{"ILL",0,1},{"ROR",5,2},{"ASR",5,2},
        {"ASL",5,2},{"ROL",5,2},{"DEC",5,2},{"ILL",0,1},
        {"INC",5,2},{"TST",5,2},{"JMP",5,2},{"CLR",5,2},
        // 0x70..0x7F  extended
        {"NEG",4,3},{"ILL",0,1},{"ILL",0,1},{"COM",4,3},
        {"LSR",4,3},{"ILL",0,1},{"ROR",4,3},{"ASR",4,3},
        {"ASL",4,3},{"ROL",4,3},{"DEC",4,3},{"ILL",0,1},
        {"INC",4,3},{"TST",4,3},{"JMP",4,3},{"CLR",4,3},
        // 0x80..0x8F  imm A
        {"SUBA",1,2},{"CMPA",1,2},{"SBCA",1,2},{"ILL",0,1},
        {"ANDA",1,2},{"BITA",1,2},{"LDAA",1,2},{"ILL",0,1},
        {"EORA",1,2},{"ADCA",1,2},{"ORAA",1,2},{"ADDA",1,2},
        {"CPX", 2,3},{"BSR", 6,2},{"LDS", 2,3},{"ILL",0,1},
        // 0x90..0x9F  dir A
        {"SUBA",3,2},{"CMPA",3,2},{"SBCA",3,2},{"ILL",0,1},
        {"ANDA",3,2},{"BITA",3,2},{"LDAA",3,2},{"STAA",3,2},
        {"EORA",3,2},{"ADCA",3,2},{"ORAA",3,2},{"ADDA",3,2},
        {"CPX", 3,2},{"ILL",0,1},{"LDS", 3,2},{"STS", 3,2},
        // 0xA0..0xAF  idx A
        {"SUBA",5,2},{"CMPA",5,2},{"SBCA",5,2},{"ILL",0,1},
        {"ANDA",5,2},{"BITA",5,2},{"LDAA",5,2},{"STAA",5,2},
        {"EORA",5,2},{"ADCA",5,2},{"ORAA",5,2},{"ADDA",5,2},
        {"CPX", 5,2},{"JSR", 5,2},{"LDS", 5,2},{"STS", 5,2},
        // 0xB0..0xBF  ext A
        {"SUBA",4,3},{"CMPA",4,3},{"SBCA",4,3},{"ILL",0,1},
        {"ANDA",4,3},{"BITA",4,3},{"LDAA",4,3},{"STAA",4,3},
        {"EORA",4,3},{"ADCA",4,3},{"ORAA",4,3},{"ADDA",4,3},
        {"CPX", 4,3},{"JSR", 4,3},{"LDS", 4,3},{"STS", 4,3},
        // 0xC0..0xCF  imm B
        {"SUBB",1,2},{"CMPB",1,2},{"SBCB",1,2},{"ILL",0,1},
        {"ANDB",1,2},{"BITB",1,2},{"LDAB",1,2},{"ILL",0,1},
        {"EORB",1,2},{"ADCB",1,2},{"ORAB",1,2},{"ADDB",1,2},
        {"ILL",0,1},{"ILL",0,1},{"LDX", 2,3},{"ILL",0,1},
        // 0xD0..0xDF  dir B
        {"SUBB",3,2},{"CMPB",3,2},{"SBCB",3,2},{"ILL",0,1},
        {"ANDB",3,2},{"BITB",3,2},{"LDAB",3,2},{"STAB",3,2},
        {"EORB",3,2},{"ADCB",3,2},{"ORAB",3,2},{"ADDB",3,2},
        {"ILL",0,1},{"ILL",0,1},{"LDX", 3,2},{"STX", 3,2},
        // 0xE0..0xEF  idx B
        {"SUBB",5,2},{"CMPB",5,2},{"SBCB",5,2},{"ILL",0,1},
        {"ANDB",5,2},{"BITB",5,2},{"LDAB",5,2},{"STAB",5,2},
        {"EORB",5,2},{"ADCB",5,2},{"ORAB",5,2},{"ADDB",5,2},
        {"ILL",0,1},{"ILL",0,1},{"LDX", 5,2},{"STX", 5,2},
        // 0xF0..0xFF  ext B
        {"SUBB",4,3},{"CMPB",4,3},{"SBCB",4,3},{"ILL",0,1},
        {"ANDB",4,3},{"BITB",4,3},{"LDAB",4,3},{"STAB",4,3},
        {"EORB",4,3},{"ADCB",4,3},{"ORAB",4,3},{"ADDB",4,3},
        {"ILL",0,1},{"ILL",0,1},{"LDX", 4,3},{"STX", 4,3},
    };
    return t[op];
}

// Format a single line: "PC: OP  MNEM <mode>" — operand byte count is enough
// to diff against MAME mnemonic-only traces. If/when we want operand bytes,
// hook a bus tap to capture the next (bytes-1) reads.
static inline void disasm6800_fmt(uint16_t pc, uint8_t op, char* out, int outlen) {
    Op6800 d = disasm6800_table(op);
    static const char* mode_str[] = {"", " #", " #16", " dir", " ext", " ,X", " rel"};
    snprintf(out, outlen, "%04X: %02X  %-4s%s", pc, op, d.mnem, mode_str[d.mode]);
}
