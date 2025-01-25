#include<stdint.h>
#include<stdlib.h>

#include "../include/instruction.h"

#ifdef _WIN32
#define clear_screen() system("cls")
#else
#define clear_screen() system("clear")
#endif

#ifndef CPU_H
#define CPU_H

#define MEMORY_SIZE 16

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

void execute_program(cpu *c);

void memory_dump(cpu *c);

void load_memory(cpu *c, uint8_t *bytes);

void display_cpu(cpu *c);

void execute_instruction(cpu *c);

#endif
