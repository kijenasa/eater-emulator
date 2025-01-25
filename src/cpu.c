#include<stdio.h>

#include "../include/cpu.h"
#include "../include/control_logic.h"

#include "../include/diagram.h"

cpu *cpu_new() {
  cpu *out = malloc(sizeof(cpu));

  out->halt = 0;
  out->flags[CARRY] = 0;
  out->flags[IS_ZERO] = 0;
  out->bus = 0;
  out->register_a = 0;
  out->register_b = 0;
  out->instruction_register = 0;
  out->memory_address_register = 0;
  out->output_register = 0;
  out->program_counter = 0;
  for(int i = 0; i <= MEMORY_SIZE; i++) {
    out->memory[i] = 0;
  }
  return out;
}

void cpu_free(cpu *c) {
  free(c);
}

void execute_program(cpu *c, uint8_t mode) {
  while(!c->halt) {
    if(mode == VISUAL) {
      display_cpu(c);
      getchar();
    }
    execute_instruction(c);
  }
}

void load_memory(cpu *c, uint8_t *bytes) {
  for(int i = 0; i < MEMORY_SIZE; i++) {
    c->memory[i] = bytes[i];
  }
}

void display_cpu(cpu *c) {
//  clear_screen();
  DIAGRAM(c->program_counter % 16,
          c->memory_address_register % MEMORY_SIZE,
          c->register_a,
          c->memory[c->memory_address_register % MEMORY_SIZE],
          c->instruction_register,
          c->register_b,
          c->output_register,
          c->bus);
}

void execute_instruction(cpu *c) {
  switch((opcode) c->instruction_register % MEMORY_SIZE) {
    case NOP: instruction_nop(c); break;
    case LDA: instruction_lda(c); break;
    case ADD: instruction_add(c); break;
    case SUB: instruction_sub(c); break;
    case STA: instruction_sta(c); break;
    case LDI: instruction_ldi(c); break;
    case JMP: instruction_jmp(c); break;
    case JC:  instruction_jc(c);  break;
    case JZ:  instruction_jz(c);  break;
    case OUT: instruction_out(c); break;
    case HLT: instruction_hlt(c); break;
  }
}
