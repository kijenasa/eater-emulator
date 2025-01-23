#include<stdio.h>

#include "../include/memory.h"
#include "../include/register.h"

void memory_in(cpu *cm int addr) {
  register_in(c, c->memory[addr]);
}

void memory_out(cpu *c, int addr) {
  register_out(c, c->memory[addr]);
}
