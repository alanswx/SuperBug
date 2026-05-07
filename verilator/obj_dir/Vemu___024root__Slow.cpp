// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vemu.h for the primary calling header

#include "Vemu__pch.h"

void Vemu___024root___ctor_var_reset(Vemu___024root* vlSelf);

Vemu___024root::Vemu___024root(Vemu__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vemu___024root___ctor_var_reset(this);
}

void Vemu___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vemu___024root::~Vemu___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
