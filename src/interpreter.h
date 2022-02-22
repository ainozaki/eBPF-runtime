#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <cstdint>

struct ebpf_insn {
  uint8_t opcode;
  uint8_t dst : 4;
  uint8_t src : 4;
  int16_t offset;
  int32_t imm;
};

class Interpreter {
public:
  Interpreter() = default;
  ~Interpreter() = default;

  int ebpf_run(void *ctx, const struct ebpf_insn &insn);
};

#endif // INTERPRETER_H_
