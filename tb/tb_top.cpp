// tb/tb_top.cpp
#include "Vcounter.h"               // сгенерировано Verilator'ом
#include "verilated.h"
#include "verilated_sc.h"
#include <systemc>

SC_MODULE(Top) {
    sc_in<bool> clk;
    sc_in<bool> rst_n;
    sc_in<bool> en;
    sc_out<sc_bv<8>> count;

    Vcounter* dut;

    SC_CTOR(Top) {
        dut = new Vcounter("dut");
        dut->clk(clk.read());
        dut->rst_n(rst_n.read());
        dut->en(en.read());
        // Подключаем вывод
        // Verilator использует свои типы, поэтому копируем вручную в sc_method
    }

    // Метод для обновления вывода
    void update_outputs() {
        count.write(dut->count);
    }

    // Clock process (Verilator требует явного вызова eval())
    void clock_proc() {
        while (true) {
            dut->eval();  // Обновляем логику
            update_outputs();
            wait();       // Ждём следующий фронт clk
        }
    }

    // Инициализация
    void init() {
        dut->rst_n = 0;
        dut->en = 0;
        wait(2);
        dut->rst_n = 1;
        dut->en = 1;
    }

    SC_HAS_PROCESS(Top);
    Top(sc_module_name nm) : sc_module(nm) {
        SC_THREAD(init);
        SC_CTHREAD(clock_proc, clk);
    }

    ~Top() {
        delete dut;
    }
};