// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VEMU_H_
#define VERILATED_VEMU_H_  // guard

#include "verilated.h"

class Vemu__Syms;
class Vemu___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vemu VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vemu__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_sys,0,0);
    VL_IN8(&service_mode,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&soft_reset,0,0);
    VL_IN8(&menu,0,0);
    VL_IN8(&adam,0,0);
    VL_IN8(&paddle_0,7,0);
    VL_IN8(&paddle_1,7,0);
    VL_IN8(&paddle_2,7,0);
    VL_IN8(&paddle_3,7,0);
    VL_IN8(&paddle_4,7,0);
    VL_IN8(&paddle_5,7,0);
    VL_OUT8(&VGA_R,7,0);
    VL_OUT8(&VGA_G,7,0);
    VL_OUT8(&VGA_B,7,0);
    VL_OUT8(&VGA_HS,0,0);
    VL_OUT8(&VGA_VS,0,0);
    VL_OUT8(&VGA_HB,0,0);
    VL_OUT8(&VGA_VB,0,0);
    VL_OUT8(&CE_PIXEL,0,0);
    VL_OUT8(&dbg_opcode,7,0);
    VL_OUT8(&dbg_din,7,0);
    VL_OUT8(&dbg_op_fetch,0,0);
    VL_OUT8(&dbg_acca,7,0);
    VL_OUT8(&dbg_accb,7,0);
    VL_OUT8(&dbg_cc,7,0);
    VL_IN8(&ioctl_download,0,0);
    VL_IN8(&ioctl_wr,0,0);
    VL_IN8(&ioctl_dout,7,0);
    VL_IN8(&ioctl_index,7,0);
    VL_OUT8(&ioctl_wait,0,0);
    VL_IN8(&sd_buff_dout,7,0);
    VL_IN8(&sd_buff_wr,0,0);
    VL_IN8(&img_readonly,0,0);
    VL_IN16(&joystick_l_analog_0,15,0);
    VL_IN16(&joystick_l_analog_1,15,0);
    VL_IN16(&joystick_l_analog_2,15,0);
    VL_IN16(&joystick_l_analog_3,15,0);
    VL_IN16(&joystick_l_analog_4,15,0);
    VL_IN16(&joystick_l_analog_5,15,0);
    VL_IN16(&joystick_r_analog_0,15,0);
    VL_IN16(&joystick_r_analog_1,15,0);
    VL_IN16(&joystick_r_analog_2,15,0);
    VL_IN16(&joystick_r_analog_3,15,0);
    VL_IN16(&joystick_r_analog_4,15,0);
    VL_IN16(&joystick_r_analog_5,15,0);
    VL_IN16(&spinner_0,8,0);
    VL_IN16(&spinner_1,8,0);
    VL_IN16(&spinner_2,8,0);
    VL_IN16(&spinner_3,8,0);
    VL_IN16(&spinner_4,8,0);
    VL_IN16(&spinner_5,8,0);
    VL_IN16(&ps2_key,10,0);
    VL_IN16(&ps2_mouse_ext,15,0);
    VL_OUT16(&AUDIO_L,15,0);
    VL_OUT16(&AUDIO_R,15,0);
    VL_OUT16(&dbg_pc,15,0);
    VL_OUT16(&dbg_addr,15,0);
    VL_OUT16(&sd_rd,9,0);
    VL_OUT16(&sd_wr,9,0);
    VL_IN16(&sd_ack,9,0);
    VL_IN16(&sd_buff_addr,8,0);
    VL_IN16(&img_mounted,9,0);
    VL_IN(&joystick_0,31,0);
    VL_IN(&joystick_1,31,0);
    VL_IN(&joystick_2,31,0);
    VL_IN(&joystick_3,31,0);
    VL_IN(&joystick_4,31,0);
    VL_IN(&joystick_5,31,0);
    VL_IN(&ps2_mouse,24,0);
    VL_IN(&ioctl_addr,24,0);
    VL_IN64(&timestamp,32,0);
    VL_IN64(&img_size,63,0);
    VL_OUT((&sd_lba)[2],31,0);
    VL_OUT8((&sd_buff_din)[2],7,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vemu___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vemu(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vemu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vemu();
  private:
    VL_UNCOPYABLE(Vemu);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
