// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vemu.h for the primary calling header

#include "Vemu__pch.h"

VL_ATTR_COLD void Vemu___024root___eval_static__TOP(Vemu___024root* vlSelf);
VL_ATTR_COLD void Vemu___024root____Vm_traceActivitySetAll(Vemu___024root* vlSelf);

VL_ATTR_COLD void Vemu___024root___eval_static(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_static\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vemu___024root___eval_static__TOP(vlSelf);
    Vemu___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__clk_6__0 
        = vlSelfRef.emu__DOT__clk_6;
    vlSelfRef.__Vtrigprevexpr___TOP__clk_sys__0 = vlSelfRef.clk_sys;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address__0 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CPU__DOT__H2__0 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__H2;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CPU__DOT__Out2_n__0 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Out2_n;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Phi2__0 
        = vlSelfRef.emu__DOT__superbug__DOT__Phi2;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__CarEna_n__0 
        = vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarEna_n;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout__0 
        = vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__R_Sel__0 
        = vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R_Sel;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int__0 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT____Vcellinp__superbug__Steer_1B_I__0 
        = vlSelfRef.emu__DOT____Vcellinp__superbug__Steer_1B_I;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__SteerReset_n__0 
        = vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT____Vcellinp__superbug__Start_I__0 
        = vlSelfRef.emu__DOT____Vcellinp__superbug__Start_I;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__gear1__0 
        = vlSelfRef.emu__DOT__gear1;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__gear3__0 
        = vlSelfRef.emu__DOT__gear3;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__m_next_track__0 
        = vlSelfRef.emu__DOT__m_next_track;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1__0 
        = vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2__0 
        = vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag__0 
        = vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CrashIn_n__0 
        = vlSelfRef.emu__DOT__superbug__DOT__CrashIn_n;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr__0 
        = vlSelfRef.emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__gear2__0 
        = vlSelfRef.emu__DOT__gear2;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__m_gas__0 
        = vlSelfRef.emu__DOT__m_gas;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir__0 
        = vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__HSRes_I__0 
        = vlSelfRef.emu__DOT__superbug__DOT__HSRes_I;
    vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__SkidIn_n__0 
        = vlSelfRef.emu__DOT__superbug__DOT__SkidIn_n;
    vlSelfRef.__Vtrigprevexpr___TOP__service_mode__0 
        = vlSelfRef.service_mode;
}

VL_ATTR_COLD void Vemu___024root___eval_static__TOP(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_static__TOP\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ioctl_wait = 0U;
    vlSelfRef.emu__DOT__btn_right = 0U;
    vlSelfRef.emu__DOT__btn_left = 0U;
    vlSelfRef.emu__DOT__btn_gas = 0U;
    vlSelfRef.emu__DOT__btn_gearup = 0U;
    vlSelfRef.emu__DOT__btn_geardown = 0U;
    vlSelfRef.emu__DOT__btn_nexttrack = 0U;
    vlSelfRef.emu__DOT__btn_one_player = 0U;
    vlSelfRef.emu__DOT__btn_two_players = 0U;
    vlSelfRef.emu__DOT__btn_start_1 = 0U;
    vlSelfRef.emu__DOT__btn_coin_1 = 0U;
    vlSelfRef.emu__DOT__btn_coin_2 = 0U;
    vlSelfRef.emu__DOT__steer1__DOT__state = 0U;
    vlSelfRef.emu__DOT__gearshift1__DOT__gear = 0U;
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__pf_write_count = 0U;
}

VL_ATTR_COLD void Vemu___024root___eval_initial__TOP(Vemu___024root* vlSelf);

VL_ATTR_COLD void Vemu___024root___eval_initial(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_initial\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vemu___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vemu___024root___eval_initial__TOP(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_initial__TOP\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 8, 2048, 0, "../roms/hex/009121d1.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__D1__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 2048, 0, "../roms/hex/009122c1.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__C1__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 2048, 0, "../roms/hex/009123a1.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__A1__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 4, 1024, 0, "../roms/hex/009124m3.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_ROM__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 4, 1024, 0, "../roms/hex/009471n3.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_ROM__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 4, 1024, 0, "../roms/hex/009125k6.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__K6__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 4, 1024, 0, "../roms/hex/009127e5.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 4, 1024, 0, "../roms/hex/009126f5.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 4, 1024, 0, "../roms/hex/009472h5.hex"s
                 ,  &(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vemu___024root___eval_final(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_final\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vemu___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vemu___024root___eval_phase__stl(Vemu___024root* vlSelf);

VL_ATTR_COLD void Vemu___024root___eval_settle(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_settle\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00001770U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vemu___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("sim.v", 5, "", "Settle region did not converge after 6000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vemu___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vemu___024root___eval_triggers__stl(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_triggers__stl\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vemu___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vemu___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vemu___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vemu___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vemu___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vemu___024root___stl_sequent__TOP__0(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___stl_sequent__TOP__0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10;
    emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10 = 0;
    // Body
    vlSelfRef.emu__DOT__sd_lba[0U] = vlSelfRef.sd_lba
        [0U];
    vlSelfRef.emu__DOT__sd_lba[1U] = vlSelfRef.sd_lba
        [1U];
    vlSelfRef.emu__DOT__sd_buff_din[0U] = vlSelfRef.sd_buff_din
        [0U];
    vlSelfRef.emu__DOT__sd_buff_din[1U] = vlSelfRef.sd_buff_din
        [1U];
    vlSelfRef.VGA_R = vlSelfRef.emu__DOT__vid_mono;
    vlSelfRef.VGA_G = vlSelfRef.emu__DOT__vid_mono;
    vlSelfRef.VGA_B = vlSelfRef.emu__DOT__vid_mono;
    vlSelfRef.VGA_HS = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int;
    vlSelfRef.VGA_HB = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int;
    vlSelfRef.VGA_VB = (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter));
    vlSelfRef.CE_PIXEL = (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter));
    vlSelfRef.dbg_pc = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc;
    vlSelfRef.dbg_acca = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca;
    vlSelfRef.dbg_accb = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb;
    vlSelfRef.dbg_cc = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc;
    vlSelfRef.emu__DOT__clk_6 = (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi 
        = ((0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
           & (0U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__H2 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                 >> 2U));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Window_en 
        = (IData)((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 9U) & (~ (IData)((0x01e0U == 
                                         (0x01e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter)))))));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__LoadPd 
        = (IData)((3U == (3U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP))));
    vlSelfRef.dbg_opcode = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code;
    vlSelfRef.emu__DOT____Vcellinp__superbug__Steer_1B_I 
        = (1U & (IData)(vlSelfRef.emu__DOT__steer));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 4U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset 
        = ((IData)(vlSelfRef.ioctl_download) | (IData)(vlSelfRef.reset));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address 
        = ((0x00000080U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg) 
                           << 4U)) | ((0x00000060U 
                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                          >> 1U)) | 
                                      (0x0000001fU 
                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD 
        = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q) 
            << 4U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank 
        = (1U & (~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)) 
                    & (0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Flash) 
                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__PFWndo))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                    ^ VL_REDXOR_8((0x18U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g 
        = (1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                     >> 5U)) ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g 
        = (1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                     >> 3U)) ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 4U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                    >> 2U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 3U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                    >> 1U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 2U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                 ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 1U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R_Sel 
        = (3U & (~ (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1) 
                     << 1U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarEna_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa) 
                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl = 2U;
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo 
        = (IData)((((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__ShiftData) 
                      >> 3U) & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 9U))) & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int))) 
                   & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                       >> 4U) ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                 >> 5U))));
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__rom_m3_addr 
        = ((0x000003c0U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout) 
                           << 6U)) | ((0x0000003cU 
                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                          << 2U)) | 
                                      (3U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                             >> 3U))));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr 
        = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q) 
            << 6U) | ((0x0000003cU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP) 
                                      << 2U)) | (3U 
                                                 & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP) 
                                                    >> 2U))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl = 2U;
    vlSelfRef.emu__DOT__vsync = ((0xf2U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
                                 & (0xf4U >= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 4U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 3U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 3U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit = 0U;
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld 
        = (1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n) 
                     & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode)) 
                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n)))) 
                 & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift) 
                       | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n)))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 1U;
    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                  >> 5U)))) {
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 5U;
            }
        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                    if (((6U == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                >> 4U))) 
                         || (7U == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                   >> 4U))))) {
                        if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                                    }
                                } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                                }
                            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                                }
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                            }
                        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                            } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                            }
                        } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                            }
                        } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                        }
                    }
                }
            }
        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 4U;
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 3U;
            } else if ((6U != (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 4U)))) {
                if ((0x0aU == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 4U)))) {
                    if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                    } else if ((0x0dU != (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        if ((0x0fU == (0x0000000fU 
                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                        }
                    }
                } else if ((0x0eU == (0x0000000fU & 
                                      ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                       >> 4U)))) {
                    if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                    } else if ((0x0dU == (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                    } else if ((0x0fU == (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((7U != (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                           >> 4U)))) {
                    if ((0x0bU == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 4U)))) {
                        if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                        } else if ((0x0dU != (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            if ((0x0fU == (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                            }
                        }
                    } else if ((0x0fU == (0x0000000fU 
                                          & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                             >> 4U)))) {
                        if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                        } else if ((0x0dU == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                        } else if ((0x0fU == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 2U;
                        }
                    }
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl 
                    = ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                        ? ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                            ? ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? 3U : ((0x00000010U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((7U == 
                                             (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                             ? 2U : 
                                            ((0x0dU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                              ? 2U : 
                                             ((0x0fU 
                                               == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                               ? 2U
                                               : 3U)))
                                         : 3U)) : (
                                                   (0x00000020U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 3U
                                                    : 
                                                   ((0x00000010U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                     ? 
                                                    ((7U 
                                                      == 
                                                      (0x0000000fU 
                                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                      ? 2U
                                                      : 
                                                     ((0x0fU 
                                                       == 
                                                       (0x0000000fU 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                       ? 2U
                                                       : 3U))
                                                     : 3U)))
                        : 3U);
            }
        } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 0U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl 
                            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 1U : 0U);
                    }
                }
            }
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 3U;
                        }
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 4U;
                    }
                }
            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((((3U == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                          || (0x0cU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                         || (0x0eU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 4U;
                                    }
                                } else if ((0x00000010U 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((((3U == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                          || (0x0cU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                         || (0x0eU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 4U;
                                    }
                                }
                            } else if ((0x00000020U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((((3U == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                      || (0x0eU == 
                                          (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                     || (0x0cU == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 4U;
                                }
                            } else if ((0x00000010U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((((3U == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                      || (0x0eU == 
                                          (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                     || (0x0cU == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 4U;
                                }
                            }
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 2U;
                    }
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl 
                    = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 6U : 5U) : 0U);
            }
        }
    }
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
    vlSelfRef.emu__DOT__joy = (0x0000ffffU & (vlSelfRef.joystick_0 
                                              | vlSelfRef.joystick_1));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
    if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        }
                    }
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 5U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 4U;
                    }
                }
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x0cU;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x0cU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x39U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 8U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 6U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 7U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 5U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                    }
                }
            } else {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x38U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 4U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x35U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 5U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
                        }
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    } else {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        }
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 4U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 3U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                    }
                } else {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 2U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2fU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 8U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
                }
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 5U;
                        }
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 3U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 2U;
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 2U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 3U;
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 4U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2dU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 5U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x30U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 4U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2bU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 3U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                }
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 2U;
                    }
                }
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
            } else {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2eU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 2U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2cU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 6U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
                } else {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2aU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 6U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x3aU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x19U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                }
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
            }
        } else {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    }
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                ? 0x3aU : ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                                  & (~ 
                                                     ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                      >> 4U))))
                                            ? 0x28U
                                            : 0x27U));
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 6U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x1aU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x24U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x26U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 2U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req)
                                ? 0x3aU : ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                                  & (~ 
                                                     ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                      >> 4U))))
                                            ? 0x28U
                                            : ((0x3eU 
                                                == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x27U
                                                : (
                                                   (0x3fU 
                                                    == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x3aU
                                                    : 0x29U))));
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 6U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x25U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 5U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x23U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 4U;
                    }
                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x22U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 8U;
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x21U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                }
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
            }
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            if (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                 & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl = 3U;
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl 
                                    = (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req)) 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack))
                                        ? 0U : 2U);
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl 
                                    = ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                  >> 4U))))
                                        ? 4U : 1U);
                            }
                        }
                    } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl 
                            = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req)
                                ? 3U : ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 4U))))
                                         ? 4U : ((0x3eU 
                                                  == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 1U
                                                  : 
                                                 ((0x3fU 
                                                   == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 2U
                                                   : 1U))));
                    }
                }
            }
        }
    } else {
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        }
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 4U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x1fU;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 5U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 8U;
                        }
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 5U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x1bU;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 8U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x1dU;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                        }
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x18U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 8U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                    }
                } else {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x1aU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 4U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 2U;
                    }
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                    = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 1U : 0x17U) : ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                  ? 0x16U
                                                  : 0x15U))
                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 0x14U : 0x13U) : 
                           ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                             ? 0x12U : 0x11U)));
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 0U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
            }
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit 
                    = ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                 >> 5U))) && ((1U & 
                                               ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                                >> 4U)) 
                                              && ((1U 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                                       >> 3U))) 
                                                  && (1U 
                                                      & ((4U 
                                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                          ? 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                           ? 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                            ? 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 7U)
                                                            : 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 6U))
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                            ? 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 5U)
                                                            : 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 4U)))
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                           ? 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                            ? 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 3U)
                                                            : 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 2U))
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                            ? 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                            >> 1U)
                                                            : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))))))));
                if (vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 7U)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 6U)))) {
                                    if ((0x00000020U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((0x00000010U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 2U)))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                                                        }
                                                    } else {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 1U)))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 6U)))) {
                                if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 0U;
                    }
                }
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 6U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 6U;
                    } else if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 6U;
                    } else if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 6U;
                        }
                    } else if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                      >> 4U)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 6U;
                        }
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                ? 1U : ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 4U))))
                                         ? 1U : 6U))
                            : 0U);
                }
            }
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x10U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x21U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x0fU;
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x0eU;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x0cU;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                        }
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 1U : (((6U == (0x0000000fU 
                                             & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                >> 4U))) 
                                     || (7U == (0x0000000fU 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                   >> 4U))))
                                     ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 8U
                                                  : 1U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 1U
                                                  : 8U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 1U
                                                  : 8U)
                                                 : 8U))
                                         : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 8U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 1U
                                                  : 8U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 8U
                                                  : 1U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 1U
                                                  : 8U))))
                                     : 1U));
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        if (((6U == (0x0000000fU & 
                                     ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                      >> 4U))) || (7U 
                                                   == 
                                                   (0x0000000fU 
                                                    & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                       >> 4U))))) {
                            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x0cU;
                                        } else {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                        }
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                            = ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 9U
                                                : 0x0aU);
                                    }
                                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    }
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x25U
                                            : 0x0bU);
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x15U
                                            : 0x17U);
                                }
                            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x16U
                                            : 0x14U);
                                } else {
                                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    }
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x25U
                                            : 0x18U);
                                }
                            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x0eU;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                }
                            } else {
                                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                }
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 0x25U : 0x0dU);
                            }
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 3U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                        }
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                } else {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 8U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 1U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 3U;
                }
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            if (((6U == (0x0000000fU 
                                         & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                            >> 4U))) 
                                 || (7U == (0x0000000fU 
                                            & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                               >> 4U))))) {
                                if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                        }
                                    }
                                }
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 0U;
                            }
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl 
                            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 1U : 2U);
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((0x00000020U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((((3U == 
                                              (0x0000000fU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                             || (0x0cU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                            || (0x0eU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))
                                            ? 6U : 0x0aU)
                                        : ((0x00000010U 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((((3U 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                                 || (0x0cU 
                                                     == 
                                                     (0x0000000fU 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                                || (0x0eU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))
                                                ? 6U
                                                : 0x0aU)
                                            : 1U)) : 
                                   ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                     ? ((((3U == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                          || (0x0eU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                         || (0x0cU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))
                                         ? 6U : 1U)
                                     : ((0x00000010U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((((3U == 
                                               (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                              || (0x0eU 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                             || (0x0cU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))
                                             ? 6U : 1U)
                                         : 1U))) : 
                               ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                 ? ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                     ? 0x0aU : 1U) : 1U));
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 2U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = ((6U == (0x0000000fU 
                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 4U))) ? 
                               ((0x0bU == (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                 ? 1U : ((0x0eU == 
                                          (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                          ? 0x18U : 5U))
                                : ((0x0aU == (0x0000000fU 
                                              & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                 >> 4U)))
                                    ? ((7U == (0x0000000fU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                        ? 8U : ((0x0dU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                 ? 0x19U
                                                 : 
                                                ((0x0fU 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                  ? 9U
                                                  : 5U)))
                                    : ((0x0eU == (0x0000000fU 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 4U)))
                                        ? ((7U == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 8U : 
                                           ((0x0dU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                             ? 9U : 
                                            ((0x0fU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                              ? 9U : 5U)))
                                        : 1U)));
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            if ((6U != (0x0000000fU 
                                        & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                           >> 4U)))) {
                                if ((0x0aU == (0x0000000fU 
                                               & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 4U)))) {
                                    if ((7U == (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x22U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                            = ((0x0dU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                ? 0x25U
                                                : (
                                                   (0x0fU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 0x24U
                                                    : 0x25U));
                                        if ((0x0dU 
                                             != (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                            if ((0x0fU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                            }
                                        }
                                    }
                                } else if ((0x0eU == 
                                            (0x0000000fU 
                                             & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                >> 4U)))) {
                                    if ((7U == (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x22U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                                    } else if ((0x0dU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                                    } else if ((0x0fU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = ((7U == (0x0000000fU 
                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 4U))) ? 
                               ((0x0bU == (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                 ? 1U : ((0x0eU == 
                                          (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                          ? 0x18U : 5U))
                                : ((0x0bU == (0x0000000fU 
                                              & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                 >> 4U)))
                                    ? ((7U == (0x0000000fU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                        ? 8U : ((0x0dU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                 ? 0x19U
                                                 : 
                                                ((0x0fU 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                  ? 9U
                                                  : 5U)))
                                    : ((0x0fU == (0x0000000fU 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 4U)))
                                        ? ((7U == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 8U : 
                                           ((0x0dU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                             ? 9U : 
                                            ((0x0fU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                              ? 9U : 5U)))
                                        : 1U)));
                        if ((7U != (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                   >> 4U)))) {
                            if ((0x0bU == (0x0000000fU 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 4U)))) {
                                if ((7U == (0x0000000fU 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x22U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((0x0dU == 
                                            (0x0000000fU 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 0x25U
                                            : ((0x0fU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                ? 0x24U
                                                : 0x25U));
                                    if ((0x0dU != (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        if ((0x0fU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                        }
                                    }
                                }
                            } else if ((0x0fU == (0x0000000fU 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 4U)))) {
                                if ((7U == (0x0000000fU 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x22U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                                } else if ((0x0dU == 
                                            (0x0000000fU 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                                } else if ((0x0fU == 
                                            (0x0000000fU 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                }
                            }
                        }
                    } else if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                                = ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((0x00000010U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 3U : 4U) : 
                                   ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                     ? ((7U == (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                         ? 8U : ((0x0dU 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                  ? 9U
                                                  : 
                                                 ((0x0fU 
                                                   == 
                                                   (0x0000000fU 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                   ? 9U
                                                   : 5U)))
                                     : ((((3U == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) 
                                          || (0x0cU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) 
                                         || (0x0eU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))))
                                         ? 7U : 1U)));
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 5U)))) {
                                if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((7U == (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x22U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                                    } else if ((0x0dU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                                    } else if ((0x0fU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                    }
                                }
                            }
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                                = ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((0x00000010U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 3U : 4U) : 
                                   ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                     ? ((7U == (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                         ? 8U : ((0x0fU 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                  ? 9U
                                                  : 
                                                 ((0x0dU 
                                                   == 
                                                   (0x0000000fU 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                   ? 0x19U
                                                   : 5U)))
                                     : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 1U
                                                  : 7U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 0x1cU
                                                  : 7U))
                                             : 1U) : 
                                        ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                          ? 1U : ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 7U
                                                    : 1U)
                                                   : 1U)))));
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 5U)))) {
                                if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((7U == (0x0000000fU 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x22U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                                    } else if ((0x0fU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                    }
                                }
                            }
                        }
                    } else if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? 3U : 4U) : 1U);
                        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                      >> 5U)))) {
                            if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x0cU
                                                    : 0x25U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 9U
                                                    : 0x0aU))
                                            : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x25U
                                                    : 0x0bU)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x15U
                                                    : 0x17U)))
                                        : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x16U
                                                    : 0x14U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x25U
                                                    : 0x18U))
                                            : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x0eU
                                                    : 0x25U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x25U
                                                    : 0x0dU))));
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x0cU
                                                    : 0x25U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 9U
                                                    : 0x0aU))
                                            : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x25U
                                                    : 0x0bU)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x15U
                                                    : 0x17U)))
                                        : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x16U
                                                    : 0x14U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x25U
                                                    : 0x18U))
                                            : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x0eU
                                                    : 0x25U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x25U
                                                    : 0x0dU))));
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                            }
                        }
                    } else if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x20U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x0dU;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x37U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                    }
                                } else {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2aU;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                        } else {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                        }
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                                            = ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x1eU
                                                : 0x36U);
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                    }
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                                }
                            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x34U
                                            : 0x32U);
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 4U : 5U);
                                }
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                                    = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x33U
                                            : 0x31U)
                                        : 1U);
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                            }
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                                = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                        >> 2U) 
                                                       | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                           >> 3U) 
                                                          ^ 
                                                          ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                           >> 1U))))
                                                    ? 0x1bU
                                                    : 1U)
                                                : (
                                                   (1U 
                                                    & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                        >> 2U) 
                                                       | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                           >> 3U) 
                                                          ^ 
                                                          ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                           >> 1U))))
                                                    ? 1U
                                                    : 0x1bU))
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & VL_REDXOR_4(
                                                                  (0x0aU 
                                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                    ? 0x1bU
                                                    : 1U)
                                                : (
                                                   (1U 
                                                    & VL_REDXOR_4(
                                                                  (0x0aU 
                                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                    ? 1U
                                                    : 0x1bU)))
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 0x1bU
                                                    : 1U)
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 1U
                                                    : 0x1bU))
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 0x1bU
                                                    : 1U)
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 1U
                                                    : 0x1bU))))
                                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (4U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 0x1bU
                                                    : 1U)
                                                : (
                                                   (4U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 1U
                                                    : 0x1bU))
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 0x1bU
                                                    : 1U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                    ? 1U
                                                    : 0x1bU)))
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? ((IData)(
                                                           (0U 
                                                            != 
                                                            (5U 
                                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                    ? 0x1bU
                                                    : 1U)
                                                : ((IData)(
                                                           (0U 
                                                            != 
                                                            (5U 
                                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                    ? 1U
                                                    : 0x1bU))
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 1U
                                                : 0x1bU))));
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 0x25U : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                     ? 0U
                                                     : 0x25U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                     ? 0x26U
                                                     : 0x25U)))
                                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x21U
                                                : 0x22U)
                                            : 0x25U)
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x25U
                                            : 1U)));
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x19U
                                            : 0x1aU)
                                        : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x1bU
                                            : 0x1cU))
                                    : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x1dU
                                            : 0x1eU)
                                        : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x10U
                                            : 0x0fU)));
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 1U)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                }
                            }
                        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 0x1fU : 0x20U)
                                    : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 0x13U : 0x12U));
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 1U)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                            }
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                        }
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 1U;
                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                        = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                            & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                            ? 0x20U : ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                  >> 4U))))
                                        ? 0x20U : 2U));
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                            = ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x24U
                                                : 0x23U);
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                            = ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x24U
                                                : 0x23U);
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                                    }
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0U
                                                : 7U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 4U
                                                : 8U));
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                                }
                            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x22U
                                            : 0x21U)
                                        : 6U);
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 5U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                                }
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                            }
                        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x24U
                                            : 0x23U);
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x25U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x11U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                                }
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0U : 7U)
                                        : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 4U : 8U));
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                            }
                        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? 0x22U : 0x21U)
                                    : 6U);
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                        } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 5U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                            }
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 1U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                        }
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 1U;
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x3aU;
                }
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 7U)))) {
                                if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 5U)))) {
                                        if ((0x00000010U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    } else {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (2U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    if (
                                                        (1U 
                                                         & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                } else {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                }
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                    } else {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                } else {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                            } else {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                } else {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                        }
                                    }
                                } else {
                                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 5U)))) {
                                        if ((0x00000010U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 2U)))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                    } else {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                            >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                } else {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                }
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                                } else {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                            } else {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                            }
                                        }
                                    }
                                    if ((0x00000020U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((0x00000010U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 3U;
                                                        }
                                                    }
                                                } else {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl 
                                                        = 
                                                        ((2U 
                                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                           ? 2U
                                                           : 3U)
                                                          : 2U);
                                                }
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 1U)))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                }
                                            } else {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                            }
                                        }
                                    } else if ((0x00000010U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 3U;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 1U)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        } else {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                        } else {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        } else {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                }
                            } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    } else if ((1U 
                                                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                }
                            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                }
                            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                }
                            } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                            }
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 0U;
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 0U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 0U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 0U;
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 7U)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 6U)))) {
                                    if ((0x00000020U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((0x00000010U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 2U)))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 1U;
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                            >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                    >> 4U)))) {
                                        if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                         >> 1U)))) {
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 0U;
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl 
                            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                    & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                    ? 1U : (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req)) 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack))
                                             ? 0U : 2U))
                                : 0U);
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl = 0U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.dbg_op_fetch = (1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl));
    vlSelfRef.VGA_VS = vlSelfRef.emu__DOT__vsync;
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld) 
           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_off 
        = ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
            ? (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))
            : ((4U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                ? 1U : 0U));
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD 
        = (0x000000ffU & ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                           ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                               ? 0U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                        ? 0U : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                                 ? 0U
                                                 : 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc) 
                                                 >> 8U))))
                           : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                               ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                   ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                                       : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                   : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                       ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg) 
                                          >> 8U) : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg)))
                               : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                   ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                       ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)
                                       : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca))
                                   : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl))
                                       ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md) 
                                          >> 8U) : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md))))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right 
        = ((1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl))
            ? 0U : ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl))
                     ? 1U : ((3U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl))
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left 
        = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl))
            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md)
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg)))
            : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md)
                    : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca) 
                        << 8U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)))
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca))));
    vlSelfRef.emu__DOT__m_gas = (1U & ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                       | ((IData)(vlSelfRef.emu__DOT__joy) 
                                          >> 4U)));
    vlSelfRef.emu__DOT__m_next_track = (1U & (((IData)(vlSelfRef.emu__DOT__joy) 
                                               >> 7U) 
                                              | (IData)(vlSelfRef.emu__DOT__btn_nexttrack)));
    vlSelfRef.emu__DOT__m_start1 = (1U & ((IData)(vlSelfRef.emu__DOT__btn_one_player) 
                                          | ((IData)(vlSelfRef.emu__DOT__joy) 
                                             >> 7U)));
    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw 
            = ((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl) 
                      >> 1U)) || (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl)));
        vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr 
            = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                    ? (0x0000fff9U | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv) 
                                      << 1U)) : (0x0000fff8U 
                                                 | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv) 
                                                    << 1U)))
                : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp));
    } else {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw 
            = ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl) 
                         >> 1U))) || (1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))));
        vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr 
            = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                    : 0xffffU));
    }
    vlSelfRef.emu__DOT__superbug__DOT__VMA = ((1U & 
                                               ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl) 
                                                >> 2U)) 
                                              || ((1U 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl) 
                                                      >> 1U)) 
                                                  || (1U 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in 
        = ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                     >> 5U))) && ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                                            >> 3U))) 
                                  && ((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                                             >> 2U)) 
                                      && ((1U & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                                                  >> 1U))) 
                                          && (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_lo 
        = (9U >= (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_hi 
        = (9U >= (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                 >> 4U)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__daa_reg 
        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
            ? ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                ? 0x66U : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_lo)
                            ? 0x60U : 0x66U)) : ((0x00000020U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                  ? 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_hi)
                                                   ? 6U
                                                   : 0x66U)
                                                  : 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_lo)
                                                   ? 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_hi)
                                                    ? 0U
                                                    : 0x60U)
                                                   : 
                                                  ((8U 
                                                    >= 
                                                    (0x0000000fU 
                                                     & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                        >> 4U)))
                                                    ? 6U
                                                    : 0x66U))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu 
        = (0x0000ffffU & ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                           ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)
                               : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)
                                   : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                       ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)
                                               : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__daa_reg)))
                                           : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                       : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)
                                               : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                           : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)
                                               : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))))
                           : ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                               ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                   ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                       ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                               : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                           : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                       : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)
                                           : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)
                                               : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in) 
                                                   << 0x0000000fU) 
                                                  | (0x00007fffU 
                                                     & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                        >> 1U))))))
                                   : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                       ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? ((0x0000fffeU 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                      << 1U)) 
                                                  | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                               : ((0x00000080U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)) 
                                                  | (0x0000007fU 
                                                     & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                        >> 1U))))
                                           : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? ((0x0000fffeU 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                      << 1U)) 
                                                  | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                               : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in) 
                                                   << 7U) 
                                                  | (0x0000007fU 
                                                     & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                        >> 1U)))))
                                       : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? ((0x0000fffeU 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                      << 1U)) 
                                                  | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                               : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in) 
                                                   << 0x0000000fU) 
                                                  | (0x00007fffU 
                                                     & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                        >> 1U))))
                                           : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                               - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                              - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in)))))
                               : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                   ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                       ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                                  + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                               : (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)))
                                           : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                  - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                               : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)))
                                       : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                                  - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                               : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                                  + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in)))
                                           : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left)
                                               : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)))))
                                   : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                       ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right))
                                               : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)))
                                           : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                               ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                                  - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                               : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                                  + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))))
                                       : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                           ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                               - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                              - (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))
                                           : (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                               + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                              + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in))))))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0xfeU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (1U & ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                     ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                         ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                         : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                             ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                             : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                 ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                         : (6U == (0x0000000fU 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__daa_reg) 
                                                      >> 4U))))
                                     : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                 : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                     : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                         : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))))
                     : ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                         ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                             ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                 ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                     : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                                        && (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                 : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                                        || (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)))
                                     : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                         : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))
                             : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                 ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                        >> 7U) : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                 : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                            >> 0x0fU)
                                         : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                     : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                         : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                             ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                 ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))) 
                                        || (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)))
                                     : (0U != (0x000000ffU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu))))
                                 : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                     : ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))) 
                                        && (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)))))
                             : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                 ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc)
                                     : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  >> 7U)) 
                                              & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                 >> 7U)) 
                                             | ((~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  >> 7U)) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 7U))) 
                                            | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)) 
                                               >> 7U))
                                         : (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                              >> 7U) 
                                             | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                 >> 7U) 
                                                & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                    >> 7U)))) 
                                            | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                >> 7U) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 7U))))))
                                 : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                     ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  >> 0x0fU)) 
                                              & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                 >> 0x0fU)) 
                                             | ((~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  >> 0x0fU)) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 0x0fU))) 
                                            | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)) 
                                               >> 0x0fU))
                                         : (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                              >> 0x0fU) 
                                             | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                 >> 0x0fU) 
                                                & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                    >> 0x0fU)))) 
                                            | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                >> 0x0fU) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 0x0fU)))))
                                     : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  >> 7U)) 
                                              & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                 >> 7U)) 
                                             | ((~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                  >> 7U)) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 7U))) 
                                            | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)) 
                                               >> 7U))
                                         : (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                              >> 7U) 
                                             | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                 >> 7U) 
                                                & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                    >> 7U)))) 
                                            | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                >> 7U) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 7U))))))))))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0xfbU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (4U & (((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                      ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                          ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                             >> 2U) : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                        ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                           >> 2U) : 
                                       ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                             ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                >> 2U)
                                             : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                 ? 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                 >> 2U)
                                                 : 
                                                (~ 
                                                 (0U 
                                                  != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))
                                         : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                 ? 
                                                (~ 
                                                 (0U 
                                                  != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))
                                                 : 
                                                (~ 
                                                 (0U 
                                                  != 
                                                  (0x000000ffU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                 ? 
                                                (~ 
                                                 (0U 
                                                  != 
                                                  (0x000000ffU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu))))
                                                 : 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                 >> 2U))))))
                      : ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                          ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                     >> 2U) : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 2U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                    ? 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    (0U 
                                                     != 
                                                     (0x000000ffU 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))))
                              : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? (~ (0U != (0x000000ffU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu))))
                                  : (~ (0U != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))
                          : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (~ (0U 
                                                != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))
                                          : (~ (0U 
                                                != 
                                                (0x000000ffU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))
                                      : (~ (0U != (0x000000ffU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))
                                  : (~ (0U != (0x000000ffU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))))
                              : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? (~ (0U != (0x000000ffU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu))))
                                  : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? (~ (0U != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)))
                                      : (~ (0U != (0x000000ffU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu))))))))) 
                    << 2U)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0xf7U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (8U & (((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                      ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                          ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                             >> 3U) : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                        ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                           >> 3U) : 
                                       ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                             ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                >> 3U)
                                             : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                 ? 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                 >> 3U)
                                                 : 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                 >> 0x0fU)))
                                         : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                 ? 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                 >> 0x0fU)
                                                 : 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                 >> 7U))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                 ? 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                 >> 7U)
                                                 : 
                                                ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                 >> 3U))))))
                      : ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                          ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                     >> 3U) : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 3U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                    ? 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                    >> 3U)
                                                    : 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                    >> 7U))))
                              : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                     >> 7U) : ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 0x0fU)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                    ? 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                    >> 0x0fU)
                                                    : 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                    >> 3U)))))
                          : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                             >> 3U)
                                          : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                             >> 7U))
                                      : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                         >> 7U)) : 
                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                  >> 7U)) : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                              ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                 >> 7U)
                                              : ((2U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                  ? 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 0x0fU)
                                                  : 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 7U)))))) 
                    << 3U)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0xefU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (((0x19U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
               || ((0x1aU != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                   && (1U & ((0x20U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                 >> 4U) : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                           >> 4U))))) 
              << 4U));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0xdfU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (0x00000020U & ((((0U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                               || (4U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)))
                               ? (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                    >> 3U) | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                               >> 3U) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 3U)))) 
                                  | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                      >> 3U) & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 3U))))
                               : ((0x20U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                   ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                      >> 5U) : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                >> 5U))) 
                             << 5U)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0xfdU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (2U & (((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                      ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                          ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                             >> 1U) : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                        ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                           >> 1U) : 
                                       ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                         ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                             ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                >> 1U)
                                             : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                                                && (1U 
                                                    & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                       >> 1U))))
                                         : ((1U & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                                                    >> 1U))) 
                                            && ((1U 
                                                 & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))) 
                                                && (1U 
                                                    & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                       >> 1U)))))))
                      : ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                          ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                                         && (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 1U)))
                                      : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                                         || (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 1U))))
                                  : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                         >> 1U) : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                    ? 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                    >> 1U)
                                                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))
                              : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                              >> 7U) 
                                             ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 6U))
                                          : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                             ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 7U)))
                                      : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                              >> 7U) 
                                             ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 6U))
                                          : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                             ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                  : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                              >> 0x0fU) 
                                             ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 0x0eU))
                                          : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))
                                      : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 0x0fU) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                   >> 0x0fU))) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 0x0fU))) 
                                             | (((~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   >> 0x0fU)) 
                                                 & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                    >> 0x0fU)) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 0x0fU)))
                                          : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                             >> 1U)))))
                          : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                              ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl)) 
                                         && (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                   >> 1U)))
                                      : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (IData)(
                                                    (0x0080U 
                                                     == 
                                                     (0x00ffU 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))
                                          : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                             >> 1U)))
                                  : ((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                                            >> 1U)) 
                                     && (1U & ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                ? (IData)(
                                                          (0x0080U 
                                                           == 
                                                           (0x00ffU 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))
                                                : (IData)(
                                                          (0x007fU 
                                                           == 
                                                           (0x00ffU 
                                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left))))))))
                              : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                  ? ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl) 
                                               >> 1U))) 
                                     && (1U & ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                                ? (
                                                   ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                      >> 7U) 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                         >> 7U))) 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                        >> 7U))) 
                                                   | (((~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                         >> 7U)) 
                                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                          >> 7U)) 
                                                      & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                         >> 7U)))
                                                : (
                                                   ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                                     >> 7U) 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                        >> 7U))) 
                                                   | (((~ 
                                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                         >> 7U)) 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                           >> 7U))) 
                                                      & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                         >> 7U))))))
                                  : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                      ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 0x0fU) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                   >> 0x0fU))) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 0x0fU))) 
                                             | (((~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   >> 0x0fU)) 
                                                 & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                    >> 0x0fU)) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 0x0fU)))
                                          : (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                               >> 0x0fU) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 0x0fU))) 
                                             | (((~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   >> 0x0fU)) 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                     >> 0x0fU))) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 0x0fU))))
                                      : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                                          ? (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                >> 7U) 
                                               & (~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                   >> 7U))) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 7U))) 
                                             | (((~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   >> 7U)) 
                                                 & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                    >> 7U)) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 7U)))
                                          : (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right)) 
                                               >> 7U) 
                                              & (~ 
                                                 ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                  >> 7U))) 
                                             | (((~ 
                                                  ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                                   >> 7U)) 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right) 
                                                     >> 7U))) 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                                   >> 7U))))))))) 
                    << 1U)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out 
        = ((0x3fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)) 
           | (((0x20U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl))
                ? ((2U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                          >> 6U)) | (1U & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                            >> 6U) 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                              >> 6U))))
                : ((2U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                          >> 6U)) | (1U & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                            >> 6U) 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left) 
                                              >> 6U))))) 
              << 6U));
    vlSelfRef.emu__DOT____Vcellinp__superbug__Start_I 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__m_start1) 
                    | (IData)(vlSelfRef.emu__DOT__btn_start_1))));
    vlSelfRef.emu__DOT__m_coin = (1U & ((IData)(vlSelfRef.emu__DOT__m_start1) 
                                        | ((IData)(vlSelfRef.emu__DOT__btn_two_players) 
                                           | ((IData)(vlSelfRef.emu__DOT__joy) 
                                              >> 8U))));
    vlSelfRef.dbg_addr = vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr;
    vlSelfRef.emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr 
        = (7U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__RAMwe 
        = ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
           & (0U == (0x0f00U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__VMA) 
           & (0x0400U == (0x1d00U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__VMA) 
           & (0x0800U == (0x1800U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__VMA) 
           & (0x1000U == (0x1800U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__VMA) 
           & (0x1800U == (0x1800U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en 
        = ((~ (IData)((0U != (0x1800U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) 
           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__VMA));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2 
        = ((IData)(vlSelfRef.emu__DOT__m_coin) | (IData)(vlSelfRef.emu__DOT__btn_coin_2));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1 
        = ((IData)(vlSelfRef.emu__DOT__m_coin) | (IData)(vlSelfRef.emu__DOT__btn_coin_1));
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select)
            ? (0x0000001fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))
            : ((0x00000010U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                               >> 2U)) | (0x0000000fU 
                                          & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                             >> 4U))));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
           & (0x0500U == (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2));
    emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
              >> 9U));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_Wren 
        = ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM)));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din 
        = (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM))
            ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD)
            : 0xffU);
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr 
        = (0x000000ffU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM)
                           ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr)
                           : ((0x000000f0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP)) 
                              | (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP) 
                                                >> 4U)))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Out2_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn) 
                    & (0x0260U == (0x02e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn) 
           & ((~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)) 
                  | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                     >> 2U))) & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw))));
    vlSelfRef.__VdfgRegularize_h4af1c392_0_0 = ((IData)(emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10) 
                                                & (0U 
                                                   == 
                                                   (0x00e0U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.__VdfgRegularize_h4af1c392_0_1 = ((IData)(emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10) 
                                                & (0x0040U 
                                                   == 
                                                   (0x00e0U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr) 
           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
              >> 9U));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr) 
           & (0x0100U == (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din 
        = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0) 
            | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1) 
               | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2)))
            ? ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0)
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout)
                : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1)
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout)
                    : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2)
                        ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout)
                        : 0xffU))) : ((IData)(((0U 
                                                == 
                                                (0x0f00U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))) 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)))
                                       ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q) 
                                           << 4U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q))
                                       : ((1U & ((~ (IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_0)) 
                                                 & (~ (IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_1))))
                                           ? 0xffU : 
                                          ((IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_0)
                                            ? (0x0000007eU 
                                               | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1) 
                                                   << 7U) 
                                                  | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2)))
                                            : ((IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_1)
                                                ? (0x000000fcU 
                                                   | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux))
                                                : 0xffU)))));
    vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                    & (0x00a0U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarRot_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                    & (0x0080U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
    vlSelfRef.dbg_din = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_base 
        = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                    ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din) 
                        << 8U) | (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)))
                    : ((0x0000ff00U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)) 
                       | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din))))
            : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                    : 0xfffeU)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_base 
        = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)
                    : ((0x0000ff00U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                       << 8U)) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)))
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)))
            : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg))
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)
                    : 0U)));
}

VL_ATTR_COLD void Vemu___024root___eval_stl(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_stl\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vemu___024root___stl_sequent__TOP__0(vlSelf);
        Vemu___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vemu___024root___eval_phase__stl(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_phase__stl\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vemu___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vemu___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vemu___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vemu___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vemu___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vemu___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vemu___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vemu___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vemu___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge emu.clk_6)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge clk_sys)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( emu.superbug.Vid_sync.prom_address)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge emu.superbug.CPU.H2)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge emu.superbug.CPU.Out2_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge emu.superbug.Phi2)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( emu.superbug.Car.CarEna_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @( emu.superbug.Car.CarROM_Dout)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @( emu.superbug.Car.R_Sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(posedge emu.superbug.Vid_sync.hsync_int)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(posedge emu.__Vcellinp__superbug__Steer_1B_I)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(negedge emu.superbug.SteerReset_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @( emu.__Vcellinp__superbug__Start_I)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @( emu.gear1)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @( emu.gear3)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @( emu.m_next_track)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @( emu.superbug.ControlInputs.Coin1)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @( emu.superbug.ControlInputs.Coin2)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 18 is active: @( emu.superbug.ControlInputs.SteerFlag)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 19 is active: @( emu.superbug.CrashIn_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 20 is active: @( emu.superbug.__Vcellinp__ControlInputs__Adr)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 21 is active: @( emu.gear2)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 22 is active: @( emu.m_gas)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 23 is active: @( emu.superbug.ControlInputs.SteerDir)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 24 is active: @( emu.superbug.HSRes_I)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 25 is active: @( emu.superbug.SkidIn_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 26 is active: @( service_mode)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vemu___024root____Vm_traceActivitySetAll(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root____Vm_traceActivitySetAll\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x0000000aU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x0000000bU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x0000000cU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x0000000dU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x0000000eU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x0000000fU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x00000010U] = 1U;
}

VL_ATTR_COLD void Vemu___024root___ctor_var_reset(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___ctor_var_reset\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_sys = 0;
    vlSelf->reset = 0;
    vlSelf->soft_reset = 0;
    vlSelf->menu = 0;
    vlSelf->adam = 0;
    vlSelf->joystick_0 = 0;
    vlSelf->joystick_1 = 0;
    vlSelf->joystick_2 = 0;
    vlSelf->joystick_3 = 0;
    vlSelf->joystick_4 = 0;
    vlSelf->joystick_5 = 0;
    vlSelf->joystick_l_analog_0 = 0;
    vlSelf->joystick_l_analog_1 = 0;
    vlSelf->joystick_l_analog_2 = 0;
    vlSelf->joystick_l_analog_3 = 0;
    vlSelf->joystick_l_analog_4 = 0;
    vlSelf->joystick_l_analog_5 = 0;
    vlSelf->joystick_r_analog_0 = 0;
    vlSelf->joystick_r_analog_1 = 0;
    vlSelf->joystick_r_analog_2 = 0;
    vlSelf->joystick_r_analog_3 = 0;
    vlSelf->joystick_r_analog_4 = 0;
    vlSelf->joystick_r_analog_5 = 0;
    vlSelf->paddle_0 = 0;
    vlSelf->paddle_1 = 0;
    vlSelf->paddle_2 = 0;
    vlSelf->paddle_3 = 0;
    vlSelf->paddle_4 = 0;
    vlSelf->paddle_5 = 0;
    vlSelf->spinner_0 = 0;
    vlSelf->spinner_1 = 0;
    vlSelf->spinner_2 = 0;
    vlSelf->spinner_3 = 0;
    vlSelf->spinner_4 = 0;
    vlSelf->spinner_5 = 0;
    vlSelf->ps2_key = 0;
    vlSelf->ps2_mouse = 0;
    vlSelf->ps2_mouse_ext = 0;
    vlSelf->timestamp = 0;
    vlSelf->VGA_R = 0;
    vlSelf->VGA_G = 0;
    vlSelf->VGA_B = 0;
    vlSelf->VGA_HS = 0;
    vlSelf->VGA_VS = 0;
    vlSelf->VGA_HB = 0;
    vlSelf->VGA_VB = 0;
    vlSelf->CE_PIXEL = 0;
    vlSelf->AUDIO_L = 0;
    vlSelf->AUDIO_R = 0;
    vlSelf->dbg_pc = 0;
    vlSelf->dbg_opcode = 0;
    vlSelf->dbg_addr = 0;
    vlSelf->dbg_din = 0;
    vlSelf->dbg_op_fetch = 0;
    vlSelf->dbg_acca = 0;
    vlSelf->dbg_accb = 0;
    vlSelf->dbg_cc = 0;
    vlSelf->service_mode = 0;
    vlSelf->ioctl_download = 0;
    vlSelf->ioctl_wr = 0;
    vlSelf->ioctl_addr = 0;
    vlSelf->ioctl_dout = 0;
    vlSelf->ioctl_index = 0;
    vlSelf->ioctl_wait = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->sd_lba[__Vi0] = 0;
    }
    vlSelf->sd_rd = 0;
    vlSelf->sd_wr = 0;
    vlSelf->sd_ack = 0;
    vlSelf->sd_buff_addr = 0;
    vlSelf->sd_buff_dout = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->sd_buff_din[__Vi0] = 0;
    }
    vlSelf->sd_buff_wr = 0;
    vlSelf->img_mounted = 0;
    vlSelf->img_readonly = 0;
    vlSelf->img_size = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->emu__DOT__sd_lba[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->emu__DOT__sd_buff_din[__Vi0] = 0;
    }
    vlSelf->emu__DOT__joy = 0;
    vlSelf->emu__DOT__UART_CTS = 0;
    vlSelf->emu__DOT__UART_RTS = 0;
    vlSelf->emu__DOT__UART_RXD = 0;
    vlSelf->emu__DOT__UART_TXD = 0;
    vlSelf->emu__DOT__UART_DTR = 0;
    vlSelf->emu__DOT__UART_DSR = 0;
    vlSelf->emu__DOT__btn_right = 0;
    vlSelf->emu__DOT__btn_left = 0;
    vlSelf->emu__DOT__btn_gas = 0;
    vlSelf->emu__DOT__btn_gearup = 0;
    vlSelf->emu__DOT__btn_geardown = 0;
    vlSelf->emu__DOT__btn_nexttrack = 0;
    vlSelf->emu__DOT__btn_one_player = 0;
    vlSelf->emu__DOT__btn_two_players = 0;
    vlSelf->emu__DOT__btn_start_1 = 0;
    vlSelf->emu__DOT__btn_coin_1 = 0;
    vlSelf->emu__DOT__btn_coin_2 = 0;
    vlSelf->emu__DOT__m_gas = 0;
    vlSelf->emu__DOT__m_next_track = 0;
    vlSelf->emu__DOT__m_start1 = 0;
    vlSelf->emu__DOT__m_coin = 0;
    vlSelf->emu__DOT__steer = 0;
    vlSelf->emu__DOT__gear1 = 0;
    vlSelf->emu__DOT__gear2 = 0;
    vlSelf->emu__DOT__gear3 = 0;
    vlSelf->emu__DOT__vsync = 0;
    vlSelf->emu__DOT__audio = 0;
    vlSelf->emu__DOT__lamp = 0;
    vlSelf->emu__DOT__lamp2 = 0;
    vlSelf->emu__DOT____Vcellinp__superbug__Steer_1B_I = 0;
    vlSelf->emu__DOT____Vcellinp__superbug__Start_I = 0;
    vlSelf->emu__DOT__clk_6 = 0;
    vlSelf->emu__DOT__locked = 0;
    vlSelf->emu__DOT__vid_mono = 0;
    vlSelf->emu__DOT__sprint_vid = 0;
    vlSelf->emu__DOT__unnamedblk1__DOT__old_state = 0;
    vlSelf->emu__DOT__steer1__DOT__state = 0;
    vlSelf->emu__DOT__steer1__DOT__unnamedblk1__DOT__count = 0;
    vlSelf->emu__DOT__gearshift1__DOT__gear = 0;
    vlSelf->emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up = 0;
    vlSelf->emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_down = 0;
    vlSelf->emu__DOT__superbug__DOT__HSRes_I = 0;
    vlSelf->emu__DOT__superbug__DOT__Phi2 = 0;
    vlSelf->emu__DOT__superbug__DOT__PCC1 = 0;
    vlSelf->emu__DOT__superbug__DOT__PCC2 = 0;
    vlSelf->emu__DOT__superbug__DOT__PFWndo = 0;
    vlSelf->emu__DOT__superbug__DOT__Flash = 0;
    vlSelf->emu__DOT__superbug__DOT__CarVideo = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU_Adr = 0;
    vlSelf->emu__DOT__superbug__DOT__VMA = 0;
    vlSelf->emu__DOT__superbug__DOT__CrashIn_n = 0;
    vlSelf->emu__DOT__superbug__DOT__SkidIn_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Attract = 0;
    vlSelf->emu__DOT__superbug__DOT__SteerReset_n = 0;
    vlSelf->emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__vblank_int = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_reset = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32 = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8 = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H256_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hblank_int = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__Reset = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__H2 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU_Din = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__RAMwe = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__IRQ_n = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__SysEn = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__rw = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__IO_Wr = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__Out2_n = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__nmi = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__prev_V16 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11 = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_base = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_off = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_base = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__daa_reg = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_lo = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_hi = 0;
    vlSelf->emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit = 0;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__CPU__DOT__D1__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__CPU__DOT__C1__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__CPU__DOT__A1__DOT__mem[__Vi0] = 0;
    }
    vlSelf->emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo = 0;
    vlSelf->emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__BD = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__Sys_en = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout2 = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__Mux_select = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__ShiftData = 0;
    vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__rom_m3_addr = 0;
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__M3_ROM__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Alpha__DOT__N3_ROM__DOT__mem[__Vi0] = 0;
    }
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__CarRot_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__CarEna_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__R1 = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__R0 = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__V16g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__V8g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__V4g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__V2g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__V1g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__H16g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__H8g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__H4g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__H2g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__H1g = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__M7Qa = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__M7Qb = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__BD2_Sel = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__BD3_Sel = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__BD4_Sel = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__R_Sel = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__prev_H16 = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__prev_V8 = 0;
    vlSelf->emu__DOT__superbug__DOT__Car__DOT__prev_CarRot_n = 0;
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Car__DOT__K6__DOT__mem[__Vi0] = 0;
    }
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PD = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PVP = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PHP = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PF_Wren = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PD_en = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__CrashCode = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__VidShift = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__LoadPd = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__Window_en = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__pf_write_count = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__prev_VBlank_arrow = 0;
    vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__prev_H8_pfwndo = 0;
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__E5__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__F5__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__H5__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem[__Vi0] = 0;
    }
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1 = 0;
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2 = 0;
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir = 0;
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag = 0;
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1 = 0;
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2 = 0;
    vlSelf->emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux = 0;
    vlSelf->__VdfgRegularize_h4af1c392_0_0 = 0;
    vlSelf->__VdfgRegularize_h4af1c392_0_1 = 0;
    vlSelf->__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter = 0;
    vlSelf->__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter = 0;
    vlSelf->__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__clk_6__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk_sys__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CPU__DOT__H2__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CPU__DOT__Out2_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Phi2__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__CarEna_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__R_Sel__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT____Vcellinp__superbug__Steer_1B_I__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__SteerReset_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT____Vcellinp__superbug__Start_I__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__gear1__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__gear3__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__m_next_track__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CrashIn_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__gear2__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__m_gas__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__HSRes_I__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__SkidIn_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__service_mode__0 = 0;
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
