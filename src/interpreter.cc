#include "interpreter.h"

#include <cstdint>
#include <iostream>

#include "ebpf_inst.h"

int Interpreter::ebpf_run(void *ctx, const struct ebpf_inst &inst) {
  std::cout << "opode : " << inst.opcode << std::endl;
  std::cout << "dst   : " << inst.dst << std::endl;
  std::cout << "src   : " << inst.src << std::endl;
  std::cout << "offset: " << inst.offset << std::endl;
  std::cout << "imm   : " << inst.imm << std::endl;
  return 0;
}
