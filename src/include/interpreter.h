#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <cstdint>

#include "ebpf_inst.h"

class Interpreter {
public:
  Interpreter() = default;
  ~Interpreter() = default;

  int ebpf_run(void *ctx, const struct ebpf_prog &prog);
};

#endif // INTERPRETER_H_
