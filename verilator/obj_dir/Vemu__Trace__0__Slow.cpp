// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vemu__Syms.h"


VL_ATTR_COLD void Vemu___024root__trace_init_sub__TOP__0(Vemu___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_init_sub__TOP__0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+258,0,"clk_sys",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+260,0,"soft_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"menu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"adam",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"joystick_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"joystick_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"joystick_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"joystick_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"joystick_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"joystick_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"joystick_l_analog_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+270,0,"joystick_l_analog_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+271,0,"joystick_l_analog_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+272,0,"joystick_l_analog_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+273,0,"joystick_l_analog_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+274,0,"joystick_l_analog_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+275,0,"joystick_r_analog_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+276,0,"joystick_r_analog_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+277,0,"joystick_r_analog_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+278,0,"joystick_r_analog_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+279,0,"joystick_r_analog_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+280,0,"joystick_r_analog_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+281,0,"paddle_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+282,0,"paddle_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+283,0,"paddle_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+284,0,"paddle_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+285,0,"paddle_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+286,0,"paddle_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+287,0,"spinner_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+288,0,"spinner_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+289,0,"spinner_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+290,0,"spinner_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+291,0,"spinner_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+292,0,"spinner_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+293,0,"ps2_key",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+294,0,"ps2_mouse",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+295,0,"ps2_mouse_ext",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+296,0,"timestamp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+298,0,"VGA_R",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+299,0,"VGA_G",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+300,0,"VGA_B",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+301,0,"VGA_HS",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"VGA_VS",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"VGA_HB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"VGA_VB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+305,0,"CE_PIXEL",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"AUDIO_L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+307,0,"AUDIO_R",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+308,0,"dbg_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+309,0,"dbg_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+310,0,"dbg_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+311,0,"dbg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+312,0,"dbg_op_fetch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+313,0,"dbg_acca",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+314,0,"dbg_accb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+315,0,"dbg_cc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+316,0,"service_mode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"ioctl_download",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+318,0,"ioctl_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+319,0,"ioctl_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+320,0,"ioctl_dout",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+321,0,"ioctl_index",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+322,0,"ioctl_wait",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sd_lba", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+323+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+325,0,"sd_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+326,0,"sd_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+327,0,"sd_ack",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+328,0,"sd_buff_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+329,0,"sd_buff_dout",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("sd_buff_din", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+330+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+332,0,"sd_buff_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+333,0,"img_mounted",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+334,0,"img_readonly",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+335,0,"img_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("emu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+258,0,"clk_sys",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+260,0,"soft_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"menu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"adam",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"joystick_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"joystick_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"joystick_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"joystick_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"joystick_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"joystick_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"joystick_l_analog_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+270,0,"joystick_l_analog_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+271,0,"joystick_l_analog_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+272,0,"joystick_l_analog_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+273,0,"joystick_l_analog_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+274,0,"joystick_l_analog_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+275,0,"joystick_r_analog_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+276,0,"joystick_r_analog_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+277,0,"joystick_r_analog_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+278,0,"joystick_r_analog_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+279,0,"joystick_r_analog_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+280,0,"joystick_r_analog_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+281,0,"paddle_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+282,0,"paddle_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+283,0,"paddle_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+284,0,"paddle_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+285,0,"paddle_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+286,0,"paddle_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+287,0,"spinner_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+288,0,"spinner_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+289,0,"spinner_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+290,0,"spinner_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+291,0,"spinner_4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+292,0,"spinner_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+293,0,"ps2_key",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+294,0,"ps2_mouse",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+295,0,"ps2_mouse_ext",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+296,0,"timestamp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+298,0,"VGA_R",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+299,0,"VGA_G",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+300,0,"VGA_B",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+301,0,"VGA_HS",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"VGA_VS",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"VGA_HB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"VGA_VB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+305,0,"CE_PIXEL",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"AUDIO_L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+307,0,"AUDIO_R",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+308,0,"dbg_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+309,0,"dbg_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+310,0,"dbg_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+311,0,"dbg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+312,0,"dbg_op_fetch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+313,0,"dbg_acca",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+314,0,"dbg_accb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+315,0,"dbg_cc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+316,0,"service_mode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"ioctl_download",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+318,0,"ioctl_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+319,0,"ioctl_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+320,0,"ioctl_dout",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+321,0,"ioctl_index",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+322,0,"ioctl_wait",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sd_lba", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+325,0,"sd_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+326,0,"sd_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+327,0,"sd_ack",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+328,0,"sd_buff_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+329,0,"sd_buff_dout",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("sd_buff_din", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+332,0,"sd_buff_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+333,0,"img_mounted",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+334,0,"img_readonly",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+335,0,"img_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+269,0,"joystick_a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"joy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+387,0,"UART_CTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"UART_RTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+389,0,"UART_RXD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+390,0,"UART_TXD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+391,0,"UART_DTR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+392,0,"UART_DSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+337,0,"pressed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+338,0,"code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+130,0,"btn_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"btn_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"btn_gas",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"btn_gearup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"btn_geardown",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"btn_nexttrack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"btn_one_player",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"btn_two_players",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"btn_start_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"btn_coin_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"btn_coin_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"m_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"m_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"m_gas",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"m_gearup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"m_geardown",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"m_next_track",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"m_start1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"m_start2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"m_coin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"steer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+25,0,"gear1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"gear2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"gear3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+393,0,"DIP_Sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+258,0,"clk_12_sim",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"videowht",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"videoblk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"compositesync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"hsync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"vsync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"hblank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"vblank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+394,0,"audio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"lamp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"lamp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"clk_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+395,0,"locked",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"vid_mono",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+396,0,"sprint_vid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("gearshift1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"gearup",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"geardown",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"gear1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"gear2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"gear3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"gear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+29,0,"old_gear_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"old_gear_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("steer1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+397,0,"clkdiv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"right",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"left",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"steer",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+31,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+35,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("superbug", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+308,0,"dbg_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+309,0,"dbg_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+310,0,"dbg_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+311,0,"dbg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+312,0,"dbg_op_fetch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+313,0,"dbg_acca",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+314,0,"dbg_accb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+315,0,"dbg_cc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+258,0,"Clk_50_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"Reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"Video1_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"Video2_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"Sync_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+394,0,"Audio_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"Coin1_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"Coin2_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"Start_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"Trak_Sel_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"Gas_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"Gear1_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"Gear2_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"Gear3_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"Steer_1A_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"Steer_1B_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"Test_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+398,0,"Slam_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+399,0,"HSRes_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"Lamp1_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"Lamp2_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"hs_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"vs_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"hblank_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"vblank_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"Clk12",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"clk_6_O",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+393,0,"DIP_Sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+340,0,"dn_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+320,0,"dn_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+318,0,"dn_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"Clk6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"Phi2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"HCount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+191,0,"VCount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+141,0,"HSync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"VSync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"HBlank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"HBlank_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"VBlank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"VBlank_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,0,"VReset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"PCC1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"PCC2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"PFWndo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"Flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"Pfld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"CarVideo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+343,0,"A_NVideo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+344,0,"Crash_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+345,0,"Skid_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"PVP_Load_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"PHP_Load_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"ArrowOff_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+346,0,"CarRot_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"CPU_Adr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+347,0,"CPU_Din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"CPU_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+69,0,"RW_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"VMA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"BVMA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"Sys_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"In1_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"Opt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"CrashIn_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"SkidIn_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"Attract",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+348,0,"SteerReset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"CrashReset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"SkidReset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"MotorSnd_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"CrashSnd_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"SkidSnd_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("Alpha", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"Clk6",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"Phi2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"RW_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"BD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+155,0,"BA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"HCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+191,0,"VCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+143,0,"HBlank_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"VBlank",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"VMA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"BVMA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"Sys_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+343,0,"A_NVideo",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"H256_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+349,0,"RAM_Addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+403,0,"RAM_Dout2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+37,0,"RAM_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+350,0,"RAM_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"Mux_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,0,"BA10and8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"BA12nor11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"SysEnBA10_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"RAMcs_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"M3_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+39,0,"N3_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+40,0,"AlphaROM_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+194,0,"ShiftLoad",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"ShiftData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+150,0,"AN_Blank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+352,0,"rom_m3_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+352,0,"rom_n3_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("M3_ROM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+352,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+38,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("N3_ROM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+352,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+39,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("P3_RAM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+349,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+350,0,"wren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+37,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("CPU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+308,0,"dbg_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+309,0,"dbg_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+310,0,"dbg_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+311,0,"dbg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+312,0,"dbg_op_fetch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+313,0,"dbg_acca",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+314,0,"dbg_accb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+315,0,"dbg_cc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+189,0,"Clk6",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"Reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"VBlank",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"HBlank",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+191,0,"VCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+190,0,"HCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+69,0,"RW_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"VMA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"PHI2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"StartLamp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"TrakSelLamp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"Attract",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"Flash",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"In1_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"Opt_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"PHP_Load_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"PVP_Load_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+346,0,"CarRot_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"ArrowOff_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+348,0,"SteerReset_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"CrashReset_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"SkidReset_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"MotorSnd_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"CrashSnd_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"SkidSnd_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"Adr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+347,0,"DBus_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"DBus_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+7,0,"Reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"H2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"V16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"Phi1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+354,0,"Legit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+355,0,"CPU_Din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"CPU_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"RAM_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+163,0,"RAMce",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"RAMwe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"ROM1_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"ROM2_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"ROM3_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+356,0,"ROM_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+165,0,"ROM1ce_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"ROM2ce_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"ROM3ce_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"R_nW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"IRQ_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"NMI_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"BVMA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"BA12nor11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"SysEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"WdogReset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"IO_Wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"Out2_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"nmi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"irq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"prev_V16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+360,0,"ce_V16_fall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"SysEn_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("A1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+45,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("C1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+44,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("CPU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+341,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"vma",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+355,0,"data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+400,0,"hold",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,0,"halt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"irq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"nmi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"test_alu",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+73,0,"test_cc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+308,0,"dbg_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+309,0,"dbg_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+310,0,"dbg_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+311,0,"dbg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+312,0,"dbg_op_fetch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+313,0,"dbg_acca",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+314,0,"dbg_accb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+315,0,"dbg_cc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+404,0,"SBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+405,0,"XBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+406,0,"HBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+407,0,"IBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+408,0,"NBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"ZBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"VBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+411,0,"CBIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"ST_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+413,0,"ST_FETCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+414,0,"ST_DECODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+415,0,"ST_EXTENDED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+416,0,"ST_INDEXED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+417,0,"ST_READ8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+418,0,"ST_READ16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+419,0,"ST_IMM16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+420,0,"ST_WRITE8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+421,0,"ST_WRITE16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+422,0,"ST_EXECUTE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+423,0,"ST_HALT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+424,0,"ST_ERROR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+425,0,"ST_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+426,0,"ST_MULEA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+427,0,"ST_MULD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+428,0,"ST_MUL0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+429,0,"ST_MUL1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+430,0,"ST_MUL2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+431,0,"ST_MUL3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+432,0,"ST_MUL4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+433,0,"ST_MUL5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+434,0,"ST_MUL6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+435,0,"ST_MUL7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+436,0,"ST_JMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+437,0,"ST_JSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+438,0,"ST_JSR1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+439,0,"ST_BRANCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+440,0,"ST_BSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+441,0,"ST_BSR1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+442,0,"ST_RTS_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+443,0,"ST_RTS_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+444,0,"ST_INT_PCL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+445,0,"ST_INT_PCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+446,0,"ST_INT_IXL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+447,0,"ST_INT_IXH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+448,0,"ST_INT_CC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+449,0,"ST_INT_ACCA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+450,0,"ST_INT_ACCB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+451,0,"ST_INT_WAI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+452,0,"ST_INT_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+453,0,"ST_RTI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+454,0,"ST_RTI_CC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+455,0,"ST_RTI_ACCA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+456,0,"ST_RTI_ACCB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+457,0,"ST_RTI_IXL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+458,0,"ST_RTI_IXH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+459,0,"ST_RTI_PCL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+460,0,"ST_RTI_PCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+461,0,"ST_PULA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+462,0,"ST_PSHA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+463,0,"ST_PULB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+464,0,"ST_PSHB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+465,0,"ST_PULX_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+466,0,"ST_PULX_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+467,0,"ST_PSHX_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+468,0,"ST_PSHX_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+469,0,"ST_VECT_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+470,0,"ST_VECT_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+471,0,"AD_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"AD_FETCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"AD_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"AD_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"AD_PUSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+476,0,"AD_PULL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+477,0,"AD_INTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+478,0,"AD_INTL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+479,0,"DO_MD_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+480,0,"DO_MD_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+481,0,"DO_ACCA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+482,0,"DO_ACCB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+483,0,"DO_IX_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+484,0,"DO_IX_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+485,0,"DO_CC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+486,0,"DO_PC_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+487,0,"DO_PC_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+488,0,"OP_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+489,0,"OP_FETCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+490,0,"OP_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+471,0,"ACCA_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"ACCA_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"ACCA_LOAD_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"ACCA_PULL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"ACCA_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+488,0,"ACCB_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+489,0,"ACCB_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+490,0,"ACCB_PULL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+491,0,"ACCB_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+488,0,"CC_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+489,0,"CC_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+490,0,"CC_PULL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+491,0,"CC_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+471,0,"IX_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"IX_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"IX_PULL_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"IX_PULL_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"IX_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+488,0,"SP_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+489,0,"SP_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+490,0,"SP_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+471,0,"PC_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"PC_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"PC_LOAD_EA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"PC_ADD_EA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"PC_PULL_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+476,0,"PC_PULL_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+477,0,"PC_INC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+471,0,"MD_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"MD_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"MD_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"MD_FETCH_FIRST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"MD_FETCH_NEXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+476,0,"MD_SHIFTL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+471,0,"EA_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"EA_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"EA_ADD_IX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"EA_LOAD_ACCB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"EA_INC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+476,0,"EA_FETCH_FIRST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+477,0,"EA_FETCH_NEXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+471,0,"IV_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"IV_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"IV_SWI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"IV_NMI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"IV_IRQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+488,0,"NMI_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+489,0,"NMI_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+490,0,"NMI_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+471,0,"LEFT_ACCA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+472,0,"LEFT_ACCB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+473,0,"LEFT_ACCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+474,0,"LEFT_MD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+475,0,"LEFT_IX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+476,0,"LEFT_SP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+488,0,"RIGHT_MD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+489,0,"RIGHT_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+490,0,"RIGHT_ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+491,0,"RIGHT_ACCB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+412,0,"ALU_ADD8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+413,0,"ALU_SUB8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+414,0,"ALU_ADD16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+415,0,"ALU_SUB16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+416,0,"ALU_ADC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+417,0,"ALU_SBC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+418,0,"ALU_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+419,0,"ALU_ORA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+420,0,"ALU_EOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+421,0,"ALU_TST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+422,0,"ALU_INC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+423,0,"ALU_DEC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+424,0,"ALU_CLR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+425,0,"ALU_NEG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+426,0,"ALU_COM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+427,0,"ALU_INX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+428,0,"ALU_DEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+429,0,"ALU_CPX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+430,0,"ALU_LSR16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+431,0,"ALU_LSL16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+432,0,"ALU_ROR8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+433,0,"ALU_ROL8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+434,0,"ALU_ASR8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+435,0,"ALU_ASL8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+436,0,"ALU_LSR8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+437,0,"ALU_SEI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+438,0,"ALU_CLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+439,0,"ALU_SEC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+440,0,"ALU_CLC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+441,0,"ALU_SEV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+442,0,"ALU_CLV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+443,0,"ALU_TPA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+444,0,"ALU_TAP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+445,0,"ALU_LD8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+446,0,"ALU_ST8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+447,0,"ALU_LD16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+448,0,"ALU_ST16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+449,0,"ALU_NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+450,0,"ALU_DAA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+74,0,"op_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+75,0,"acca",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"accb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+77,0,"cc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"xreg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+79,0,"sp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+80,0,"ea",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+81,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+82,0,"md",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+83,0,"iv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+84,0,"nmi_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"nmi_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+116,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+117,0,"pc_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+87,0,"ea_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+88,0,"op_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+89,0,"md_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+90,0,"acca_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+91,0,"accb_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+92,0,"ix_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+93,0,"cc_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+94,0,"sp_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+118,0,"iv_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+95,0,"left_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+96,0,"right_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+97,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+98,0,"addr_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+99,0,"dout_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+100,0,"nmi_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+101,0,"left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+102,0,"right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+72,0,"out_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+73,0,"cc_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+361,0,"pc_off",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+362,0,"pc_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+103,0,"ea_off",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+363,0,"ea_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+104,0,"carry_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"daa_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+106,0,"valid_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"valid_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"mul_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("D1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+43,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("M1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+164,0,"wren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+243,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+49,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("N1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+164,0,"wren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+50,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("Car", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"Clk6",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"Clk50",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"RW_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"BD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+155,0,"BA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"HCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+191,0,"VCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+346,0,"CarRot_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"CarVideo",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"H1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"H2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"H4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"H8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"H16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"H32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"H64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"H128",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+206,0,"H128n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+207,0,"H256",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"V1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"V2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"V4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"V8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"V16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"V32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"V64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"V128",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"V128n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+231,0,"CarROM_Adr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+216,0,"CarROM_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+182,0,"CarEna_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+224,0,"R1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"R0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"CV16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+233,0,"CV8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"CV4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"CV2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"CV1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+237,0,"CH16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+238,0,"CH8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"CH4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"CH2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"CH1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"V16g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"V8g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"V4g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"V2g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"V1g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"H16g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"H8g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"H4g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"H2g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"H1g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"M7Qa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"M7Qb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"BD2_Sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"BD3_Sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"BD4_Sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"R_Sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+185,0,"prev_H16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"prev_V8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+230,0,"prev_CarRot_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("K6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+258,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+231,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+216,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("ControlInputs", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+393,0,"DIP_Sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+17,0,"Coin1_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"Coin2_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"Start_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"TrackSel_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"Gas_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"Gear1_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"Gear2_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"Gear3_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"Test_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+399,0,"HScoreRes_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+398,0,"Slam_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"Steering1A_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"Steering1B_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+348,0,"SteerReset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"In1_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"Opt_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"SkidIn_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"CrashIn_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+170,0,"Adr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+347,0,"DBus",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"Coin1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"Coin2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+364,0,"SteerDir",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"SteerFlag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"Steering1A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+366,0,"InputMux1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+367,0,"InputMux2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+368,0,"DIP_Mux",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("Playfield", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"Clk6",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"RW_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"BD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+155,0,"BA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"HCount",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+156,0,"Sys_En",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"HSync",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"HBlank",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"VBlank",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"ArrowOff_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"CarVideo",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"PVP_Load_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"PHP_Load_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+344,0,"Crash_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+345,0,"Skid_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"CrashIn_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"SkidIn_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"CrashReset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"SkidReset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"PfWndo",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"PCC1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"PCC2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"Pfld",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"H1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"H2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"H4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"H8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"H16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"H32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"H64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"H128",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+207,0,"H256",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+369,0,"PFROM_Adr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+51,0,"E5_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+52,0,"F5_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+53,0,"H5_Dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+54,0,"Vid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+125,0,"PD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+370,0,"PVP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+55,0,"PHP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+371,0,"PF_RAM_Adr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+245,0,"PFRAM_Din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+171,0,"PF_Wren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+372,0,"PF_RAMce_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"PfldRAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+373,0,"BD_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+492,0,"PD_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"RnW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"CrashCode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"SkidCode_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"CrashSkid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"CrashArrow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+374,0,"PfCarVid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"Arrow_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"VidShift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+126,0,"LoadPd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"PfWndo_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"Window_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"Pf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"pf_write_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+65,0,"prev_VBlank_arrow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"prev_H8_pfwndo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("E5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+369,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+51,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("E6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+371,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+171,0,"wren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+246,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+67,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("F5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+369,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+52,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("F6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+371,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+171,0,"wren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+247,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+68,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("H5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+369,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+53,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("Vid_mixer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"Clk6",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"HSync",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"VSync",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"HBlank_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"VBlank_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"PCC1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"PCC2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"PFWndo",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"Flash",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"Pfld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"CarVideo",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+343,0,"A_NVideo",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"CSync",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"Video1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"Video2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"CompSync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"CompBlank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+375,0,"FlashWndo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"PCC1Pfld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"PCC2Pfld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+376,0,"CarPfld1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+377,0,"CarPfld2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+378,0,"CarPfWndo1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"CarPfWndo2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+380,0,"CarPfAN1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"CarPfAN2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+382,0,"CompVid1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+383,0,"CompVid2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"VideoLatch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("Vid_sync", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+258,0,"clk_12",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"clk_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+219,0,"clk6_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"hcount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+191,0,"vcount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+141,0,"hsync",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"hblank",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"vblank",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"vsync",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,0,"vreset",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+220,0,"h_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+207,0,"H256",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"H256_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"H128",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"H64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"H32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"H16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"H8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+221,0,"H8_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"H4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"H4_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"H2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"H1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+191,0,"v_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+214,0,"V128",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"V64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"V32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"V16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"V8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"V4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"V2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"V1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+384,0,"sync_bus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+144,0,"sync_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+493,0,"vblank_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+398,0,"vreset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"hblank_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"hsync_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+494,0,"hsync_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,0,"prom_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+145,0,"prev_H32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"prev_H8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"prev_H256_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"prev_hblank_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"prev_hsync_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"ce_H32_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"ce_H8_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"ce_H256n_fall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"ce_hblank_fall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"ce_hsync_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+223,0,"ce_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("M2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+152,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+384,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+149,0,"old_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vemu___024root__trace_init_top(Vemu___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_init_top\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vemu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vemu___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vemu___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vemu___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vemu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vemu___024root__trace_register(Vemu___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_register\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vemu___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vemu___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vemu___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vemu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vemu___024root__trace_const_0_sub_0(Vemu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vemu___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_const_0\n"); );
    // Body
    Vemu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vemu___024root*>(voidSelf);
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vemu___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vemu___024root__trace_const_0_sub_0(Vemu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_const_0_sub_0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+387,(vlSelfRef.emu__DOT__UART_CTS));
    bufp->fullBit(oldp+388,(vlSelfRef.emu__DOT__UART_RTS));
    bufp->fullBit(oldp+389,(vlSelfRef.emu__DOT__UART_RXD));
    bufp->fullBit(oldp+390,(vlSelfRef.emu__DOT__UART_TXD));
    bufp->fullBit(oldp+391,(vlSelfRef.emu__DOT__UART_DTR));
    bufp->fullBit(oldp+392,(vlSelfRef.emu__DOT__UART_DSR));
    bufp->fullCData(oldp+393,(0x98U),8);
    bufp->fullBit(oldp+394,(vlSelfRef.emu__DOT__audio));
    bufp->fullBit(oldp+395,(vlSelfRef.emu__DOT__locked));
    bufp->fullCData(oldp+396,(vlSelfRef.emu__DOT__sprint_vid),2);
    bufp->fullIData(oldp+397,(0x000057e4U),32);
    bufp->fullBit(oldp+398,(1U));
    bufp->fullBit(oldp+399,(vlSelfRef.emu__DOT__superbug__DOT__HSRes_I));
    bufp->fullBit(oldp+400,(0U));
    bufp->fullBit(oldp+401,(vlSelfRef.emu__DOT__superbug__DOT__CrashIn_n));
    bufp->fullBit(oldp+402,(vlSelfRef.emu__DOT__superbug__DOT__SkidIn_n));
    bufp->fullCData(oldp+403,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout2),8);
    bufp->fullIData(oldp+404,(7U),32);
    bufp->fullIData(oldp+405,(6U),32);
    bufp->fullIData(oldp+406,(5U),32);
    bufp->fullIData(oldp+407,(4U),32);
    bufp->fullIData(oldp+408,(3U),32);
    bufp->fullIData(oldp+409,(2U),32);
    bufp->fullIData(oldp+410,(1U),32);
    bufp->fullIData(oldp+411,(0U),32);
    bufp->fullCData(oldp+412,(0U),6);
    bufp->fullCData(oldp+413,(1U),6);
    bufp->fullCData(oldp+414,(2U),6);
    bufp->fullCData(oldp+415,(3U),6);
    bufp->fullCData(oldp+416,(4U),6);
    bufp->fullCData(oldp+417,(5U),6);
    bufp->fullCData(oldp+418,(6U),6);
    bufp->fullCData(oldp+419,(7U),6);
    bufp->fullCData(oldp+420,(8U),6);
    bufp->fullCData(oldp+421,(9U),6);
    bufp->fullCData(oldp+422,(0x0aU),6);
    bufp->fullCData(oldp+423,(0x0bU),6);
    bufp->fullCData(oldp+424,(0x0cU),6);
    bufp->fullCData(oldp+425,(0x0dU),6);
    bufp->fullCData(oldp+426,(0x0eU),6);
    bufp->fullCData(oldp+427,(0x0fU),6);
    bufp->fullCData(oldp+428,(0x10U),6);
    bufp->fullCData(oldp+429,(0x11U),6);
    bufp->fullCData(oldp+430,(0x12U),6);
    bufp->fullCData(oldp+431,(0x13U),6);
    bufp->fullCData(oldp+432,(0x14U),6);
    bufp->fullCData(oldp+433,(0x15U),6);
    bufp->fullCData(oldp+434,(0x16U),6);
    bufp->fullCData(oldp+435,(0x17U),6);
    bufp->fullCData(oldp+436,(0x18U),6);
    bufp->fullCData(oldp+437,(0x19U),6);
    bufp->fullCData(oldp+438,(0x1aU),6);
    bufp->fullCData(oldp+439,(0x1bU),6);
    bufp->fullCData(oldp+440,(0x1cU),6);
    bufp->fullCData(oldp+441,(0x1dU),6);
    bufp->fullCData(oldp+442,(0x1eU),6);
    bufp->fullCData(oldp+443,(0x1fU),6);
    bufp->fullCData(oldp+444,(0x20U),6);
    bufp->fullCData(oldp+445,(0x21U),6);
    bufp->fullCData(oldp+446,(0x22U),6);
    bufp->fullCData(oldp+447,(0x23U),6);
    bufp->fullCData(oldp+448,(0x24U),6);
    bufp->fullCData(oldp+449,(0x25U),6);
    bufp->fullCData(oldp+450,(0x26U),6);
    bufp->fullCData(oldp+451,(0x27U),6);
    bufp->fullCData(oldp+452,(0x28U),6);
    bufp->fullCData(oldp+453,(0x29U),6);
    bufp->fullCData(oldp+454,(0x2aU),6);
    bufp->fullCData(oldp+455,(0x2bU),6);
    bufp->fullCData(oldp+456,(0x2cU),6);
    bufp->fullCData(oldp+457,(0x2dU),6);
    bufp->fullCData(oldp+458,(0x2eU),6);
    bufp->fullCData(oldp+459,(0x2fU),6);
    bufp->fullCData(oldp+460,(0x30U),6);
    bufp->fullCData(oldp+461,(0x31U),6);
    bufp->fullCData(oldp+462,(0x32U),6);
    bufp->fullCData(oldp+463,(0x33U),6);
    bufp->fullCData(oldp+464,(0x34U),6);
    bufp->fullCData(oldp+465,(0x35U),6);
    bufp->fullCData(oldp+466,(0x36U),6);
    bufp->fullCData(oldp+467,(0x37U),6);
    bufp->fullCData(oldp+468,(0x38U),6);
    bufp->fullCData(oldp+469,(0x39U),6);
    bufp->fullCData(oldp+470,(0x3aU),6);
    bufp->fullCData(oldp+471,(0U),3);
    bufp->fullCData(oldp+472,(1U),3);
    bufp->fullCData(oldp+473,(2U),3);
    bufp->fullCData(oldp+474,(3U),3);
    bufp->fullCData(oldp+475,(4U),3);
    bufp->fullCData(oldp+476,(5U),3);
    bufp->fullCData(oldp+477,(6U),3);
    bufp->fullCData(oldp+478,(7U),3);
    bufp->fullCData(oldp+479,(0U),4);
    bufp->fullCData(oldp+480,(1U),4);
    bufp->fullCData(oldp+481,(2U),4);
    bufp->fullCData(oldp+482,(3U),4);
    bufp->fullCData(oldp+483,(4U),4);
    bufp->fullCData(oldp+484,(5U),4);
    bufp->fullCData(oldp+485,(6U),4);
    bufp->fullCData(oldp+486,(7U),4);
    bufp->fullCData(oldp+487,(8U),4);
    bufp->fullCData(oldp+488,(0U),2);
    bufp->fullCData(oldp+489,(1U),2);
    bufp->fullCData(oldp+490,(2U),2);
    bufp->fullCData(oldp+491,(3U),2);
    bufp->fullBit(oldp+492,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD_en));
    bufp->fullBit(oldp+493,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__vblank_int));
    bufp->fullBit(oldp+494,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_reset));
}

VL_ATTR_COLD void Vemu___024root__trace_full_0_sub_0(Vemu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vemu___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_full_0\n"); );
    // Body
    Vemu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vemu___024root*>(voidSelf);
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vemu___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vemu___024root__trace_full_0_sub_0(Vemu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu___024root__trace_full_0_sub_0\n"); );
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.emu__DOT__sd_lba[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.emu__DOT__sd_lba[1]),32);
    bufp->fullCData(oldp+3,(vlSelfRef.emu__DOT__sd_buff_din[0]),8);
    bufp->fullCData(oldp+4,(vlSelfRef.emu__DOT__sd_buff_din[1]),8);
    bufp->fullSData(oldp+5,(vlSelfRef.emu__DOT__joy),16);
    bufp->fullBit(oldp+6,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset)))));
    bufp->fullBit(oldp+7,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__Reset));
    bufp->fullBit(oldp+8,((1U & ((IData)(vlSelfRef.emu__DOT__btn_left) 
                                 | ((IData)(vlSelfRef.emu__DOT__joy) 
                                    >> 1U)))));
    bufp->fullBit(oldp+9,((1U & ((IData)(vlSelfRef.emu__DOT__btn_right) 
                                 | (IData)(vlSelfRef.emu__DOT__joy)))));
    bufp->fullBit(oldp+10,((1U & ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                  | ((IData)(vlSelfRef.emu__DOT__joy) 
                                     >> 4U)))));
    bufp->fullBit(oldp+11,((1U & ((IData)(vlSelfRef.emu__DOT__btn_gearup) 
                                  | ((IData)(vlSelfRef.emu__DOT__joy) 
                                     >> 5U)))));
    bufp->fullBit(oldp+12,((1U & ((IData)(vlSelfRef.emu__DOT__btn_geardown) 
                                  | ((IData)(vlSelfRef.emu__DOT__joy) 
                                     >> 6U)))));
    bufp->fullBit(oldp+13,((1U & (((IData)(vlSelfRef.emu__DOT__joy) 
                                   >> 7U) | (IData)(vlSelfRef.emu__DOT__btn_nexttrack)))));
    bufp->fullBit(oldp+14,(vlSelfRef.emu__DOT__m_start1));
    bufp->fullBit(oldp+15,((1U & ((IData)(vlSelfRef.emu__DOT__btn_two_players) 
                                  | ((IData)(vlSelfRef.emu__DOT__joy) 
                                     >> 8U)))));
    bufp->fullBit(oldp+16,(vlSelfRef.emu__DOT__m_coin));
    bufp->fullBit(oldp+17,((1U & (~ ((IData)(vlSelfRef.emu__DOT__m_coin) 
                                     | (IData)(vlSelfRef.emu__DOT__btn_coin_1))))));
    bufp->fullBit(oldp+18,((1U & (~ ((IData)(vlSelfRef.emu__DOT__m_coin) 
                                     | (IData)(vlSelfRef.emu__DOT__btn_coin_2))))));
    bufp->fullBit(oldp+19,((1U & (~ ((IData)(vlSelfRef.emu__DOT__m_start1) 
                                     | (IData)(vlSelfRef.emu__DOT__btn_start_1))))));
    bufp->fullBit(oldp+20,((1U & (~ (((IData)(vlSelfRef.emu__DOT__joy) 
                                      >> 7U) | (IData)(vlSelfRef.emu__DOT__btn_nexttrack))))));
    bufp->fullBit(oldp+21,((1U & (~ ((IData)(vlSelfRef.emu__DOT__btn_gas) 
                                     | ((IData)(vlSelfRef.emu__DOT__joy) 
                                        >> 4U))))));
    bufp->fullBit(oldp+22,(((IData)(vlSelfRef.emu__DOT__m_coin) 
                            | (IData)(vlSelfRef.emu__DOT__btn_coin_1))));
    bufp->fullBit(oldp+23,(((IData)(vlSelfRef.emu__DOT__m_coin) 
                            | (IData)(vlSelfRef.emu__DOT__btn_coin_2))));
    bufp->fullCData(oldp+24,(vlSelfRef.emu__DOT__steer),2);
    bufp->fullBit(oldp+25,(vlSelfRef.emu__DOT__gear1));
    bufp->fullBit(oldp+26,(vlSelfRef.emu__DOT__gear2));
    bufp->fullBit(oldp+27,(vlSelfRef.emu__DOT__gear3));
    bufp->fullCData(oldp+28,(vlSelfRef.emu__DOT__gearshift1__DOT__gear),3);
    bufp->fullBit(oldp+29,(vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_up));
    bufp->fullBit(oldp+30,(vlSelfRef.emu__DOT__gearshift1__DOT__unnamedblk1__DOT__old_gear_down));
    bufp->fullCData(oldp+31,(vlSelfRef.emu__DOT__steer1__DOT__state),4);
    bufp->fullBit(oldp+32,((1U & ((IData)(vlSelfRef.emu__DOT__steer) 
                                  >> 1U))));
    bufp->fullBit(oldp+33,((1U & (IData)(vlSelfRef.emu__DOT__steer))));
    bufp->fullBit(oldp+34,((1U & (~ ((IData)(vlSelfRef.emu__DOT__steer) 
                                     >> 1U)))));
    bufp->fullIData(oldp+35,(vlSelfRef.emu__DOT__steer1__DOT__unnamedblk1__DOT__count),32);
    bufp->fullBit(oldp+36,(vlSelfRef.emu__DOT__superbug__DOT__PFWndo));
    bufp->fullCData(oldp+37,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout),8);
    bufp->fullCData(oldp+38,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout),4);
    bufp->fullCData(oldp+39,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout),4);
    bufp->fullCData(oldp+40,(((0x00000010U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Dout))
                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__N3_Dout)
                               : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__M3_Dout))),4);
    bufp->fullCData(oldp+41,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__ShiftData),4);
    bufp->fullCData(oldp+42,((((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q) 
                               << 4U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q))),8);
    bufp->fullCData(oldp+43,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout),8);
    bufp->fullCData(oldp+44,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout),8);
    bufp->fullCData(oldp+45,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout),8);
    bufp->fullBit(oldp+46,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n));
    bufp->fullBit(oldp+47,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IRQ_n)))));
    bufp->fullBit(oldp+48,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__prev_V16));
    bufp->fullCData(oldp+49,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__M1__q),4);
    bufp->fullCData(oldp+50,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____Vcellout__N1__q),4);
    bufp->fullCData(oldp+51,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout),4);
    bufp->fullCData(oldp+52,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout),4);
    bufp->fullCData(oldp+53,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout),4);
    bufp->fullCData(oldp+54,(((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q))
                               ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__E5_Dout)
                               : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q))
                                   ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__H5_Dout)
                                   : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__F5_Dout)))),4);
    bufp->fullCData(oldp+55,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PHP),8);
    bufp->fullBit(oldp+56,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode));
    bufp->fullBit(oldp+57,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n));
    bufp->fullBit(oldp+58,(((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode)) 
                            & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n))));
    bufp->fullBit(oldp+59,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n) 
                                     & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode)) 
                                        & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n)))))));
    bufp->fullBit(oldp+60,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Arrow_n));
    bufp->fullCData(oldp+61,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift),4);
    bufp->fullBit(oldp+62,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n));
    bufp->fullBit(oldp+63,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__VidShift) 
                                     | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfWndo_n))))));
    bufp->fullIData(oldp+64,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__pf_write_count),32);
    bufp->fullBit(oldp+65,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_VBlank_arrow));
    bufp->fullBit(oldp+66,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__prev_H8_pfwndo));
    bufp->fullCData(oldp+67,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__E6__q),4);
    bufp->fullCData(oldp+68,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT____Vcellout__F6__q),4);
    bufp->fullBit(oldp+69,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw));
    bufp->fullBit(oldp+70,(vlSelfRef.emu__DOT__superbug__DOT__VMA));
    bufp->fullBit(oldp+71,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)))));
    bufp->fullSData(oldp+72,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__out_alu),16);
    bufp->fullCData(oldp+73,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_out),8);
    bufp->fullCData(oldp+74,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_code),8);
    bufp->fullCData(oldp+75,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca),8);
    bufp->fullCData(oldp+76,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb),8);
    bufp->fullCData(oldp+77,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc),8);
    bufp->fullSData(oldp+78,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__xreg),16);
    bufp->fullSData(oldp+79,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp),16);
    bufp->fullSData(oldp+80,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea),16);
    bufp->fullSData(oldp+81,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc),16);
    bufp->fullSData(oldp+82,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md),16);
    bufp->fullCData(oldp+83,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv),2);
    bufp->fullBit(oldp+84,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_req));
    bufp->fullBit(oldp+85,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ack));
    bufp->fullCData(oldp+86,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__state),6);
    bufp->fullCData(oldp+87,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl),3);
    bufp->fullCData(oldp+88,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__op_ctrl),2);
    bufp->fullCData(oldp+89,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__md_ctrl),3);
    bufp->fullCData(oldp+90,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__acca_ctrl),3);
    bufp->fullCData(oldp+91,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__accb_ctrl),2);
    bufp->fullCData(oldp+92,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ix_ctrl),3);
    bufp->fullCData(oldp+93,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__cc_ctrl),2);
    bufp->fullCData(oldp+94,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__sp_ctrl),2);
    bufp->fullCData(oldp+95,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left_ctrl),3);
    bufp->fullCData(oldp+96,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right_ctrl),2);
    bufp->fullCData(oldp+97,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__alu_ctrl),6);
    bufp->fullCData(oldp+98,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__addr_ctrl),3);
    bufp->fullCData(oldp+99,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__dout_ctrl),4);
    bufp->fullCData(oldp+100,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__nmi_ctrl),2);
    bufp->fullSData(oldp+101,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__left),16);
    bufp->fullSData(oldp+102,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__right),16);
    bufp->fullSData(oldp+103,(((2U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                ? (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea))
                                : ((4U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
                                    ? 1U : 0U))),16);
    bufp->fullBit(oldp+104,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__carry_in));
    bufp->fullCData(oldp+105,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__daa_reg),8);
    bufp->fullBit(oldp+106,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_lo));
    bufp->fullBit(oldp+107,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__valid_hi));
    bufp->fullBit(oldp+108,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__mul_bit));
    bufp->fullCData(oldp+109,(vlSelfRef.emu__DOT__vid_mono),8);
    bufp->fullBit(oldp+110,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H256_n));
    bufp->fullBit(oldp+111,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hblank_int));
    bufp->fullBit(oldp+112,(vlSelfRef.emu__DOT__lamp));
    bufp->fullBit(oldp+113,(vlSelfRef.emu__DOT__lamp2));
    bufp->fullBit(oldp+114,(vlSelfRef.emu__DOT__superbug__DOT__Flash));
    bufp->fullBit(oldp+115,(vlSelfRef.emu__DOT__superbug__DOT__Attract));
    bufp->fullCData(oldp+116,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__next_state),6);
    bufp->fullCData(oldp+117,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl),3);
    bufp->fullCData(oldp+118,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__iv_ctrl),3);
    bufp->fullBit(oldp+119,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch) 
                                   >> 2U))));
    bufp->fullBit(oldp+120,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch) 
                                   >> 1U))));
    bufp->fullBit(oldp+121,((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch))));
    bufp->fullBit(oldp+122,(vlSelfRef.emu__DOT__superbug__DOT__PCC1));
    bufp->fullBit(oldp+123,(vlSelfRef.emu__DOT__superbug__DOT__PCC2));
    bufp->fullBit(oldp+124,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld));
    bufp->fullCData(oldp+125,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PD),8);
    bufp->fullBit(oldp+126,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__LoadPd));
    bufp->fullBit(oldp+127,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld))));
    bufp->fullBit(oldp+128,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld))));
    bufp->fullCData(oldp+129,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__VideoLatch),3);
    bufp->fullBit(oldp+130,(vlSelfRef.emu__DOT__btn_right));
    bufp->fullBit(oldp+131,(vlSelfRef.emu__DOT__btn_left));
    bufp->fullBit(oldp+132,(vlSelfRef.emu__DOT__btn_gas));
    bufp->fullBit(oldp+133,(vlSelfRef.emu__DOT__btn_gearup));
    bufp->fullBit(oldp+134,(vlSelfRef.emu__DOT__btn_geardown));
    bufp->fullBit(oldp+135,(vlSelfRef.emu__DOT__btn_nexttrack));
    bufp->fullBit(oldp+136,(vlSelfRef.emu__DOT__btn_one_player));
    bufp->fullBit(oldp+137,(vlSelfRef.emu__DOT__btn_two_players));
    bufp->fullBit(oldp+138,(vlSelfRef.emu__DOT__btn_start_1));
    bufp->fullBit(oldp+139,(vlSelfRef.emu__DOT__btn_coin_1));
    bufp->fullBit(oldp+140,(vlSelfRef.emu__DOT__btn_coin_2));
    bufp->fullBit(oldp+141,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int));
    bufp->fullBit(oldp+142,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int));
    bufp->fullBit(oldp+143,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)))));
    bufp->fullCData(oldp+144,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg),4);
    bufp->fullBit(oldp+145,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32));
    bufp->fullBit(oldp+146,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8));
    bufp->fullBit(oldp+147,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int));
    bufp->fullBit(oldp+148,(((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hsync_int)) 
                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int))));
    bufp->fullBit(oldp+149,(vlSelfRef.emu__DOT__unnamedblk1__DOT__old_state));
    bufp->fullBit(oldp+150,((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)) 
                                   & (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                       >> 4U) ^ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                                 >> 5U))))));
    bufp->fullBit(oldp+151,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hsync_int) 
                                      | (IData)(vlSelfRef.emu__DOT__vsync))))));
    bufp->fullCData(oldp+152,(((0x00000080U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_reg) 
                                               << 4U)) 
                               | ((0x00000060U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                                  >> 1U)) 
                                  | (0x0000001fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))))),8);
    bufp->fullBit(oldp+153,((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H32)) 
                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 6U)))));
    bufp->fullBit(oldp+154,((1U & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H8)) 
                                   & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 4U)))));
    bufp->fullSData(oldp+155,(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr),16);
    bufp->fullBit(oldp+156,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en));
    bufp->fullBit(oldp+157,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_0)))));
    bufp->fullBit(oldp+158,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_1)))));
    bufp->fullBit(oldp+159,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select));
    bufp->fullBit(oldp+160,((IData)((0x0400U == (0x0500U 
                                                 & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))));
    bufp->fullBit(oldp+161,((1U & (~ (IData)((0U != 
                                              (0x1800U 
                                               & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+162,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                                      & (0x0400U == 
                                         (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+163,((0U == (0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr) 
                                                   >> 8U)))));
    bufp->fullBit(oldp+164,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__RAMwe));
    bufp->fullBit(oldp+165,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0)))));
    bufp->fullBit(oldp+166,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1)))));
    bufp->fullBit(oldp+167,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2)))));
    bufp->fullSData(oldp+168,((0x000007ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))),11);
    bufp->fullCData(oldp+169,((0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))),8);
    bufp->fullCData(oldp+170,((7U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))),3);
    bufp->fullBit(oldp+171,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_Wren));
    bufp->fullBit(oldp+172,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM));
    bufp->fullBit(oldp+173,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                      & (0x0020U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+174,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                      & (0U == (0x00e0U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+175,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                      & (0x00e0U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+176,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                      & (0x0040U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+177,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                      & (0x0060U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+178,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3) 
                                      & (0x0080U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+179,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3) 
                                      & (0x00a0U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+180,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_3) 
                                      & (0x00c0U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+181,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_11) 
                                      & (0x00c0U == 
                                         (0x00e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+182,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa) 
                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb))))));
    bufp->fullBit(oldp+183,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qa));
    bufp->fullBit(oldp+184,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__M7Qb));
    bufp->fullBit(oldp+185,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_H16));
    bufp->fullBit(oldp+186,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_V8));
    bufp->fullBit(oldp+187,(vlSelfRef.emu__DOT__vsync));
    bufp->fullBit(oldp+188,((0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    bufp->fullBit(oldp+189,((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))));
    bufp->fullSData(oldp+190,((0x000001ffU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                              >> 1U))),9);
    bufp->fullCData(oldp+191,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter),8);
    bufp->fullBit(oldp+192,((0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    bufp->fullBit(oldp+193,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 9U)))));
    bufp->fullBit(oldp+194,((IData)((6U == (6U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))))));
    bufp->fullBit(oldp+195,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 2U))));
    bufp->fullBit(oldp+196,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 4U))));
    bufp->fullBit(oldp+197,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi)))));
    bufp->fullBit(oldp+198,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__nmi));
    bufp->fullBit(oldp+199,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 1U))));
    bufp->fullBit(oldp+200,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 3U))));
    bufp->fullBit(oldp+201,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 4U))));
    bufp->fullBit(oldp+202,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 5U))));
    bufp->fullBit(oldp+203,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 6U))));
    bufp->fullBit(oldp+204,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 7U))));
    bufp->fullBit(oldp+205,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 8U))));
    bufp->fullBit(oldp+206,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 8U)))));
    bufp->fullBit(oldp+207,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                   >> 9U))));
    bufp->fullBit(oldp+208,((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter))));
    bufp->fullBit(oldp+209,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 1U))));
    bufp->fullBit(oldp+210,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 2U))));
    bufp->fullBit(oldp+211,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 3U))));
    bufp->fullBit(oldp+212,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 5U))));
    bufp->fullBit(oldp+213,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 6U))));
    bufp->fullBit(oldp+214,((1U & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                   >> 7U))));
    bufp->fullBit(oldp+215,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                      >> 7U)))));
    bufp->fullCData(oldp+216,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarROM_Dout),4);
    bufp->fullBit(oldp+217,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__Window_en));
    bufp->fullBit(oldp+218,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank));
    bufp->fullBit(oldp+219,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter)))));
    bufp->fullSData(oldp+220,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter),10);
    bufp->fullBit(oldp+221,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 4U)))));
    bufp->fullBit(oldp+222,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                      >> 3U)))));
    bufp->fullBit(oldp+223,((0x0150U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter))));
    bufp->fullBit(oldp+224,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1));
    bufp->fullBit(oldp+225,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0));
    bufp->fullBit(oldp+226,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD2_Sel));
    bufp->fullBit(oldp+227,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD3_Sel));
    bufp->fullBit(oldp+228,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel));
    bufp->fullCData(oldp+229,((3U & (~ (((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R1) 
                                         << 1U) | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__R0))))),2);
    bufp->fullBit(oldp+230,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__prev_CarRot_n));
    bufp->fullSData(oldp+231,((((((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
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
    bufp->fullBit(oldp+232,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g))));
    bufp->fullBit(oldp+233,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g))));
    bufp->fullBit(oldp+234,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g))));
    bufp->fullBit(oldp+235,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g))));
    bufp->fullBit(oldp+236,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g))));
    bufp->fullBit(oldp+237,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g))));
    bufp->fullBit(oldp+238,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g))));
    bufp->fullBit(oldp+239,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g))));
    bufp->fullBit(oldp+240,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g))));
    bufp->fullBit(oldp+241,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__BD4_Sel)
                              ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g)
                              : (IData)(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g))));
    bufp->fullCData(oldp+242,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD),8);
    bufp->fullCData(oldp+243,((0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD))),4);
    bufp->fullCData(oldp+244,((0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__BD) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+245,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din),8);
    bufp->fullCData(oldp+246,((0x0000000fU & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+247,((0x0000000fU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFRAM_Din))),4);
    bufp->fullBit(oldp+248,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V16g));
    bufp->fullBit(oldp+249,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V8g));
    bufp->fullBit(oldp+250,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V4g));
    bufp->fullBit(oldp+251,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V2g));
    bufp->fullBit(oldp+252,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__V1g));
    bufp->fullBit(oldp+253,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H16g));
    bufp->fullBit(oldp+254,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H8g));
    bufp->fullBit(oldp+255,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H4g));
    bufp->fullBit(oldp+256,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H2g));
    bufp->fullBit(oldp+257,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__H1g));
    bufp->fullBit(oldp+258,(vlSelfRef.clk_sys));
    bufp->fullBit(oldp+259,(vlSelfRef.reset));
    bufp->fullBit(oldp+260,(vlSelfRef.soft_reset));
    bufp->fullBit(oldp+261,(vlSelfRef.menu));
    bufp->fullBit(oldp+262,(vlSelfRef.adam));
    bufp->fullIData(oldp+263,(vlSelfRef.joystick_0),32);
    bufp->fullIData(oldp+264,(vlSelfRef.joystick_1),32);
    bufp->fullIData(oldp+265,(vlSelfRef.joystick_2),32);
    bufp->fullIData(oldp+266,(vlSelfRef.joystick_3),32);
    bufp->fullIData(oldp+267,(vlSelfRef.joystick_4),32);
    bufp->fullIData(oldp+268,(vlSelfRef.joystick_5),32);
    bufp->fullSData(oldp+269,(vlSelfRef.joystick_l_analog_0),16);
    bufp->fullSData(oldp+270,(vlSelfRef.joystick_l_analog_1),16);
    bufp->fullSData(oldp+271,(vlSelfRef.joystick_l_analog_2),16);
    bufp->fullSData(oldp+272,(vlSelfRef.joystick_l_analog_3),16);
    bufp->fullSData(oldp+273,(vlSelfRef.joystick_l_analog_4),16);
    bufp->fullSData(oldp+274,(vlSelfRef.joystick_l_analog_5),16);
    bufp->fullSData(oldp+275,(vlSelfRef.joystick_r_analog_0),16);
    bufp->fullSData(oldp+276,(vlSelfRef.joystick_r_analog_1),16);
    bufp->fullSData(oldp+277,(vlSelfRef.joystick_r_analog_2),16);
    bufp->fullSData(oldp+278,(vlSelfRef.joystick_r_analog_3),16);
    bufp->fullSData(oldp+279,(vlSelfRef.joystick_r_analog_4),16);
    bufp->fullSData(oldp+280,(vlSelfRef.joystick_r_analog_5),16);
    bufp->fullCData(oldp+281,(vlSelfRef.paddle_0),8);
    bufp->fullCData(oldp+282,(vlSelfRef.paddle_1),8);
    bufp->fullCData(oldp+283,(vlSelfRef.paddle_2),8);
    bufp->fullCData(oldp+284,(vlSelfRef.paddle_3),8);
    bufp->fullCData(oldp+285,(vlSelfRef.paddle_4),8);
    bufp->fullCData(oldp+286,(vlSelfRef.paddle_5),8);
    bufp->fullSData(oldp+287,(vlSelfRef.spinner_0),9);
    bufp->fullSData(oldp+288,(vlSelfRef.spinner_1),9);
    bufp->fullSData(oldp+289,(vlSelfRef.spinner_2),9);
    bufp->fullSData(oldp+290,(vlSelfRef.spinner_3),9);
    bufp->fullSData(oldp+291,(vlSelfRef.spinner_4),9);
    bufp->fullSData(oldp+292,(vlSelfRef.spinner_5),9);
    bufp->fullSData(oldp+293,(vlSelfRef.ps2_key),11);
    bufp->fullIData(oldp+294,(vlSelfRef.ps2_mouse),25);
    bufp->fullSData(oldp+295,(vlSelfRef.ps2_mouse_ext),16);
    bufp->fullQData(oldp+296,(vlSelfRef.timestamp),33);
    bufp->fullCData(oldp+298,(vlSelfRef.VGA_R),8);
    bufp->fullCData(oldp+299,(vlSelfRef.VGA_G),8);
    bufp->fullCData(oldp+300,(vlSelfRef.VGA_B),8);
    bufp->fullBit(oldp+301,(vlSelfRef.VGA_HS));
    bufp->fullBit(oldp+302,(vlSelfRef.VGA_VS));
    bufp->fullBit(oldp+303,(vlSelfRef.VGA_HB));
    bufp->fullBit(oldp+304,(vlSelfRef.VGA_VB));
    bufp->fullBit(oldp+305,(vlSelfRef.CE_PIXEL));
    bufp->fullSData(oldp+306,(vlSelfRef.AUDIO_L),16);
    bufp->fullSData(oldp+307,(vlSelfRef.AUDIO_R),16);
    bufp->fullSData(oldp+308,(vlSelfRef.dbg_pc),16);
    bufp->fullCData(oldp+309,(vlSelfRef.dbg_opcode),8);
    bufp->fullSData(oldp+310,(vlSelfRef.dbg_addr),16);
    bufp->fullCData(oldp+311,(vlSelfRef.dbg_din),8);
    bufp->fullBit(oldp+312,(vlSelfRef.dbg_op_fetch));
    bufp->fullCData(oldp+313,(vlSelfRef.dbg_acca),8);
    bufp->fullCData(oldp+314,(vlSelfRef.dbg_accb),8);
    bufp->fullCData(oldp+315,(vlSelfRef.dbg_cc),8);
    bufp->fullBit(oldp+316,(vlSelfRef.service_mode));
    bufp->fullBit(oldp+317,(vlSelfRef.ioctl_download));
    bufp->fullBit(oldp+318,(vlSelfRef.ioctl_wr));
    bufp->fullIData(oldp+319,(vlSelfRef.ioctl_addr),25);
    bufp->fullCData(oldp+320,(vlSelfRef.ioctl_dout),8);
    bufp->fullCData(oldp+321,(vlSelfRef.ioctl_index),8);
    bufp->fullBit(oldp+322,(vlSelfRef.ioctl_wait));
    bufp->fullIData(oldp+323,(vlSelfRef.sd_lba[0]),32);
    bufp->fullIData(oldp+324,(vlSelfRef.sd_lba[1]),32);
    bufp->fullSData(oldp+325,(vlSelfRef.sd_rd),10);
    bufp->fullSData(oldp+326,(vlSelfRef.sd_wr),10);
    bufp->fullSData(oldp+327,(vlSelfRef.sd_ack),10);
    bufp->fullSData(oldp+328,(vlSelfRef.sd_buff_addr),9);
    bufp->fullCData(oldp+329,(vlSelfRef.sd_buff_dout),8);
    bufp->fullCData(oldp+330,(vlSelfRef.sd_buff_din[0]),8);
    bufp->fullCData(oldp+331,(vlSelfRef.sd_buff_din[1]),8);
    bufp->fullBit(oldp+332,(vlSelfRef.sd_buff_wr));
    bufp->fullSData(oldp+333,(vlSelfRef.img_mounted),10);
    bufp->fullBit(oldp+334,(vlSelfRef.img_readonly));
    bufp->fullQData(oldp+335,(vlSelfRef.img_size),64);
    bufp->fullBit(oldp+337,((1U & ((IData)(vlSelfRef.ps2_key) 
                                   >> 9U))));
    bufp->fullSData(oldp+338,((0x000001ffU & (IData)(vlSelfRef.ps2_key))),9);
    bufp->fullBit(oldp+339,((1U & (~ (IData)(vlSelfRef.service_mode)))));
    bufp->fullIData(oldp+340,((0x0001ffffU & vlSelfRef.ioctl_addr)),17);
    bufp->fullBit(oldp+341,(vlSelfRef.emu__DOT__superbug__DOT__Phi2));
    bufp->fullBit(oldp+342,(vlSelfRef.emu__DOT__superbug__DOT__CarVideo));
    bufp->fullBit(oldp+343,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo));
    bufp->fullBit(oldp+344,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode) 
                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid))))));
    bufp->fullBit(oldp+345,((1U & (~ ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__CrashCode) 
                                          | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__SkidCode_n))) 
                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid))))));
    bufp->fullBit(oldp+346,(vlSelfRef.emu__DOT__superbug__DOT__Car__DOT__CarRot_n));
    bufp->fullCData(oldp+347,(((IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_0)
                                ? (0x0000007eU | (((IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1) 
                                                   << 7U) 
                                                  | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2)))
                                : ((IData)(vlSelfRef.__VdfgRegularize_h4af1c392_0_1)
                                    ? (0x000000fcU 
                                       | (IData)(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux))
                                    : 0xffU))),8);
    bufp->fullBit(oldp+348,(vlSelfRef.emu__DOT__superbug__DOT__SteerReset_n));
    bufp->fullCData(oldp+349,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__RAM_Addr),7);
    bufp->fullBit(oldp+350,(((~ ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                                     & (0x0400U == 
                                        (0x0500U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) 
                                 & (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))) 
                             & ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Mux_select)))));
    bufp->fullBit(oldp+351,(((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__Sys_en) 
                                 & (0x0400U == (0x0500U 
                                                & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))) 
                             & (0xf0U <= (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)))));
    bufp->fullSData(oldp+352,(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__rom_m3_addr),10);
    bufp->fullBit(oldp+353,((1U & (~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)))));
    bufp->fullBit(oldp+354,((1U & (~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Phi2)) 
                                      | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                                         >> 2U))))));
    bufp->fullCData(oldp+355,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din),8);
    bufp->fullCData(oldp+356,(((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_0)
                                ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM1_Dout)
                                : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_1)
                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM2_Dout)
                                    : ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT____VdfgRegularize_h17664f61_0_2)
                                        ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__ROM3_Dout)
                                        : 0xffU)))),8);
    bufp->fullBit(oldp+357,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn));
    bufp->fullBit(oldp+358,(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__IO_Wr));
    bufp->fullBit(oldp+359,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__SysEn) 
                                      & (0x0260U == 
                                         (0x02e0U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU_Adr))))))));
    bufp->fullBit(oldp+360,(((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter) 
                                 >> 4U)) & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__prev_V16))));
    bufp->fullSData(oldp+361,(((3U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                ? ((0x0000ff00U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea) 
                                                                  >> 7U)))) 
                                                   << 8U)) 
                                   | (0x000000ffU & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea)))
                                : ((6U == (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                    ? 1U : 0U))),16);
    bufp->fullSData(oldp+362,(((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                ? ((2U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                    ? (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc)
                                    : ((1U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__pc_ctrl))
                                        ? (((IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU_Din) 
                                            << 8U) 
                                           | (0x000000ffU 
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
    bufp->fullSData(oldp+363,(((4U & (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__CPU__DOT__ea_ctrl))
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
    bufp->fullBit(oldp+364,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerDir));
    bufp->fullBit(oldp+365,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__SteerFlag));
    bufp->fullBit(oldp+366,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux1));
    bufp->fullBit(oldp+367,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__InputMux2));
    bufp->fullCData(oldp+368,(vlSelfRef.emu__DOT__superbug__DOT__ControlInputs__DOT__DIP_Mux),2);
    bufp->fullSData(oldp+369,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PFROM_Adr),10);
    bufp->fullCData(oldp+370,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PVP),8);
    bufp->fullCData(oldp+371,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PF_RAM_Adr),8);
    bufp->fullBit(oldp+372,((1U & (~ ((0xf0U > (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__v_counter)) 
                                      | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM))))));
    bufp->fullBit(oldp+373,((1U & (~ ((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__CPU__DOT__rw)) 
                                      & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfldRAM))))));
    bufp->fullBit(oldp+374,(vlSelfRef.emu__DOT__superbug__DOT__Playfield__DOT__PfCarVid));
    bufp->fullBit(oldp+375,(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo));
    bufp->fullBit(oldp+376,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                      | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))))));
    bufp->fullBit(oldp+377,((1U & (~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                      | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                         & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))))));
    bufp->fullBit(oldp+378,((1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                       | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                   ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)))));
    bufp->fullBit(oldp+379,((1U & ((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                       | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                          & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                   ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)))));
    bufp->fullBit(oldp+380,((1U & (~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                           | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                       ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                      | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))))));
    bufp->fullBit(oldp+381,((1U & (~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                           | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                              & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                       ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                      | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))))));
    bufp->fullBit(oldp+382,((1U & (~ ((~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                               | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC1) 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                           ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                          | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))) 
                                      | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank))))));
    bufp->fullBit(oldp+383,((1U & (~ ((~ (((~ ((IData)(vlSelfRef.emu__DOT__superbug__DOT__CarVideo) 
                                               | ((IData)(vlSelfRef.emu__DOT__superbug__DOT__PCC2) 
                                                  & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__Pfld)))) 
                                           ^ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__FlashWndo)) 
                                          | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Alpha__DOT__A_NVideo))) 
                                      | (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_mixer__DOT__CompBlank))))));
    bufp->fullCData(oldp+384,(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__sync_bus),4);
    bufp->fullBit(oldp+385,((((IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__h_counter) 
                              >> 9U) & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_H256_n))));
    bufp->fullBit(oldp+386,(((~ (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__hblank_int)) 
                             & (IData)(vlSelfRef.emu__DOT__superbug__DOT__Vid_sync__DOT__prev_hblank_int))));
}
