#ifndef EBPF_INST_H_
#define EBPF_INST_H_

struct ebpf_inst {
  uint8_t opcode;
  uint8_t dst : 4;
  uint8_t src : 4;
  int16_t offset;
  int32_t imm;
};

/* Class */
#define EBPF_CLASS_LD    0x00
#define EBPF_CLASS_LDX   0x01
#define EBPF_CLASS_ST    0x02
#define EBPF_CLASS_STX   0x03
#define EBPF_CLASS_ALU   0x04
#define EBPF_CLASS_JMP   0x05
#define EBPF_CLASS_ALU64 0x07

/* ALU field */
#define EBPF_OP(code) ((code)&0xf0)
#define EBPF_SRC_IMM  0x00
#define EBPF_SRC_REG  0x08
#define EBPF_TO_LE    0x00
#define EBPF_TO_BE    0x08

#define EBPF_ADD  0x00
#define EBPF_SUB  0x10
#define EBPF_MUL  0x20
#define EBPF_DIV  0x30
#define EBPF_OR   0x40
#define EBPF_AND  0x50
#define EBPF_LSH  0x60
#define EBPF_RSH  0x70
#define EBPF_NEG  0x80
#define EBPF_MOD  0x90
#define EBPF_XOR  0xa0
#define EBPF_MOV  0xb0
#define EBPF_ARSH 0xc0
#define EBPF_END  0xd0

#define EBPF_OP_ADD_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_ADD)
#define EBPF_OP_ADD_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_ADD)
#define EBPF_OP_SUB_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_SUB)
#define EBPF_OP_SUB_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_SUB)
#define EBPF_OP_MUL_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_MUL)
#define EBPF_OP_MUL_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_MUL)
#define EBPF_OP_DIV_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_DIV)
#define EBPF_OP_DIV_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_DIV)
#define EBPF_OP_OR_IMM   (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_OR)
#define EBPF_OP_OR_REG   (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_OR)
#define EBPF_OP_AND_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_AND)
#define EBPF_OP_AND_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_AND)
#define EBPF_OP_LSH_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_LSH)
#define EBPF_OP_LSH_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_LSH)
#define EBPF_OP_RSH_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_RSH)
#define EBPF_OP_RSH_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_RSH)
#define EBPF_OP_NEG      (EBPF_CLASS_ALU | EBPF_NEG)
#define EBPF_OP_MOD_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_MOD)
#define EBPF_OP_MOD_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_MOD)
#define EBPF_OP_XOR_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_XOR)
#define EBPF_OP_XOR_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_XOR)
#define EBPF_OP_MOV_IMM  (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_MOV)
#define EBPF_OP_MOV_REG  (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_MOV)
#define EBPF_OP_ARSH_IMM (EBPF_CLASS_ALU | EBPF_SRC_IMM | EBPF_ARSH)
#define EBPF_OP_ARSH_REG (EBPF_CLASS_ALU | EBPF_SRC_REG | EBPF_ARSH)
#define EBPF_OP_LE       (EBPF_CLASS_ALU | EBPF_TO_LE)
#define EBPF_OP_BE       (EBPF_CLASS_ALU | EBPF_TO_BE)

#endif // EBPF_INST_H_
