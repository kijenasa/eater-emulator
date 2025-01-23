#include<stdio.h>

#include "../include/memory.h"
#include "../include/register.h"

void memory_in(cpu *c) {
  register_in(c, c->memory[c->memory_address_register]);
}

void memory_out(cpu *c) {
  register_out(c, c->memory[c->memory_address_register]);
}
