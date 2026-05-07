// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vemu.h for the primary calling header

#include "Vemu__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vemu___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vemu___024root___eval_triggers__ico(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_triggers__ico\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vemu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vemu___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___trigger_anySet__ico\n"); );
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

void Vemu___024root___ico_sequent__TOP__0(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___ico_sequent__TOP__0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset 
        = ((IData)(vlSelfRef.ioctl_download) | (IData)(vlSelfRef.reset));
    vlSelfRef.emu__DOT__joy = (0x0000ffffU & (vlSelfRef.joystick_0 
                                              | vlSelfRef.joystick_1));
    vlSelfRef.emu__DOT__m_gas = (1U & ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                       | ((IData)(vlSelfRef.emu__DOT__joy) 
                                          >> 4U)));
    vlSelfRef.emu__DOT__m_next_track = (1U & (((IData)(vlSelfRef.emu__DOT__joy) 
                                               >> 7U) 
                                              | (IData)(vlSelfRef.emu__DOT__btn_nexttrack)));
    vlSelfRef.emu__DOT__m_start1 = (1U & ((IData)(vlSelfRef.emu__DOT__btn_one_player) 
                                          | ((IData)(vlSelfRef.emu__DOT__joy) 
                                             >> 7U)));
    vlSelfRef.emu__DOT____Vcellinp__superbug__Start_I 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__m_start1) 
                    | (IData)(vlSelfRef.emu__DOT__btn_start_1))));
    vlSelfRef.emu__DOT__m_coin = (1U & ((IData)(vlSelfRef.emu__DOT__m_start1) 
                                        | ((IData)(vlSelfRef.emu__DOT__btn_two_players) 
                                           | ((IData)(vlSelfRef.emu__DOT__joy) 
                                              >> 8U))));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2 
        = ((IData)(vlSelfRef.emu__DOT__m_coin) | (IData)(vlSelfRef.emu__DOT__btn_coin_2));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1 
        = ((IData)(vlSelfRef.emu__DOT__m_coin) | (IData)(vlSelfRef.emu__DOT__btn_coin_1));
}

void Vemu___024root___eval_ico(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_ico\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vemu___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

bool Vemu___024root___eval_phase__ico(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_phase__ico\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vemu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vemu___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vemu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vemu___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vemu___024root___eval_triggers__act(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_triggers__act\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((((IData)(vlSelfRef.service_mode) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__service_mode__0)) 
                                                         << 0x0000000aU) 
                                                        | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__SkidIn_n) 
                                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__SkidIn_n__0)) 
                                                            << 9U) 
                                                           | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__HSRes_I) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__HSRes_I__0)) 
                                                              << 8U))) 
                                                       | (((((((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.emu__DOT__m_gas) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__m_gas__0)) 
                                                                << 2U)) 
                                                            | ((((IData)(vlSelfRef.emu__DOT__gear2) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__gear2__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT____Vcellinp__ControlInputs__Adr__0)))) 
                                                           << 4U) 
                                                          | (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CrashIn_n) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CrashIn_n__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag__0)) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1) 
                                                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1__0)))))) 
                                                      << 0x00000010U) 
                                                     | ((((((((IData)(vlSelfRef.emu__DOT__m_next_track) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__m_next_track__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.emu__DOT__gear3) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__gear3__0)) 
                                                               << 2U)) 
                                                           | ((((IData)(vlSelfRef.emu__DOT__gear1) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__gear1__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.emu__DOT____Vcellinp__superbug__Start_I) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT____Vcellinp__superbug__Start_I__0)))) 
                                                          << 0x0000000cU) 
                                                         | ((((((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__SteerReset_n__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.emu__DOT____Vcellinp__superbug__Steer_1B_I) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT____Vcellinp__superbug__Steer_1B_I__0))) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int__0))) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R_Sel) 
                                                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__R_Sel__0)))) 
                                                            << 8U)) 
                                                        | (((((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarEna_n) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Car__DOT__CarEna_n__0)) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Phi2__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Out2_n) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CPU__DOT__Out2_n__0))))) 
                                                            << 4U) 
                                                           | (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__H2) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__CPU__DOT__H2__0))) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address) 
                                                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address__0)) 
                                                                  << 2U)) 
                                                              | ((((IData)(vlSelfRef.clk_sys) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_sys__0))) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.emu__DOT__clk_6) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__emu__DOT__clk_6__0))))))))));
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
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered[0U] = (4ULL | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000040ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000080ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000100ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000001000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000002000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000004000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000008000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000010000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000020000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000040000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000080000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000100000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000200000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000400000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000800000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000001000000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000002000000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000004000000ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vemu___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vemu___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___trigger_anySet__act\n"); );
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

void Vemu___024root___act_sequent__TOP__0(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___act_sequent__TOP__0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((((((((0U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state)) 
               | (1U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) 
              | (2U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) 
             | (3U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) 
            | (4U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) 
           | (5U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) 
          | (6U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) 
         | (7U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state)))) {
        if ((0U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 0U;
            if ((1U & ((IData)(vlSelfRef.emu__DOT__btn_left) 
                       | ((IData)(vlSelfRef.emu__DOT__joy) 
                          >> 1U)))) {
                vlSelfRef.emu__DOT__steer1__DOT__state = 1U;
            }
            if ((1U & ((IData)(vlSelfRef.emu__DOT__btn_right) 
                       | (IData)(vlSelfRef.emu__DOT__joy)))) {
                vlSelfRef.emu__DOT__steer1__DOT__state = 5U;
            }
        } else if ((1U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 0U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 2U;
        } else if ((2U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 1U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 3U;
        } else if ((3U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 3U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 4U;
        } else if ((4U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 2U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 0U;
        } else if ((5U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 0U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 6U;
        } else if ((6U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
            vlSelfRef.emu__DOT__steer = 2U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 7U;
        } else {
            vlSelfRef.emu__DOT__steer = 3U;
            vlSelfRef.emu__DOT__steer1__DOT__state = 8U;
        }
    } else if ((8U == (IData)(vlSelfRef.emu__DOT__steer1__DOT__state))) {
        vlSelfRef.emu__DOT__steer = 1U;
        vlSelfRef.emu__DOT__steer1__DOT__state = 0U;
    }
    if (vlSelfRef.emu__DOT__m_coin) {
        vlSelfRef.emu__DOT__gearshift1__DOT__gear = 0U;
    }
    if ((1U & ((IData)(vlSelfRef.emu__DOT__btn_gearup) 
               | ((IData)(vlSelfRef.emu__DOT__joy) 
                  >> 5U)))) {
        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up)))) {
            if ((4U > (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear))) {
                vlSelfRef.emu__DOT__gearshift1__DOT__gear 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear)));
            }
            vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up = 1U;
        }
    } else {
        vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up = 0U;
    }
    if ((1U & ((IData)(vlSelfRef.emu__DOT__btn_geardown) 
               | ((IData)(vlSelfRef.emu__DOT__joy) 
                  >> 6U)))) {
        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_down)))) {
            if ((0U < (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear))) {
                vlSelfRef.emu__DOT__gearshift1__DOT__gear 
                    = (7U & ((IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear) 
                             - (IData)(1U)));
            }
            vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_down = 1U;
        }
    } else {
        vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up = 0U;
    }
    if ((0U == (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear))) {
        vlSelfRef.emu__DOT__gear1 = 0U;
        vlSelfRef.emu__DOT__gear2 = 1U;
        vlSelfRef.emu__DOT__gear3 = 1U;
    } else if ((1U == (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear))) {
        vlSelfRef.emu__DOT__gear1 = 1U;
        vlSelfRef.emu__DOT__gear2 = 0U;
        vlSelfRef.emu__DOT__gear3 = 1U;
    } else if ((2U == (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear))) {
        vlSelfRef.emu__DOT__gear1 = 1U;
        vlSelfRef.emu__DOT__gear2 = 1U;
        vlSelfRef.emu__DOT__gear3 = 0U;
    } else if ((3U == (IData)(vlSelfRef.emu__DOT__gearshift1__DOT__gear))) {
        vlSelfRef.emu__DOT__gear1 = 1U;
        vlSelfRef.emu__DOT__gear2 = 1U;
        vlSelfRef.emu__DOT__gear3 = 1U;
    }
    vlSelfRef.emu__DOT____Vcellinp__superbug__Steer_1B_I 
        = (1U & (IData)(vlSelfRef.emu__DOT__steer));
}

void Vemu___024root___eval_act(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_act\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vemu___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void Vemu___024root___nba_sequent__TOP__0(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PHP;
    __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PHP = 0;
    CData/*3:0*/ __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0;
    __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0;
    __VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0;
    __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0;
    __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0;
    __VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0;
    __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0;
    __VdlyVal__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 = 0;
    CData/*6:0*/ __VdlyDim0__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0;
    __VdlyDim0__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0;
    __VdlySet__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0;
    __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0;
    __VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0;
    __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0;
    __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0;
    __VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0;
    __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 = 0;
    // Body
    __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 = 0U;
    __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 = 0U;
    __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 = 0U;
    __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 = 0U;
    __VdlySet__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 = 0U;
    __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PHP 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP;
    vlSelfRef.emu__DOT__steer1__DOT__unnamedblk1__DOT__count = 0x000057e4U;
    if (vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_Wren) {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__pf_write_count 
            = ((IData)(1U) + vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__pf_write_count);
        __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 
            = (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din) 
                              >> 4U));
        __VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 
            = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr;
        __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0 = 1U;
        __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 
            = (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din));
        __VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 
            = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr;
        __VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__LoadPd) {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift 
            = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout)
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout)));
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n 
            = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD) 
                     >> 3U));
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode 
            = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD) 
                     >> 4U));
    } else {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift 
            = (7U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift) 
                     >> 1U));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__ShiftData 
        = ((IData)((6U == (6U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))))
            ? ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout)
                : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout))
            : (0x0000000eU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__ShiftData) 
                              << 1U)));
    if (vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__RAMwe) {
        __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 
            = (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD));
        __VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 
            = (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr));
        __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0 = 1U;
        __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 
            = (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                              >> 4U));
        __VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 
            = (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr));
        __VdlySet__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0 = 1U;
    }
    if (((~ ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                 & (0x0400U == (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) 
             & (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))) 
         & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select)))) {
        __VdlyVal__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 
            = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD;
        __VdlyDim0__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 
            = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr;
        __VdlySet__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
         & (0U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) {
        __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PHP 
            = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD;
    } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)))) {
        __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PHP 
            = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP)));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr];
    if ((0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))) {
        vlSelfRef.emu__DOT__superbug__DOT__PFWndo = 0U;
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n = 1U;
    } else if ((1U & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                       >> 4U) & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_H8_pfwndo))))) {
        vlSelfRef.emu__DOT__superbug__DOT__PFWndo = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Window_en;
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n 
            = (1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Window_en)));
    }
    if (vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int) {
        if (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                 >> 4U)) & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__prev_V16))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n = 0U;
        }
    } else {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n = 1U;
    }
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__D1__DOT__mem
        [(0x000007ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))];
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__C1__DOT__mem
        [(0x000007ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))];
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__A1__DOT__mem
        [(0x000007ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))];
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem
        [(0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))];
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem
        [(0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))];
    if (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
         & (0x00e0U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n = 1U;
    } else if (((0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_VBlank_arrow)))) {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n = 0U;
    }
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP 
        = __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PHP;
    if (__VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0) {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem[__VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0] 
            = __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__E6__DOT__mem__v0;
    }
    if (__VdlySet__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem[__VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0] 
            = __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__M1__DOT__mem__v0;
    }
    if (__VdlySet__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem[__VdlyDim0__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0] 
            = __VdlyVal__emu__DOT__superbug__DOT__CPU__DOT__N1__DOT__mem__v0;
    }
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr];
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr];
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr];
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr];
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_ROM__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__rom_m3_addr];
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_ROM__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__rom_m3_addr];
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem
        [vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr];
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_H8_pfwndo 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                 >> 4U));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__prev_V16 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                 >> 4U));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_VBlank_arrow 
        = (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter));
    if (__VdlySet__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0) {
        vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem[__VdlyDim0__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0] 
            = __VdlyVal__emu__DOT__superbug__DOT__Playfield__DOT__F6__DOT__mem__v0;
    }
    if (__VdlySet__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0) {
        vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem[__VdlyDim0__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0] 
            = __VdlyVal__emu__DOT__superbug__DOT__Alpha__DOT__P3_RAM__DOT__mem__v0;
    }
}

extern const VlUnpacked<CData/*1:0*/, 32> Vemu__ConstPool__TABLE_h19b76b16_0;

void Vemu___024root___nba_sequent__TOP__1(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__1\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*0:0*/ __Vdly__emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack;
    __Vdly__emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack = 0;
    // Body
    __Vdly__emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack 
        = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack;
    __Vdly__emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack 
        = ((1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl)) 
           || ((0U != (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl)) 
               && (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca 
        = (0x000000ffU & ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl))
                           ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca)
                           : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl))
                               ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl))
                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                                   : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu) 
                                      >> 8U)) : ((1U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl))
                                                  ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)
                                                  : 0U))));
    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg 
            = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg;
    } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg 
            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl))
                ? ((0x00ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg)) 
                   | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din) 
                      << 8U)) : ((0xff00U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg)) 
                                 | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)));
    } else {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg 
            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)
                : 0U);
    }
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md 
        = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl))
            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl))
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md)
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl))
                    ? (0x0000fffeU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md) 
                                      << 1U)) : ((0x0000ff00U 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md) 
                                                     << 8U)) 
                                                 | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din))))
            : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu))
                : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl))
                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md)
                    : 0U)));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc 
        = ((0U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl))
            ? 0xd0U : ((1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl))
                        ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out)
                        : ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl))
                            ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                            : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb 
        = ((0U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl))
            ? 0U : (0x000000ffU & ((1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl))
                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)
                                    : ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl))
                                        ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                                        : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code 
        = ((0U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl))
            ? 1U : ((1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl))
                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din)
                     : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)));
    __Vtableidx2 = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv) 
                     << 3U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv 
        = Vemu__ConstPool__TABLE_h19b76b16_0[__Vtableidx2];
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp 
        = ((0U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl))
            ? 0U : ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl))
                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu)
                     : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp)));
    if (vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req = 0U;
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state = 0U;
    } else {
        if (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi) 
             & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req = 1U;
        } else if (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi)) 
                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req = 0U;
        }
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state 
            = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state;
    }
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc 
        = (0x0000ffffU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_base) 
                          + ((3U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                              ? ((0x0000ff00U & ((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                                >> 7U)))) 
                                                 << 8U)) 
                                 | (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)))
                              : ((6U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                  ? 1U : 0U))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack 
        = __Vdly__emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack;
    vlSelfRef.dbg_acca = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca;
    vlSelfRef.dbg_cc = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc;
    vlSelfRef.dbg_accb = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb;
    vlSelfRef.dbg_opcode = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 4U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl = 2U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl = 2U;
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
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 0U;
    vlSelfRef.dbg_pc = vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea 
        = (0x0000ffffU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_base) 
                          + (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_off)));
    vlSelfRef.dbg_op_fetch = (1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl));
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
                        }
                    }
                }
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                    = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 0U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                 ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                     ? 0U : 8U) : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                    ? 7U
                                                    : 5U)));
            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 4U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 5U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                } else {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 4U : 3U);
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                }
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                    = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 3U : 2U);
            } else {
                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                }
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                    = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 2U : 8U);
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
            }
        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 7U : 5U);
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 4U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 3U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                    = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 2U : 6U);
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 6U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x19U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 1U;
            }
        } else {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    }
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 6U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x1aU;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 2U : 6U);
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                    = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 5U : 4U) : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                           ? 8U : 7U));
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
            }
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl 
                                = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                    & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                    ? 1U : (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req)) 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack))
                                             ? 0U : 2U));
                        }
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
                        }
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 7U : 8U);
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 8U : 7U);
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                    }
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 0U : 8U);
                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 7U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 3U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 2U;
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 0U;
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
            }
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x21U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl = 0x24U;
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                            = (((6U == (0x0000000fU 
                                        & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                           >> 4U))) 
                                || (7U == (0x0000000fU 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 4U))))
                                ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x0cU
                                                : 0x25U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 9U
                                                : 0x0aU))
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x25U
                                                : 0x0bU)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x15U
                                                : 0x17U)))
                                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x16U
                                                : 0x14U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x25U
                                                : 0x18U))
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x0eU
                                                : 0x25U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x25U
                                                : 0x0dU))))
                                : 0x25U);
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 1U : 0U);
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
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((7U == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 0x22U
                                            : ((0x0dU 
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
                                                    : 0x25U)));
                                } else if ((0x0eU == 
                                            (0x0000000fU 
                                             & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                >> 4U)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((7U == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 0x22U
                                            : ((0x0dU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                ? 0x24U
                                                : (
                                                   (0x0fU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 0x24U
                                                    : 0x25U)));
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((7U != (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                   >> 4U)))) {
                            if ((0x0bU == (0x0000000fU 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 4U)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((7U == (0x0000000fU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                        ? 0x22U : (
                                                   (0x0dU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 0x25U
                                                    : 
                                                   ((0x0fU 
                                                     == 
                                                     (0x0000000fU 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                     ? 0x24U
                                                     : 0x25U)));
                            } else if ((0x0fU == (0x0000000fU 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 4U)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((7U == (0x0000000fU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                        ? 0x22U : (
                                                   (0x0dU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 0x24U
                                                    : 
                                                   ((0x0fU 
                                                     == 
                                                     (0x0000000fU 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                     ? 0x24U
                                                     : 0x25U)));
                            }
                        }
                    } else if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                          >> 5U)))) {
                                if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                        = ((7U == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 0x22U
                                            : ((0x0dU 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                ? 0x24U
                                                : (
                                                   (0x0fU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 0x24U
                                                    : 0x25U)));
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                             >> 5U)))) {
                            if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                    = ((7U == (0x0000000fU 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                        ? 0x22U : (
                                                   (0x0fU 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 0x24U
                                                    : 0x25U));
                            }
                        }
                    } else if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                      >> 5U)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                = ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
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
                                                    : 0x0dU))))
                                    : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
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
                                                    : 0x0dU)))));
                        }
                    } else if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                                = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x25U
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 2U
                                                : 0x25U))
                                        : 2U) : ((4U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 0x25U
                                                   : 3U)
                                                  : 2U));
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                            = ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
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
                                            : 1U)))
                                : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x19U
                                                : 0x1aU)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x1bU
                                                : 0x1cU))
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x1dU
                                                : 0x1eU)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x10U
                                                : 0x0fU)))
                                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x1fU
                                                : 0x20U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x13U
                                                : 0x12U))
                                        : 0x25U)));
                    }
                } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl = 0U;
                    if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl 
                            = ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x24U
                                                : 0x23U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x24U
                                                : 0x23U))
                                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0U
                                                : 7U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 4U
                                                : 8U)))
                                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x22U
                                                : 0x21U)
                                            : 6U) : 
                                       ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? 2U : 5U)
                                         : 1U))) : 
                               ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                 ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                     ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? 0x24U
                                             : 0x23U)
                                         : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? 0x25U
                                             : 0x11U))
                                     : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? 0U : 7U)
                                         : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? 4U : 8U)))
                                 : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                     ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? 0x22U
                                             : 0x21U)
                                         : 6U) : ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 3U
                                                    : 5U)
                                                   : 1U))));
                    }
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
                                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
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
                                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((0x00000020U 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((0x00000010U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((4U 
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
                                            if ((1U 
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
                                } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                    >> 1U)))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 2U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl = 0U;
                        }
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
                    }
                }
            }
        }
    }
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right 
        = ((1U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl))
            ? 0U : ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl))
                     ? 1U : ((3U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl))
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md))));
    if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
            }
        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
            }
        } else {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
            }
        } else {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
        }
    } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl 
                    = (((6U == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                               >> 4U))) 
                        || (7U == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 4U))))
                        ? 3U : 2U);
            }
        }
    } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                if ((6U != (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                           >> 4U)))) {
                    if ((0x0aU == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                  >> 4U)))) {
                        if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                        } else if ((0x0dU != (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            if ((0x0fU == (0x0000000fU 
                                           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                            }
                        }
                    } else if ((0x0eU == (0x0000000fU 
                                          & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                             >> 4U)))) {
                        if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                        } else if ((0x0dU == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                        } else if ((0x0fU == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                        }
                    }
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
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                    } else if ((0x0dU != (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        if ((0x0fU == (0x0000000fU 
                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                        }
                    }
                } else if ((0x0fU == (0x0000000fU & 
                                      ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                       >> 4U)))) {
                    if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                    } else if ((0x0dU == (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                    } else if ((0x0fU == (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                    }
                }
            }
        } else if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                              >> 5U)))) {
                    if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 1U;
                        } else if ((0x0dU == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
                        } else if ((0x0fU == (0x0000000fU 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                 >> 5U)))) {
                if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                    if ((7U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
                    } else if ((0x0fU == (0x0000000fU 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 5U;
                    }
                }
            }
        } else if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                          >> 5U)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl 
                    = ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                        ? 1U : 0U);
            }
        } else if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl 
                    = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                        ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? 5U : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? 0U : 5U))
                            : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? 5U : 4U) : 5U))
                        : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? 5U : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? 4U : 5U))
                            : 5U));
            }
        } else if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 0U;
        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                              >> 1U)))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 4U;
                }
            }
        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                          >> 1U)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl = 2U;
            }
        }
    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl 
                = ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                    ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                        ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? 4U : 2U) : 1U) : 
                       ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                         ? 1U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                  ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                      ? 2U : 1U) : 1U)))
                    : ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                        ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                            ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                ? 5U : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? 0U : 4U))
                            : 0U) : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                      ? 0U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 2U
                                                   : 0U)
                                               : 0U))));
        }
    }
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
    if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl 
            = ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                ? ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 0U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                 ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                     ? 0U : 6U) : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                    ? 7U
                                                    : 4U)))
                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 4U : 5U) : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                               ? 5U
                                               : 4U))
                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 5U : 4U) : 5U))) : 
               ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                 ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                     ? 5U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                              ? 5U : 0U)) : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                              ? ((2U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                   ? 0U
                                                   : 4U)
                                                  : 4U)
                                              : 4U)));
    } else if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl 
            = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                    ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 5U : 4U) : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                       ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                           ? 0U : 4U)
                                       : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                           ? 4U : 0U)))
                : 0U);
    } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl 
            = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                ? 0U : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                         ? 0U : 3U));
    } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl 
            = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                    ? 1U : 2U) : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                   ? 2U : 0U));
    } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 1U;
    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl = 1U;
    }
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw 
        = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
            ? ((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl) 
                      >> 1U)) || (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl)))
            : ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl) 
                         >> 1U))) || (1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl)))));
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
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_off 
        = ((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
            ? (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))
            : ((4U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                ? 1U : 0U));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 4U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 3U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 3U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit = 0U;
    if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
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
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 2U;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 3U;
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 2U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 3U)))) {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit 
                = ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                             >> 5U))) && ((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                                 >> 4U)) 
                                          && ((1U & 
                                               (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
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
    } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
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
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                }
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                            }
                        } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                            }
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                        }
                    } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                        } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                        }
                    } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                         >> 2U)))) {
        if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                              >> 7U)))) {
                    if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                      >> 5U)))) {
                            if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            if ((1U 
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
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
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
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                        } else {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    }
                                } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                }
                            } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
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
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    }
                                } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                }
                            } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                }
                            } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                         >> 5U)))) {
                        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    }
                                }
                            } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                    } else {
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                 >> 1U)))) {
                                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                }
                            }
                        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                        } else if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 1U;
                                } else {
                                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                }
                            } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
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
                }
            }
        } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                if ((0x00000040U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                    if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                        if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                            } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 2U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                            }
                        } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                            if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                            } else {
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 1U;
                                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 1U;
                            }
                        } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
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
                        } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))) {
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
                        } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))) {
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
            }
        } else {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl = 0U;
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl = 0U;
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl = 0U;
        }
    }
}

void Vemu___024root___nba_sequent__TOP__2(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__2\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Phi2 = (1U & 
                                               ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset)) 
                                                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2))));
}

void Vemu___024root___nba_sequent__TOP__3(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__3\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter;
    vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter;
    vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter 
        = ((0x03ffU == (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))
            ? 0x00000100U : (0x000003ffU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))));
    if ((0x0150U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))) {
        vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter 
            = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H256_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 9U)));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hblank_int 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int;
    vlSelfRef.emu__DOT__vid_mono = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch))
                                     ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch))
                                         ? 0xffU : 0x86U)
                                     : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch))
                                         ? 0x70U : 0U));
    vlSelfRef.VGA_R = vlSelfRef.emu__DOT__vid_mono;
    vlSelfRef.VGA_G = vlSelfRef.emu__DOT__vid_mono;
    vlSelfRef.VGA_B = vlSelfRef.emu__DOT__vid_mono;
}

void Vemu___024root___nba_sequent__TOP__4(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__4\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PVP;
    __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PVP = 0;
    // Body
    __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PVP 
        = vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP;
    if (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
         & (0x0020U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) {
        __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PVP 
            = vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD;
    } else if ((0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))) {
        __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PVP 
            = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP)));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP 
        = __Vdly__emu__DOT__superbug__DOT__Playfield__DOT__PVP;
}

extern const VlUnpacked<CData/*3:0*/, 256> Vemu__ConstPool__TABLE_h1e2de6e5_0;

void Vemu___024root___nba_sequent__TOP__5(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__5\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus;
    __Vtableidx1 = ((0x00000080U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg) 
                                    << 4U)) | ((0x00000060U 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                                   >> 1U)) 
                                               | (0x0000001fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus 
        = Vemu__ConstPool__TABLE_h1e2de6e5_0[__Vtableidx1];
}

void Vemu___024root___nba_sequent__TOP__6(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__6\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__lamp = (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr));
    vlSelfRef.emu__DOT__lamp2 = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
                                       >> 3U));
    vlSelfRef.emu__DOT__superbug__DOT__Attract = (1U 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
                                                     >> 1U));
    vlSelfRef.emu__DOT__superbug__DOT__Flash = (1U 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
                                                   >> 2U));
}

extern const VlUnpacked<CData/*1:0*/, 8> Vemu__ConstPool__TABLE_he2a9f562_0;

void Vemu___024root___nba_sequent__TOP__7(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__7\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    __Vtableidx6 = (7U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux 
        = Vemu__ConstPool__TABLE_he2a9f562_0[__Vtableidx6];
}

extern const VlUnpacked<CData/*0:0*/, 512> Vemu__ConstPool__TABLE_hb332deed_0;

void Vemu___024root___nba_sequent__TOP__8(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__8\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    __Vtableidx5 = ((((((IData)(vlSelfRef.emu__DOT__gear2) 
                        << 4U) | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir) 
                                   << 3U) | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__SkidIn_n) 
                                             << 2U))) 
                      | ((2U & ((~ ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                    | ((IData)(vlSelfRef.emu__DOT__joy) 
                                       >> 4U))) << 1U)) 
                         | (1U & (~ (IData)(vlSelfRef.service_mode))))) 
                     << 4U) | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__HSRes_I) 
                                << 3U) | (7U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2 
        = Vemu__ConstPool__TABLE_hb332deed_0[__Vtableidx5];
}

extern const VlUnpacked<CData/*0:0*/, 2048> Vemu__ConstPool__TABLE_h801284dc_0;

void Vemu___024root___nba_sequent__TOP__9(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__9\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*10:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    __Vtableidx4 = (((((4U & ((~ (((IData)(vlSelfRef.emu__DOT__joy) 
                                   >> 7U) | (IData)(vlSelfRef.emu__DOT__btn_nexttrack))) 
                              << 2U)) | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CrashIn_n) 
                                          << 1U) | 
                                         (1U & (~ ((IData)(vlSelfRef.emu__DOT__m_start1) 
                                                   | (IData)(vlSelfRef.emu__DOT__btn_start_1)))))) 
                      << 8U) | (((4U & ((~ ((IData)(vlSelfRef.emu__DOT__m_coin) 
                                            | (IData)(vlSelfRef.emu__DOT__btn_coin_2))) 
                                        << 2U)) | (
                                                   (2U 
                                                    & ((~ 
                                                        ((IData)(vlSelfRef.emu__DOT__m_coin) 
                                                         | (IData)(vlSelfRef.emu__DOT__btn_coin_1))) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag))) 
                                << 5U)) | (((IData)(vlSelfRef.emu__DOT__gear1) 
                                            << 4U) 
                                           | (((IData)(vlSelfRef.emu__DOT__gear3) 
                                               << 3U) 
                                              | (7U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr)))));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1 
        = Vemu__ConstPool__TABLE_h801284dc_0[__Vtableidx4];
}

void Vemu___024root___nba_comb__TOP__0(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl = 1U;
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 1U;
    if ((0x00000020U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl 
                                = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                    & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                    ? 3U : ((1U & (
                                                   (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                       >> 4U))))
                                             ? 4U : 1U));
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
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                    = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? 0x0cU : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                    ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                        ? 0x0cU : 0x39U)
                                    : 1U));
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 5U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 4U;
                    }
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                    = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 0x38U : 0x35U) : 1U)
                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 1U : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                     ? 1U : 0x2fU)));
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
        } else if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 4U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x2dU;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 0x30U : 0x2bU);
                }
            } else {
                vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                    = ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 0x2eU : 0x2cU) : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                 ? 0x2aU
                                                 : 0x3aU));
            }
        } else {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                = ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                    ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                ? 0x3aU : ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                                  & (~ 
                                                     ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                      >> 4U))))
                                            ? 0x28U
                                            : 0x27U))
                            : 0x24U) : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                         ? 0x26U : 
                                        ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req)
                                          ? 0x3aU : 
                                         ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                     >> 4U))))
                                           ? 0x28U : 
                                          ((0x3eU == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? 0x27U
                                            : ((0x3fU 
                                                == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 0x3aU
                                                : 0x29U))))))
                    : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 0x25U : 0x23U) : ((1U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                 ? 0x22U
                                                 : 0x21U)));
        }
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state)))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl = 0U;
                        }
                    }
                }
            }
        }
        if ((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 4U;
                        } else {
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x1fU;
                            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 5U;
                        }
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                            = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 0x1bU : 0x1dU);
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))) {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 1U;
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl = 3U;
                    } else {
                        vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state = 0x18U;
                    }
                } else {
                    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                        = ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 0x1aU : 1U);
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
            }
        } else {
            vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state 
                = ((8U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                    ? ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? 0x10U : 0x0fU) : 
                           ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                             ? 0x0eU : 0x0cU)) : ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                    ? 1U
                                                    : 
                                                   (((6U 
                                                      == 
                                                      (0x0000000fU 
                                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                          >> 4U))) 
                                                     || (7U 
                                                         == 
                                                         (0x0000000fU 
                                                          & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                             >> 4U))))
                                                     ? 
                                                    ((8U 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                       ? 
                                                      ((2U 
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
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                         ? 1U
                                                         : 8U)
                                                        : 8U))
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                        ? 8U
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                         ? 1U
                                                         : 8U))
                                                       : 
                                                      ((2U 
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
                                                     : 1U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                                    ? 8U
                                                    : 1U)))
                    : ((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                        ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? 1U : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                     ? ((0x00000080U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((0x00000040U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? ((0x00000020U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((((3U 
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
                                                 : 
                                                ((0x00000010U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((((3U 
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
                                                  : 1U))
                                             : ((0x00000020U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((((3U 
                                                    == 
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
                                                  ? 6U
                                                  : 1U)
                                                 : 
                                                ((0x00000010U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((((3U 
                                                     == 
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
                                                   ? 6U
                                                   : 1U)
                                                  : 1U)))
                                         : ((0x00000040U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? ((0x00000020U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 0x0aU
                                                 : 1U)
                                             : 1U))
                                     : ((6U == (0x0000000fU 
                                                & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                   >> 4U)))
                                         ? ((0x0bU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                             ? 1U : 
                                            ((0x0eU 
                                              == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                              ? 0x18U
                                              : 5U))
                                         : ((0x0aU 
                                             == (0x0000000fU 
                                                 & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                    >> 4U)))
                                             ? ((7U 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                 ? 8U
                                                 : 
                                                ((0x0dU 
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
                                             : ((0x0eU 
                                                 == 
                                                 (0x0000000fU 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 4U)))
                                                 ? 
                                                ((7U 
                                                  == 
                                                  (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                  ? 8U
                                                  : 
                                                 ((0x0dU 
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
                                                 : 1U)))))
                        : ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                            ? ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                                ? ((7U == (0x0000000fU 
                                           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                              >> 4U)))
                                    ? ((0x0bU == (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                        ? 1U : ((0x0eU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                 ? 0x18U
                                                 : 5U))
                                    : ((0x0bU == (0x0000000fU 
                                                  & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                     >> 4U)))
                                        ? ((7U == (0x0000000fU 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                            ? 8U : 
                                           ((0x0dU 
                                             == (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                             ? 0x19U
                                             : ((0x0fU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                 ? 9U
                                                 : 5U)))
                                        : ((0x0fU == 
                                            (0x0000000fU 
                                             & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code) 
                                                >> 4U)))
                                            ? ((7U 
                                                == 
                                                (0x0000000fU 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                ? 8U
                                                : (
                                                   (0x0dU 
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
                                            : 1U)))
                                : ((0x00000080U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                    ? ((0x00000040U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((0x00000020U 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((0x00000010U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 3U
                                                : 4U)
                                            : ((0x00000010U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (7U 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 8U
                                                    : 
                                                   ((0x0dU 
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
                                                : (
                                                   (((3U 
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
                                                    ? 7U
                                                    : 1U)))
                                        : ((0x00000020U 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((0x00000010U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 3U
                                                : 4U)
                                            : ((0x00000010U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? (
                                                   (7U 
                                                    == 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code)))
                                                    ? 8U
                                                    : 
                                                   ((0x0fU 
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
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                     ? 
                                                    ((2U 
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
                                                     : 1U)
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                     ? 1U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                       ? 7U
                                                       : 1U)
                                                      : 1U))))))
                                    : ((0x00000040U 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                        ? ((0x00000020U 
                                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                            ? ((0x00000010U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                ? 3U
                                                : 4U)
                                            : 1U) : 
                                       ((0x00000020U 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                         ? ((0x00000010U 
                                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                             ? ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 0x20U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x0dU
                                                    : 0x37U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x2aU
                                                    : 1U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x1eU
                                                    : 0x36U)))
                                                 : 
                                                ((4U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x34U
                                                    : 0x32U)
                                                   : 1U)
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 0x33U
                                                    : 0x31U)
                                                   : 1U)))
                                             : ((8U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((1U 
                                                     & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                         >> 2U) 
                                                        | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                            >> 3U) 
                                                           ^ 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                            >> 1U))))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((1U 
                                                     & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                         >> 2U) 
                                                        | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                            >> 3U) 
                                                           ^ 
                                                           ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                            >> 1U))))
                                                     ? 1U
                                                     : 0x1bU))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((1U 
                                                     & VL_REDXOR_4(
                                                                   (0x0aU 
                                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((1U 
                                                     & VL_REDXOR_4(
                                                                   (0x0aU 
                                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                     ? 1U
                                                     : 0x1bU)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 1U
                                                     : 0x1bU))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 1U
                                                     : 0x1bU))))
                                                 : 
                                                ((4U 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 1U
                                                     : 0x1bU))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))
                                                     ? 1U
                                                     : 0x1bU)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 
                                                   ((IData)(
                                                            (0U 
                                                             != 
                                                             (5U 
                                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                     ? 0x1bU
                                                     : 1U)
                                                    : 
                                                   ((IData)(
                                                            (0U 
                                                             != 
                                                             (5U 
                                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc))))
                                                     ? 1U
                                                     : 0x1bU))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code))
                                                    ? 1U
                                                    : 0x1bU)))))
                                         : 1U)))) : 
                           ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state))
                             ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req) 
                                 & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack)))
                                 ? 0x20U : ((1U & (
                                                   (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)) 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc) 
                                                       >> 4U))))
                                             ? 0x20U
                                             : 2U))
                             : 0x3aU))));
            if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state) 
                          >> 3U)))) {
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
        }
    }
}

void Vemu___024root___nba_sequent__TOP__10(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__10\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch 
        = ((4U & ((~ ((~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                               | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                           ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                          | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))) 
                      | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank))) 
                  << 2U)) | ((2U & ((~ ((~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                                 | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                             ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                            | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))) 
                                        | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank))) 
                                    << 1U)) | (1U & 
                                               (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int) 
                                                   | (IData)(vlSelfRef.emu__DOT__vsync))))));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld 
        = (1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n) 
                     & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode)) 
                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n)))) 
                 & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift) 
                       | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n)))));
    if (vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__LoadPd) {
        vlSelfRef.emu__DOT__superbug__DOT__PCC1 = (1U 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD) 
                                                      >> 6U));
        vlSelfRef.emu__DOT__superbug__DOT__PCC2 = (1U 
                                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD) 
                                                      >> 7U));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__LoadPd 
        = (IData)((3U == (3U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP))));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD 
        = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q) 
            << 4U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q));
}

void Vemu___024root___nba_comb__TOP__1(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__1\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr 
        = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q) 
            << 6U) | ((0x0000003cU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP) 
                                      << 2U)) | (3U 
                                                 & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP) 
                                                    >> 2U))));
}

void Vemu___024root___nba_sequent__TOP__11(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__11\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int)) 
         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int))) {
        vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg 
            = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus;
    }
    if (((IData)(vlSelfRef.emu__DOT__unnamedblk1__DOT__old_state) 
         != (1U & ((IData)(vlSelfRef.ps2_key) >> 0x0aU)))) {
        if (((((((((0x0000006bU == (0x000000ffU & (IData)(vlSelfRef.ps2_key))) 
                   | (0x00000074U == (0x000000ffU & (IData)(vlSelfRef.ps2_key)))) 
                  | (0x0014U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) 
                 | (0x0011U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) 
                | (0x0029U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) 
               | (0x0012U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) 
              | (5U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) 
             | (6U == (0x000001ffU & (IData)(vlSelfRef.ps2_key))))) {
            if ((0x0000006bU == (0x000000ffU & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_left = (1U 
                                                & ((IData)(vlSelfRef.ps2_key) 
                                                   >> 9U));
            } else if ((0x00000074U == (0x000000ffU 
                                        & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_right = (1U 
                                                 & ((IData)(vlSelfRef.ps2_key) 
                                                    >> 9U));
            } else if ((0x0014U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_gas = (1U & 
                                               ((IData)(vlSelfRef.ps2_key) 
                                                >> 9U));
            } else if ((0x0011U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_gearup = (1U 
                                                  & ((IData)(vlSelfRef.ps2_key) 
                                                     >> 9U));
            } else if ((0x0029U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_geardown = 
                    (1U & ((IData)(vlSelfRef.ps2_key) 
                           >> 9U));
            } else if ((0x0012U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_nexttrack = 
                    (1U & ((IData)(vlSelfRef.ps2_key) 
                           >> 9U));
            } else if ((5U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
                vlSelfRef.emu__DOT__btn_one_player 
                    = (1U & ((IData)(vlSelfRef.ps2_key) 
                             >> 9U));
            } else {
                vlSelfRef.emu__DOT__btn_two_players 
                    = (1U & ((IData)(vlSelfRef.ps2_key) 
                             >> 9U));
            }
        } else if ((0x0016U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
            vlSelfRef.emu__DOT__btn_start_1 = (1U & 
                                               ((IData)(vlSelfRef.ps2_key) 
                                                >> 9U));
        } else if ((0x002eU == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
            vlSelfRef.emu__DOT__btn_coin_1 = (1U & 
                                              ((IData)(vlSelfRef.ps2_key) 
                                               >> 9U));
        } else if ((0x0036U == (0x000001ffU & (IData)(vlSelfRef.ps2_key)))) {
            vlSelfRef.emu__DOT__btn_coin_2 = (1U & 
                                              ((IData)(vlSelfRef.ps2_key) 
                                               >> 9U));
        }
    }
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int 
        = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int;
    vlSelfRef.emu__DOT__m_gas = (1U & ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                       | ((IData)(vlSelfRef.emu__DOT__joy) 
                                          >> 4U)));
    vlSelfRef.emu__DOT__m_next_track = (1U & (((IData)(vlSelfRef.emu__DOT__joy) 
                                               >> 7U) 
                                              | (IData)(vlSelfRef.emu__DOT__btn_nexttrack)));
    vlSelfRef.emu__DOT__unnamedblk1__DOT__old_state 
        = (1U & ((IData)(vlSelfRef.ps2_key) >> 0x0aU));
    vlSelfRef.emu__DOT__m_start1 = (1U & ((IData)(vlSelfRef.emu__DOT__btn_one_player) 
                                          | ((IData)(vlSelfRef.emu__DOT__joy) 
                                             >> 7U)));
    vlSelfRef.emu__DOT____Vcellinp__superbug__Start_I 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__m_start1) 
                    | (IData)(vlSelfRef.emu__DOT__btn_start_1))));
    vlSelfRef.emu__DOT__m_coin = (1U & ((IData)(vlSelfRef.emu__DOT__m_start1) 
                                        | ((IData)(vlSelfRef.emu__DOT__btn_two_players) 
                                           | ((IData)(vlSelfRef.emu__DOT__joy) 
                                              >> 8U))));
    if (vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int) {
        if ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8)) 
                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                      >> 4U)))) {
            vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int 
                = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                         >> 6U));
        }
    } else {
        vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int = 0U;
    }
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin2 
        = ((IData)(vlSelfRef.emu__DOT__m_coin) | (IData)(vlSelfRef.emu__DOT__btn_coin_2));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__Coin1 
        = ((IData)(vlSelfRef.emu__DOT__m_coin) | (IData)(vlSelfRef.emu__DOT__btn_coin_1));
    vlSelfRef.VGA_HS = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int;
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                 >> 4U));
    if ((0x00000200U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))) {
        vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int = 0U;
    } else if ((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32)) 
                      & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                         >> 6U)))) {
        vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int 
            = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                        >> 7U)));
    }
    vlSelfRef.VGA_HB = vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int;
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                 >> 6U));
}

void Vemu___024root___nba_sequent__TOP__12(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__12\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n) 
           && (1U & (~ ((IData)(vlSelfRef.emu__DOT__steer) 
                        >> 1U))));
    vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag 
        = vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n;
}

void Vemu___024root___nba_sequent__TOP__13(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__13\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10;
    emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10 = 0;
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr = ((4U 
                                                   & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                                                     ? 
                                                    (0x0000fff9U 
                                                     | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv) 
                                                        << 1U))
                                                     : 
                                                    (0x0000fff8U 
                                                     | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv) 
                                                        << 1U)))
                                                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl))
                                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                                                     : 0xffffU)));
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
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
           & (0x0500U == (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_10 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
              >> 9U));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_Wren 
        = ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM)));
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
}

void Vemu___024root___nba_comb__TOP__2(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__2\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Flash) 
                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__PFWndo))));
}

extern const VlUnpacked<CData/*0:0*/, 128> Vemu__ConstPool__TABLE_h1d9bba92_0;

void Vemu___024root___nba_sequent__TOP__14(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__14\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    __Vtableidx3 = (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout) 
                     << 3U) | ((6U & ((~ (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1) 
                                           << 1U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0))) 
                                      << 1U)) | (1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa) 
                                                     & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb))))));
    vlSelfRef.emu__DOT__superbug__DOT__CarVideo = Vemu__ConstPool__TABLE_h1d9bba92_0
        [__Vtableidx3];
}

void Vemu___024root___nba_sequent__TOP__15(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__15\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus 
        = vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus;
}

void Vemu___024root___nba_comb__TOP__3(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__3\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Out2_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn) 
                    & (0x0260U == (0x02e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
}

void Vemu___024root___nba_comb__TOP__4(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__4\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr 
        = (0x000000ffU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM)
                           ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr)
                           : ((0x000000f0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP)) 
                              | (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP) 
                                                >> 4U)))));
}

void Vemu___024root___nba_comb__TOP__5(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__5\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vemu___024root___nba_sequent__TOP__16(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__16\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                >> 3U) & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_V8))))) {
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb 
            = (IData)((0x60U == (0xe0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    }
    if ((1U & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                >> 5U) & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_H16))))) {
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa 
            = (IData)((0x02c0U == (0x03c0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_V8 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                 >> 3U));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarEna_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa) 
                    & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_H16 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                 >> 5U));
}

void Vemu___024root___nba_sequent__TOP__17(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__17\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter 
        = vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter;
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter 
        = vlSelfRef.__Vdly__emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter;
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout 
        = vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__K6__DOT__mem
        [(((((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g)
                : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g)) 
              << 4U) | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                           ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g)
                           : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g)) 
                         << 3U) | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                     ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g)
                                     : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g)) 
                                   << 2U))) | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                  ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g)
                                                  : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g)) 
                                                << 1U) 
                                               | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g)
                                                   : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g)))) 
           << 5U) | (((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                         ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g)
                         : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g)) 
                       << 4U) | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g)
                                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g)) 
                                  << 3U) | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g)
                                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g)) 
                                            << 2U))) 
                     | ((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                           ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g)
                           : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g)) 
                         << 1U) | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g)
                                    : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g)))))];
    vlSelfRef.VGA_VB = (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi 
        = ((0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
           & (0U == (0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank 
        = (1U & (~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)) 
                    & (0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))));
    vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prom_address 
        = ((0x00000080U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg) 
                           << 4U)) | ((0x00000060U 
                                       & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                          >> 1U)) | 
                                      (0x0000001fU 
                                       & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    vlSelfRef.emu__DOT__vsync = ((0xf2U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
                                 & (0xf4U >= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)));
    vlSelfRef.CE_PIXEL = (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter));
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Window_en 
        = (IData)((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 9U) & (~ (IData)((0x01e0U == 
                                         (0x01e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter)))))));
    vlSelfRef.emu__DOT__clk_6 = (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__H2 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                 >> 2U));
    vlSelfRef.VGA_VS = vlSelfRef.emu__DOT__vsync;
}

void Vemu___024root___nba_comb__TOP__6(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__6\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld) 
           & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo));
}

void Vemu___024root___nba_comb__TOP__7(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__7\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

void Vemu___024root___nba_comb__TOP__8(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__8\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select)
            ? (0x0000001fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))
            : ((0x00000010U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                               >> 2U)) | (0x0000000fU 
                                          & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                             >> 4U))));
}

void Vemu___024root___nba_comb__TOP__9(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__9\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn) 
           & ((~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)) 
                  | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                     >> 2U))) & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw))));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr) 
           & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
              >> 9U));
    vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11 
        = ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr) 
           & (0x0100U == (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))));
    vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                    & (0x00a0U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
}

void Vemu___024root___nba_sequent__TOP__18(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__18\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarRot_n) 
         & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_CarRot_n)))) {
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0 
            = (1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD));
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1 
            = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                     >> 1U));
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel 
            = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                     >> 2U));
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel 
            = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                     >> 3U));
        vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel 
            = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                     >> 4U));
    }
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R_Sel 
        = (3U & (~ (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1) 
                     << 1U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_CarRot_n 
        = vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarRot_n;
}

void Vemu___024root___nba_sequent__TOP__19(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_sequent__TOP__19\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din 
        = (((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM))
            ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD)
            : 0xffU);
}

void Vemu___024root___nba_comb__TOP__10(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__10\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g 
        = (1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                     >> 5U)) ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 4U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 3U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 2U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                    >> 1U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                    ^ VL_REDXOR_8((0x18U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))))));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g 
        = (1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                     >> 3U)) ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                    >> 2U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                 ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                    >> 1U)));
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g 
        = (1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel) 
                 ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)));
}

void Vemu___024root___nba_comb__TOP__11(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___nba_comb__TOP__11\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarRot_n 
        = (1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                    & (0x0080U == (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
}

void Vemu___024root___eval_nba(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_nba\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__6(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x0000000007f00000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x00000000001ff000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0000000000000021ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__10(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    if ((0x0000000000000201ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__11(vlSelf);
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__13(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x0000000aU] = 1U;
    }
    if ((0x0000000000000011ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x00000000000001c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__14(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x0000000000000028ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x0000000000000221ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x0000000007fff021ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__16(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x0000000bU] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__17(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x0000000cU] = 1U;
    }
    if ((0x00000000000001c1ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x0000000000000022ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x000000000000002aULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__9(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x0000000dU] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_sequent__TOP__18(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x0000000eU] = 1U;
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_sequent__TOP__19(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x0000000fU] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vemu___024root___nba_comb__TOP__10(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x00000010U] = 1U;
    }
    if ((0x000000000000002aULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vemu___024root___nba_comb__TOP__11(vlSelf);
    }
}

void Vemu___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vemu___024root___eval_phase__act(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_phase__act\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vemu___024root___eval_triggers__act(vlSelf);
    Vemu___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vemu___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vemu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vemu___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vemu___024root___eval_phase__nba(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_phase__nba\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vemu___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vemu___024root___eval_nba(vlSelf);
        Vemu___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vemu___024root___eval(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00001770U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vemu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("sim.v", 5, "", "Input combinational region did not converge after 6000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vemu___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00001770U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vemu___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("sim.v", 5, "", "NBA region did not converge after 6000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00001770U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vemu___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("sim.v", 5, "", "Active region did not converge after 6000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vemu___024root___eval_phase__act(vlSelf));
    } while (Vemu___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vemu___024root___eval_debug_assertions(Vemu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root___eval_debug_assertions\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_sys & 0xfeU)))) {
        Verilated::overWidthError("clk_sys");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.soft_reset & 0xfeU)))) {
        Verilated::overWidthError("soft_reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.menu & 0xfeU)))) {
        Verilated::overWidthError("menu");
    }
    if (VL_UNLIKELY(((vlSelfRef.adam & 0xfeU)))) {
        Verilated::overWidthError("adam");
    }
    if (VL_UNLIKELY(((vlSelfRef.spinner_0 & 0xfe00U)))) {
        Verilated::overWidthError("spinner_0");
    }
    if (VL_UNLIKELY(((vlSelfRef.spinner_1 & 0xfe00U)))) {
        Verilated::overWidthError("spinner_1");
    }
    if (VL_UNLIKELY(((vlSelfRef.spinner_2 & 0xfe00U)))) {
        Verilated::overWidthError("spinner_2");
    }
    if (VL_UNLIKELY(((vlSelfRef.spinner_3 & 0xfe00U)))) {
        Verilated::overWidthError("spinner_3");
    }
    if (VL_UNLIKELY(((vlSelfRef.spinner_4 & 0xfe00U)))) {
        Verilated::overWidthError("spinner_4");
    }
    if (VL_UNLIKELY(((vlSelfRef.spinner_5 & 0xfe00U)))) {
        Verilated::overWidthError("spinner_5");
    }
    if (VL_UNLIKELY(((vlSelfRef.ps2_key & 0xf800U)))) {
        Verilated::overWidthError("ps2_key");
    }
    if (VL_UNLIKELY(((vlSelfRef.ps2_mouse & 0xfe000000U)))) {
        Verilated::overWidthError("ps2_mouse");
    }
    if (VL_UNLIKELY(((vlSelfRef.timestamp & 0ULL)))) {
        Verilated::overWidthError("timestamp");
    }
    if (VL_UNLIKELY(((vlSelfRef.service_mode & 0xfeU)))) {
        Verilated::overWidthError("service_mode");
    }
    if (VL_UNLIKELY(((vlSelfRef.ioctl_download & 0xfeU)))) {
        Verilated::overWidthError("ioctl_download");
    }
    if (VL_UNLIKELY(((vlSelfRef.ioctl_wr & 0xfeU)))) {
        Verilated::overWidthError("ioctl_wr");
    }
    if (VL_UNLIKELY(((vlSelfRef.ioctl_addr & 0xfe000000U)))) {
        Verilated::overWidthError("ioctl_addr");
    }
    if (VL_UNLIKELY(((vlSelfRef.sd_ack & 0xfc00U)))) {
        Verilated::overWidthError("sd_ack");
    }
    if (VL_UNLIKELY(((vlSelfRef.sd_buff_addr & 0xfe00U)))) {
        Verilated::overWidthError("sd_buff_addr");
    }
    if (VL_UNLIKELY(((vlSelfRef.sd_buff_wr & 0xfeU)))) {
        Verilated::overWidthError("sd_buff_wr");
    }
    if (VL_UNLIKELY(((vlSelfRef.img_mounted & 0xfc00U)))) {
        Verilated::overWidthError("img_mounted");
    }
    if (VL_UNLIKELY(((vlSelfRef.img_readonly & 0xfeU)))) {
        Verilated::overWidthError("img_readonly");
    }
}
#endif  // VL_DEBUG
