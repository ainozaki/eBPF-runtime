#include "interpreter.h"

#include <cstdint>
#include <iostream>

int Interpreter::ebpf_run(void *ctx, const struct ebpf_insn &insn) {
  std::cout << "opode : " << insn.opcode << std::endl;
  std::cout << "dst   : " << insn.dst << std::endl;
  std::cout << "src   : " << insn.src << std::endl;
  std::cout << "offset: " << insn.offset << std::endl;
  std::cout << "imm   : " << insn.imm << std::endl;
  return 0;
}
