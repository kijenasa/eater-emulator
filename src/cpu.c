#include "../include/cpu.h"

cpu *cpu_new() {
  cpu *out = malloc(sizeof(cpu));

  out->halt = 0;
  out->flags = {0,0};
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

void execute_instruction(cpu *c, instruction inst) {
  switch(inst) {
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
