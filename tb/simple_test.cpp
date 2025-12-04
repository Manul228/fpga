// tb/simple_test.cpp
#include "Vcounter.h"
#include "verilated.h"
#include <systemc>
#include <iostream>

using namespace sc_core;

int sc_main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);

    Vcounter top("top");

    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> rst_n("rst_n");
    sc_signal<bool> en("en");
    sc_signal<uint32_t> count_out("count_out");  // ← сигнал для выхода

    // Подключаем ВСЕ порты
    top.clk(clk);
    top.rst_n(rst_n);
    top.en(en);
    top.count(count_out);  // ← обязательно!

    rst_n = false;
    en = false;
    sc_start(10, SC_NS);

    rst_n = true;
    en = true;

    for (int i = 0; i < 10; ++i) {
        sc_start(10, SC_NS);
        std::cout << "Count = " << count_out.read() << std::endl;
    }

    return 0;
}