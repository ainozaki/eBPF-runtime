#include "interpreter.h"

#include <iostream>

int main(int argc, char *argv[]) {
  int *ctx;
  struct ebpf_insn insn;
  Interpreter interpreter;

  int err = interpreter.ebpf_run((void *)ctx, insn);
  if (err) {
    std::cout << "Error while executing ebpf program" << std::endl;
  }
}
