#include<stdint.h>
#include<stdlib.h>

#define MEMORY_SIZE;

typedef struct {
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

void execute_instruction(cpu *c); // TODO: add param for instruction
