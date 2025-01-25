#include<stdint.h>

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

uint8_t get_parameter(uint8_t instruction);

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
