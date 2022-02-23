#include "interpreter.h"

#include <cstdint>
#include <iostream>

#include "ebpf.h"
#include "ebpf_inst.h"

enum ErrorMessage {
  DIVIDE_BY_ZERO,
};

const char *error_message_table[] = {
    "divide by zero at PC %u\n",
};

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
    case EBPF_OP_ADD_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] + (uint32_t)(inst->imm);
      break;
    case EBPF_OP_SUB_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] - (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_SUB_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] - (uint32_t)(inst->imm);
      break;
    case EBPF_OP_MUL_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] * (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_MUL_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] * (uint32_t)(inst->imm);
      break;
    case EBPF_OP_DIV_REG:
      if (reg[inst->src] == 0) {
        fprintf(stderr, error_message_table[DIVIDE_BY_ZERO], pc);
        return -1;
      }
      reg[inst->dst] = (uint32_t)reg[inst->dst] / (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_DIV_IMM:
      if (inst->imm == 0) {
        fprintf(stderr, error_message_table[DIVIDE_BY_ZERO], pc);
        return -1;
      }
      reg[inst->dst] = (uint32_t)reg[inst->dst] / (uint32_t)(inst->imm);
      break;
    case EBPF_OP_OR_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] | (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_OR_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] | (uint32_t)(inst->imm);
      break;
    case EBPF_OP_AND_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] & (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_AND_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] & (uint32_t)(inst->imm);
      break;
    case EBPF_OP_LSH_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] << (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_LSH_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] << (uint32_t)(inst->imm);
      break;
    case EBPF_OP_RSH_REG:
    /*TODO: Really? */
    case EBPF_OP_ARSH_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] >> (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_RSH_IMM:
    /*TODO: Really? */
    case EBPF_OP_ARSH_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] >> (uint32_t)(inst->imm);
      break;
    case EBPF_OP_NEG:
      reg[inst->dst] = -(uint32_t)reg[inst->dst];
      break;
    case EBPF_OP_MOD_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] % (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_MOD_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] % (uint32_t)(inst->imm);
      break;
    case EBPF_OP_XOR_REG:
      reg[inst->dst] = (uint32_t)reg[inst->dst] ^ (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_XOR_IMM:
      reg[inst->dst] = (uint32_t)reg[inst->dst] ^ (uint32_t)(inst->imm);
      break;
    case EBPF_OP_MOV_REG:
      reg[inst->dst] = (uint32_t)reg[inst->src];
      break;
    case EBPF_OP_MOV_IMM:
      reg[inst->dst] = (uint32_t)(inst->imm);
      break;
    default:
      fprintf(stderr, "Unknown opcode.\n");
      return -1;
    }
  }

  return 0;
}
