#include "../include/control_logic.h"

#include "../include/register.h"
#include "../include/memory.h"
#include "../include/alu.h"

#include<stdio.h>

static void instruction_fetch(cpu *c) {
  register_out(c, c->program_counter);
  register_in(c, &c->memory_address_register);

  memory_out(c);
  register_in(c, &c->instruction_register);
  c->program_counter++;
}

void instruction_nop(cpu *c) {
  instruction_fetch(c);
}

void instruction_lda(cpu *c) {
  register_out(c, c->instruction_register);
  register_in(c, &c->memory_address_register);

  memory_out(c);
  register_in(c, &c->register_a);

  instruction_fetch(c);
}

void instruction_add(cpu *c) {
  register_out(c, c->instruction_register);
  register_in(c, &c->memory_address_register);

  memory_out(c);
  register_in(c, &c->register_b);

  alu_add(c);
  register_in(c, &c->register_a);

  instruction_fetch(c);
}

void instruction_sub(cpu *c) {
  register_out(c, c->instruction_register);
  register_in(c, &c->memory_address_register);

  memory_out(c);
  register_in(c, &c->register_b);

  alu_sub(c);
  register_in(c, &c->register_a);

  instruction_fetch(c);
}

void instruction_sta(cpu *c) {
  register_out(c, c->instruction_register);
  register_in(c, &c->memory_address_register);

  register_out(c, c->register_a);
  memory_in(c);

  instruction_fetch(c);
}

void instruction_ldi(cpu *c) {
  register_out(c, c->instruction_register);
  register_in(c, &c->register_a);

  instruction_fetch(c);
}

void instruction_jmp(cpu *c) {
  register_out(c, c->instruction_register);
  register_in(c, &c->program_counter);

  instruction_fetch(c);
}

void instruction_jc(cpu *c) {
  if(c->flags[CARRY]) {
    register_out(c, c->instruction_register);
    register_in(c, &c->program_counter);
  }

  instruction_fetch(c);
}

void instruction_jz(cpu *c) {
  if(c->flags[IS_ZERO]) {
    register_out(c, c->instruction_register);
    register_in(c, &c->program_counter);
  }

  instruction_fetch(c);
}

void instruction_out(cpu *c) {
  register_out(c, c->register_a);
  register_in(c, &c->output_register);

  instruction_fetch(c);
}

void instruction_hlt(cpu *c) {
  c->halt = 1;

  instruction_fetch(c);

}
