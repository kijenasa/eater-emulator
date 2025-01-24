#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef enum {
  NOP,
  LDA,
  ADD,
  SUB,
  STA,
  LDI,
  JMP,
  JC,
  JZ,
  OUT,
  HLT
} opcode;

#endif
