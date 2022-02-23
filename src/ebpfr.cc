#include <iostream>

#include "ebpf.h"
#include "ebpf_inst.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {
  int *ctx;
  struct ebpf_prog prog;
  Interpreter interpreter;

  int err = interpreter.ebpf_run((void *)ctx, prog);
  if (err) {
    std::cout << "Error while executing ebpf program" << std::endl;
  }
}
