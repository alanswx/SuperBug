//===========================================================================
//
//  S Y N T H E S I Z A B L E    CPU68   C O R E
//
//  Verilog port of John E. Kent's cpu68.vhd (OpenCores, 2002-2004).
//  Hand-written, from-scratch translation of the original VHDL.
//  The previous Verilog in this tree was the output of a broken auto-converter
//  and did not function; this file replaces it.
//
//  Implements a Motorola 6800 compatible core with the 6801 additions
//  (LSRD/ASLD, MUL, PSHX/PULX, ABX, ADDD/SUBD, LDD/STD, LDX immediate, etc.).
//  Falling-edge clocked, matching the original VHDL.
//
//===========================================================================

`default_nettype none

module cpu68(
    clk,
    rst,
    rw,
    vma,
    address,
    data_in,
    data_out,
    hold,
    halt,
    irq,
    nmi,
    test_alu,
    test_cc,
    dbg_pc,
    dbg_opcode,
    dbg_addr,
    dbg_din,
    dbg_op_fetch,
    dbg_acca,
    dbg_accb,
    dbg_cc
);
    input             clk;
    input             rst;
    output reg        rw;
    output reg        vma;
    output reg [15:0] address;
    input      [7:0]  data_in;
    output reg [7:0]  data_out;
    input             hold;
    input             halt;
    input             irq;
    input             nmi;
    output     [15:0] test_alu;
    output     [7:0]  test_cc;
    output     [15:0] dbg_pc;
    output     [7:0]  dbg_opcode;
    output     [15:0] dbg_addr;
    output     [7:0]  dbg_din;
    output            dbg_op_fetch;  // pulses high during the fetch cycle
    output      [7:0] dbg_acca;
    output      [7:0] dbg_accb;
    output      [7:0] dbg_cc;

    // CC bit positions
    localparam SBIT = 7;
    localparam XBIT = 6;
    localparam HBIT = 5;
    localparam IBIT = 4;
    localparam NBIT = 3;
    localparam ZBIT = 2;
    localparam VBIT = 1;
    localparam CBIT = 0;

    // ===== State encoding =====
    localparam [5:0]
        ST_RESET    = 6'd0,
        ST_FETCH    = 6'd1,
        ST_DECODE   = 6'd2,
        ST_EXTENDED = 6'd3,
        ST_INDEXED  = 6'd4,
        ST_READ8    = 6'd5,
        ST_READ16   = 6'd6,
        ST_IMM16    = 6'd7,
        ST_WRITE8   = 6'd8,
        ST_WRITE16  = 6'd9,
        ST_EXECUTE  = 6'd10,
        ST_HALT     = 6'd11,
        ST_ERROR    = 6'd12,
        ST_MUL      = 6'd13,
        ST_MULEA    = 6'd14,
        ST_MULD     = 6'd15,
        ST_MUL0     = 6'd16,
        ST_MUL1     = 6'd17,
        ST_MUL2     = 6'd18,
        ST_MUL3     = 6'd19,
        ST_MUL4     = 6'd20,
        ST_MUL5     = 6'd21,
        ST_MUL6     = 6'd22,
        ST_MUL7     = 6'd23,
        ST_JMP      = 6'd24,
        ST_JSR      = 6'd25,
        ST_JSR1     = 6'd26,
        ST_BRANCH   = 6'd27,
        ST_BSR      = 6'd28,
        ST_BSR1     = 6'd29,
        ST_RTS_HI   = 6'd30,
        ST_RTS_LO   = 6'd31,
        ST_INT_PCL  = 6'd32,
        ST_INT_PCH  = 6'd33,
        ST_INT_IXL  = 6'd34,
        ST_INT_IXH  = 6'd35,
        ST_INT_CC   = 6'd36,
        ST_INT_ACCA = 6'd37,
        ST_INT_ACCB = 6'd38,
        ST_INT_WAI  = 6'd39,
        ST_INT_MASK = 6'd40,
        ST_RTI      = 6'd41,
        ST_RTI_CC   = 6'd42,
        ST_RTI_ACCA = 6'd43,
        ST_RTI_ACCB = 6'd44,
        ST_RTI_IXL  = 6'd45,
        ST_RTI_IXH  = 6'd46,
        ST_RTI_PCL  = 6'd47,
        ST_RTI_PCH  = 6'd48,
        ST_PULA     = 6'd49,
        ST_PSHA     = 6'd50,
        ST_PULB     = 6'd51,
        ST_PSHB     = 6'd52,
        ST_PULX_LO  = 6'd53,
        ST_PULX_HI  = 6'd54,
        ST_PSHX_LO  = 6'd55,
        ST_PSHX_HI  = 6'd56,
        ST_VECT_LO  = 6'd57,
        ST_VECT_HI  = 6'd58;

    // ===== Mux control encodings =====
    localparam [2:0]
        AD_IDLE  = 3'd0, AD_FETCH = 3'd1, AD_READ  = 3'd2, AD_WRITE = 3'd3,
        AD_PUSH  = 3'd4, AD_PULL  = 3'd5, AD_INTH  = 3'd6, AD_INTL  = 3'd7;

    localparam [3:0]
        DO_MD_LO = 4'd0, DO_MD_HI = 4'd1, DO_ACCA = 4'd2, DO_ACCB = 4'd3,
        DO_IX_LO = 4'd4, DO_IX_HI = 4'd5, DO_CC   = 4'd6, DO_PC_LO = 4'd7, DO_PC_HI = 4'd8;

    localparam [1:0] OP_RESET = 2'd0, OP_FETCH = 2'd1, OP_LATCH = 2'd2;

    localparam [2:0]
        ACCA_RESET = 3'd0, ACCA_LOAD = 3'd1, ACCA_LOAD_HI = 3'd2,
        ACCA_PULL  = 3'd3, ACCA_LATCH = 3'd4;

    localparam [1:0]
        ACCB_RESET = 2'd0, ACCB_LOAD = 2'd1, ACCB_PULL = 2'd2, ACCB_LATCH = 2'd3;

    localparam [1:0] CC_RESET = 2'd0, CC_LOAD = 2'd1, CC_PULL = 2'd2, CC_LATCH = 2'd3;

    localparam [2:0]
        IX_RESET = 3'd0, IX_LOAD = 3'd1, IX_PULL_LO = 3'd2,
        IX_PULL_HI = 3'd3, IX_LATCH = 3'd4;

    localparam [1:0] SP_RESET = 2'd0, SP_LATCH = 2'd1, SP_LOAD = 2'd2;

    localparam [2:0]
        PC_RESET = 3'd0, PC_LATCH = 3'd1, PC_LOAD_EA = 3'd2, PC_ADD_EA = 3'd3,
        PC_PULL_LO = 3'd4, PC_PULL_HI = 3'd5, PC_INC = 3'd6;

    localparam [2:0]
        MD_RESET = 3'd0, MD_LATCH = 3'd1, MD_LOAD = 3'd2,
        MD_FETCH_FIRST = 3'd3, MD_FETCH_NEXT = 3'd4, MD_SHIFTL = 3'd5;

    localparam [2:0]
        EA_RESET = 3'd0, EA_LATCH = 3'd1, EA_ADD_IX = 3'd2, EA_LOAD_ACCB = 3'd3,
        EA_INC = 3'd4, EA_FETCH_FIRST = 3'd5, EA_FETCH_NEXT = 3'd6;

    localparam [2:0]
        IV_RESET = 3'd0, IV_LATCH = 3'd1, IV_SWI = 3'd2, IV_NMI = 3'd3, IV_IRQ = 3'd4;

    localparam [1:0] NMI_RESET = 2'd0, NMI_SET = 2'd1, NMI_LATCH = 2'd2;

    localparam [2:0]
        LEFT_ACCA = 3'd0, LEFT_ACCB = 3'd1, LEFT_ACCD = 3'd2,
        LEFT_MD = 3'd3, LEFT_IX = 3'd4, LEFT_SP = 3'd5;

    localparam [1:0]
        RIGHT_MD = 2'd0, RIGHT_ZERO = 2'd1, RIGHT_ONE = 2'd2, RIGHT_ACCB = 2'd3;

    localparam [5:0]
        ALU_ADD8 = 6'd0,  ALU_SUB8 = 6'd1,  ALU_ADD16 = 6'd2, ALU_SUB16 = 6'd3,
        ALU_ADC  = 6'd4,  ALU_SBC  = 6'd5,
        ALU_AND  = 6'd6,  ALU_ORA  = 6'd7,  ALU_EOR   = 6'd8,
        ALU_TST  = 6'd9,  ALU_INC  = 6'd10, ALU_DEC   = 6'd11, ALU_CLR = 6'd12,
        ALU_NEG  = 6'd13, ALU_COM  = 6'd14,
        ALU_INX  = 6'd15, ALU_DEX  = 6'd16, ALU_CPX   = 6'd17,
        ALU_LSR16 = 6'd18, ALU_LSL16 = 6'd19,
        ALU_ROR8  = 6'd20, ALU_ROL8  = 6'd21,
        ALU_ASR8  = 6'd22, ALU_ASL8  = 6'd23, ALU_LSR8 = 6'd24,
        ALU_SEI = 6'd25, ALU_CLI = 6'd26, ALU_SEC = 6'd27, ALU_CLC = 6'd28,
        ALU_SEV = 6'd29, ALU_CLV = 6'd30, ALU_TPA = 6'd31, ALU_TAP = 6'd32,
        ALU_LD8 = 6'd33, ALU_ST8 = 6'd34, ALU_LD16 = 6'd35, ALU_ST16 = 6'd36,
        ALU_NOP = 6'd37, ALU_DAA = 6'd38;

    // ===== State and registers =====
    reg  [7:0]  op_code;
    reg  [7:0]  acca;
    reg  [7:0]  accb;
    reg  [7:0]  cc;
    reg  [15:0] xreg;
    reg  [15:0] sp;
    reg  [15:0] ea;
    reg  [15:0] pc;
    reg  [15:0] md;
    reg  [1:0]  iv;
    reg         nmi_req;
    reg         nmi_ack;
    reg  [5:0]  state;

    // Combinational sequencer outputs
    reg  [5:0]  next_state;
    reg  [2:0]  pc_ctrl;
    reg  [2:0]  ea_ctrl;
    reg  [1:0]  op_ctrl;
    reg  [2:0]  md_ctrl;
    reg  [2:0]  acca_ctrl;
    reg  [1:0]  accb_ctrl;
    reg  [2:0]  ix_ctrl;
    reg  [1:0]  cc_ctrl;
    reg  [1:0]  sp_ctrl;
    reg  [2:0]  iv_ctrl;
    reg  [2:0]  left_ctrl;
    reg  [1:0]  right_ctrl;
    reg  [5:0]  alu_ctrl;
    reg  [2:0]  addr_ctrl;
    reg  [3:0]  dout_ctrl;
    reg  [1:0]  nmi_ctrl;

    // ALU
    reg  [15:0] left;
    reg  [15:0] right;
    reg  [15:0] out_alu;
    reg  [7:0]  cc_out;

    assign test_alu   = out_alu;
    assign test_cc    = cc_out;
    assign dbg_pc     = pc;
    assign dbg_opcode = op_code;
    assign dbg_addr   = address;
    assign dbg_din    = data_in;
    assign dbg_op_fetch = (op_ctrl == OP_FETCH);
    assign dbg_acca     = acca;
    assign dbg_accb     = accb;
    assign dbg_cc       = cc;

    // ----------------------------------
    // Address bus mux
    // ----------------------------------
    always @* begin
        case (addr_ctrl)
            AD_IDLE:  begin address = 16'hFFFF;             vma = 1'b0; rw = 1'b1; end
            AD_FETCH: begin address = pc;                   vma = 1'b1; rw = 1'b1; end
            AD_READ:  begin address = ea;                   vma = 1'b1; rw = 1'b1; end
            AD_WRITE: begin address = ea;                   vma = 1'b1; rw = 1'b0; end
            AD_PUSH:  begin address = sp;                   vma = 1'b1; rw = 1'b0; end
            AD_PULL:  begin address = sp;                   vma = 1'b1; rw = 1'b1; end
            AD_INTH:  begin address = {13'b1111111111111, iv, 1'b0}; vma = 1'b1; rw = 1'b1; end
            AD_INTL:  begin address = {13'b1111111111111, iv, 1'b1}; vma = 1'b1; rw = 1'b1; end
            default:  begin address = 16'hFFFF;             vma = 1'b0; rw = 1'b1; end
        endcase
    end

    // ----------------------------------
    // Data out mux
    // ----------------------------------
    always @* begin
        case (dout_ctrl)
            DO_MD_HI: data_out = md[15:8];
            DO_MD_LO: data_out = md[7:0];
            DO_ACCA:  data_out = acca;
            DO_ACCB:  data_out = accb;
            DO_IX_LO: data_out = xreg[7:0];
            DO_IX_HI: data_out = xreg[15:8];
            DO_CC:    data_out = cc;
            DO_PC_LO: data_out = pc[7:0];
            DO_PC_HI: data_out = pc[15:8];
            default:  data_out = 8'h00;
        endcase
    end

    // ----------------------------------
    // PC update
    // ----------------------------------
    reg [15:0] pc_off;
    reg [15:0] pc_base;
    always @* begin
        case (pc_ctrl)
            PC_ADD_EA: pc_off = {{8{ea[7]}}, ea[7:0]};
            PC_INC:    pc_off = 16'h0001;
            default:   pc_off = 16'h0000;
        endcase
        case (pc_ctrl)
            PC_RESET:   pc_base = 16'hFFFE;
            PC_LOAD_EA: pc_base = ea;
            PC_PULL_LO: pc_base = {pc[15:8], data_in};
            PC_PULL_HI: pc_base = {data_in,  pc[7:0]};
            default:    pc_base = pc;
        endcase
    end
    always @(negedge clk) begin
        if (~hold) pc <= pc_base + pc_off;
    end

    // ----------------------------------
    // EA update
    // ----------------------------------
    reg [15:0] ea_off;
    reg [15:0] ea_base;
    always @* begin
        case (ea_ctrl)
            EA_ADD_IX: ea_off = {8'h00, ea[7:0]};
            EA_INC:    ea_off = 16'h0001;
            default:   ea_off = 16'h0000;
        endcase
        case (ea_ctrl)
            EA_RESET:       ea_base = 16'h0000;
            EA_LOAD_ACCB:   ea_base = {8'h00, accb};
            EA_ADD_IX:      ea_base = xreg;
            EA_FETCH_FIRST: ea_base = {8'h00, data_in};
            EA_FETCH_NEXT:  ea_base = {ea[7:0], data_in};
            default:        ea_base = ea;
        endcase
    end
    always @(negedge clk) begin
        if (~hold) ea <= ea_base + ea_off;
    end

    // ----------------------------------
    // ACCA
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (acca_ctrl)
                ACCA_RESET:   acca <= 8'h00;
                ACCA_LOAD:    acca <= out_alu[7:0];
                ACCA_LOAD_HI: acca <= out_alu[15:8];
                ACCA_PULL:    acca <= data_in;
                default:      acca <= acca;
            endcase
        end
    end

    // ----------------------------------
    // ACCB
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (accb_ctrl)
                ACCB_RESET: accb <= 8'h00;
                ACCB_LOAD:  accb <= out_alu[7:0];
                ACCB_PULL:  accb <= data_in;
                default:    accb <= accb;
            endcase
        end
    end

    // ----------------------------------
    // X index
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (ix_ctrl)
                IX_RESET:   xreg <= 16'h0000;
                IX_LOAD:    xreg <= out_alu;
                IX_PULL_HI: xreg[15:8] <= data_in;
                IX_PULL_LO: xreg[7:0]  <= data_in;
                default:    xreg <= xreg;
            endcase
        end
    end

    // ----------------------------------
    // SP
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (sp_ctrl)
                SP_RESET: sp <= 16'h0000;
                SP_LOAD:  sp <= out_alu;
                default:  sp <= sp;
            endcase
        end
    end

    // ----------------------------------
    // MD
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (md_ctrl)
                MD_RESET:       md <= 16'h0000;
                MD_LOAD:        md <= out_alu;
                MD_FETCH_FIRST: md <= {8'h00, data_in};
                MD_FETCH_NEXT:  md <= {md[7:0], data_in};
                MD_SHIFTL:      md <= {md[14:0], 1'b0};
                default:        md <= md;
            endcase
        end
    end

    // ----------------------------------
    // CC
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (cc_ctrl)
                CC_RESET: cc <= 8'b11010000;  // I bit set: mask IRQs at reset (matches MC6800)
                CC_LOAD:  cc <= cc_out;
                CC_PULL:  cc <= data_in;
                default:  cc <= cc;
            endcase
        end
    end

    // ----------------------------------
    // IV
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (iv_ctrl)
                IV_RESET: iv <= 2'b11;
                IV_NMI:   iv <= 2'b10;
                IV_SWI:   iv <= 2'b01;
                IV_IRQ:   iv <= 2'b00;
                default:  iv <= iv;
            endcase
        end
    end

    // ----------------------------------
    // op fetch
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            case (op_ctrl)
                OP_RESET: op_code <= 8'b00000001;
                OP_FETCH: op_code <= data_in;
                default:  op_code <= op_code;
            endcase
        end
    end

    // ----------------------------------
    // Left mux
    // ----------------------------------
    always @* begin
        case (left_ctrl)
            LEFT_ACCA: left = {8'h00, acca};
            LEFT_ACCB: left = {8'h00, accb};
            LEFT_ACCD: left = {acca, accb};
            LEFT_IX:   left = xreg;
            LEFT_SP:   left = sp;
            default:   left = md;
        endcase
    end

    // ----------------------------------
    // Right mux
    // ----------------------------------
    always @* begin
        case (right_ctrl)
            RIGHT_ZERO: right = 16'h0000;
            RIGHT_ONE:  right = 16'h0001;
            RIGHT_ACCB: right = {8'h00, accb};
            default:    right = md;
        endcase
    end

    // ----------------------------------
    // ALU
    // ----------------------------------
    reg        carry_in;
    reg [7:0]  daa_reg;
    reg        valid_lo, valid_hi;
    always @* begin
        case (alu_ctrl)
            ALU_ADC, ALU_SBC, ALU_ROL8, ALU_ROR8: carry_in = cc[CBIT];
            default: carry_in = 1'b0;
        endcase

        valid_lo = (left[3:0] <= 4'd9);
        valid_hi = (left[7:4] <= 4'd9);

        // DAA correction
        if (cc[CBIT] == 1'b0) begin
            if (cc[HBIT] == 1'b1)
                daa_reg = valid_hi ? 8'h06 : 8'h66;
            else if (valid_lo)
                daa_reg = valid_hi ? 8'h00 : 8'h60;
            else
                daa_reg = (left[7:4] <= 4'd8) ? 8'h06 : 8'h66;
        end else begin
            if (cc[HBIT] == 1'b1)
                daa_reg = 8'h66;
            else
                daa_reg = valid_lo ? 8'h60 : 8'h66;
        end

        // Main ALU
        case (alu_ctrl)
            ALU_ADD8, ALU_INC, ALU_ADD16, ALU_INX, ALU_ADC:
                out_alu = left + right + {15'h0000, carry_in};
            ALU_SUB8, ALU_DEC, ALU_SUB16, ALU_DEX, ALU_SBC, ALU_CPX:
                out_alu = left - right - {15'h0000, carry_in};
            ALU_AND:  out_alu = left & right;
            ALU_ORA:  out_alu = left | right;
            ALU_EOR:  out_alu = left ^ right;
            ALU_LSL16, ALU_ASL8, ALU_ROL8: out_alu = {left[14:0], carry_in};
            ALU_LSR16, ALU_LSR8:           out_alu = {carry_in, left[15:1]};
            ALU_ROR8: out_alu = {8'h00, carry_in, left[7:1]};
            ALU_ASR8: out_alu = {8'h00, left[7], left[7:1]};
            ALU_NEG:  out_alu = right - left;
            ALU_COM:  out_alu = ~left;
            ALU_CLR, ALU_LD8, ALU_LD16: out_alu = right;
            ALU_ST8, ALU_ST16, ALU_TST: out_alu = left;
            ALU_DAA:  out_alu = left + {8'h00, daa_reg};
            ALU_TPA:  out_alu = {8'h00, cc};
            default:  out_alu = left;
        endcase

        // Carry
        case (alu_ctrl)
            ALU_ADD8, ALU_ADC:
                cc_out[CBIT] = (left[7] & right[7]) | (left[7] & ~out_alu[7]) | (right[7] & ~out_alu[7]);
            ALU_SUB8, ALU_SBC:
                cc_out[CBIT] = (~left[7] & right[7]) | (~left[7] & out_alu[7]) | (right[7] & out_alu[7]);
            ALU_ADD16:
                cc_out[CBIT] = (left[15] & right[15]) | (left[15] & ~out_alu[15]) | (right[15] & ~out_alu[15]);
            ALU_SUB16:
                cc_out[CBIT] = (~left[15] & right[15]) | (~left[15] & out_alu[15]) | (right[15] & out_alu[15]);
            ALU_ROR8, ALU_LSR16, ALU_LSR8, ALU_ASR8: cc_out[CBIT] = left[0];
            ALU_ROL8, ALU_ASL8: cc_out[CBIT] = left[7];
            ALU_LSL16: cc_out[CBIT] = left[15];
            ALU_COM:   cc_out[CBIT] = 1'b1;
            ALU_NEG, ALU_CLR: cc_out[CBIT] = |out_alu[7:0];
            ALU_DAA:   cc_out[CBIT] = (daa_reg[7:4] == 4'b0110);
            ALU_SEC:   cc_out[CBIT] = 1'b1;
            ALU_CLC:   cc_out[CBIT] = 1'b0;
            ALU_TST:   cc_out[CBIT] = 1'b0;     // TST clears carry per 6800 spec
            ALU_TAP:   cc_out[CBIT] = left[CBIT];
            default:   cc_out[CBIT] = cc[CBIT];
        endcase

        // Zero
        case (alu_ctrl)
            ALU_ADD8, ALU_SUB8, ALU_ADC, ALU_SBC,
            ALU_AND, ALU_ORA, ALU_EOR,
            ALU_INC, ALU_DEC, ALU_NEG, ALU_COM, ALU_CLR,
            ALU_ROL8, ALU_ROR8, ALU_ASR8, ALU_ASL8, ALU_LSR8,
            ALU_LD8, ALU_ST8, ALU_TST:
                cc_out[ZBIT] = ~|out_alu[7:0];
            ALU_ADD16, ALU_SUB16, ALU_LSL16, ALU_LSR16,
            ALU_INX, ALU_DEX, ALU_LD16, ALU_ST16, ALU_CPX:
                cc_out[ZBIT] = ~|out_alu;
            ALU_TAP: cc_out[ZBIT] = left[ZBIT];
            default: cc_out[ZBIT] = cc[ZBIT];
        endcase

        // Negative
        case (alu_ctrl)
            ALU_ADD8, ALU_SUB8, ALU_ADC, ALU_SBC,
            ALU_AND, ALU_ORA, ALU_EOR,
            ALU_ROL8, ALU_ROR8, ALU_ASR8, ALU_ASL8, ALU_LSR8,
            ALU_INC, ALU_DEC, ALU_NEG, ALU_COM, ALU_CLR,
            ALU_LD8, ALU_ST8, ALU_TST:
                cc_out[NBIT] = out_alu[7];
            ALU_ADD16, ALU_SUB16, ALU_LSL16, ALU_LSR16,
            ALU_LD16, ALU_ST16, ALU_CPX:
                cc_out[NBIT] = out_alu[15];
            ALU_TAP: cc_out[NBIT] = left[NBIT];
            default: cc_out[NBIT] = cc[NBIT];
        endcase

        // I bit
        case (alu_ctrl)
            ALU_SEI: cc_out[IBIT] = 1'b1;
            ALU_CLI: cc_out[IBIT] = 1'b0;
            ALU_TAP: cc_out[IBIT] = left[IBIT];
            default: cc_out[IBIT] = cc[IBIT];
        endcase

        // H bit
        case (alu_ctrl)
            ALU_ADD8, ALU_ADC:
                cc_out[HBIT] = (left[3] & right[3]) | (right[3] & ~out_alu[3]) | (left[3] & ~out_alu[3]);
            ALU_TAP: cc_out[HBIT] = left[HBIT];
            default: cc_out[HBIT] = cc[HBIT];
        endcase

        // V bit
        case (alu_ctrl)
            ALU_ADD8, ALU_ADC:
                cc_out[VBIT] = ( left[7] &  right[7] & ~out_alu[7]) |
                               (~left[7] & ~right[7] &  out_alu[7]);
            ALU_SUB8, ALU_SBC:
                cc_out[VBIT] = ( left[7] & ~right[7] & ~out_alu[7]) |
                               (~left[7] &  right[7] &  out_alu[7]);
            ALU_ADD16:
                cc_out[VBIT] = ( left[15] &  right[15] & ~out_alu[15]) |
                               (~left[15] & ~right[15] &  out_alu[15]);
            ALU_SUB16, ALU_CPX:
                cc_out[VBIT] = ( left[15] & ~right[15] & ~out_alu[15]) |
                               (~left[15] &  right[15] &  out_alu[15]);
            ALU_INC:
                cc_out[VBIT] = (~left[7] & left[6] & left[5] & left[4] &
                                 left[3] & left[2] & left[1] & left[0]);
            ALU_DEC, ALU_NEG:
                cc_out[VBIT] = ( left[7] & ~left[6] & ~left[5] & ~left[4] &
                                ~left[3] & ~left[2] & ~left[1] & ~left[0]);
            ALU_ASR8:  cc_out[VBIT] = left[0] ^ left[7];
            ALU_LSR8, ALU_LSR16: cc_out[VBIT] = left[0];
            ALU_ROR8:  cc_out[VBIT] = left[0] ^ cc[CBIT];
            ALU_LSL16: cc_out[VBIT] = left[15] ^ left[14];
            ALU_ROL8, ALU_ASL8: cc_out[VBIT] = left[7] ^ left[6];
            ALU_TAP:   cc_out[VBIT] = left[VBIT];
            ALU_AND, ALU_ORA, ALU_EOR, ALU_COM,
            ALU_ST8, ALU_ST16, ALU_LD8, ALU_LD16, ALU_CLV,
            ALU_TST:
                       cc_out[VBIT] = 1'b0;
            ALU_SEV:   cc_out[VBIT] = 1'b1;
            default:   cc_out[VBIT] = cc[VBIT];
        endcase

        // X and S
        case (alu_ctrl)
            ALU_TAP: begin
                cc_out[XBIT] = cc[XBIT] & left[XBIT];
                cc_out[SBIT] = left[SBIT];
            end
            default: begin
                cc_out[XBIT] = cc[XBIT] & left[XBIT];
                cc_out[SBIT] = cc[SBIT];
            end
        endcase
    end

    // ----------------------------------
    // NMI edge detect / ack
    // ----------------------------------
    always @(negedge clk) begin
        if (~hold) begin
            if (rst) nmi_req <= 1'b0;
            else if ( nmi & ~nmi_ack) nmi_req <= 1'b1;
            else if (~nmi &  nmi_ack) nmi_req <= 1'b0;
        end
    end

    always @(negedge clk) begin
        if (~hold) begin
            case (nmi_ctrl)
                NMI_SET:   nmi_ack <= 1'b1;
                NMI_RESET: nmi_ack <= 1'b0;
                default:   nmi_ack <= nmi_ack;
            endcase
        end
    end

    // ----------------------------------
    // State sequencer
    // ----------------------------------
    // helper for MUL bit selection
    reg mul_bit;
    always @* begin
        // Defaults (most states override these)
        op_ctrl    = OP_LATCH;
        acca_ctrl  = ACCA_LATCH;
        accb_ctrl  = ACCB_LATCH;
        ix_ctrl    = IX_LATCH;
        sp_ctrl    = SP_LATCH;
        pc_ctrl    = PC_LATCH;
        ea_ctrl    = EA_LATCH;
        md_ctrl    = MD_LATCH;
        iv_ctrl    = IV_LATCH;
        nmi_ctrl   = NMI_LATCH;
        left_ctrl  = LEFT_ACCA;
        right_ctrl = RIGHT_ZERO;
        alu_ctrl   = ALU_NOP;
        cc_ctrl    = CC_LATCH;
        addr_ctrl  = AD_IDLE;
        dout_ctrl  = DO_MD_LO;
        next_state = ST_FETCH;
        mul_bit    = 1'b0;

        case (state)
        ST_RESET: begin
            op_ctrl=OP_RESET; acca_ctrl=ACCA_RESET; accb_ctrl=ACCB_RESET;
            ix_ctrl=IX_RESET; sp_ctrl=SP_RESET; pc_ctrl=PC_RESET;
            ea_ctrl=EA_RESET; md_ctrl=MD_RESET; iv_ctrl=IV_RESET; nmi_ctrl=NMI_RESET;
            cc_ctrl=CC_RESET;
            next_state = ST_VECT_HI;
        end

        ST_VECT_HI: begin
            pc_ctrl    = PC_PULL_HI;
            addr_ctrl  = AD_INTH;
            dout_ctrl  = DO_PC_HI;
            next_state = ST_VECT_LO;
        end

        ST_VECT_LO: begin
            pc_ctrl    = PC_PULL_LO;
            addr_ctrl  = AD_INTL;
            dout_ctrl  = DO_PC_LO;
            next_state = ST_FETCH;
        end

        ST_FETCH: begin
            op_ctrl    = OP_FETCH;
            ea_ctrl    = EA_RESET;
            addr_ctrl  = AD_FETCH;
            dout_ctrl  = DO_MD_LO;

            // ALU dispatch on previous opcode
            case (op_code[7:4])
                4'b0000, 4'b0001, 4'b0010, 4'b0011,
                4'b0100, 4'b0101, 4'b0110, 4'b0111: begin
                    // idle ALU
                end

                4'b1000, 4'b1001, 4'b1010, 4'b1011: begin
                    case (op_code[3:0])
                        4'b0000: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SUB8;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b0001: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SUB8;  cc_ctrl=CC_LOAD;                          end
                        4'b0010: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SBC;   cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b0011: begin left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SUB16; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD_HI; accb_ctrl=ACCB_LOAD; end
                        4'b0100: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_AND;   cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b0101: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_AND;   cc_ctrl=CC_LOAD;                          end
                        4'b0110: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_LD8;   cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b0111: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ST8;   cc_ctrl=CC_LOAD;                          end
                        4'b1000: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_EOR;   cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b1001: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ADC;   cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b1010: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ORA;   cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b1011: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ADD8;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD;    end
                        4'b1100: begin left_ctrl=LEFT_IX;   right_ctrl=RIGHT_MD; alu_ctrl=ALU_CPX;   cc_ctrl=CC_LOAD;                          end
                        4'b1101: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_NOP;                                              end
                        4'b1110: begin left_ctrl=LEFT_SP;   right_ctrl=RIGHT_MD; alu_ctrl=ALU_LD16;  cc_ctrl=CC_LOAD; sp_ctrl=SP_LOAD;        end
                        4'b1111: begin left_ctrl=LEFT_SP;   right_ctrl=RIGHT_MD; alu_ctrl=ALU_ST16;  cc_ctrl=CC_LOAD;                          end
                        default: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_MD; alu_ctrl=ALU_NOP;                                              end
                    endcase
                end

                4'b1100, 4'b1101, 4'b1110, 4'b1111: begin
                    case (op_code[3:0])
                        4'b0000: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SUB8;  cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b0001: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SUB8;  cc_ctrl=CC_LOAD;                          end
                        4'b0010: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_SBC;   cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b0011: begin left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ADD16; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD_HI; accb_ctrl=ACCB_LOAD; end
                        4'b0100: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_AND;   cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b0101: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_AND;   cc_ctrl=CC_LOAD;                          end
                        4'b0110: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_LD8;   cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b0111: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ST8;   cc_ctrl=CC_LOAD;                          end
                        4'b1000: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_EOR;   cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b1001: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ADC;   cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b1010: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ORA;   cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b1011: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ADD8;  cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD;    end
                        4'b1100: begin left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_LD16;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD_HI; accb_ctrl=ACCB_LOAD; end
                        4'b1101: begin left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ST16;  cc_ctrl=CC_LOAD;                          end
                        4'b1110: begin left_ctrl=LEFT_IX;   right_ctrl=RIGHT_MD; alu_ctrl=ALU_LD16;  cc_ctrl=CC_LOAD; ix_ctrl=IX_LOAD;        end
                        4'b1111: begin left_ctrl=LEFT_IX;   right_ctrl=RIGHT_MD; alu_ctrl=ALU_ST16;  cc_ctrl=CC_LOAD;                          end
                        default: begin left_ctrl=LEFT_ACCB; right_ctrl=RIGHT_MD; alu_ctrl=ALU_NOP;                                              end
                    endcase
                end

                default: begin
                    left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_NOP;
                end
            endcase

            // Interrupt / halt arbitration
            if (halt) begin
                pc_ctrl    = PC_LATCH;
                nmi_ctrl   = NMI_LATCH;
                next_state = ST_HALT;
            end else if (nmi_req & ~nmi_ack) begin
                pc_ctrl    = PC_LATCH;
                nmi_ctrl   = NMI_SET;
                next_state = ST_INT_PCL;
            end else begin
                if (~nmi_req & nmi_ack) nmi_ctrl = NMI_RESET;
                else                    nmi_ctrl = NMI_LATCH;

                if (irq & ~cc[IBIT]) begin
                    pc_ctrl    = PC_LATCH;
                    next_state = ST_INT_PCL;
                end else begin
                    pc_ctrl    = PC_INC;
                    next_state = ST_DECODE;
                end
            end
        end

        ST_DECODE: begin
            ea_ctrl    = EA_FETCH_FIRST;
            addr_ctrl  = AD_FETCH;
            dout_ctrl  = DO_MD_LO;

            case (op_code[7:4])
            4'b0000: begin
                md_ctrl = MD_FETCH_FIRST;
                case (op_code[3:0])
                    4'b0001: begin alu_ctrl=ALU_NOP; end
                    4'b0100: begin left_ctrl=LEFT_ACCD; alu_ctrl=ALU_LSR16; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD_HI; accb_ctrl=ACCB_LOAD; end
                    4'b0101: begin left_ctrl=LEFT_ACCD; alu_ctrl=ALU_LSL16; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD_HI; accb_ctrl=ACCB_LOAD; end
                    4'b0110: begin alu_ctrl=ALU_TAP;   cc_ctrl=CC_LOAD; end
                    4'b0111: begin alu_ctrl=ALU_TPA;   acca_ctrl=ACCA_LOAD; end
                    4'b1000: begin left_ctrl=LEFT_IX; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_INX; cc_ctrl=CC_LOAD; ix_ctrl=IX_LOAD; end
                    4'b1001: begin left_ctrl=LEFT_IX; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_DEX; cc_ctrl=CC_LOAD; ix_ctrl=IX_LOAD; end
                    4'b1010: begin alu_ctrl=ALU_CLV; cc_ctrl=CC_LOAD; end
                    4'b1011: begin alu_ctrl=ALU_SEV; cc_ctrl=CC_LOAD; end
                    4'b1100: begin alu_ctrl=ALU_CLC; cc_ctrl=CC_LOAD; end
                    4'b1101: begin alu_ctrl=ALU_SEC; cc_ctrl=CC_LOAD; end
                    4'b1110: begin alu_ctrl=ALU_CLI; cc_ctrl=CC_LOAD; end
                    4'b1111: begin alu_ctrl=ALU_SEI; cc_ctrl=CC_LOAD; end
                    default: begin alu_ctrl=ALU_NOP; end
                endcase
                next_state = ST_FETCH;
            end

            4'b0001: begin
                md_ctrl  = MD_FETCH_FIRST;
                left_ctrl = LEFT_ACCA; right_ctrl = RIGHT_ACCB;
                case (op_code[3:0])
                    4'b0000: begin alu_ctrl=ALU_SUB8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b0001: begin alu_ctrl=ALU_SUB8; cc_ctrl=CC_LOAD;                       end
                    4'b0110: begin alu_ctrl=ALU_ST8;  cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b0111: begin alu_ctrl=ALU_LD8;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1001: begin alu_ctrl=ALU_DAA;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1011: begin alu_ctrl=ALU_ADD8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    default: begin alu_ctrl=ALU_NOP;                                        end
                endcase
                next_state = ST_FETCH;
            end

            4'b0010: begin
                md_ctrl = MD_FETCH_FIRST;
                pc_ctrl = PC_INC;
                case (op_code[3:0])
                    4'b0000: next_state = ST_BRANCH;
                    4'b0001: next_state = ST_FETCH;
                    4'b0010: next_state = (~(cc[CBIT]|cc[ZBIT])) ? ST_BRANCH : ST_FETCH;
                    4'b0011: next_state = ( (cc[CBIT]|cc[ZBIT])) ? ST_BRANCH : ST_FETCH;
                    4'b0100: next_state = (~cc[CBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b0101: next_state = ( cc[CBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b0110: next_state = (~cc[ZBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b0111: next_state = ( cc[ZBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b1000: next_state = (~cc[VBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b1001: next_state = ( cc[VBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b1010: next_state = (~cc[NBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b1011: next_state = ( cc[NBIT]) ? ST_BRANCH : ST_FETCH;
                    4'b1100: next_state = (~(cc[NBIT]^cc[VBIT])) ? ST_BRANCH : ST_FETCH;
                    4'b1101: next_state = ( (cc[NBIT]^cc[VBIT])) ? ST_BRANCH : ST_FETCH;
                    4'b1110: next_state = (~(cc[ZBIT]|(cc[NBIT]^cc[VBIT]))) ? ST_BRANCH : ST_FETCH;
                    4'b1111: next_state = ( (cc[ZBIT]|(cc[NBIT]^cc[VBIT]))) ? ST_BRANCH : ST_FETCH;
                    default: next_state = ST_FETCH;
                endcase
            end

            4'b0011: begin
                md_ctrl = MD_FETCH_FIRST;
                case (op_code[3:0])
                    4'b0000: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; ix_ctrl=IX_LOAD; next_state=ST_FETCH; end
                    4'b0001: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD; next_state=ST_FETCH; end
                    4'b0010: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD; next_state=ST_PULA;  end
                    4'b0011: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD; next_state=ST_PULB;  end
                    4'b0100: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD; next_state=ST_FETCH; end
                    4'b0101: begin left_ctrl=LEFT_IX; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD; next_state=ST_FETCH; end
                    4'b0110: begin left_ctrl=LEFT_SP; alu_ctrl=ALU_NOP; next_state=ST_PSHA; end
                    4'b0111: begin left_ctrl=LEFT_SP; alu_ctrl=ALU_NOP; next_state=ST_PSHB; end
                    4'b1000: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD; next_state=ST_PULX_HI; end
                    4'b1001: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD; next_state=ST_RTS_HI;  end
                    4'b1010: begin left_ctrl=LEFT_IX; right_ctrl=RIGHT_ACCB; alu_ctrl=ALU_ADD16; ix_ctrl=IX_LOAD; next_state=ST_FETCH; end
                    4'b1011: begin left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD; next_state=ST_RTI_CC; end
                    4'b1100: begin left_ctrl=LEFT_SP; alu_ctrl=ALU_NOP; next_state=ST_PSHX_LO; end
                    4'b1101: begin left_ctrl=LEFT_ACCA; right_ctrl=RIGHT_ACCB; alu_ctrl=ALU_ADD16; next_state=ST_MUL; end
                    4'b1110: begin left_ctrl=LEFT_SP; alu_ctrl=ALU_NOP; next_state=ST_INT_PCL; end
                    4'b1111: begin left_ctrl=LEFT_SP; alu_ctrl=ALU_NOP; next_state=ST_INT_PCL; end
                    default: begin left_ctrl=LEFT_SP; alu_ctrl=ALU_NOP; next_state=ST_FETCH; end
                endcase
            end

            4'b0100: begin
                md_ctrl = MD_FETCH_FIRST;
                left_ctrl = LEFT_ACCA;
                case (op_code[3:0])
                    4'b0000: begin alu_ctrl=ALU_NEG;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b0011: begin alu_ctrl=ALU_COM;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b0100: begin alu_ctrl=ALU_LSR8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b0110: begin alu_ctrl=ALU_ROR8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b0111: begin alu_ctrl=ALU_ASR8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1000: begin alu_ctrl=ALU_ASL8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1001: begin alu_ctrl=ALU_ROL8; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1010: begin right_ctrl=RIGHT_ONE; alu_ctrl=ALU_DEC; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1100: begin right_ctrl=RIGHT_ONE; alu_ctrl=ALU_INC; cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    4'b1101: begin alu_ctrl=ALU_TST;  cc_ctrl=CC_LOAD; end
                    4'b1110: begin alu_ctrl=ALU_NOP; end
                    4'b1111: begin alu_ctrl=ALU_CLR;  cc_ctrl=CC_LOAD; acca_ctrl=ACCA_LOAD; end
                    default: begin alu_ctrl=ALU_NOP; end
                endcase
                next_state = ST_FETCH;
            end

            4'b0101: begin
                md_ctrl = MD_FETCH_FIRST;
                left_ctrl = LEFT_ACCB;
                case (op_code[3:0])
                    4'b0000: begin alu_ctrl=ALU_NEG;  cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b0011: begin alu_ctrl=ALU_COM;  cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b0100: begin alu_ctrl=ALU_LSR8; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b0110: begin alu_ctrl=ALU_ROR8; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b0111: begin alu_ctrl=ALU_ASR8; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b1000: begin alu_ctrl=ALU_ASL8; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b1001: begin alu_ctrl=ALU_ROL8; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b1010: begin right_ctrl=RIGHT_ONE; alu_ctrl=ALU_DEC; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b1100: begin right_ctrl=RIGHT_ONE; alu_ctrl=ALU_INC; cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    4'b1101: begin alu_ctrl=ALU_TST;  cc_ctrl=CC_LOAD; end
                    4'b1110: begin alu_ctrl=ALU_NOP; end
                    4'b1111: begin alu_ctrl=ALU_CLR;  cc_ctrl=CC_LOAD; accb_ctrl=ACCB_LOAD; end
                    default: begin alu_ctrl=ALU_NOP; end
                endcase
                next_state = ST_FETCH;
            end

            4'b0110: begin md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC; next_state=ST_INDEXED; end
            4'b0111: begin md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC; next_state=ST_EXTENDED; end

            4'b1000: begin
                md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC;
                case (op_code[3:0])
                    4'b0011, 4'b1100, 4'b1110: next_state=ST_IMM16;
                    4'b1101: next_state=ST_BSR;
                    default: next_state=ST_FETCH;
                endcase
            end

            4'b1001: begin
                pc_ctrl=PC_INC;
                case (op_code[3:0])
                    4'b0111: begin left_ctrl=LEFT_ACCA; alu_ctrl=ALU_ST8;  md_ctrl=MD_LOAD; next_state=ST_WRITE8;  end
                    4'b1111: begin left_ctrl=LEFT_SP;   alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD; next_state=ST_WRITE16; end
                    4'b1101: begin alu_ctrl=ALU_NOP; md_ctrl=MD_FETCH_FIRST; next_state=ST_JSR; end
                    default: begin alu_ctrl=ALU_NOP; md_ctrl=MD_FETCH_FIRST; next_state=ST_READ8; end
                endcase
            end

            4'b1010: begin md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC; next_state=ST_INDEXED;  end
            4'b1011: begin md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC; next_state=ST_EXTENDED; end

            4'b1100: begin
                md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC;
                case (op_code[3:0])
                    4'b0011, 4'b1100, 4'b1110: next_state=ST_IMM16;
                    default: next_state=ST_FETCH;
                endcase
            end

            4'b1101: begin
                pc_ctrl=PC_INC;
                case (op_code[3:0])
                    4'b0111: begin left_ctrl=LEFT_ACCB; alu_ctrl=ALU_ST8;  md_ctrl=MD_LOAD; next_state=ST_WRITE8;  end
                    4'b1101: begin left_ctrl=LEFT_ACCD; alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD; next_state=ST_WRITE16; end
                    4'b1111: begin left_ctrl=LEFT_IX;   alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD; next_state=ST_WRITE16; end
                    default: begin alu_ctrl=ALU_NOP; md_ctrl=MD_FETCH_FIRST; next_state=ST_READ8; end
                endcase
            end

            4'b1110: begin md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC; next_state=ST_INDEXED;  end
            4'b1111: begin md_ctrl=MD_FETCH_FIRST; pc_ctrl=PC_INC; next_state=ST_EXTENDED; end

            default: begin md_ctrl=MD_FETCH_FIRST; next_state=ST_FETCH; end
            endcase
        end

        ST_IMM16: begin
            pc_ctrl    = PC_INC;
            md_ctrl    = MD_FETCH_NEXT;
            addr_ctrl  = AD_FETCH;
            dout_ctrl  = DO_MD_LO;
            next_state = ST_FETCH;
        end

        ST_INDEXED: begin
            ea_ctrl    = EA_ADD_IX;
            addr_ctrl  = AD_IDLE;
            dout_ctrl  = DO_MD_LO;
            case (op_code[7:4])
                4'b0110: begin
                    case (op_code[3:0])
                        4'b1011: next_state = ST_FETCH;
                        4'b1110: next_state = ST_JMP;
                        default: next_state = ST_READ8;
                    endcase
                end
                4'b1010: begin
                    case (op_code[3:0])
                        4'b0111: begin left_ctrl=LEFT_ACCA; alu_ctrl=ALU_ST8;  md_ctrl=MD_LOAD;  next_state=ST_WRITE8;  end
                        4'b1101: begin alu_ctrl=ALU_NOP; next_state=ST_JSR; end
                        4'b1111: begin left_ctrl=LEFT_SP;   alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;  next_state=ST_WRITE16; end
                        default: begin alu_ctrl=ALU_NOP; next_state=ST_READ8; end
                    endcase
                end
                4'b1110: begin
                    case (op_code[3:0])
                        4'b0111: begin left_ctrl=LEFT_ACCB; alu_ctrl=ALU_ST8;  md_ctrl=MD_LOAD;  next_state=ST_WRITE8;  end
                        4'b1101: begin left_ctrl=LEFT_ACCD; alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;  next_state=ST_WRITE16; end
                        4'b1111: begin left_ctrl=LEFT_IX;   alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;  next_state=ST_WRITE16; end
                        default: begin alu_ctrl=ALU_NOP; next_state=ST_READ8; end
                    endcase
                end
                default: next_state = ST_FETCH;
            endcase
        end

        ST_EXTENDED: begin
            pc_ctrl    = PC_INC;
            ea_ctrl    = EA_FETCH_NEXT;
            addr_ctrl  = AD_FETCH;
            dout_ctrl  = DO_MD_LO;
            case (op_code[7:4])
                4'b0111: begin
                    case (op_code[3:0])
                        4'b1011: next_state = ST_FETCH;
                        4'b1110: next_state = ST_JMP;
                        default: next_state = ST_READ8;
                    endcase
                end
                4'b1011: begin
                    case (op_code[3:0])
                        4'b0111: begin left_ctrl=LEFT_ACCA; alu_ctrl=ALU_ST8;  md_ctrl=MD_LOAD;  next_state=ST_WRITE8;  end
                        4'b1101: begin alu_ctrl=ALU_NOP; next_state=ST_JSR; end
                        4'b1111: begin left_ctrl=LEFT_SP;   alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;  next_state=ST_WRITE16; end
                        default: begin alu_ctrl=ALU_NOP; next_state=ST_READ8; end
                    endcase
                end
                4'b1111: begin
                    case (op_code[3:0])
                        4'b0111: begin left_ctrl=LEFT_ACCB; alu_ctrl=ALU_ST8;  md_ctrl=MD_LOAD;  next_state=ST_WRITE8;  end
                        4'b1101: begin left_ctrl=LEFT_ACCD; alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;  next_state=ST_WRITE16; end
                        4'b1111: begin left_ctrl=LEFT_IX;   alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;  next_state=ST_WRITE16; end
                        default: begin alu_ctrl=ALU_NOP; next_state=ST_READ8; end
                    endcase
                end
                default: next_state = ST_FETCH;
            endcase
        end

        ST_READ8: begin
            addr_ctrl = AD_READ;
            dout_ctrl = DO_MD_LO;
            md_ctrl   = MD_FETCH_FIRST;
            case (op_code[7:4])
                4'b0110, 4'b0111: next_state = ST_EXECUTE;
                4'b1001, 4'b1010, 4'b1011: begin
                    case (op_code[3:0])
                        4'b0011, 4'b1110, 4'b1100: begin ea_ctrl = EA_INC; next_state = ST_READ16; end
                        default: next_state = ST_FETCH;
                    endcase
                end
                4'b1101, 4'b1110, 4'b1111: begin
                    case (op_code[3:0])
                        4'b0011, 4'b1100, 4'b1110: begin ea_ctrl = EA_INC; next_state = ST_READ16; end
                        default: next_state = ST_EXECUTE;
                    endcase
                end
                default: next_state = ST_FETCH;
            endcase
        end

        ST_READ16: begin
            md_ctrl    = MD_FETCH_NEXT;
            addr_ctrl  = AD_READ;
            dout_ctrl  = DO_MD_LO;
            next_state = ST_FETCH;
        end

        ST_WRITE16: begin
            ea_ctrl    = EA_INC;
            addr_ctrl  = AD_WRITE;
            dout_ctrl  = DO_MD_HI;
            next_state = ST_WRITE8;
        end

        ST_WRITE8: begin
            addr_ctrl  = AD_WRITE;
            dout_ctrl  = DO_MD_LO;
            next_state = ST_FETCH;
        end

        ST_JMP: begin
            pc_ctrl    = PC_LOAD_EA;
            addr_ctrl  = AD_IDLE;
            dout_ctrl  = DO_MD_LO;
            next_state = ST_FETCH;
        end

        ST_JSR: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_PC_LO;
            next_state = ST_JSR1;
        end

        ST_JSR1: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_PC_HI;
            next_state = ST_JMP;
        end

        ST_BRANCH: begin
            pc_ctrl    = PC_ADD_EA;
            addr_ctrl  = AD_IDLE;
            dout_ctrl  = DO_MD_LO;
            next_state = ST_FETCH;
        end

        ST_BSR: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_PC_LO;
            next_state = ST_BSR1;
        end

        ST_BSR1: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_PC_HI;
            next_state = ST_BRANCH;
        end

        ST_RTS_HI: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            pc_ctrl=PC_PULL_HI;
            addr_ctrl=AD_PULL; dout_ctrl=DO_PC_HI;
            next_state = ST_RTS_LO;
        end

        ST_RTS_LO: begin
            pc_ctrl=PC_PULL_LO;
            addr_ctrl=AD_PULL; dout_ctrl=DO_PC_LO;
            next_state = ST_FETCH;
        end

        // MUL chain
        ST_MUL: begin
            left_ctrl=LEFT_ACCA; alu_ctrl=ALU_ST16; md_ctrl=MD_LOAD;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            next_state = ST_MULEA;
        end
        ST_MULEA: begin
            ea_ctrl=EA_LOAD_ACCB;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            next_state = ST_MULD;
        end
        ST_MULD: begin
            alu_ctrl=ALU_LD8; acca_ctrl=ACCA_LOAD_HI; accb_ctrl=ACCB_LOAD;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            next_state = ST_MUL0;
        end
        ST_MUL0, ST_MUL1, ST_MUL2, ST_MUL3,
        ST_MUL4, ST_MUL5, ST_MUL6, ST_MUL7: begin
            left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_ADD16;
            md_ctrl=MD_SHIFTL;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            case (state)
                ST_MUL0: mul_bit = ea[0];
                ST_MUL1: mul_bit = ea[1];
                ST_MUL2: mul_bit = ea[2];
                ST_MUL3: mul_bit = ea[3];
                ST_MUL4: mul_bit = ea[4];
                ST_MUL5: mul_bit = ea[5];
                ST_MUL6: mul_bit = ea[6];
                ST_MUL7: mul_bit = ea[7];
                default: mul_bit = 1'b0;
            endcase
            if (mul_bit) begin
                cc_ctrl   = CC_LOAD;
                acca_ctrl = ACCA_LOAD_HI;
                accb_ctrl = ACCB_LOAD;
            end
            case (state)
                ST_MUL0: next_state = ST_MUL1;
                ST_MUL1: next_state = ST_MUL2;
                ST_MUL2: next_state = ST_MUL3;
                ST_MUL3: next_state = ST_MUL4;
                ST_MUL4: next_state = ST_MUL5;
                ST_MUL5: next_state = ST_MUL6;
                ST_MUL6: next_state = ST_MUL7;
                ST_MUL7: next_state = ST_FETCH;
                default: next_state = ST_FETCH;
            endcase
        end

        ST_EXECUTE: begin
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            case (op_code[7:4])
                4'b0110, 4'b0111: begin
                    left_ctrl = LEFT_MD;
                    case (op_code[3:0])
                        4'b0000: begin alu_ctrl=ALU_NEG;  cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b0011: begin alu_ctrl=ALU_COM;  cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b0100: begin alu_ctrl=ALU_LSR8; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b0110: begin alu_ctrl=ALU_ROR8; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b0111: begin alu_ctrl=ALU_ASR8; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b1000: begin alu_ctrl=ALU_ASL8; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b1001: begin alu_ctrl=ALU_ROL8; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b1010: begin right_ctrl=RIGHT_ONE; alu_ctrl=ALU_DEC; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b1011: begin alu_ctrl=ALU_NOP; next_state=ST_FETCH; end
                        4'b1100: begin right_ctrl=RIGHT_ONE; alu_ctrl=ALU_INC; cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        4'b1101: begin alu_ctrl=ALU_TST;  cc_ctrl=CC_LOAD; next_state=ST_FETCH; end
                        4'b1110: begin alu_ctrl=ALU_NOP; next_state=ST_FETCH; end
                        4'b1111: begin alu_ctrl=ALU_CLR;  cc_ctrl=CC_LOAD; md_ctrl=MD_LOAD; next_state=ST_WRITE8; end
                        default: begin alu_ctrl=ALU_NOP; next_state=ST_FETCH; end
                    endcase
                end
                default: begin
                    left_ctrl=LEFT_ACCD; right_ctrl=RIGHT_MD; alu_ctrl=ALU_NOP;
                    next_state = ST_FETCH;
                end
            endcase
        end

        // Stack pushes / pulls
        ST_PSHA: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_ACCA;
            next_state = ST_FETCH;
        end
        ST_PULA: begin
            acca_ctrl=ACCA_PULL;
            addr_ctrl=AD_PULL; dout_ctrl=DO_ACCA;
            next_state = ST_FETCH;
        end
        ST_PSHB: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_ACCB;
            next_state = ST_FETCH;
        end
        ST_PULB: begin
            accb_ctrl=ACCB_PULL;
            addr_ctrl=AD_PULL; dout_ctrl=DO_ACCB;
            next_state = ST_FETCH;
        end
        ST_PSHX_LO: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_IX_LO;
            next_state = ST_PSHX_HI;
        end
        ST_PSHX_HI: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_IX_HI;
            next_state = ST_FETCH;
        end
        ST_PULX_HI: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            ix_ctrl=IX_PULL_HI;
            addr_ctrl=AD_PULL; dout_ctrl=DO_IX_HI;
            next_state = ST_PULX_LO;
        end
        ST_PULX_LO: begin
            ix_ctrl=IX_PULL_LO;
            addr_ctrl=AD_PULL; dout_ctrl=DO_IX_LO;
            next_state = ST_FETCH;
        end

        // RTI
        ST_RTI: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_CC;
            next_state = ST_RTI_CC;
        end
        ST_RTI_CC: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            cc_ctrl=CC_PULL;
            addr_ctrl=AD_PULL; dout_ctrl=DO_CC;
            next_state = ST_RTI_ACCB;
        end
        ST_RTI_ACCB: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            accb_ctrl=ACCB_PULL;
            addr_ctrl=AD_PULL; dout_ctrl=DO_ACCB;
            next_state = ST_RTI_ACCA;
        end
        ST_RTI_ACCA: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            acca_ctrl=ACCA_PULL;
            addr_ctrl=AD_PULL; dout_ctrl=DO_ACCA;
            next_state = ST_RTI_IXH;
        end
        ST_RTI_IXH: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            ix_ctrl=IX_PULL_HI;
            addr_ctrl=AD_PULL; dout_ctrl=DO_IX_HI;
            next_state = ST_RTI_IXL;
        end
        ST_RTI_IXL: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            ix_ctrl=IX_PULL_LO;
            addr_ctrl=AD_PULL; dout_ctrl=DO_IX_LO;
            next_state = ST_RTI_PCH;
        end
        ST_RTI_PCH: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_ADD16; sp_ctrl=SP_LOAD;
            pc_ctrl=PC_PULL_HI;
            addr_ctrl=AD_PULL; dout_ctrl=DO_PC_HI;
            next_state = ST_RTI_PCL;
        end
        ST_RTI_PCL: begin
            pc_ctrl=PC_PULL_LO;
            addr_ctrl=AD_PULL; dout_ctrl=DO_PC_LO;
            next_state = ST_FETCH;
        end

        // Interrupt push sequence
        ST_INT_PCL: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_PC_LO;
            next_state = ST_INT_PCH;
        end
        ST_INT_PCH: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_PC_HI;
            next_state = ST_INT_IXL;
        end
        ST_INT_IXL: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_IX_LO;
            next_state = ST_INT_IXH;
        end
        ST_INT_IXH: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_IX_HI;
            next_state = ST_INT_ACCA;
        end
        ST_INT_ACCA: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_ACCA;
            next_state = ST_INT_ACCB;
        end
        ST_INT_ACCB: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_ACCB;
            next_state = ST_INT_CC;
        end
        ST_INT_CC: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_SUB16; sp_ctrl=SP_LOAD;
            addr_ctrl=AD_PUSH; dout_ctrl=DO_CC;
            if (nmi_req) begin
                iv_ctrl    = IV_NMI;
                next_state = ST_VECT_HI;
            end else if (irq & ~cc[IBIT]) begin
                iv_ctrl    = IV_IRQ;
                next_state = ST_INT_MASK;
            end else begin
                case (op_code)
                    8'b00111110: begin iv_ctrl=IV_LATCH; next_state=ST_INT_WAI; end
                    8'b00111111: begin iv_ctrl=IV_SWI;   next_state=ST_VECT_HI; end
                    default:     begin iv_ctrl=IV_LATCH; next_state=ST_RTI;     end
                endcase
            end
        end

        ST_INT_WAI: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ONE; alu_ctrl=ALU_CLI; cc_ctrl=CC_LOAD;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_CC;
            if (nmi_req & ~nmi_ack) begin
                iv_ctrl    = IV_NMI;
                nmi_ctrl   = NMI_SET;
                next_state = ST_VECT_HI;
            end else begin
                if (~nmi_req & nmi_ack) nmi_ctrl = NMI_RESET;
                else                    nmi_ctrl = NMI_LATCH;
                if (irq & ~cc[IBIT]) begin
                    iv_ctrl    = IV_IRQ;
                    next_state = ST_INT_MASK;
                end else begin
                    iv_ctrl    = IV_LATCH;
                    next_state = ST_INT_WAI;
                end
            end
        end

        ST_INT_MASK: begin
            left_ctrl=LEFT_SP; right_ctrl=RIGHT_ZERO; alu_ctrl=ALU_SEI; cc_ctrl=CC_LOAD;
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            next_state = ST_VECT_HI;
        end

        ST_HALT: begin
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            next_state = halt ? ST_HALT : ST_FETCH;
        end

        default: begin
            addr_ctrl=AD_IDLE; dout_ctrl=DO_MD_LO;
            next_state = ST_ERROR;
        end
        endcase
    end

    // ----------------------------------
    // State register
    // ----------------------------------
    always @(negedge clk) begin
        if (rst)        state <= ST_RESET;
        else if (~hold) state <= next_state;
    end

endmodule

`default_nettype wire
