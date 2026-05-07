// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vemu__Syms.h"


void Vemu___024root__trace_chg_0_sub_0(Vemu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vemu___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_chg_0\n"); );
    // Body
    Vemu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vemu___024root*>(voidSelf);
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vemu___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vemu___024root__trace_chg_0_sub_0(Vemu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_chg_0_sub_0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.emu__DOT__sd_lba[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.emu__DOT__sd_lba[1]),32);
        bufp->chgCData(oldp+2,(vlSelfRef.emu__DOT__sd_buff_din[0]),8);
        bufp->chgCData(oldp+3,(vlSelfRef.emu__DOT__sd_buff_din[1]),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+4,(vlSelfRef.emu__DOT__joy),16);
        bufp->chgBit(oldp+5,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset)))));
        bufp->chgBit(oldp+6,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgBit(oldp+7,((1U & ((IData)(vlSelfRef.emu__DOT__btn_left) 
                                    | ((IData)(vlSelfRef.emu__DOT__joy) 
                                       >> 1U)))));
        bufp->chgBit(oldp+8,((1U & ((IData)(vlSelfRef.emu__DOT__btn_right) 
                                    | (IData)(vlSelfRef.emu__DOT__joy)))));
        bufp->chgBit(oldp+9,((1U & ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                    | ((IData)(vlSelfRef.emu__DOT__joy) 
                                       >> 4U)))));
        bufp->chgBit(oldp+10,((1U & ((IData)(vlSelfRef.emu__DOT__btn_gearup) 
                                     | ((IData)(vlSelfRef.emu__DOT__joy) 
                                        >> 5U)))));
        bufp->chgBit(oldp+11,((1U & ((IData)(vlSelfRef.emu__DOT__btn_geardown) 
                                     | ((IData)(vlSelfRef.emu__DOT__joy) 
                                        >> 6U)))));
        bufp->chgBit(oldp+12,((1U & (((IData)(vlSelfRef.emu__DOT__joy) 
                                      >> 7U) | (IData)(vlSelfRef.emu__DOT__btn_nexttrack)))));
        bufp->chgBit(oldp+13,(vlSelfRef.emu__DOT__m_start1));
        bufp->chgBit(oldp+14,((1U & ((IData)(vlSelfRef.emu__DOT__btn_two_players) 
                                     | ((IData)(vlSelfRef.emu__DOT__joy) 
                                        >> 8U)))));
        bufp->chgBit(oldp+15,(vlSelfRef.emu__DOT__m_coin));
        bufp->chgBit(oldp+16,((1U & (~ ((IData)(vlSelfRef.emu__DOT__m_coin) 
                                        | (IData)(vlSelfRef.emu__DOT__btn_coin_1))))));
        bufp->chgBit(oldp+17,((1U & (~ ((IData)(vlSelfRef.emu__DOT__m_coin) 
                                        | (IData)(vlSelfRef.emu__DOT__btn_coin_2))))));
        bufp->chgBit(oldp+18,((1U & (~ ((IData)(vlSelfRef.emu__DOT__m_start1) 
                                        | (IData)(vlSelfRef.emu__DOT__btn_start_1))))));
        bufp->chgBit(oldp+19,((1U & (~ (((IData)(vlSelfRef.emu__DOT__joy) 
                                         >> 7U) | (IData)(vlSelfRef.emu__DOT__btn_nexttrack))))));
        bufp->chgBit(oldp+20,((1U & (~ ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                        | ((IData)(vlSelfRef.emu__DOT__joy) 
                                           >> 4U))))));
        bufp->chgBit(oldp+21,(((IData)(vlSelfRef.emu__DOT__m_coin) 
                               | (IData)(vlSelfRef.emu__DOT__btn_coin_1))));
        bufp->chgBit(oldp+22,(((IData)(vlSelfRef.emu__DOT__m_coin) 
                               | (IData)(vlSelfRef.emu__DOT__btn_coin_2))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+23,(vlSelfRef.emu__DOT__steer),2);
        bufp->chgBit(oldp+24,(vlSelfRef.emu__DOT__gear1));
        bufp->chgBit(oldp+25,(vlSelfRef.emu__DOT__gear2));
        bufp->chgBit(oldp+26,(vlSelfRef.emu__DOT__gear3));
        bufp->chgCData(oldp+27,(vlSelfRef.emu__DOT__gearshift1__DOT__gear),3);
        bufp->chgBit(oldp+28,(vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up));
        bufp->chgBit(oldp+29,(vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_down));
        bufp->chgCData(oldp+30,(vlSelfRef.emu__DOT__steer1__DOT__state),4);
        bufp->chgBit(oldp+31,((1U & ((IData)(vlSelfRef.emu__DOT__steer) 
                                     >> 1U))));
        bufp->chgBit(oldp+32,((1U & (IData)(vlSelfRef.emu__DOT__steer))));
        bufp->chgBit(oldp+33,((1U & (~ ((IData)(vlSelfRef.emu__DOT__steer) 
                                        >> 1U)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+34,(vlSelfRef.emu__DOT__steer1__DOT__unnamedblk1__DOT__count),32);
        bufp->chgBit(oldp+35,(vlSelfRef.emu__DOT__superbug__DOT__PFWndo));
        bufp->chgCData(oldp+36,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout),8);
        bufp->chgCData(oldp+37,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout),4);
        bufp->chgCData(oldp+38,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout),4);
        bufp->chgCData(oldp+39,(((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout))
                                  ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout)
                                  : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout))),4);
        bufp->chgCData(oldp+40,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__ShiftData),4);
        bufp->chgCData(oldp+41,((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q) 
                                  << 4U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q))),8);
        bufp->chgCData(oldp+42,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout),8);
        bufp->chgCData(oldp+43,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout),8);
        bufp->chgCData(oldp+44,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout),8);
        bufp->chgBit(oldp+45,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n));
        bufp->chgBit(oldp+46,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)))));
        bufp->chgBit(oldp+47,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__prev_V16));
        bufp->chgCData(oldp+48,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q),4);
        bufp->chgCData(oldp+49,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q),4);
        bufp->chgCData(oldp+50,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout),4);
        bufp->chgCData(oldp+51,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout),4);
        bufp->chgCData(oldp+52,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout),4);
        bufp->chgCData(oldp+53,(((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q))
                                  ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout)
                                  : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q))
                                      ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout)
                                      : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout)))),4);
        bufp->chgCData(oldp+54,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP),8);
        bufp->chgBit(oldp+55,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode));
        bufp->chgBit(oldp+56,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n));
        bufp->chgBit(oldp+57,(((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode)) 
                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n))));
        bufp->chgBit(oldp+58,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n) 
                                        & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode)) 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n)))))));
        bufp->chgBit(oldp+59,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n));
        bufp->chgCData(oldp+60,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift),4);
        bufp->chgBit(oldp+61,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n));
        bufp->chgBit(oldp+62,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift) 
                                        | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n))))));
        bufp->chgIData(oldp+63,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__pf_write_count),32);
        bufp->chgBit(oldp+64,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_VBlank_arrow));
        bufp->chgBit(oldp+65,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_H8_pfwndo));
        bufp->chgCData(oldp+66,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q),4);
        bufp->chgCData(oldp+67,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+68,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw));
        bufp->chgBit(oldp+69,(vlSelfRef.emu__DOT__superbug__DOT__VMA));
        bufp->chgBit(oldp+70,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)))));
        bufp->chgSData(oldp+71,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu),16);
        bufp->chgCData(oldp+72,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out),8);
        bufp->chgCData(oldp+73,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code),8);
        bufp->chgCData(oldp+74,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca),8);
        bufp->chgCData(oldp+75,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb),8);
        bufp->chgCData(oldp+76,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc),8);
        bufp->chgSData(oldp+77,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg),16);
        bufp->chgSData(oldp+78,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp),16);
        bufp->chgSData(oldp+79,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea),16);
        bufp->chgSData(oldp+80,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc),16);
        bufp->chgSData(oldp+81,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md),16);
        bufp->chgCData(oldp+82,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv),2);
        bufp->chgBit(oldp+83,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req));
        bufp->chgBit(oldp+84,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack));
        bufp->chgCData(oldp+85,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state),6);
        bufp->chgCData(oldp+86,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl),3);
        bufp->chgCData(oldp+87,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl),2);
        bufp->chgCData(oldp+88,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl),3);
        bufp->chgCData(oldp+89,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl),3);
        bufp->chgCData(oldp+90,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl),2);
        bufp->chgCData(oldp+91,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl),3);
        bufp->chgCData(oldp+92,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl),2);
        bufp->chgCData(oldp+93,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl),2);
        bufp->chgCData(oldp+94,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl),3);
        bufp->chgCData(oldp+95,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl),2);
        bufp->chgCData(oldp+96,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl),6);
        bufp->chgCData(oldp+97,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl),3);
        bufp->chgCData(oldp+98,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl),4);
        bufp->chgCData(oldp+99,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl),2);
        bufp->chgSData(oldp+100,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left),16);
        bufp->chgSData(oldp+101,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right),16);
        bufp->chgSData(oldp+102,(((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                   ? (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))
                                   : ((4U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                       ? 1U : 0U))),16);
        bufp->chgBit(oldp+103,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in));
        bufp->chgCData(oldp+104,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__daa_reg),8);
        bufp->chgBit(oldp+105,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_lo));
        bufp->chgBit(oldp+106,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_hi));
        bufp->chgBit(oldp+107,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+108,(vlSelfRef.emu__DOT__vid_mono),8);
        bufp->chgBit(oldp+109,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H256_n));
        bufp->chgBit(oldp+110,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hblank_int));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+111,(vlSelfRef.emu__DOT__lamp));
        bufp->chgBit(oldp+112,(vlSelfRef.emu__DOT__lamp2));
        bufp->chgBit(oldp+113,(vlSelfRef.emu__DOT__superbug__DOT__Flash));
        bufp->chgBit(oldp+114,(vlSelfRef.emu__DOT__superbug__DOT__Attract));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgCData(oldp+115,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state),6);
        bufp->chgCData(oldp+116,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl),3);
        bufp->chgCData(oldp+117,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgBit(oldp+118,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch) 
                                      >> 2U))));
        bufp->chgBit(oldp+119,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch) 
                                      >> 1U))));
        bufp->chgBit(oldp+120,((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch))));
        bufp->chgBit(oldp+121,(vlSelfRef.emu__DOT__superbug__DOT__PCC1));
        bufp->chgBit(oldp+122,(vlSelfRef.emu__DOT__superbug__DOT__PCC2));
        bufp->chgBit(oldp+123,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld));
        bufp->chgCData(oldp+124,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD),8);
        bufp->chgBit(oldp+125,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__LoadPd));
        bufp->chgBit(oldp+126,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld))));
        bufp->chgBit(oldp+127,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld))));
        bufp->chgCData(oldp+128,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgBit(oldp+129,(vlSelfRef.emu__DOT__btn_right));
        bufp->chgBit(oldp+130,(vlSelfRef.emu__DOT__btn_left));
        bufp->chgBit(oldp+131,(vlSelfRef.emu__DOT__btn_gas));
        bufp->chgBit(oldp+132,(vlSelfRef.emu__DOT__btn_gearup));
        bufp->chgBit(oldp+133,(vlSelfRef.emu__DOT__btn_geardown));
        bufp->chgBit(oldp+134,(vlSelfRef.emu__DOT__btn_nexttrack));
        bufp->chgBit(oldp+135,(vlSelfRef.emu__DOT__btn_one_player));
        bufp->chgBit(oldp+136,(vlSelfRef.emu__DOT__btn_two_players));
        bufp->chgBit(oldp+137,(vlSelfRef.emu__DOT__btn_start_1));
        bufp->chgBit(oldp+138,(vlSelfRef.emu__DOT__btn_coin_1));
        bufp->chgBit(oldp+139,(vlSelfRef.emu__DOT__btn_coin_2));
        bufp->chgBit(oldp+140,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int));
        bufp->chgBit(oldp+141,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int));
        bufp->chgBit(oldp+142,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)))));
        bufp->chgCData(oldp+143,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg),4);
        bufp->chgBit(oldp+144,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32));
        bufp->chgBit(oldp+145,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8));
        bufp->chgBit(oldp+146,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int));
        bufp->chgBit(oldp+147,(((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int)) 
                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int))));
        bufp->chgBit(oldp+148,(vlSelfRef.emu__DOT__unnamedblk1__DOT__old_state));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[9U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x0000000cU])))) {
        bufp->chgBit(oldp+149,((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)) 
                                      & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                          >> 4U) ^ 
                                         ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                          >> 5U))))));
        bufp->chgBit(oldp+150,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int) 
                                         | (IData)(vlSelfRef.emu__DOT__vsync))))));
        bufp->chgCData(oldp+151,(((0x00000080U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg) 
                                                  << 4U)) 
                                  | ((0x00000060U & 
                                      ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                       >> 1U)) | (0x0000001fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))))),8);
        bufp->chgBit(oldp+152,((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32)) 
                                      & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 6U)))));
        bufp->chgBit(oldp+153,((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8)) 
                                      & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 4U)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x0000000aU]))) {
        bufp->chgSData(oldp+154,(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr),16);
        bufp->chgBit(oldp+155,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en));
        bufp->chgBit(oldp+156,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_0)))));
        bufp->chgBit(oldp+157,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_1)))));
        bufp->chgBit(oldp+158,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select));
        bufp->chgBit(oldp+159,((IData)((0x0400U == 
                                        (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
        bufp->chgBit(oldp+160,((1U & (~ (IData)((0U 
                                                 != 
                                                 (0x1800U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+161,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                                         & (0x0400U 
                                            == (0x0500U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+162,((0U == (0x0000000fU 
                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
                                          >> 8U)))));
        bufp->chgBit(oldp+163,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__RAMwe));
        bufp->chgBit(oldp+164,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0)))));
        bufp->chgBit(oldp+165,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1)))));
        bufp->chgBit(oldp+166,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2)))));
        bufp->chgSData(oldp+167,((0x000007ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))),11);
        bufp->chgCData(oldp+168,((0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))),8);
        bufp->chgCData(oldp+169,((7U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))),3);
        bufp->chgBit(oldp+170,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_Wren));
        bufp->chgBit(oldp+171,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[0x0000000aU] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x0000000dU])))) {
        bufp->chgBit(oldp+172,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                         & (0x0020U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+173,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                         & (0U == (0x00e0U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+174,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                         & (0x00e0U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+175,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                         & (0x0040U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+176,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                         & (0x0060U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+177,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3) 
                                         & (0x0080U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+178,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3) 
                                         & (0x00a0U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+179,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3) 
                                         & (0x00c0U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
        bufp->chgBit(oldp+180,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                         & (0x00c0U 
                                            == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x0000000bU]))) {
        bufp->chgBit(oldp+181,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa) 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb))))));
        bufp->chgBit(oldp+182,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa));
        bufp->chgBit(oldp+183,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb));
        bufp->chgBit(oldp+184,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_H16));
        bufp->chgBit(oldp+185,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_V8));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x0000000cU]))) {
        bufp->chgBit(oldp+186,(vlSelfRef.emu__DOT__vsync));
        bufp->chgBit(oldp+187,((0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
        bufp->chgBit(oldp+188,((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))));
        bufp->chgSData(oldp+189,((0x000001ffU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                                 >> 1U))),9);
        bufp->chgCData(oldp+190,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter),8);
        bufp->chgBit(oldp+191,((0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
        bufp->chgBit(oldp+192,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 9U)))));
        bufp->chgBit(oldp+193,((IData)((6U == (6U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))))));
        bufp->chgBit(oldp+194,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 2U))));
        bufp->chgBit(oldp+195,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 4U))));
        bufp->chgBit(oldp+196,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi)))));
        bufp->chgBit(oldp+197,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi));
        bufp->chgBit(oldp+198,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 1U))));
        bufp->chgBit(oldp+199,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 3U))));
        bufp->chgBit(oldp+200,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 4U))));
        bufp->chgBit(oldp+201,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 5U))));
        bufp->chgBit(oldp+202,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 6U))));
        bufp->chgBit(oldp+203,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 7U))));
        bufp->chgBit(oldp+204,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 8U))));
        bufp->chgBit(oldp+205,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 8U)))));
        bufp->chgBit(oldp+206,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 9U))));
        bufp->chgBit(oldp+207,((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
        bufp->chgBit(oldp+208,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 1U))));
        bufp->chgBit(oldp+209,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 2U))));
        bufp->chgBit(oldp+210,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 3U))));
        bufp->chgBit(oldp+211,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 5U))));
        bufp->chgBit(oldp+212,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 6U))));
        bufp->chgBit(oldp+213,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 7U))));
        bufp->chgBit(oldp+214,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                         >> 7U)))));
        bufp->chgCData(oldp+215,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout),4);
        bufp->chgBit(oldp+216,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Window_en));
        bufp->chgBit(oldp+217,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank));
        bufp->chgBit(oldp+218,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter)))));
        bufp->chgSData(oldp+219,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter),10);
        bufp->chgBit(oldp+220,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 4U)))));
        bufp->chgBit(oldp+221,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 3U)))));
        bufp->chgBit(oldp+222,((0x0150U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x0000000eU]))) {
        bufp->chgBit(oldp+223,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1));
        bufp->chgBit(oldp+224,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0));
        bufp->chgBit(oldp+225,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel));
        bufp->chgBit(oldp+226,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel));
        bufp->chgBit(oldp+227,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel));
        bufp->chgCData(oldp+228,((3U & (~ (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1) 
                                            << 1U) 
                                           | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0))))),2);
        bufp->chgBit(oldp+229,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_CarRot_n));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[0x0000000eU] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x00000010U])))) {
        bufp->chgSData(oldp+230,((((((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                        ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g)
                                        : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g)) 
                                      << 4U) | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g)
                                                   : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g)) 
                                                 << 3U) 
                                                | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g)
                                                     : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g)) 
                                                   << 2U))) 
                                    | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                          ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g)
                                          : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g)) 
                                        << 1U) | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g)
                                                   : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g)))) 
                                   << 5U) | (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g)
                                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g)) 
                                               << 4U) 
                                              | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g)
                                                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g)) 
                                                  << 3U) 
                                                 | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                      ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g)
                                                      : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g)) 
                                                    << 2U))) 
                                             | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g)
                                                   : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g)) 
                                                 << 1U) 
                                                | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g)
                                                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g)))))),10);
        bufp->chgBit(oldp+231,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g))));
        bufp->chgBit(oldp+232,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g))));
        bufp->chgBit(oldp+233,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g))));
        bufp->chgBit(oldp+234,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g))));
        bufp->chgBit(oldp+235,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g))));
        bufp->chgBit(oldp+236,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g))));
        bufp->chgBit(oldp+237,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g))));
        bufp->chgBit(oldp+238,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g))));
        bufp->chgBit(oldp+239,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g))));
        bufp->chgBit(oldp+240,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                 ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g)
                                 : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x0000000fU]))) {
        bufp->chgCData(oldp+241,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD),8);
        bufp->chgCData(oldp+242,((0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD))),4);
        bufp->chgCData(oldp+243,((0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                                                 >> 4U))),4);
        bufp->chgCData(oldp+244,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din),8);
        bufp->chgCData(oldp+245,((0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din) 
                                                 >> 4U))),4);
        bufp->chgCData(oldp+246,((0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din))),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x00000010U]))) {
        bufp->chgBit(oldp+247,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g));
        bufp->chgBit(oldp+248,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g));
        bufp->chgBit(oldp+249,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g));
        bufp->chgBit(oldp+250,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g));
        bufp->chgBit(oldp+251,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g));
        bufp->chgBit(oldp+252,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g));
        bufp->chgBit(oldp+253,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g));
        bufp->chgBit(oldp+254,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g));
        bufp->chgBit(oldp+255,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g));
        bufp->chgBit(oldp+256,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g));
    }
    bufp->chgBit(oldp+257,(vlSelfRef.clk_sys));
    bufp->chgBit(oldp+258,(vlSelfRef.reset));
    bufp->chgBit(oldp+259,(vlSelfRef.soft_reset));
    bufp->chgBit(oldp+260,(vlSelfRef.menu));
    bufp->chgBit(oldp+261,(vlSelfRef.adam));
    bufp->chgIData(oldp+262,(vlSelfRef.joystick_0),32);
    bufp->chgIData(oldp+263,(vlSelfRef.joystick_1),32);
    bufp->chgIData(oldp+264,(vlSelfRef.joystick_2),32);
    bufp->chgIData(oldp+265,(vlSelfRef.joystick_3),32);
    bufp->chgIData(oldp+266,(vlSelfRef.joystick_4),32);
    bufp->chgIData(oldp+267,(vlSelfRef.joystick_5),32);
    bufp->chgSData(oldp+268,(vlSelfRef.joystick_l_analog_0),16);
    bufp->chgSData(oldp+269,(vlSelfRef.joystick_l_analog_1),16);
    bufp->chgSData(oldp+270,(vlSelfRef.joystick_l_analog_2),16);
    bufp->chgSData(oldp+271,(vlSelfRef.joystick_l_analog_3),16);
    bufp->chgSData(oldp+272,(vlSelfRef.joystick_l_analog_4),16);
    bufp->chgSData(oldp+273,(vlSelfRef.joystick_l_analog_5),16);
    bufp->chgSData(oldp+274,(vlSelfRef.joystick_r_analog_0),16);
    bufp->chgSData(oldp+275,(vlSelfRef.joystick_r_analog_1),16);
    bufp->chgSData(oldp+276,(vlSelfRef.joystick_r_analog_2),16);
    bufp->chgSData(oldp+277,(vlSelfRef.joystick_r_analog_3),16);
    bufp->chgSData(oldp+278,(vlSelfRef.joystick_r_analog_4),16);
    bufp->chgSData(oldp+279,(vlSelfRef.joystick_r_analog_5),16);
    bufp->chgCData(oldp+280,(vlSelfRef.paddle_0),8);
    bufp->chgCData(oldp+281,(vlSelfRef.paddle_1),8);
    bufp->chgCData(oldp+282,(vlSelfRef.paddle_2),8);
    bufp->chgCData(oldp+283,(vlSelfRef.paddle_3),8);
    bufp->chgCData(oldp+284,(vlSelfRef.paddle_4),8);
    bufp->chgCData(oldp+285,(vlSelfRef.paddle_5),8);
    bufp->chgSData(oldp+286,(vlSelfRef.spinner_0),9);
    bufp->chgSData(oldp+287,(vlSelfRef.spinner_1),9);
    bufp->chgSData(oldp+288,(vlSelfRef.spinner_2),9);
    bufp->chgSData(oldp+289,(vlSelfRef.spinner_3),9);
    bufp->chgSData(oldp+290,(vlSelfRef.spinner_4),9);
    bufp->chgSData(oldp+291,(vlSelfRef.spinner_5),9);
    bufp->chgSData(oldp+292,(vlSelfRef.ps2_key),11);
    bufp->chgIData(oldp+293,(vlSelfRef.ps2_mouse),25);
    bufp->chgSData(oldp+294,(vlSelfRef.ps2_mouse_ext),16);
    bufp->chgQData(oldp+295,(vlSelfRef.timestamp),33);
    bufp->chgCData(oldp+297,(vlSelfRef.VGA_R),8);
    bufp->chgCData(oldp+298,(vlSelfRef.VGA_G),8);
    bufp->chgCData(oldp+299,(vlSelfRef.VGA_B),8);
    bufp->chgBit(oldp+300,(vlSelfRef.VGA_HS));
    bufp->chgBit(oldp+301,(vlSelfRef.VGA_VS));
    bufp->chgBit(oldp+302,(vlSelfRef.VGA_HB));
    bufp->chgBit(oldp+303,(vlSelfRef.VGA_VB));
    bufp->chgBit(oldp+304,(vlSelfRef.CE_PIXEL));
    bufp->chgSData(oldp+305,(vlSelfRef.AUDIO_L),16);
    bufp->chgSData(oldp+306,(vlSelfRef.AUDIO_R),16);
    bufp->chgSData(oldp+307,(vlSelfRef.dbg_pc),16);
    bufp->chgCData(oldp+308,(vlSelfRef.dbg_opcode),8);
    bufp->chgSData(oldp+309,(vlSelfRef.dbg_addr),16);
    bufp->chgCData(oldp+310,(vlSelfRef.dbg_din),8);
    bufp->chgBit(oldp+311,(vlSelfRef.dbg_op_fetch));
    bufp->chgCData(oldp+312,(vlSelfRef.dbg_acca),8);
    bufp->chgCData(oldp+313,(vlSelfRef.dbg_accb),8);
    bufp->chgCData(oldp+314,(vlSelfRef.dbg_cc),8);
    bufp->chgBit(oldp+315,(vlSelfRef.service_mode));
    bufp->chgBit(oldp+316,(vlSelfRef.ioctl_download));
    bufp->chgBit(oldp+317,(vlSelfRef.ioctl_wr));
    bufp->chgIData(oldp+318,(vlSelfRef.ioctl_addr),25);
    bufp->chgCData(oldp+319,(vlSelfRef.ioctl_dout),8);
    bufp->chgCData(oldp+320,(vlSelfRef.ioctl_index),8);
    bufp->chgBit(oldp+321,(vlSelfRef.ioctl_wait));
    bufp->chgIData(oldp+322,(vlSelfRef.sd_lba[0]),32);
    bufp->chgIData(oldp+323,(vlSelfRef.sd_lba[1]),32);
    bufp->chgSData(oldp+324,(vlSelfRef.sd_rd),10);
    bufp->chgSData(oldp+325,(vlSelfRef.sd_wr),10);
    bufp->chgSData(oldp+326,(vlSelfRef.sd_ack),10);
    bufp->chgSData(oldp+327,(vlSelfRef.sd_buff_addr),9);
    bufp->chgCData(oldp+328,(vlSelfRef.sd_buff_dout),8);
    bufp->chgCData(oldp+329,(vlSelfRef.sd_buff_din[0]),8);
    bufp->chgCData(oldp+330,(vlSelfRef.sd_buff_din[1]),8);
    bufp->chgBit(oldp+331,(vlSelfRef.sd_buff_wr));
    bufp->chgSData(oldp+332,(vlSelfRef.img_mounted),10);
    bufp->chgBit(oldp+333,(vlSelfRef.img_readonly));
    bufp->chgQData(oldp+334,(vlSelfRef.img_size),64);
    bufp->chgBit(oldp+336,((1U & ((IData)(vlSelfRef.ps2_key) 
                                  >> 9U))));
    bufp->chgSData(oldp+337,((0x000001ffU & (IData)(vlSelfRef.ps2_key))),9);
    bufp->chgBit(oldp+338,((1U & (~ (IData)(vlSelfRef.service_mode)))));
    bufp->chgIData(oldp+339,((0x0001ffffU & vlSelfRef.ioctl_addr)),17);
    bufp->chgBit(oldp+340,(vlSelfRef.emu__DOT__superbug__DOT__Phi2));
    bufp->chgBit(oldp+341,(vlSelfRef.emu__DOT__superbug__DOT__CarVideo));
    bufp->chgBit(oldp+342,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo));
    bufp->chgBit(oldp+343,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode) 
                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid))))));
    bufp->chgBit(oldp+344,((1U & (~ ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode) 
                                         | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n))) 
                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid))))));
    bufp->chgBit(oldp+345,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarRot_n));
    bufp->chgCData(oldp+346,(((IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_0)
                               ? (0x0000007eU | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1) 
                                                  << 7U) 
                                                 | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2)))
                               : ((IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_1)
                                   ? (0x000000fcU | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux))
                                   : 0xffU))),8);
    bufp->chgBit(oldp+347,(vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n));
    bufp->chgCData(oldp+348,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr),7);
    bufp->chgBit(oldp+349,(((~ ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                                    & (0x0400U == (0x0500U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) 
                                & (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))) 
                            & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select)))));
    bufp->chgBit(oldp+350,(((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                                & (0x0400U == (0x0500U 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) 
                            & (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))));
    bufp->chgSData(oldp+351,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__rom_m3_addr),10);
    bufp->chgBit(oldp+352,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)))));
    bufp->chgBit(oldp+353,((1U & (~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)) 
                                     | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                        >> 2U))))));
    bufp->chgCData(oldp+354,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din),8);
    bufp->chgCData(oldp+355,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0)
                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout)
                               : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1)
                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout)
                                   : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2)
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout)
                                       : 0xffU)))),8);
    bufp->chgBit(oldp+356,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn));
    bufp->chgBit(oldp+357,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr));
    bufp->chgBit(oldp+358,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn) 
                                     & (0x0260U == 
                                        (0x02e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->chgBit(oldp+359,(((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                >> 4U)) & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__prev_V16))));
    bufp->chgSData(oldp+360,(((3U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                               ? ((0x0000ff00U & ((- (IData)(
                                                             (1U 
                                                              & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                                 >> 7U)))) 
                                                  << 8U)) 
                                  | (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)))
                               : ((6U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                   ? 1U : 0U))),16);
    bufp->chgSData(oldp+361,(((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                               ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                                   : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                       ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din) 
                                           << 8U) | 
                                          (0x000000ffU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)))
                                       : ((0x0000ff00U 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)) 
                                          | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din))))
                               : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                   ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                                       : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))
                                   : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                                       : 0xfffeU)))),16);
    bufp->chgSData(oldp+362,(((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                               ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                   ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)
                                       : ((0x0000ff00U 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                              << 8U)) 
                                          | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)))
                                   : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                                       : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)))
                               : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                   ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)
                                       : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg))
                                   : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)
                                       : 0U)))),16);
    bufp->chgBit(oldp+363,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir));
    bufp->chgBit(oldp+364,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag));
    bufp->chgBit(oldp+365,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1));
    bufp->chgBit(oldp+366,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2));
    bufp->chgCData(oldp+367,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux),2);
    bufp->chgSData(oldp+368,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr),10);
    bufp->chgCData(oldp+369,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP),8);
    bufp->chgCData(oldp+370,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr),8);
    bufp->chgBit(oldp+371,((1U & (~ ((0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
                                     | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM))))));
    bufp->chgBit(oldp+372,((1U & (~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM))))));
    bufp->chgBit(oldp+373,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid));
    bufp->chgBit(oldp+374,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo));
    bufp->chgBit(oldp+375,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                     | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))))));
    bufp->chgBit(oldp+376,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                     | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))))));
    bufp->chgBit(oldp+377,((1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                      | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                  ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)))));
    bufp->chgBit(oldp+378,((1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                      | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                  ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)))));
    bufp->chgBit(oldp+379,((1U & (~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                          | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                      ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                     | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))))));
    bufp->chgBit(oldp+380,((1U & (~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                          | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                      ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                     | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))))));
    bufp->chgBit(oldp+381,((1U & (~ ((~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                              | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                          ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                         | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))) 
                                     | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank))))));
    bufp->chgBit(oldp+382,((1U & (~ ((~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                              | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                          ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                         | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))) 
                                     | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank))))));
    bufp->chgCData(oldp+383,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus),4);
    bufp->chgBit(oldp+384,((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                             >> 9U) & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H256_n))));
    bufp->chgBit(oldp+385,(((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)) 
                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hblank_int))));
}

void Vemu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_cleanup\n"); );
    // Body
    Vemu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vemu___024root*>(voidSelf);
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x0000000aU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x0000000bU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x0000000cU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x0000000dU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x0000000eU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x0000000fU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x00000010U] = 0U;
}
