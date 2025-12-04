VERILATOR = verilator
CXX = g++

SYSTEMC_HOME ?= /usr/local/systemc
VERILATOR_INCLUDE = /usr/local/verilator/share/verilator/include

RTL = rtl/counter.sv
OBJ_DIR = obj_dir

all: sim_simple

$(OBJ_DIR)/Vcounter.cpp: $(RTL)
	env -u VERILATOR_ROOT $(VERILATOR) -cc --exe -Mdir $(OBJ_DIR) --sc $(RTL)

sim_simple: $(OBJ_DIR)/Vcounter.cpp
	cd $(OBJ_DIR) && \
	g++ -std=c++17 \
		-I. \
		-I/usr/local/verilator/share/verilator/include \
		-I/usr/local/systemc/include \
		-L/usr/local/systemc/lib-linux64 -lsystemc -lpthread \
		$(CURDIR)/tb/simple_test.cpp Vcounter.cpp \
		-o sim_simple

clean:
	rm -rf $(OBJ_DIR) sim_simple wave.vcd

.PHONY: all clean