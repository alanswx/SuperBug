//===========================================================================--
//
//  S Y N T H E Z I A B L E    CPU68   C O R E
//
//  www.OpenCores.Org - December 2002
//  This core adheres to the GNU public license  
//
// File name      : cpu68.vhd
//
// Purpose        : Implements a 6800 compatible CPU core with some
//                  additional instructions found in the 6801
//                  
// Dependencies   : ieee.Std_Logic_1164
//                  ieee.std_logic_unsigned
//
// Author         : John E. Kent      
//
//===========================================================================----
//
// Revision History:
//
// Date:          Revision         Author
// 22 Sep 2002    0.1              John Kent
//
// 30 Oct 2002    0.2              John Kent
// made NMI edge triggered
//
// 30 Oct 2002    0.3              John Kent
// more corrections to NMI
// added wai_wait_state to prevent stack overflow on wai.
//
//  1 Nov 2002    0.4              John Kent
// removed WAI states and integrated WAI with the interrupt service routine
// replace Data out (do) and Data in (di) register with a single Memory Data (md) reg.
// Added Multiply instruction states.
// run ALU and CC out of CPU module for timing measurements.
// 
//  3 Nov 2002    0.5              John Kent
// Memory Data Register was not loaded on Store instructions
// SEV and CLV were not defined in the ALU
// Overflow Flag on NEG was incorrect
//
// 16th Feb 2003  0.6              John Kent
// Rearranged the execution cycle for dual operand instructions
// so that occurs during the following fetch cycle.
// This allows the reduction of one clock cycle from dual operand
// instruction. Note that this also necessitated re-arranging the
// program counter so that it is no longer incremented in the ALU.
// The effective address has also been re-arranged to include a 
// separate added. The STD (store accd) now sets the condition codes.
//
// 28th Jun 2003 0.7               John Kent
// Added Hold and Halt signals. Hold is used to steal cycles from the
// CPU or add wait states. Halt puts the CPU in the inactive state
// and is only honoured in the fetch cycle. Both signals are active high.
//
// 9th Jan 2004 0.8						John Kent
// Clear instruction did an alu_ld8 rather than an alu_clr, so
// the carry bit was not cleared correctly.
// This error was picked up by Michael Hassenfratz.
//

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
    test_cc
);
    input             clk;
    input             rst;
    output reg        rw;
    output reg        vma;
    output reg [15:0] address;
    input [7:0]       data_in;
    output reg [7:0]  data_out;
    input             hold;
    input             halt;
    input             irq;
    input             nmi;
    output reg [15:0] test_alu;
    output reg [7:0]  test_cc;
    
    
    parameter         SBIT = 7;
    parameter         XBIT = 6;
    parameter         HBIT = 5;
    parameter         IBIT = 4;
    parameter         NBIT = 3;
    parameter         ZBIT = 2;
    parameter         VBIT = 1;
    parameter         CBIT = 0;
    
    parameter [5:0]   state_type_reset_state = 0,
                      state_type_fetch_state = 1,
                      state_type_decode_state = 2,
                      state_type_extended_state = 3,
                      state_type_indexed_state = 4,
                      state_type_read8_state = 5,
                      state_type_read16_state = 6,
                      state_type_immediate16_state = 7,
                      state_type_write8_state = 8,
                      state_type_write16_state = 9,
                      state_type_execute_state = 10,
                      state_type_halt_state = 11,
                      state_type_error_state = 12,
                      state_type_mul_state = 13,
                      state_type_mulea_state = 14,
                      state_type_muld_state = 15,
                      state_type_mul0_state = 16,
                      state_type_mul1_state = 17,
                      state_type_mul2_state = 18,
                      state_type_mul3_state = 19,
                      state_type_mul4_state = 20,
                      state_type_mul5_state = 21,
                      state_type_mul6_state = 22,
                      state_type_mul7_state = 23,
                      state_type_jmp_state = 24,
                      state_type_jsr_state = 25,
                      state_type_jsr1_state = 26,
                      state_type_branch_state = 27,
                      state_type_bsr_state = 28,
                      state_type_bsr1_state = 29,
                      state_type_rts_hi_state = 30,
                      state_type_rts_lo_state = 31,
                      state_type_int_pcl_state = 32,
                      state_type_int_pch_state = 33,
                      state_type_int_ixl_state = 34,
                      state_type_int_ixh_state = 35,
                      state_type_int_cc_state = 36,
                      state_type_int_acca_state = 37,
                      state_type_int_accb_state = 38,
                      state_type_int_wai_state = 39,
                      state_type_int_mask_state = 40,
                      state_type_rti_state = 41,
                      state_type_rti_cc_state = 42,
                      state_type_rti_acca_state = 43,
                      state_type_rti_accb_state = 44,
                      state_type_rti_ixl_state = 45,
                      state_type_rti_ixh_state = 46,
                      state_type_rti_pcl_state = 47,
                      state_type_rti_pch_state = 48,
                      state_type_pula_state = 49,
                      state_type_psha_state = 50,
                      state_type_pulb_state = 51,
                      state_type_pshb_state = 52,
                      state_type_pulx_lo_state = 53,
                      state_type_pulx_hi_state = 54,
                      state_type_pshx_lo_state = 55,
                      state_type_pshx_hi_state = 56,
                      state_type_vect_lo_state = 57,
                      state_type_vect_hi_state = 58;
    parameter [2:0]   addr_type_idle_ad = 0,
                      addr_type_fetch_ad = 1,
                      addr_type_read_ad = 2,
                      addr_type_write_ad = 3,
                      addr_type_push_ad = 4,
                      addr_type_pull_ad = 5,
                      addr_type_int_hi_ad = 6,
                      addr_type_int_lo_ad = 7;
    parameter [3:0]   dout_type_md_lo_dout = 0,
                      dout_type_md_hi_dout = 1,
                      dout_type_acca_dout = 2,
                      dout_type_accb_dout = 3,
                      dout_type_ix_lo_dout = 4,
                      dout_type_ix_hi_dout = 5,
                      dout_type_cc_dout = 6,
                      dout_type_pc_lo_dout = 7,
                      dout_type_pc_hi_dout = 8;
    parameter [1:0]   op_type_reset_op = 0,
                      op_type_fetch_op = 1,
                      op_type_latch_op = 2;
    parameter [2:0]   acca_type_reset_acca = 0,
                      acca_type_load_acca = 1,
                      acca_type_load_hi_acca = 2,
                      acca_type_pull_acca = 3,
                      acca_type_latch_acca = 4;
    parameter [1:0]   accb_type_reset_accb = 0,
                      accb_type_load_accb = 1,
                      accb_type_pull_accb = 2,
                      accb_type_latch_accb = 3;
    parameter [1:0]   cc_type_reset_cc = 0,
                      cc_type_load_cc = 1,
                      cc_type_pull_cc = 2,
                      cc_type_latch_cc = 3;
    parameter [2:0]   ix_type_reset_ix = 0,
                      ix_type_load_ix = 1,
                      ix_type_pull_lo_ix = 2,
                      ix_type_pull_hi_ix = 3,
                      ix_type_latch_ix = 4;
    parameter [1:0]   sp_type_reset_sp = 0,
                      sp_type_latch_sp = 1,
                      sp_type_load_sp = 2;
    parameter [2:0]   pc_type_reset_pc = 0,
                      pc_type_latch_pc = 1,
                      pc_type_load_ea_pc = 2,
                      pc_type_add_ea_pc = 3,
                      pc_type_pull_lo_pc = 4,
                      pc_type_pull_hi_pc = 5,
                      pc_type_inc_pc = 6;
    parameter [2:0]   md_type_reset_md = 0,
                      md_type_latch_md = 1,
                      md_type_load_md = 2,
                      md_type_fetch_first_md = 3,
                      md_type_fetch_next_md = 4,
                      md_type_shiftl_md = 5;
    parameter [2:0]   ea_type_reset_ea = 0,
                      ea_type_latch_ea = 1,
                      ea_type_add_ix_ea = 2,
                      ea_type_load_accb_ea = 3,
                      ea_type_inc_ea = 4,
                      ea_type_fetch_first_ea = 5,
                      ea_type_fetch_next_ea = 6;
    parameter [2:0]   iv_type_reset_iv = 0,
                      iv_type_latch_iv = 1,
                      iv_type_swi_iv = 2,
                      iv_type_nmi_iv = 3,
                      iv_type_irq_iv = 4;
    parameter [1:0]   nmi_type_reset_nmi = 0,
                      nmi_type_set_nmi = 1,
                      nmi_type_latch_nmi = 2;
    parameter [2:0]   left_type_acca_left = 0,
                      left_type_accb_left = 1,
                      left_type_accd_left = 2,
                      left_type_md_left = 3,
                      left_type_ix_left = 4,
                      left_type_sp_left = 5;
    parameter [1:0]   right_type_md_right = 0,
                      right_type_zero_right = 1,
                      right_type_plus_one_right = 2,
                      right_type_accb_right = 3;
    parameter [5:0]   alu_type_alu_add8 = 0,
                      alu_type_alu_sub8 = 1,
                      alu_type_alu_add16 = 2,
                      alu_type_alu_sub16 = 3,
                      alu_type_alu_adc = 4,
                      alu_type_alu_sbc = 5,
                      alu_type_alu_and = 6,
                      alu_type_alu_ora = 7,
                      alu_type_alu_eor = 8,
                      alu_type_alu_tst = 9,
                      alu_type_alu_inc = 10,
                      alu_type_alu_dec = 11,
                      alu_type_alu_clr = 12,
                      alu_type_alu_neg = 13,
                      alu_type_alu_com = 14,
                      alu_type_alu_inx = 15,
                      alu_type_alu_dex = 16,
                      alu_type_alu_cpx = 17,
                      alu_type_alu_lsr16 = 18,
                      alu_type_alu_lsl16 = 19,
                      alu_type_alu_ror8 = 20,
                      alu_type_alu_rol8 = 21,
                      alu_type_alu_asr8 = 22,
                      alu_type_alu_asl8 = 23,
                      alu_type_alu_lsr8 = 24,
                      alu_type_alu_sei = 25,
                      alu_type_alu_cli = 26,
                      alu_type_alu_sec = 27,
                      alu_type_alu_clc = 28,
                      alu_type_alu_sev = 29,
                      alu_type_alu_clv = 30,
                      alu_type_alu_tpa = 31,
                      alu_type_alu_tap = 32,
                      alu_type_alu_ld8 = 33,
                      alu_type_alu_st8 = 34,
                      alu_type_alu_ld16 = 35,
                      alu_type_alu_st16 = 36,
                      alu_type_alu_nop = 37,
                      alu_type_alu_daa = 38;
    
    reg [7:0]         op_code;
    reg [7:0]         acca;
    reg [7:0]         accb;
    reg [7:0]         cc;
    reg [7:0]         cc_out;
    reg [15:0]        xreg;
    reg [15:0]        sp;
    reg [15:0]        ea;
    reg [15:0]        pc;
    reg [15:0]        md;
    reg [15:0]        left;
    reg [15:0]        right;
    reg [15:0]        out_alu;
    reg [1:0]         iv;
    reg               nmi_req;
    reg               nmi_ack;
    
    reg [5:0]         state;
    reg [5:0]         next_state;
    reg [2:0]         pc_ctrl;
    reg [2:0]         ea_ctrl;
    reg [1:0]         op_ctrl;
    reg [2:0]         md_ctrl;
    reg [2:0]         acca_ctrl;
    reg [1:0]         accb_ctrl;
    reg [2:0]         ix_ctrl;
    reg [1:0]         cc_ctrl;
    reg [1:0]         sp_ctrl;
    reg [2:0]         iv_ctrl;
    reg [2:0]         left_ctrl;
    reg [1:0]         right_ctrl;
    reg [5:0]         alu_ctrl;
    reg [2:0]         addr_ctrl;
    reg [3:0]         dout_ctrl;
    reg [1:0]         nmi_ctrl;
    
    //--------------------------------
    //
    // Address bus multiplexer
    //
    //--------------------------------
    
    
    always @(clk or addr_ctrl or pc or ea or sp or iv)
    begin: addr_mux
        case (addr_ctrl)
            addr_type_idle_ad :
                begin
                    address <= 16'b1111111111111111;
                    vma <= 1'b0;
                    rw <= 1'b1;
                end
            addr_type_fetch_ad :
                begin
                    address <= pc;
                    vma <= 1'b1;
                    rw <= 1'b1;
                end
            addr_type_read_ad :
                begin
                    address <= ea;
                    vma <= 1'b1;
                    rw <= 1'b1;
                end
            addr_type_write_ad :
                begin
                    address <= ea;
                    vma <= 1'b1;
                    rw <= 1'b0;
                end
            addr_type_push_ad :
                begin
                    address <= sp;
                    vma <= 1'b1;
                    rw <= 1'b0;
                end
            addr_type_pull_ad :
                begin
                    address <= sp;
                    vma <= 1'b1;
                    rw <= 1'b1;
                end
            addr_type_int_hi_ad :
                begin
                    address <= {13'b1111111111111, iv, 1'b0};
                    vma <= 1'b1;
                    rw <= 1'b1;
                end
            addr_type_int_lo_ad :
                begin
                    address <= {13'b1111111111111, iv, 1'b1};
                    vma <= 1'b1;
                    rw <= 1'b1;
                end
            default :
                begin
                    address <= 16'b1111111111111111;
                    vma <= 1'b0;
                    rw <= 1'b1;
                end
        endcase
    end
    
    //------------------------------
    //
    // Data Bus output
    //
    //------------------------------
    
    always @(clk or dout_ctrl or md or acca or accb or xreg or pc or cc)
    begin: dout_mux
        case (dout_ctrl)
            dout_type_md_hi_dout :		// alu output
                data_out <= md[15:8];
            dout_type_md_lo_dout :
                data_out <= md[7:0];
            dout_type_acca_dout :		// accumulator a
                data_out <= acca;
            dout_type_accb_dout :		// accumulator b
                data_out <= accb;
            dout_type_ix_lo_dout :		// index reg
                data_out <= xreg[7:0];
            dout_type_ix_hi_dout :		// index reg
                data_out <= xreg[15:8];
            dout_type_cc_dout :		// condition codes
                data_out <= cc;
            dout_type_pc_lo_dout :		// low order pc
                data_out <= pc[7:0];
            dout_type_pc_hi_dout :		// high order pc
                data_out <= pc[15:8];
            default :
                data_out <= 8'b00000000;
        endcase
    end
    
    //--------------------------------
    //
    // Program Counter Control
    //
    //--------------------------------
    
    
    always @(negedge clk or pc_ctrl or pc or out_alu or data_in or ea or hold)
    begin: pc_mux
        reg [15:0]        tempof;
        reg [15:0]        temppc;
        case (pc_ctrl)
            pc_type_add_ea_pc :
                if (ea[7] == 1'b0)
                    tempof = {8'b00000000, ea[7:0]};
                else
                    tempof = {8'b11111111, ea[7:0]};
            pc_type_inc_pc :
                tempof = 16'b0000000000000001;
            default :
                tempof = 16'b0000000000000000;
        endcase
        
        case (pc_ctrl)
            pc_type_reset_pc :
                temppc = 16'b1111111111111110;
            pc_type_load_ea_pc :
                temppc = ea;
            pc_type_pull_lo_pc :
                begin
                    temppc[7:0] = data_in;
                    temppc[15:8] = pc[15:8];
                end
            pc_type_pull_hi_pc :
                begin
                    temppc[7:0] = pc[7:0];
                    temppc[15:8] = data_in;
                end
            default :
                temppc = pc;
        endcase
        
        
        begin
            if (hold == 1'b1)
                pc <= pc;
            else
                pc <= temppc + tempof;
        end
    end
    
    //--------------------------------
    //
    // Effective Address  Control
    //
    //--------------------------------
    
    
    always @(negedge clk or ea_ctrl or ea or out_alu or data_in or accb or xreg or hold)
    begin: ea_mux
        reg [15:0]        tempind;
        reg [15:0]        tempea;
        case (ea_ctrl)
            ea_type_add_ix_ea :
                tempind = {8'b00000000, ea[7:0]};
            ea_type_inc_ea :
                tempind = 16'b0000000000000001;
            default :
                tempind = 16'b0000000000000000;
        endcase
        
        case (ea_ctrl)
            ea_type_reset_ea :
                tempea = 16'b0000000000000000;
            ea_type_load_accb_ea :
                tempea = {8'b00000000, accb[7:0]};
            ea_type_add_ix_ea :
                tempea = xreg;
            ea_type_fetch_first_ea :
                begin
                    tempea[7:0] = data_in;
                    tempea[15:8] = 8'b00000000;
                end
            ea_type_fetch_next_ea :
                begin
                    tempea[7:0] = data_in;
                    tempea[15:8] = ea[7:0];
                end
            default :
                tempea = ea;
        endcase
        
        
        begin
            if (hold == 1'b1)
                ea <= ea;
            else
                ea <= tempea + tempind;
        end
    end
    
    //------------------------------
    //
    // Accumulator A
    //
    //------------------------------
    
    always @(negedge clk or acca_ctrl or out_alu or acca or data_in or hold)
    begin: acca_mux
        
        begin
            if (hold == 1'b1)
                acca <= acca;
            else
                case (acca_ctrl)
                    acca_type_reset_acca :
                        acca <= 8'b00000000;
                    acca_type_load_acca :
                        acca <= out_alu[7:0];
                    acca_type_load_hi_acca :
                        acca <= out_alu[15:8];
                    acca_type_pull_acca :
                        acca <= data_in;
                    default :
                        //	 when latch_acca =>
                        acca <= acca;
                endcase
        end
    end
    
    //------------------------------
    //
    // Accumulator B
    //
    //------------------------------
    
    always @(negedge clk or accb_ctrl or out_alu or accb or data_in or hold)
    begin: accb_mux
        
        begin
            if (hold == 1'b1)
                accb <= accb;
            else
                case (accb_ctrl)
                    accb_type_reset_accb :
                        accb <= 8'b00000000;
                    accb_type_load_accb :
                        accb <= out_alu[7:0];
                    accb_type_pull_accb :
                        accb <= data_in;
                    default :
                        //	 when latch_accb =>
                        accb <= accb;
                endcase
        end
    end
    
    //------------------------------
    //
    // X Index register
    //
    //------------------------------
    
    always @(negedge clk or ix_ctrl or out_alu or xreg or data_in or hold)
    begin: ix_mux
        
        begin
            if (hold == 1'b1)
                xreg <= xreg;
            else
                case (ix_ctrl)
                    ix_type_reset_ix :
                        xreg <= 16'b0000000000000000;
                    ix_type_load_ix :
                        xreg <= out_alu[15:0];
                    ix_type_pull_hi_ix :
                        xreg[15:8] <= data_in;
                    ix_type_pull_lo_ix :
                        xreg[7:0] <= data_in;
                    default :
                        //	 when latch_ix =>
                        xreg <= xreg;
                endcase
        end
    end
    
    //------------------------------
    //
    // stack pointer
    //
    //------------------------------
    
    always @(negedge clk or sp_ctrl or out_alu or hold)
    begin: sp_mux
        
        begin
            if (hold == 1'b1)
                sp <= sp;
            else
                case (sp_ctrl)
                    sp_type_reset_sp :
                        sp <= 16'b0000000000000000;
                    sp_type_load_sp :
                        sp <= out_alu[15:0];
                    default :
                        //	 when latch_sp =>
                        sp <= sp;
                endcase
        end
    end
    
    //------------------------------
    //
    // Memory Data
    //
    //------------------------------
    
    always @(negedge clk or md_ctrl or out_alu or data_in or md or hold)
    begin: md_mux
        
        begin
            if (hold == 1'b1)
                md <= md;
            else
                case (md_ctrl)
                    md_type_reset_md :
                        md <= 16'b0000000000000000;
                    md_type_load_md :
                        md <= out_alu[15:0];
                    md_type_fetch_first_md :
                        begin
                            md[15:8] <= 8'b00000000;
                            md[7:0] <= data_in;
                        end
                    md_type_fetch_next_md :
                        begin
                            md[15:8] <= md[7:0];
                            md[7:0] <= data_in;
                        end
                    md_type_shiftl_md :
                        begin
                            md[15:1] <= md[14:0];
                            md[0] <= 1'b0;
                        end
                    default :
                        //	 when latch_md =>
                        md <= md;
                endcase
        end
    end
    
    //--------------------------------
    //
    // Condition Codes
    //
    //--------------------------------
    
    
    always @(negedge clk or cc_ctrl or cc_out or cc or data_in or hold)
    begin: cc_mux
        
        begin
            if (hold == 1'b1)
                cc <= cc;
            else
                case (cc_ctrl)
                    cc_type_reset_cc :
                        cc <= 8'b11000000;
                    cc_type_load_cc :
                        cc <= cc_out;
                    cc_type_pull_cc :
                        cc <= data_in;
                    default :
                        //  when latch_cc =>
                        cc <= cc;
                endcase
        end
    end
    
    //--------------------------------
    //
    // interrupt vector
    //
    //--------------------------------
    
    
    always @(negedge clk or iv_ctrl or hold)
    begin: iv_mux
        
        begin
            if (hold == 1'b1)
                iv <= iv;
            else
                case (iv_ctrl)
                    iv_type_reset_iv :
                        iv <= 2'b11;
                    iv_type_nmi_iv :
                        iv <= 2'b10;
                    iv_type_swi_iv :
                        iv <= 2'b01;
                    iv_type_irq_iv :
                        iv <= 2'b00;
                    default :
                        iv <= iv;
                endcase
        end
    end
    
    //--------------------------------
    //
    // op code fetch
    //
    //--------------------------------
    
    
    always @(negedge clk or data_in or op_ctrl or op_code or hold)
    begin: op_fetch
        
        begin
            if (hold == 1'b1)
                op_code <= op_code;
            else
                case (op_ctrl)
                    op_type_reset_op :
                        op_code <= 8'b00000001;		// nop
                    op_type_fetch_op :
                        op_code <= data_in;
                    default :
                        //	 when latch_op =>
                        op_code <= op_code;
                endcase
        end
    end
    
    //--------------------------------
    //
    // Left Mux
    //
    //--------------------------------
    
    
    always @(left_ctrl or acca or accb or xreg or sp or pc or ea or md)
    begin: left_mux
        case (left_ctrl)
            left_type_acca_left :
                begin
                    left[15:8] <= 8'b00000000;
                    left[7:0] <= acca;
                end
            left_type_accb_left :
                begin
                    left[15:8] <= 8'b00000000;
                    left[7:0] <= accb;
                end
            left_type_accd_left :
                begin
                    left[15:8] <= acca;
                    left[7:0] <= accb;
                end
            left_type_ix_left :
                left <= xreg;
            left_type_sp_left :
                left <= sp;
            default :
                //	 when md_left =>
                left <= md;
        endcase
    end
    //--------------------------------
    //
    // Right Mux
    //
    //--------------------------------
    
    
    always @(right_ctrl or data_in or md or accb or ea)
    begin: right_mux
        case (right_ctrl)
            right_type_zero_right :
                right <= 16'b0000000000000000;
            right_type_plus_one_right :
                right <= 16'b0000000000000001;
            right_type_accb_right :
                right <= {8'b00000000, accb};
            default :
                //	 when md_right =>
                right <= md;
        endcase
    end
    
    //--------------------------------
    //
    // Arithmetic Logic Unit
    //
    //--------------------------------
    
    
    always @(alu_ctrl or cc or left or right or out_alu or cc_out)
    begin: mux_alu
        reg               valid_lo;
        reg               valid_hi;
        reg               carry_in;
        reg [7:0]         daa_reg;
        
        case (alu_ctrl)
            alu_type_alu_adc, alu_type_alu_sbc, alu_type_alu_rol8, alu_type_alu_ror8 :
                carry_in = cc[CBIT];
            default :
                carry_in = 1'b0;
        endcase
        
        valid_lo = left[3:0] <= 9;
        valid_hi = left[7:4] <= 9;
        
        if (cc[CBIT] == 1'b0)
        begin
            if (cc[HBIT] == 1'b1)
            begin
                if (valid_hi)
                    daa_reg = 8'b00000110;
                else
                    daa_reg = 8'b01100110;
            end
            else
                if (valid_lo)
                begin
                    if (valid_hi)
                        daa_reg = 8'b00000000;
                    else
                        daa_reg = 8'b01100000;
                end
                else
                    if (left[7:4] <= 8)
                        daa_reg = 8'b00000110;
                    else
                        daa_reg = 8'b01100110;
        end
        else
            if (cc[HBIT] == 1'b1)
                daa_reg = 8'b01100110;
            else
                if (valid_lo)
                    daa_reg = 8'b01100000;
                else
                    daa_reg = 8'b01100110;
        
        case (alu_ctrl)
            alu_type_alu_add8, alu_type_alu_inc, alu_type_alu_add16, alu_type_alu_inx, alu_type_alu_adc :
                out_alu <= left + right + ({15'b000000000000000, carry_in});
            alu_type_alu_sub8, alu_type_alu_dec, alu_type_alu_sub16, alu_type_alu_dex, alu_type_alu_sbc, alu_type_alu_cpx :
                out_alu <= left - right - ({15'b000000000000000, carry_in});
            alu_type_alu_and :
                out_alu <= left & right;		// and/bit
            alu_type_alu_ora :
                out_alu <= left | right;		// or
            alu_type_alu_eor :
                out_alu <= left ^ right;		// eor/xor
            alu_type_alu_lsl16, alu_type_alu_asl8, alu_type_alu_rol8 :
                out_alu <= {left[14:0], carry_in};		// rol8/asl8/lsl16
            alu_type_alu_lsr16, alu_type_alu_lsr8 :
                out_alu <= {carry_in, left[15:1]};		// lsr
            alu_type_alu_ror8 :
                out_alu <= {8'b00000000, carry_in, left[7:1]};		// ror
            alu_type_alu_asr8 :
                out_alu <= {8'b00000000, left[7], left[7:1]};		// asr
            alu_type_alu_neg :
                out_alu <= right - left;		// neg (right=0)
            alu_type_alu_com :
                out_alu <= (~left);
            alu_type_alu_clr, alu_type_alu_ld8, alu_type_alu_ld16 :
                out_alu <= right;		// clr, ld
            alu_type_alu_st8, alu_type_alu_st16 :
                out_alu <= left;
            alu_type_alu_daa :
                out_alu <= left + ({8'b00000000, daa_reg});
            alu_type_alu_tpa :
                out_alu <= {8'b00000000, cc};
            default :
                out_alu <= left;		// nop
        endcase
        
        //
        // carry bit
        //
        case (alu_ctrl)
            alu_type_alu_add8, alu_type_alu_adc :
                cc_out[CBIT] <= (left[7] & right[7]) | (left[7] & (~out_alu[7])) | (right[7] & (~out_alu[7]));
            alu_type_alu_sub8, alu_type_alu_sbc :
                cc_out[CBIT] <= (((~left[7])) & right[7]) | (((~left[7])) & out_alu[7]) | (right[7] & out_alu[7]);
            alu_type_alu_add16 :
                cc_out[CBIT] <= (left[15] & right[15]) | (left[15] & (~out_alu[15])) | (right[15] & (~out_alu[15]));
            alu_type_alu_sub16 :
                cc_out[CBIT] <= (((~left[15])) & right[15]) | (((~left[15])) & out_alu[15]) | (right[15] & out_alu[15]);
            alu_type_alu_ror8, alu_type_alu_lsr16, alu_type_alu_lsr8, alu_type_alu_asr8 :
                cc_out[CBIT] <= left[0];
            alu_type_alu_rol8, alu_type_alu_asl8 :
                cc_out[CBIT] <= left[7];
            alu_type_alu_lsl16 :
                cc_out[CBIT] <= left[15];
            alu_type_alu_com :
                cc_out[CBIT] <= 1'b1;
            alu_type_alu_neg, alu_type_alu_clr :
                cc_out[CBIT] <= out_alu[7] | out_alu[6] | out_alu[5] | out_alu[4] | out_alu[3] | out_alu[2] | out_alu[1] | out_alu[0];
            alu_type_alu_daa :
                if (daa_reg[7:4] == 4'b0110)
                    cc_out[CBIT] <= 1'b1;
                else
                    cc_out[CBIT] <= 1'b0;
            alu_type_alu_sec :
                cc_out[CBIT] <= 1'b1;
            alu_type_alu_clc :
                cc_out[CBIT] <= 1'b0;
            alu_type_alu_tap :
                cc_out[CBIT] <= left[CBIT];
            default :		// carry is not affected by cpx
                cc_out[CBIT] <= cc[CBIT];
        endcase
        //
        // Zero flag
        //
        case (alu_ctrl)
            alu_type_alu_add8, alu_type_alu_sub8, alu_type_alu_adc, alu_type_alu_sbc, alu_type_alu_and, alu_type_alu_ora, alu_type_alu_eor, alu_type_alu_inc, alu_type_alu_dec, alu_type_alu_neg, alu_type_alu_com, alu_type_alu_clr, alu_type_alu_rol8, alu_type_alu_ror8, alu_type_alu_asr8, alu_type_alu_asl8, alu_type_alu_lsr8, alu_type_alu_ld8, alu_type_alu_st8 :
                cc_out[ZBIT] <= (~(out_alu[7] | out_alu[6] | out_alu[5] | out_alu[4] | out_alu[3] | out_alu[2] | out_alu[1] | out_alu[0]));
            alu_type_alu_add16, alu_type_alu_sub16, alu_type_alu_lsl16, alu_type_alu_lsr16, alu_type_alu_inx, alu_type_alu_dex, alu_type_alu_ld16, alu_type_alu_st16, alu_type_alu_cpx :
                cc_out[ZBIT] <= (~(out_alu[15] | out_alu[14] | out_alu[13] | out_alu[12] | out_alu[11] | out_alu[10] | out_alu[9] | out_alu[8] | out_alu[7] | out_alu[6] | out_alu[5] | out_alu[4] | out_alu[3] | out_alu[2] | out_alu[1] | out_alu[0]));
            alu_type_alu_tap :
                cc_out[ZBIT] <= left[ZBIT];
            default :
                cc_out[ZBIT] <= cc[ZBIT];
        endcase
        
        //
        // negative flag
        //
        case (alu_ctrl)
            alu_type_alu_add8, alu_type_alu_sub8, alu_type_alu_adc, alu_type_alu_sbc, alu_type_alu_and, alu_type_alu_ora, alu_type_alu_eor, alu_type_alu_rol8, alu_type_alu_ror8, alu_type_alu_asr8, alu_type_alu_asl8, alu_type_alu_lsr8, alu_type_alu_inc, alu_type_alu_dec, alu_type_alu_neg, alu_type_alu_com, alu_type_alu_clr, alu_type_alu_ld8, alu_type_alu_st8 :
                cc_out[NBIT] <= out_alu[7];
            alu_type_alu_add16, alu_type_alu_sub16, alu_type_alu_lsl16, alu_type_alu_lsr16, alu_type_alu_ld16, alu_type_alu_st16, alu_type_alu_cpx :
                cc_out[NBIT] <= out_alu[15];
            alu_type_alu_tap :
                cc_out[NBIT] <= left[NBIT];
            default :
                cc_out[NBIT] <= cc[NBIT];
        endcase
        
        //
        // Interrupt mask flag
        //
        case (alu_ctrl)
            alu_type_alu_sei :
                cc_out[IBIT] <= 1'b1;		// set interrupt mask
            alu_type_alu_cli :
                cc_out[IBIT] <= 1'b0;		// clear interrupt mask
            alu_type_alu_tap :
                cc_out[IBIT] <= left[IBIT];
            default :
                cc_out[IBIT] <= cc[IBIT];		// interrupt mask
        endcase
        
        //
        // Half Carry flag
        //
        case (alu_ctrl)
            alu_type_alu_add8, alu_type_alu_adc :
                cc_out[HBIT] <= (left[3] & right[3]) | (right[3] & (~out_alu[3])) | (left[3] & (~out_alu[3]));
            alu_type_alu_tap :
                cc_out[HBIT] <= left[HBIT];
            default :
                cc_out[HBIT] <= cc[HBIT];
        endcase
        
        //
        // Overflow flag
        //
        case (alu_ctrl)
            alu_type_alu_add8, alu_type_alu_adc :
                cc_out[VBIT] <= (left[7] & right[7] & ((~out_alu[7]))) | (((~left[7])) & ((~right[7])) & out_alu[7]);
            alu_type_alu_sub8, alu_type_alu_sbc :
                cc_out[VBIT] <= (left[7] & ((~right[7])) & ((~out_alu[7]))) | (((~left[7])) & right[7] & out_alu[7]);
            alu_type_alu_add16 :
                cc_out[VBIT] <= (left[15] & right[15] & ((~out_alu[15]))) | (((~left[15])) & ((~right[15])) & out_alu[15]);
            alu_type_alu_sub16, alu_type_alu_cpx :
                cc_out[VBIT] <= (left[15] & ((~right[15])) & ((~out_alu[15]))) | (((~left[15])) & right[15] & out_alu[15]);
            alu_type_alu_inc :
                cc_out[VBIT] <= (((~left[7])) & left[6] & left[5] & left[4] & left[3] & left[2] & left[1] & left[0]);
            alu_type_alu_dec, alu_type_alu_neg :
                cc_out[VBIT] <= (left[7] & ((~left[6])) & ((~left[5])) & ((~left[4])) & ((~left[3])) & ((~left[2])) & ((~left[1])) & ((~left[0])));
            alu_type_alu_asr8 :
                cc_out[VBIT] <= left[0] ^ left[7];
            alu_type_alu_lsr8, alu_type_alu_lsr16 :
                cc_out[VBIT] <= left[0];
            alu_type_alu_ror8 :
                cc_out[VBIT] <= left[0] ^ cc[CBIT];
            alu_type_alu_lsl16 :
                cc_out[VBIT] <= left[15] ^ left[14];
            alu_type_alu_rol8, alu_type_alu_asl8 :
                cc_out[VBIT] <= left[7] ^ left[6];
            alu_type_alu_tap :
                cc_out[VBIT] <= left[VBIT];
            alu_type_alu_and, alu_type_alu_ora, alu_type_alu_eor, alu_type_alu_com, alu_type_alu_st8, alu_type_alu_st16, alu_type_alu_ld8, alu_type_alu_ld16, alu_type_alu_clv :
                cc_out[VBIT] <= 1'b0;
            alu_type_alu_sev :
                cc_out[VBIT] <= 1'b1;
            default :
                cc_out[VBIT] <= cc[VBIT];
        endcase
        
        case (alu_ctrl)
            alu_type_alu_tap :
                begin
                    cc_out[XBIT] <= cc[XBIT] & left[XBIT];
                    cc_out[SBIT] <= left[SBIT];
                end
            default :
                begin
                    cc_out[XBIT] <= cc[XBIT] & left[XBIT];
                    cc_out[SBIT] <= cc[SBIT];
                end
        endcase
        
        test_alu <= out_alu;
        test_cc <= cc_out;
    end
    
    //----------------------------------
    //
    // Detect Edge of NMI interrupt
    //
    //----------------------------------
    
    
    always @(negedge clk or rst or nmi or nmi_ack)
    begin: nmi_handler
        
        begin
            if (hold == 1'b1)
                nmi_req <= nmi_req;
            else
                if (rst == 1'b1)
                    nmi_req <= 1'b0;
                else
                    if ((nmi == 1'b1) & (nmi_ack == 1'b0))
                        nmi_req <= 1'b1;
                    else
                        if ((nmi == 1'b0) & (nmi_ack == 1'b1))
                            nmi_req <= 1'b0;
                        else
                            nmi_req <= nmi_req;
        end
    end
    
    //----------------------------------
    //
    // Nmi mux
    //
    //----------------------------------
    
    
    always @(negedge clk or nmi_ctrl or nmi_ack or hold)
    begin: nmi_mux
        
        begin
            if (hold == 1'b1)
                nmi_ack <= nmi_ack;
            else
                case (nmi_ctrl)
                    nmi_type_set_nmi :
                        nmi_ack <= 1'b1;
                    nmi_type_reset_nmi :
                        nmi_ack <= 1'b0;
                    default :
                        //  when latch_nmi =>
                        nmi_ack <= nmi_ack;
                endcase
        end
    end
    
    //----------------------------------
    //
    // state sequencer
    //
    //----------------------------------
    
    always @(state or op_code or cc or ea or irq or nmi_req or nmi_ack or hold or halt)
        case (state)
            state_type_reset_state :		//  released from reset
                begin
                    // reset the registers
                    op_ctrl <= op_type_reset_op;
                    acca_ctrl <= acca_type_reset_acca;
                    accb_ctrl <= accb_type_reset_accb;
                    ix_ctrl <= ix_type_reset_ix;
                    sp_ctrl <= sp_type_reset_sp;
                    pc_ctrl <= pc_type_reset_pc;
                    ea_ctrl <= ea_type_reset_ea;
                    md_ctrl <= md_type_reset_md;
                    iv_ctrl <= iv_type_reset_iv;
                    nmi_ctrl <= nmi_type_reset_nmi;
                    // idle the ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_reset_cc;
                    // idle the bus
                    dout_ctrl <= dout_type_md_lo_dout;
                    addr_ctrl <= addr_type_idle_ad;
                    next_state <= state_type_vect_hi_state;
                end
            
            //
            // Jump via interrupt vector
            // iv holds interrupt type
            // fetch PC hi from vector location
            //
            state_type_vect_hi_state :
                begin
                    // default the registers
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    md_ctrl <= md_type_latch_md;
                    ea_ctrl <= ea_type_latch_ea;
                    iv_ctrl <= iv_type_latch_iv;
                    // idle the ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // fetch pc low interrupt vector
                    pc_ctrl <= pc_type_pull_hi_pc;
                    addr_ctrl <= addr_type_int_hi_ad;
                    dout_ctrl <= dout_type_pc_hi_dout;
                    next_state <= state_type_vect_lo_state;
                end
            //
            // jump via interrupt vector
            // iv holds vector type
            // fetch PC lo from vector location
            //
            state_type_vect_lo_state :
                begin
                    // default the registers
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    md_ctrl <= md_type_latch_md;
                    ea_ctrl <= ea_type_latch_ea;
                    iv_ctrl <= iv_type_latch_iv;
                    // idle the ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // fetch the vector low byte
                    pc_ctrl <= pc_type_pull_lo_pc;
                    addr_ctrl <= addr_type_int_lo_ad;
                    dout_ctrl <= dout_type_pc_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            //
            // Here to fetch an instruction
            // PC points to opcode
            // Should service interrupt requests at this point
            // either from the timer
            // or from the external input.
            //
            state_type_fetch_state :
                begin
                    case (op_code[7:4])
                        // branch conditional
                        // acca single op
                        // accb single op
                        // indexed single op
                        4'b0000, 4'b0001, 4'b0010, 4'b0011, 4'b0100, 4'b0101, 4'b0110, 4'b0111 :		// extended single op
                            begin
                                // idle ALU
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                            end
                        
                        // acca immediate
                        // acca direct
                        // acca indexed
                        4'b1000, 4'b1001, 4'b1010, 4'b1011 :		// acca extended
                            case (op_code[3:0])
                                4'b0000 :		// suba
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sub8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0001 :		// cmpa
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sub8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0010 :		// sbca
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sbc;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0011 :		// subd
                                    begin
                                        left_ctrl <= left_type_accd_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sub16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_hi_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0100 :		// anda
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_and;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0101 :		// bita
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_and;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0110 :		// ldaa
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ld8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0111 :		// staa
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_st8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1000 :		// eora
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_eor;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1001 :		// adca
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_adc;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1010 :		// oraa
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ora;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1011 :		// adda
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_add8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1100 :		// cpx
                                    begin
                                        left_ctrl <= left_type_ix_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_cpx;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1101 :		// bsr / jsr
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1110 :		// lds
                                    begin
                                        left_ctrl <= left_type_sp_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ld16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_load_sp;
                                    end
                                4'b1111 :		// sts
                                    begin
                                        left_ctrl <= left_type_sp_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                            endcase
                        // accb immediate
                        // accb direct
                        // accb indexed
                        4'b1100, 4'b1101, 4'b1110, 4'b1111 :		// accb extended
                            case (op_code[3:0])
                                4'b0000 :		// subb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sub8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0001 :		// cmpb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sub8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0010 :		// sbcb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_sbc;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0011 :		// addd
                                    begin
                                        left_ctrl <= left_type_accd_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_add16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_hi_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0100 :		// andb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_and;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0101 :		// bitb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_and;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0110 :		// ldab
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ld8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b0111 :		// stab
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_st8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1000 :		// eorb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_eor;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1001 :		// adcb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_adc;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1010 :		// orab
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ora;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1011 :		// addb
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_add8;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1100 :		// ldd
                                    begin
                                        left_ctrl <= left_type_accd_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ld16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_load_hi_acca;
                                        accb_ctrl <= accb_type_load_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1101 :		// std
                                    begin
                                        left_ctrl <= left_type_accd_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1110 :		// ldx
                                    begin
                                        left_ctrl <= left_type_ix_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_ld16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_load_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                4'b1111 :		// stx
                                    begin
                                        left_ctrl <= left_type_ix_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_load_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                                default :
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_md_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        acca_ctrl <= acca_type_latch_acca;
                                        accb_ctrl <= accb_type_latch_accb;
                                        ix_ctrl <= ix_type_latch_ix;
                                        sp_ctrl <= sp_type_latch_sp;
                                    end
                            endcase
                        default :
                            begin
                                left_ctrl <= left_type_accd_left;
                                right_ctrl <= right_type_md_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                            end
                    endcase
                    md_ctrl <= md_type_latch_md;
                    // fetch the op code
                    op_ctrl <= op_type_fetch_op;
                    ea_ctrl <= ea_type_reset_ea;
                    addr_ctrl <= addr_type_fetch_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    iv_ctrl <= iv_type_latch_iv;
                    if (halt == 1'b1)
                    begin
                        pc_ctrl <= pc_type_latch_pc;
                        nmi_ctrl <= nmi_type_latch_nmi;
                        next_state <= state_type_halt_state;
                    end
                    // service non maskable interrupts
                    else if ((nmi_req == 1'b1) & (nmi_ack == 1'b0))
                    begin
                        pc_ctrl <= pc_type_latch_pc;
                        nmi_ctrl <= nmi_type_set_nmi;
                        next_state <= state_type_int_pcl_state;
                    end
                    else
                    begin
                        // service maskable interrupts
                        //
                        // nmi request is not cleared until nmi input goes low
                        //
                        if ((nmi_req == 1'b0) & (nmi_ack == 1'b1))
                            nmi_ctrl <= nmi_type_reset_nmi;
                        else
                            nmi_ctrl <= nmi_type_latch_nmi;
                        //
                        // IRQ is level sensitive
                        //
                        if ((irq == 1'b1) & (cc[IBIT] == 1'b0))
                        begin
                            pc_ctrl <= pc_type_latch_pc;
                            next_state <= state_type_int_pcl_state;
                        end
                        else
                        begin
                            // Advance the PC to fetch next instruction byte
                            pc_ctrl <= pc_type_inc_pc;
                            next_state <= state_type_decode_state;
                        end
                    end
                end
            //
            // Here to decode instruction
            // and fetch next byte of intruction
            // whether it be necessary or not
            //
            state_type_decode_state :
                begin
                    // fetch first byte of address or immediate data
                    ea_ctrl <= ea_type_fetch_first_ea;
                    addr_ctrl <= addr_type_fetch_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    iv_ctrl <= iv_type_latch_iv;
                    case (op_code[7:4])
                        4'b0000 :
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                sp_ctrl <= sp_type_latch_sp;
                                pc_ctrl <= pc_type_latch_pc;
                                case (op_code[3:0])
                                    4'b0001 :		// nop
                                        begin
                                            left_ctrl <= left_type_accd_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b0100 :		// lsrd
                                        begin
                                            left_ctrl <= left_type_accd_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_lsr16;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_load_hi_acca;
                                            accb_ctrl <= accb_type_load_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b0101 :		// lsld
                                        begin
                                            left_ctrl <= left_type_accd_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_lsl16;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_load_hi_acca;
                                            accb_ctrl <= accb_type_load_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b0110 :		// tap
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_tap;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b0111 :		// tpa
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_tpa;
                                            cc_ctrl <= cc_type_latch_cc;
                                            acca_ctrl <= acca_type_load_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b1000 :		// inx
                                        begin
                                            left_ctrl <= left_type_ix_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_inx;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_load_ix;
                                        end
                                    4'b1001 :		// dex
                                        begin
                                            left_ctrl <= left_type_ix_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_dex;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_load_ix;
                                        end
                                    4'b1010 :		// clv
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_clv;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b1011 :		// sev
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_sev;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b1100 :		// clc
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_clc;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b1101 :		// sec
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_sec;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b1110 :		// cli
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_cli;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    4'b1111 :		// sei
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_sei;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                    default :
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                            ix_ctrl <= ix_type_latch_ix;
                                        end
                                endcase
                                next_state <= state_type_fetch_state;
                            end
                        // acca / accb inherent instructions
                        4'b0001 :
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                pc_ctrl <= pc_type_latch_pc;
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_accb_right;
                                case (op_code[3:0])
                                    4'b0000 :		// sba
                                        begin
                                            alu_ctrl <= alu_type_alu_sub8;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_load_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                        end
                                    4'b0001 :		// cba
                                        begin
                                            alu_ctrl <= alu_type_alu_sub8;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                        end
                                    4'b0110 :		// tab
                                        begin
                                            alu_ctrl <= alu_type_alu_st8;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_load_accb;
                                        end
                                    4'b0111 :		// tba
                                        begin
                                            alu_ctrl <= alu_type_alu_ld8;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_load_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                        end
                                    4'b1001 :		// daa
                                        begin
                                            alu_ctrl <= alu_type_alu_daa;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_load_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                        end
                                    4'b1011 :		// aba
                                        begin
                                            alu_ctrl <= alu_type_alu_add8;
                                            cc_ctrl <= cc_type_load_cc;
                                            acca_ctrl <= acca_type_load_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                        end
                                    default :
                                        begin
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            acca_ctrl <= acca_type_latch_acca;
                                            accb_ctrl <= accb_type_latch_accb;
                                        end
                                endcase
                                next_state <= state_type_fetch_state;
                            end
                        4'b0010 :		// branch conditional
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                // increment the pc
                                pc_ctrl <= pc_type_inc_pc;
                                case (op_code[3:0])
                                    4'b0000 :		// bra
                                        next_state <= state_type_branch_state;
                                    4'b0001 :		// brn
                                        next_state <= state_type_fetch_state;
                                    4'b0010 :		// bhi
                                        if ((cc[CBIT] | cc[ZBIT]) == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b0011 :		// bls
                                        if ((cc[CBIT] | cc[ZBIT]) == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b0100 :		// bcc/bhs
                                        if (cc[CBIT] == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b0101 :		// bcs/blo
                                        if (cc[CBIT] == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b0110 :		// bne
                                        if (cc[ZBIT] == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b0111 :		// beq
                                        if (cc[ZBIT] == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1000 :		// bvc
                                        if (cc[VBIT] == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1001 :		// bvs
                                        if (cc[VBIT] == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1010 :		// bpl
                                        if (cc[NBIT] == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1011 :		// bmi
                                        if (cc[NBIT] == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1100 :		// bge
                                        if ((cc[NBIT] ^ cc[VBIT]) == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1101 :		// blt
                                        if ((cc[NBIT] ^ cc[VBIT]) == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1110 :		// bgt
                                        if ((cc[ZBIT] | (cc[NBIT] ^ cc[VBIT])) == 1'b0)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    4'b1111 :		// ble
                                        if ((cc[ZBIT] | (cc[NBIT] ^ cc[VBIT])) == 1'b1)
                                            next_state <= state_type_branch_state;
                                        else
                                            next_state <= state_type_fetch_state;
                                    default :
                                        next_state <= state_type_fetch_state;
                                endcase
                            end
                        //
                        // Single byte stack operators
                        // Do not advance PC
                        //
                        4'b0011 :
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                pc_ctrl <= pc_type_latch_pc;
                                case (op_code[3:0])
                                    4'b0000 :		// tsx
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_load_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b0001 :		// ins
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b0010 :		// pula
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_pula_state;
                                        end
                                    4'b0011 :		// pulb
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_pulb_state;
                                        end
                                    4'b0100 :		// des
                                        begin
                                            // decrement sp
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_sub16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b0101 :		// txs
                                        begin
                                            left_ctrl <= left_type_ix_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_sub16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b0110 :		// psha
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_psha_state;
                                        end
                                    4'b0111 :		// pshb
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_pshb_state;
                                        end
                                    4'b1000 :		// pulx
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_pulx_hi_state;
                                        end
                                    4'b1001 :		// rts
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_rts_hi_state;
                                        end
                                    4'b1010 :		// abx
                                        begin
                                            left_ctrl <= left_type_ix_left;
                                            right_ctrl <= right_type_accb_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_load_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b1011 :		// rti
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_load_sp;
                                            next_state <= state_type_rti_cc_state;
                                        end
                                    4'b1100 :		// pshx
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_pshx_lo_state;
                                        end
                                    4'b1101 :		// mul
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_accb_right;
                                            alu_ctrl <= alu_type_alu_add16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_mul_state;
                                        end
                                    4'b1110 :		// wai
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_int_pcl_state;
                                        end
                                    4'b1111 :		// swi
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_int_pcl_state;
                                        end
                                    default :
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            ix_ctrl <= ix_type_latch_ix;
                                            sp_ctrl <= sp_type_latch_sp;
                                            next_state <= state_type_fetch_state;
                                        end
                                endcase
                            end
                        //
                        // Accumulator A Single operand
                        // source = Acc A dest = Acc A
                        // Do not advance PC
                        //
                        4'b0100 :		// acca single op
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                accb_ctrl <= accb_type_latch_accb;
                                pc_ctrl <= pc_type_latch_pc;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                left_ctrl <= left_type_acca_left;
                                case (op_code[3:0])
                                    4'b0000 :		// neg
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_neg;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0011 :		// com
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_com;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0100 :		// lsr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_lsr8;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0110 :		// ror
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_ror8;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0111 :		// asr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_asr8;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1000 :		// asl
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_asl8;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1001 :		// rol
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_rol8;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1010 :		// dec
                                        begin
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_dec;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1011 :		// undefined
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            acca_ctrl <= acca_type_latch_acca;
                                            cc_ctrl <= cc_type_latch_cc;
                                        end
                                    4'b1100 :		// inc
                                        begin
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_inc;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1101 :		// tst
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st8;
                                            acca_ctrl <= acca_type_latch_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1110 :		// jmp
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            acca_ctrl <= acca_type_latch_acca;
                                            cc_ctrl <= cc_type_latch_cc;
                                        end
                                    4'b1111 :		// clr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_clr;
                                            acca_ctrl <= acca_type_load_acca;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    default :
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            acca_ctrl <= acca_type_latch_acca;
                                            cc_ctrl <= cc_type_latch_cc;
                                        end
                                endcase
                                next_state <= state_type_fetch_state;
                            end
                        //
                        // single operand acc b
                        // Do not advance PC
                        //
                        4'b0101 :
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                pc_ctrl <= pc_type_latch_pc;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                left_ctrl <= left_type_accb_left;
                                case (op_code[3:0])
                                    4'b0000 :		// neg
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_neg;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0011 :		// com
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_com;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0100 :		// lsr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_lsr8;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0110 :		// ror
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_ror8;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b0111 :		// asr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_asr8;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1000 :		// asl
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_asl8;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1001 :		// rol
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_rol8;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1010 :		// dec
                                        begin
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_dec;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1011 :		// undefined
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            accb_ctrl <= accb_type_latch_accb;
                                            cc_ctrl <= cc_type_latch_cc;
                                        end
                                    4'b1100 :		// inc
                                        begin
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_inc;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1101 :		// tst
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st8;
                                            accb_ctrl <= accb_type_latch_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    4'b1110 :		// jmp
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            accb_ctrl <= accb_type_latch_accb;
                                            cc_ctrl <= cc_type_latch_cc;
                                        end
                                    4'b1111 :		// clr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_clr;
                                            accb_ctrl <= accb_type_load_accb;
                                            cc_ctrl <= cc_type_load_cc;
                                        end
                                    default :
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            accb_ctrl <= accb_type_latch_accb;
                                            cc_ctrl <= cc_type_latch_cc;
                                        end
                                endcase
                                next_state <= state_type_fetch_state;
                            end
                        //
                        // Single operand indexed
                        // Two byte instruction so advance PC
                        // EA should hold index offset
                        //
                        4'b0110 :		// indexed single op
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc 
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                next_state <= state_type_indexed_state;
                            end
                        //
                        // Single operand extended addressing
                        // three byte instruction so advance the PC
                        // Low order EA holds high order address
                        //
                        4'b0111 :		// extended single op
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                next_state <= state_type_extended_state;
                            end
                        
                        4'b1000 :		// acca immediate
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                case (op_code[3:0])
                                    // subdd #
                                    // cpx #
                                    4'b0011, 4'b1100, 4'b1110 :		// lds #
                                        next_state <= state_type_immediate16_state;
                                    4'b1101 :		// bsr
                                        next_state <= state_type_bsr_state;
                                    default :
                                        next_state <= state_type_fetch_state;
                                endcase
                            end
                        
                        4'b1001 :		// acca direct
                            begin
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                pc_ctrl <= pc_type_inc_pc;
                                case (op_code[3:0])
                                    4'b0111 :		// staa direct
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st8;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1111 :		// sts direct
                                        begin
                                            left_ctrl <= left_type_sp_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write16_state;
                                        end
                                    4'b1101 :		// jsr direct
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_fetch_first_md;
                                            next_state <= state_type_jsr_state;
                                        end
                                    default :
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_fetch_first_md;
                                            next_state <= state_type_read8_state;
                                        end
                                endcase
                            end
                        
                        4'b1010 :		// acca indexed
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                next_state <= state_type_indexed_state;
                            end
                        
                        4'b1011 :		// acca extended
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                next_state <= state_type_extended_state;
                            end
                        
                        4'b1100 :		// accb immediate
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                case (op_code[3:0])
                                    // addd #
                                    // ldd #
                                    4'b0011, 4'b1100, 4'b1110 :		// ldx #
                                        next_state <= state_type_immediate16_state;
                                    default :
                                        next_state <= state_type_fetch_state;
                                endcase
                            end
                        
                        4'b1101 :		// accb direct
                            begin
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                pc_ctrl <= pc_type_inc_pc;
                                case (op_code[3:0])
                                    4'b0111 :		// stab direct
                                        begin
                                            left_ctrl <= left_type_accb_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st8;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1101 :		// std direct
                                        begin
                                            left_ctrl <= left_type_accd_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write16_state;
                                        end
                                    4'b1111 :		// stx direct
                                        begin
                                            left_ctrl <= left_type_ix_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st16;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write16_state;
                                        end
                                    default :
                                        begin
                                            left_ctrl <= left_type_acca_left;
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_fetch_first_md;
                                            next_state <= state_type_read8_state;
                                        end
                                endcase
                            end
                        
                        4'b1110 :		// accb indexed
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                next_state <= state_type_indexed_state;
                            end
                        
                        4'b1111 :		// accb extended
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // increment the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_inc_pc;
                                next_state <= state_type_extended_state;
                            end
                        
                        default :
                            begin
                                md_ctrl <= md_type_fetch_first_md;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                // idle the pc
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                pc_ctrl <= pc_type_latch_pc;
                                next_state <= state_type_fetch_state;
                            end
                    endcase
                end
            
            state_type_immediate16_state :
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    op_ctrl <= op_type_latch_op;
                    iv_ctrl <= iv_type_latch_iv;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment pc
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    pc_ctrl <= pc_type_inc_pc;
                    // fetch next immediate byte
                    md_ctrl <= md_type_fetch_next_md;
                    addr_ctrl <= addr_type_fetch_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            //
            // ea holds 8 bit index offet
            // calculate the effective memory address
            // using the alu
            //
            state_type_indexed_state :
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    // calculate effective address from index reg
                    // index offest is not sign extended
                    ea_ctrl <= ea_type_add_ix_ea;
                    // idle the bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    // work out next state
                    case (op_code[7:4])
                        4'b0110 :		// single op indexed
                            begin
                                md_ctrl <= md_type_latch_md;
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                case (op_code[3:0])
                                    4'b1011 :		// undefined
                                        next_state <= state_type_fetch_state;
                                    4'b1110 :		// jmp
                                        next_state <= state_type_jmp_state;
                                    default :
                                        next_state <= state_type_read8_state;
                                endcase
                            end
                        4'b1010 :		// acca indexed
                            case (op_code[3:0])
                                4'b0111 :		// staa
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st8;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write8_state;
                                    end
                                4'b1101 :		// jsr
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_latch_md;
                                        next_state <= state_type_jsr_state;
                                    end
                                4'b1111 :		// sts
                                    begin
                                        left_ctrl <= left_type_sp_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write16_state;
                                    end
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_latch_md;
                                        next_state <= state_type_read8_state;
                                    end
                            endcase
                        4'b1110 :		// accb indexed
                            case (op_code[3:0])
                                4'b0111 :		// stab direct
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st8;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write8_state;
                                    end
                                4'b1101 :		// std direct
                                    begin
                                        left_ctrl <= left_type_accd_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write16_state;
                                    end
                                4'b1111 :		// stx direct
                                    begin
                                        left_ctrl <= left_type_ix_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write16_state;
                                    end
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_latch_md;
                                        next_state <= state_type_read8_state;
                                    end
                            endcase
                        default :
                            begin
                                md_ctrl <= md_type_latch_md;
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                next_state <= state_type_fetch_state;
                            end
                    endcase
                end
            //
            // ea holds the low byte of the absolute address
            // Move ea low byte into ea high byte
            // load new ea low byte to for absolute 16 bit address
            // advance the program counter
            //
            state_type_extended_state :		// fetch ea low byte
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    // increment pc
                    pc_ctrl <= pc_type_inc_pc;
                    // fetch next effective address bytes
                    ea_ctrl <= ea_type_fetch_next_ea;
                    addr_ctrl <= addr_type_fetch_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    // work out the next state
                    case (op_code[7:4])
                        4'b0111 :		// single op extended
                            begin
                                md_ctrl <= md_type_latch_md;
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                case (op_code[3:0])
                                    4'b1011 :		// undefined
                                        next_state <= state_type_fetch_state;
                                    4'b1110 :		// jmp
                                        next_state <= state_type_jmp_state;
                                    default :
                                        next_state <= state_type_read8_state;
                                endcase
                            end
                        4'b1011 :		// acca extended
                            case (op_code[3:0])
                                4'b0111 :		// staa
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st8;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write8_state;
                                    end
                                4'b1101 :		// jsr
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_latch_md;
                                        next_state <= state_type_jsr_state;
                                    end
                                4'b1111 :		// sts
                                    begin
                                        left_ctrl <= left_type_sp_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write16_state;
                                    end
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_latch_md;
                                        next_state <= state_type_read8_state;
                                    end
                            endcase
                        4'b1111 :		// accb extended
                            case (op_code[3:0])
                                4'b0111 :		// stab
                                    begin
                                        left_ctrl <= left_type_accb_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st8;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write8_state;
                                    end
                                4'b1101 :		// std
                                    begin
                                        left_ctrl <= left_type_accd_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write16_state;
                                    end
                                4'b1111 :		// stx
                                    begin
                                        left_ctrl <= left_type_ix_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_st16;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_load_md;
                                        next_state <= state_type_write16_state;
                                    end
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_latch_md;
                                        next_state <= state_type_read8_state;
                                    end
                            endcase
                        default :
                            begin
                                md_ctrl <= md_type_latch_md;
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                next_state <= state_type_fetch_state;
                            end
                    endcase
                end
            //
            // here if ea holds low byte (direct page)
            // can enter here from extended addressing
            // read memory location
            // note that reads may be 8 or 16 bits
            //
            state_type_read8_state :		// read data
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    //
                    addr_ctrl <= addr_type_read_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    case (op_code[7:4])
                        4'b0110, 4'b0111 :		// single operand
                            begin
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                md_ctrl <= md_type_fetch_first_md;
                                ea_ctrl <= ea_type_latch_ea;
                                next_state <= state_type_execute_state;
                            end
                        
                        4'b1001, 4'b1010, 4'b1011 :		// acca
                            case (op_code[3:0])
                                // subd
                                // lds
                                4'b0011, 4'b1110, 4'b1100 :		// cpx
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_fetch_first_md;
                                        // increment the effective address in case of 16 bit load
                                        ea_ctrl <= ea_type_inc_ea;
                                        next_state <= state_type_read16_state;
                                    end
                                //					    when "0111" =>   -- staa
                                // 					      left_ctrl  <= acca_left;
                                //					      right_ctrl <= zero_right;
                                //					      alu_ctrl   <= alu_st8;
                                //                     cc_ctrl    <= latch_cc;
                                //				         md_ctrl    <= load_md;
                                // 					      ea_ctrl    <= latch_ea;
                                //					      next_state <= write8_state;
                                //					    when "1101" => -- jsr
                                //			            left_ctrl  <= acca_left;
                                //				         right_ctrl <= zero_right;
                                //				         alu_ctrl   <= alu_nop;
                                //                     cc_ctrl    <= latch_cc;
                                //                     md_ctrl    <= latch_md;
                                // 					      ea_ctrl    <= latch_ea;
                                //					      next_state <= jsr_state;
                                //					    when "1111" =>  -- sts
                                // 					      left_ctrl  <= sp_left;
                                //					      right_ctrl <= zero_right;
                                //					      alu_ctrl   <= alu_st16;
                                //                     cc_ctrl    <= latch_cc;
                                //				         md_ctrl    <= load_md;
                                //					      ea_ctrl    <= latch_ea;
                                //					      next_state <= write16_state;
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_fetch_first_md;
                                        ea_ctrl <= ea_type_latch_ea;
                                        next_state <= state_type_fetch_state;
                                    end
                            endcase
                        
                        4'b1101, 4'b1110, 4'b1111 :		// accb
                            case (op_code[3:0])
                                // addd
                                // ldd
                                4'b0011, 4'b1100, 4'b1110 :		// ldx
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_fetch_first_md;
                                        // increment the effective address in case of 16 bit load
                                        ea_ctrl <= ea_type_inc_ea;
                                        next_state <= state_type_read16_state;
                                    end
                                //					    when "0111" =>   -- stab
                                // 					      left_ctrl  <= accb_left;
                                //					      right_ctrl <= zero_right;
                                //					      alu_ctrl   <= alu_st8;
                                //                     cc_ctrl    <= latch_cc;
                                //				         md_ctrl    <= load_md;
                                //					      ea_ctrl    <= latch_ea;
                                //					      next_state <= write8_state;
                                //					    when "1101" => -- std
                                //			            left_ctrl  <= accd_left;
                                //				         right_ctrl <= zero_right;
                                //				         alu_ctrl   <= alu_st16;
                                //                     cc_ctrl    <= latch_cc;
                                //                     md_ctrl    <= load_md;
                                // 					      ea_ctrl    <= latch_ea;
                                //					      next_state <= write16_state;
                                //					    when "1111" =>  -- stx
                                // 					      left_ctrl  <= ix_left;
                                //					      right_ctrl <= zero_right;
                                //					      alu_ctrl   <= alu_st16;
                                //                     cc_ctrl    <= latch_cc;
                                //				         md_ctrl    <= load_md;
                                //					      ea_ctrl    <= latch_ea;
                                //					      next_state <= write16_state;
                                default :
                                    begin
                                        left_ctrl <= left_type_acca_left;
                                        right_ctrl <= right_type_zero_right;
                                        alu_ctrl <= alu_type_alu_nop;
                                        cc_ctrl <= cc_type_latch_cc;
                                        md_ctrl <= md_type_fetch_first_md;
                                        ea_ctrl <= ea_type_latch_ea;
                                        next_state <= state_type_execute_state;
                                    end
                            endcase
                        default :
                            begin
                                left_ctrl <= left_type_acca_left;
                                right_ctrl <= right_type_zero_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                md_ctrl <= md_type_fetch_first_md;
                                ea_ctrl <= ea_type_latch_ea;
                                next_state <= state_type_fetch_state;
                            end
                    endcase
                end
            
            state_type_read16_state :		// read second data byte from ea
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // idle the effective address
                    ea_ctrl <= ea_type_latch_ea;
                    // read the low byte of the 16 bit data
                    md_ctrl <= md_type_fetch_next_md;
                    addr_ctrl <= addr_type_read_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            //
            // 16 bit Write state
            // write high byte of ALU output.
            // EA hold address of memory to write to
            // Advance the effective address in ALU
            //
            state_type_write16_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    // increment the effective address
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    ea_ctrl <= ea_type_inc_ea;
                    // write the ALU hi byte to ea
                    addr_ctrl <= addr_type_write_ad;
                    dout_ctrl <= dout_type_md_hi_dout;
                    next_state <= state_type_write8_state;
                end
            //
            // 8 bit write
            // Write low 8 bits of ALU output
            //
            state_type_write8_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // idle the ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // write ALU low byte output
                    addr_ctrl <= addr_type_write_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_jmp_state :
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // load PC with effective address
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    pc_ctrl <= pc_type_load_ea_pc;
                    // idle the bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_jsr_state :		// JSR
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write pc low
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_pc_lo_dout;
                    next_state <= state_type_jsr1_state;
                end
            
            state_type_jsr1_state :		// JSR
                begin
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write pc hi
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_pc_hi_dout;
                    next_state <= state_type_jmp_state;
                end
            
            state_type_branch_state :		// Bcc
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // calculate signed branch
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    pc_ctrl <= pc_type_add_ea_pc;
                    // idle the bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_bsr_state :		// BSR
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write pc low
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_pc_lo_dout;
                    next_state <= state_type_bsr1_state;
                end
            
            state_type_bsr1_state :		// BSR
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write pc hi
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_pc_hi_dout;
                    next_state <= state_type_branch_state;
                end
            
            state_type_rts_hi_state :		// RTS
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment the sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // read pc hi
                    pc_ctrl <= pc_type_pull_hi_pc;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_pc_hi_dout;
                    next_state <= state_type_rts_lo_state;
                end
            
            state_type_rts_lo_state :		// RTS1
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // idle the ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // read pc low
                    pc_ctrl <= pc_type_pull_lo_pc;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_pc_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_mul_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // move acca to md
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_st16;
                    cc_ctrl <= cc_type_latch_cc;
                    md_ctrl <= md_type_load_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mulea_state;
                end
            
            state_type_mulea_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    md_ctrl <= md_type_latch_md;
                    // idle ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // move accb to ea
                    ea_ctrl <= ea_type_load_accb_ea;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_muld_state;
                end
            
            state_type_muld_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    md_ctrl <= md_type_latch_md;
                    // clear accd
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_ld8;
                    cc_ctrl <= cc_type_latch_cc;
                    acca_ctrl <= acca_type_load_hi_acca;
                    accb_ctrl <= accb_type_load_accb;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul0_state;
                end
            
            state_type_mul0_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 0 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[0] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul1_state;
                end
            
            state_type_mul1_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 1 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[1] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul2_state;
                end
            
            state_type_mul2_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 2 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[2] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul3_state;
                end
            
            state_type_mul3_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 3 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[3] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul4_state;
                end
            
            state_type_mul4_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 4 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[4] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul5_state;
                end
            
            state_type_mul5_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 5 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[5] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul6_state;
                end
            
            state_type_mul6_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 6 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[6] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_mul7_state;
                end
            
            state_type_mul7_state :
                begin
                    // default
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // if bit 7 of ea set, add accd to md
                    left_ctrl <= left_type_accd_left;
                    right_ctrl <= right_type_md_right;
                    alu_ctrl <= alu_type_alu_add16;
                    if (ea[7] == 1'b1)
                    begin
                        cc_ctrl <= cc_type_load_cc;
                        acca_ctrl <= acca_type_load_hi_acca;
                        accb_ctrl <= accb_type_load_accb;
                    end
                    else
                    begin
                        cc_ctrl <= cc_type_latch_cc;
                        acca_ctrl <= acca_type_latch_acca;
                        accb_ctrl <= accb_type_latch_accb;
                    end
                    md_ctrl <= md_type_shiftl_md;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_execute_state :		// execute single operand instruction
                begin
                    // default
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    case (op_code[7:4])
                        // indexed single op
                        4'b0110, 4'b0111 :		// extended single op
                            begin
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                pc_ctrl <= pc_type_latch_pc;
                                iv_ctrl <= iv_type_latch_iv;
                                ea_ctrl <= ea_type_latch_ea;
                                // idle the bus
                                addr_ctrl <= addr_type_idle_ad;
                                dout_ctrl <= dout_type_md_lo_dout;
                                left_ctrl <= left_type_md_left;
                                case (op_code[3:0])
                                    4'b0000 :		// neg
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_neg;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b0011 :		// com
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_com;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b0100 :		// lsr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_lsr8;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b0110 :		// ror
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_ror8;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b0111 :		// asr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_asr8;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1000 :		// asl
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_asl8;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1001 :		// rol
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_rol8;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1010 :		// dec
                                        begin
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_dec;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1011 :		// undefined
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_latch_md;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b1100 :		// inc
                                        begin
                                            right_ctrl <= right_type_plus_one_right;
                                            alu_ctrl <= alu_type_alu_inc;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    4'b1101 :		// tst
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_st8;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_latch_md;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b1110 :		// jmp
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_latch_md;
                                            next_state <= state_type_fetch_state;
                                        end
                                    4'b1111 :		// clr
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_clr;
                                            cc_ctrl <= cc_type_load_cc;
                                            md_ctrl <= md_type_load_md;
                                            next_state <= state_type_write8_state;
                                        end
                                    default :
                                        begin
                                            right_ctrl <= right_type_zero_right;
                                            alu_ctrl <= alu_type_alu_nop;
                                            cc_ctrl <= cc_type_latch_cc;
                                            md_ctrl <= md_type_latch_md;
                                            next_state <= state_type_fetch_state;
                                        end
                                endcase
                            end
                        
                        default :
                            begin
                                left_ctrl <= left_type_accd_left;
                                right_ctrl <= right_type_md_right;
                                alu_ctrl <= alu_type_alu_nop;
                                cc_ctrl <= cc_type_latch_cc;
                                acca_ctrl <= acca_type_latch_acca;
                                accb_ctrl <= accb_type_latch_accb;
                                ix_ctrl <= ix_type_latch_ix;
                                sp_ctrl <= sp_type_latch_sp;
                                pc_ctrl <= pc_type_latch_pc;
                                md_ctrl <= md_type_latch_md;
                                iv_ctrl <= iv_type_latch_iv;
                                ea_ctrl <= ea_type_latch_ea;
                                // idle the bus
                                addr_ctrl <= addr_type_idle_ad;
                                dout_ctrl <= dout_type_md_lo_dout;
                                next_state <= state_type_fetch_state;
                            end
                    endcase
                end
            
            state_type_psha_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write acca
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_acca_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_pula_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // idle sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_latch_sp;
                    // read acca
                    acca_ctrl <= acca_type_pull_acca;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_acca_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_pshb_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write accb
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_accb_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_pulb_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // idle sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_latch_sp;
                    // read accb
                    accb_ctrl <= accb_type_pull_accb;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_accb_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_pshx_lo_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write ix low
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_ix_lo_dout;
                    next_state <= state_type_pshx_hi_state;
                end
            
            state_type_pshx_hi_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write ix hi
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_ix_hi_dout;
                    next_state <= state_type_fetch_state;
                end
            
            state_type_pulx_hi_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // pull ix hi
                    ix_ctrl <= ix_type_pull_hi_ix;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_ix_hi_dout;
                    next_state <= state_type_pulx_lo_state;
                end
            
            state_type_pulx_lo_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // idle sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_latch_sp;
                    // read ix low
                    ix_ctrl <= ix_type_pull_lo_ix;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_ix_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            //
            // return from interrupt
            // enter here from bogus interrupts
            //
            state_type_rti_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    sp_ctrl <= sp_type_load_sp;
                    // idle address bus
                    cc_ctrl <= cc_type_latch_cc;
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_cc_dout;
                    next_state <= state_type_rti_cc_state;
                end
            
            state_type_rti_cc_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    sp_ctrl <= sp_type_load_sp;
                    // read cc
                    cc_ctrl <= cc_type_pull_cc;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_cc_dout;
                    next_state <= state_type_rti_accb_state;
                end
            
            state_type_rti_accb_state :
                begin
                    // default registers
                    acca_ctrl <= acca_type_latch_acca;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // read accb
                    accb_ctrl <= accb_type_pull_accb;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_accb_dout;
                    next_state <= state_type_rti_acca_state;
                end
            
            state_type_rti_acca_state :
                begin
                    // default registers
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // read acca
                    acca_ctrl <= acca_type_pull_acca;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_acca_dout;
                    next_state <= state_type_rti_ixh_state;
                end
            
            state_type_rti_ixh_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // read ix hi
                    ix_ctrl <= ix_type_pull_hi_ix;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_ix_hi_dout;
                    next_state <= state_type_rti_ixl_state;
                end
            
            state_type_rti_ixl_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // read ix low
                    ix_ctrl <= ix_type_pull_lo_ix;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_ix_lo_dout;
                    next_state <= state_type_rti_pch_state;
                end
            
            state_type_rti_pch_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // increment sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_add16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // pull pc hi
                    pc_ctrl <= pc_type_pull_hi_pc;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_pc_hi_dout;
                    next_state <= state_type_rti_pcl_state;
                end
            
            state_type_rti_pcl_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // idle sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_latch_sp;
                    // pull pc low
                    pc_ctrl <= pc_type_pull_lo_pc;
                    addr_ctrl <= addr_type_pull_ad;
                    dout_ctrl <= dout_type_pc_lo_dout;
                    next_state <= state_type_fetch_state;
                end
            
            //
            // here on interrupt
            // iv register hold interrupt type
            //
            state_type_int_pcl_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write pc low
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_pc_lo_dout;
                    next_state <= state_type_int_pch_state;
                end
            
            state_type_int_pch_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write pc hi
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_pc_hi_dout;
                    next_state <= state_type_int_ixl_state;
                end
            
            state_type_int_ixl_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write ix low
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_ix_lo_dout;
                    next_state <= state_type_int_ixh_state;
                end
            
            state_type_int_ixh_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write ix hi
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_ix_hi_dout;
                    next_state <= state_type_int_acca_state;
                end
            
            state_type_int_acca_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write acca
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_acca_dout;
                    next_state <= state_type_int_accb_state;
                end
            
            state_type_int_accb_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write accb
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_accb_dout;
                    next_state <= state_type_int_cc_state;
                end
            
            state_type_int_cc_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // decrement sp
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_sub16;
                    cc_ctrl <= cc_type_latch_cc;
                    sp_ctrl <= sp_type_load_sp;
                    // write cc
                    addr_ctrl <= addr_type_push_ad;
                    dout_ctrl <= dout_type_cc_dout;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    //
                    // nmi is edge triggered
                    // nmi_req is cleared when nmi goes low.
                    //
                    if (nmi_req == 1'b1)
                    begin
                        iv_ctrl <= iv_type_nmi_iv;
                        next_state <= state_type_vect_hi_state;
                    end
                    else
                        //
                        // IRQ is level sensitive
                        //
                        if ((irq == 1'b1) & (cc[IBIT] == 1'b0))
                        begin
                            iv_ctrl <= iv_type_irq_iv;
                            next_state <= state_type_int_mask_state;
                        end
                        else
                            case (op_code)
                                8'b00111110 :		// WAI (wait for interrupt)
                                    begin
                                        iv_ctrl <= iv_type_latch_iv;
                                        next_state <= state_type_int_wai_state;
                                    end
                                8'b00111111 :		// SWI (Software interrupt)
                                    begin
                                        iv_ctrl <= iv_type_swi_iv;
                                        next_state <= state_type_vect_hi_state;
                                    end
                                default :		// bogus interrupt (return)
                                    begin
                                        iv_ctrl <= iv_type_latch_iv;
                                        next_state <= state_type_rti_state;
                                    end
                            endcase
                end
            
            state_type_int_wai_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    op_ctrl <= op_type_latch_op;
                    ea_ctrl <= ea_type_latch_ea;
                    // enable interrupts
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_plus_one_right;
                    alu_ctrl <= alu_type_alu_cli;
                    cc_ctrl <= cc_type_load_cc;
                    sp_ctrl <= sp_type_latch_sp;
                    // idle bus
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_cc_dout;
                    if ((nmi_req == 1'b1) & (nmi_ack == 1'b0))
                    begin
                        iv_ctrl <= iv_type_nmi_iv;
                        nmi_ctrl <= nmi_type_set_nmi;
                        next_state <= state_type_vect_hi_state;
                    end
                    else
                    begin
                        //
                        // nmi request is not cleared until nmi input goes low
                        //
                        if ((nmi_req == 1'b0) & (nmi_ack == 1'b1))
                            nmi_ctrl <= nmi_type_reset_nmi;
                        else
                            nmi_ctrl <= nmi_type_latch_nmi;
                        //
                        // IRQ is level sensitive
                        //
                        if ((irq == 1'b1) & (cc[IBIT] == 1'b0))
                        begin
                            iv_ctrl <= iv_type_irq_iv;
                            next_state <= state_type_int_mask_state;
                        end
                        else
                        begin
                            iv_ctrl <= iv_type_latch_iv;
                            next_state <= state_type_int_wai_state;
                        end
                    end
                end
            
            state_type_int_mask_state :
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // Mask IRQ
                    left_ctrl <= left_type_sp_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_sei;
                    cc_ctrl <= cc_type_load_cc;
                    sp_ctrl <= sp_type_latch_sp;
                    // idle bus cycle
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_vect_hi_state;
                end
            
            state_type_halt_state :		// halt CPU.
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // do nothing in ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // idle bus cycle
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    if (halt == 1'b1)
                        next_state <= state_type_halt_state;
                    else
                        next_state <= state_type_fetch_state;
                end
            
            default :		// error state halt on undefine states
                begin
                    // default
                    acca_ctrl <= acca_type_latch_acca;
                    accb_ctrl <= accb_type_latch_accb;
                    ix_ctrl <= ix_type_latch_ix;
                    sp_ctrl <= sp_type_latch_sp;
                    pc_ctrl <= pc_type_latch_pc;
                    md_ctrl <= md_type_latch_md;
                    iv_ctrl <= iv_type_latch_iv;
                    op_ctrl <= op_type_latch_op;
                    nmi_ctrl <= nmi_type_latch_nmi;
                    ea_ctrl <= ea_type_latch_ea;
                    // do nothing in ALU
                    left_ctrl <= left_type_acca_left;
                    right_ctrl <= right_type_zero_right;
                    alu_ctrl <= alu_type_alu_nop;
                    cc_ctrl <= cc_type_latch_cc;
                    // idle bus cycle
                    addr_ctrl <= addr_type_idle_ad;
                    dout_ctrl <= dout_type_md_lo_dout;
                    next_state <= state_type_error_state;
                end
        endcase
    
    //------------------------------
    //
    // state machine
    //
    //------------------------------
    
    
    always @(negedge clk or rst or state or hold)
    begin: change_state
        
        begin
            if (rst == 1'b1)
                state <= state_type_reset_state;
            else if (hold == 1'b1)
                state <= state;
            else
                state <= next_state;
        end
    end
    
endmodule
