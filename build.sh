#!/bin/bash
rm -rf obj_dir

set -e
verilator -cc --exe --build -Mdir obj_dir --sc \
    -CFLAGS "-I/usr/local/systemc/include -std=c++17" \
    -LDFLAGS "-L/usr/local/systemc/lib-linux64 -lsystemc -lpthread" \
    tb/simple_test.cpp \
    rtl/counter.sv