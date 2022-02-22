#include <iostream>

#include "ebpf_inst.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {
  int *ctx;
  struct ebpf_inst inst;
  Interpreter interpreter;

  int err = interpreter.ebpf_run((void *)ctx, inst);
  if (err) {
    std::cout << "Error while executing ebpf program" << std::endl;
  }
}
