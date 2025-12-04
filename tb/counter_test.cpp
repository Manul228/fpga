// tb/counter_test.cpp
#include <uvm>

class counter_env : public uvm::uvm_env {
public:
    UVM_COMPONENT_UTILS(counter_env);
    counter_env(uvm::uvm_component_name name) : uvm::uvm_env(name) {}

    void build_phase(uvm::uvm_phase& phase) override {
        UVM_INFO("COUNTER_ENV", "Build phase", UVM_LOW);
    }

    void run_phase(uvm::uvm_phase& phase) override {
        UVM_INFO("COUNTER_ENV", "Starting test", UVM_LOW);
        phase.raise_objection(this);
        // Просто подождём 20 тактов
        sc_core::wait(20, sc_core::SC_NS);
        phase.drop_objection(this);
        UVM_INFO("COUNTER_ENV", "Test done", UVM_LOW);
    }
};

class counter_test : public uvm::uvm_test {
public:
    counter_env* env;
    UVM_COMPONENT_UTILS(counter_test);
    counter_test(uvm::uvm_component_name name) : uvm::uvm_test(name) {}

    void build_phase(uvm::uvm_phase& phase) override {
        env = counter_env::type_id::create("env", this);
    }
};

// Регистрируем тест
int sc_main(int argc, char* argv[]) {
    counter_test::type_id::set_type_override("counter_test");
    uvm::uvm_root::get()->set_default_phase_timeout(100, sc_core::SC_NS);
    uvm::run_test("counter_test");
    return 0;
}