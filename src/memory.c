#include<stdio.h>

#include "../include/memory.h"
#include "../include/register.h"

// TODO: make the addressing "circular" so i dont have to convert everything to 4 bits

void memory_in(cpu *c) {
  register_in(c, &c->memory[c->memory_address_register]);
}

void memory_out(cpu *c) {
  register_out(c, c->memory[c->memory_address_register]);
}
