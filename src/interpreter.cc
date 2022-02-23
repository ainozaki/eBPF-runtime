#include "interpreter.h"

#include <cstdint>
#include <iostream>

#include "ebpf.h"
#include "ebpf_inst.h"

int Interpreter::ebpf_run(void *ctx, const struct ebpf_prog &prog) {
  uint64_t reg[REG_MAX];    /* eleven 64bit register */
  uint8_t stack[STACK_MAX]; /* 512 byte large stack */
  uint32_t pc = 0;          /* 100 million of max inst */
  struct ebpf_inst *inst = prog.insts;

  reg[1] = (uint64_t)ctx;
  reg[10] = (uint64_t)(stack + STACK_MAX);

  while (true) {
    inst = inst + pc++;
    switch (inst->opcode) {
    case EBPF_OP_ADD_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] + (uint32_t)reg[inst->src];
      break;
    }
  }

  return 0;
}
