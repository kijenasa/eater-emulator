#include "../include/cpu.h"

cpu *cpu_new() {
  cpu *out = malloc(sizeof(cpu));
  out->bus = 0;
  out->register_a = 0;
  out->register_b = 0;
  out->instruction_register = 0;
  out->memory_address_register = 0;
  out->output_register = 0;
  out->program_counter = 0;
  return out;
}

void cpu_free(cpu *c) {
  free(c);
}
