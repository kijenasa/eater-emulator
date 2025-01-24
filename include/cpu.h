#include<stdint.h>
#include<stdlib.h>

#include "../include/instruction.h"

#ifndef CPU_H
#define CPU_H

#define MEMORY_SIZE 16

// Index positions of flags[]
#define CARRY 0
#define IS_ZERO 1

typedef struct {
  uint8_t halt;
  uint8_t flags[2];
  uint8_t bus;
  uint8_t register_a;
  uint8_t register_b;
  uint8_t instruction_register;
  uint8_t memory_address_register;
  uint8_t output_register;
  uint8_t program_counter;
  uint8_t memory[MEMORY_SIZE];
} cpu;

cpu *cpu_new();

void cpu_free(cpu *c);

void execute_program(cpu *c, uint8_t visual);

void display_cpu(cpu *c);

void execute_instruction(cpu *c);

#endif
