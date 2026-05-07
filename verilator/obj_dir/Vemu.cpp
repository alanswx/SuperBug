// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vemu__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vemu::Vemu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vemu__Syms(contextp(), _vcname__, this)}
    , clk_sys{vlSymsp->TOP.clk_sys}
    , service_mode{vlSymsp->TOP.service_mode}
    , reset{vlSymsp->TOP.reset}
    , soft_reset{vlSymsp->TOP.soft_reset}
    , menu{vlSymsp->TOP.menu}
    , adam{vlSymsp->TOP.adam}
    , paddle_0{vlSymsp->TOP.paddle_0}
    , paddle_1{vlSymsp->TOP.paddle_1}
    , paddle_2{vlSymsp->TOP.paddle_2}
    , paddle_3{vlSymsp->TOP.paddle_3}
    , paddle_4{vlSymsp->TOP.paddle_4}
    , paddle_5{vlSymsp->TOP.paddle_5}
    , VGA_R{vlSymsp->TOP.VGA_R}
    , VGA_G{vlSymsp->TOP.VGA_G}
    , VGA_B{vlSymsp->TOP.VGA_B}
    , VGA_HS{vlSymsp->TOP.VGA_HS}
    , VGA_VS{vlSymsp->TOP.VGA_VS}
    , VGA_HB{vlSymsp->TOP.VGA_HB}
    , VGA_VB{vlSymsp->TOP.VGA_VB}
    , CE_PIXEL{vlSymsp->TOP.CE_PIXEL}
    , dbg_opcode{vlSymsp->TOP.dbg_opcode}
    , dbg_din{vlSymsp->TOP.dbg_din}
    , dbg_op_fetch{vlSymsp->TOP.dbg_op_fetch}
    , dbg_acca{vlSymsp->TOP.dbg_acca}
    , dbg_accb{vlSymsp->TOP.dbg_accb}
    , dbg_cc{vlSymsp->TOP.dbg_cc}
    , ioctl_download{vlSymsp->TOP.ioctl_download}
    , ioctl_wr{vlSymsp->TOP.ioctl_wr}
    , ioctl_dout{vlSymsp->TOP.ioctl_dout}
    , ioctl_index{vlSymsp->TOP.ioctl_index}
    , ioctl_wait{vlSymsp->TOP.ioctl_wait}
    , sd_buff_dout{vlSymsp->TOP.sd_buff_dout}
    , sd_buff_wr{vlSymsp->TOP.sd_buff_wr}
    , img_readonly{vlSymsp->TOP.img_readonly}
    , joystick_l_analog_0{vlSymsp->TOP.joystick_l_analog_0}
    , joystick_l_analog_1{vlSymsp->TOP.joystick_l_analog_1}
    , joystick_l_analog_2{vlSymsp->TOP.joystick_l_analog_2}
    , joystick_l_analog_3{vlSymsp->TOP.joystick_l_analog_3}
    , joystick_l_analog_4{vlSymsp->TOP.joystick_l_analog_4}
    , joystick_l_analog_5{vlSymsp->TOP.joystick_l_analog_5}
    , joystick_r_analog_0{vlSymsp->TOP.joystick_r_analog_0}
    , joystick_r_analog_1{vlSymsp->TOP.joystick_r_analog_1}
    , joystick_r_analog_2{vlSymsp->TOP.joystick_r_analog_2}
    , joystick_r_analog_3{vlSymsp->TOP.joystick_r_analog_3}
    , joystick_r_analog_4{vlSymsp->TOP.joystick_r_analog_4}
    , joystick_r_analog_5{vlSymsp->TOP.joystick_r_analog_5}
    , spinner_0{vlSymsp->TOP.spinner_0}
    , spinner_1{vlSymsp->TOP.spinner_1}
    , spinner_2{vlSymsp->TOP.spinner_2}
    , spinner_3{vlSymsp->TOP.spinner_3}
    , spinner_4{vlSymsp->TOP.spinner_4}
    , spinner_5{vlSymsp->TOP.spinner_5}
    , ps2_key{vlSymsp->TOP.ps2_key}
    , ps2_mouse_ext{vlSymsp->TOP.ps2_mouse_ext}
    , AUDIO_L{vlSymsp->TOP.AUDIO_L}
    , AUDIO_R{vlSymsp->TOP.AUDIO_R}
    , dbg_pc{vlSymsp->TOP.dbg_pc}
    , dbg_addr{vlSymsp->TOP.dbg_addr}
    , sd_rd{vlSymsp->TOP.sd_rd}
    , sd_wr{vlSymsp->TOP.sd_wr}
    , sd_ack{vlSymsp->TOP.sd_ack}
    , sd_buff_addr{vlSymsp->TOP.sd_buff_addr}
    , img_mounted{vlSymsp->TOP.img_mounted}
    , joystick_0{vlSymsp->TOP.joystick_0}
    , joystick_1{vlSymsp->TOP.joystick_1}
    , joystick_2{vlSymsp->TOP.joystick_2}
    , joystick_3{vlSymsp->TOP.joystick_3}
    , joystick_4{vlSymsp->TOP.joystick_4}
    , joystick_5{vlSymsp->TOP.joystick_5}
    , ps2_mouse{vlSymsp->TOP.ps2_mouse}
    , ioctl_addr{vlSymsp->TOP.ioctl_addr}
    , timestamp{vlSymsp->TOP.timestamp}
    , img_size{vlSymsp->TOP.img_size}
    , sd_lba{vlSymsp->TOP.sd_lba}
    , sd_buff_din{vlSymsp->TOP.sd_buff_din}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vemu::Vemu(const char* _vcname__)
    : Vemu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vemu::~Vemu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vemu___024root___eval_debug_assertions(Vemu___024root* vlSelf);
#endif  // VL_DEBUG
void Vemu___024root___eval_static(Vemu___024root* vlSelf);
void Vemu___024root___eval_initial(Vemu___024root* vlSelf);
void Vemu___024root___eval_settle(Vemu___024root* vlSelf);
void Vemu___024root___eval(Vemu___024root* vlSelf);

void Vemu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vemu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vemu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vemu___024root___eval_static(&(vlSymsp->TOP));
        Vemu___024root___eval_initial(&(vlSymsp->TOP));
        Vemu___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vemu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vemu::eventsPending() { return false; }

uint64_t Vemu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vemu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vemu___024root___eval_final(Vemu___024root* vlSelf);

VL_ATTR_COLD void Vemu::final() {
    Vemu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vemu::hierName() const { return vlSymsp->name(); }
const char* Vemu::modelName() const { return "Vemu"; }
unsigned Vemu::threads() const { return 1; }
void Vemu::prepareClone() const { contextp()->prepareClone(); }
void Vemu::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vemu::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vemu___024root__trace_decl_types(VerilatedVcd* tracep);

void Vemu___024root__trace_init_top(Vemu___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vemu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vemu___024root*>(voidSelf);
    Vemu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vemu___024root__trace_decl_types(tracep);
    Vemu___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vemu___024root__trace_register(Vemu___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vemu::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vemu::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vemu___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
