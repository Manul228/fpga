// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcounter.h for the primary calling header

#ifndef VERILATED_VCOUNTER___024ROOT_H_
#define VERILATED_VCOUNTER___024ROOT_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"


class Vcounter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcounter___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ __Vcellout__counter__count;
    CData/*0:0*/ __Vcellinp__counter__en;
    CData/*0:0*/ __Vcellinp__counter__rst_n;
    CData/*0:0*/ __Vcellinp__counter__clk;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP____Vcellinp__counter__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP____Vcellinp__counter__rst_n__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    sc_core::sc_in<bool> clk;
    sc_core::sc_in<bool> rst_n;
    sc_core::sc_in<bool> en;
    sc_core::sc_out<uint32_t> count;

    // INTERNAL VARIABLES
    Vcounter__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcounter___024root(Vcounter__Syms* symsp, const char* v__name);
    ~Vcounter___024root();
    VL_UNCOPYABLE(Vcounter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
