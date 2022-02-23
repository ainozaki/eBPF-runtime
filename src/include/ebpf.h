#ifndef EBPF_H_
#define EBPF_H_

#define REG_MAX   11
#define STACK_MAX 512

struct ebpf_inst {
  uint8_t opcode;
  uint8_t dst : 4;
  uint8_t src : 4;
  int16_t offset;
  int32_t imm;
};

struct ebpf_prog {
  struct ebpf_inst *insts;
};

#endif // EBPF_H_
