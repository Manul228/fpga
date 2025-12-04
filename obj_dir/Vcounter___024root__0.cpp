// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter.h for the primary calling header

#include "Vcounter__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vcounter___024root___eval_triggers__ico(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_triggers__ico\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcounter___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vcounter___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___trigger_anySet__ico\n"); );
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

void Vcounter___024root___ico_sequent__TOP__0(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___ico_sequent__TOP__0\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_ASSIGN_ISI(1, vlSelfRef.__Vcellinp__counter__rst_n, vlSelfRef.rst_n);
    VL_ASSIGN_ISI(1, vlSelfRef.__Vcellinp__counter__clk, vlSelfRef.clk);
    VL_ASSIGN_ISI(1, vlSelfRef.__Vcellinp__counter__en, vlSelfRef.en);
}

void Vcounter___024root___eval_ico(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_ico\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vcounter___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vcounter___024root___eval_phase__ico(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_phase__ico\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vcounter___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vcounter___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vcounter___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vcounter___024root___eval_triggers__act(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_triggers__act\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.__Vcellinp__counter__rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP____Vcellinp__counter__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.__Vcellinp__counter__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP____Vcellinp__counter__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP____Vcellinp__counter__clk__0 
        = vlSelfRef.__Vcellinp__counter__clk;
    vlSelfRef.__Vtrigprevexpr___TOP____Vcellinp__counter__rst_n__0 
        = vlSelfRef.__Vcellinp__counter__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcounter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vcounter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___trigger_anySet__act\n"); );
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

void Vcounter___024root___nba_sequent__TOP__0(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___nba_sequent__TOP__0\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__Vcellinp__counter__rst_n) {
        if (vlSelfRef.__Vcellinp__counter__en) {
            vlSelfRef.__Vcellout__counter__count = 
                (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vcellout__counter__count)));
        }
    } else {
        vlSelfRef.__Vcellout__counter__count = 0U;
    }
    VL_ASSIGN_SII(8, vlSelfRef.count, vlSelfRef.__Vcellout__counter__count);
}

void Vcounter___024root___eval_nba(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_nba\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vcounter___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vcounter___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vcounter___024root___eval_phase__act(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_phase__act\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcounter___024root___eval_triggers__act(vlSelf);
    Vcounter___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vcounter___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vcounter___024root___eval_phase__nba(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_phase__nba\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vcounter___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vcounter___024root___eval_nba(vlSelf);
        Vcounter___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vcounter___024root___eval(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vcounter___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("rtl/counter.sv", 2, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vcounter___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vcounter___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("rtl/counter.sv", 2, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vcounter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("rtl/counter.sv", 2, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vcounter___024root___eval_phase__act(vlSelf));
    } while (Vcounter___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vcounter___024root___eval_debug_assertions(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_debug_assertions\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
