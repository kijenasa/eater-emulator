#include "../include/cpu.h"
#include "../include/register.h"

void register_out(cpu *c, uint8_t r) {
  c->bus = r;
}

void register_in(cpu *c, uint8_t *r) {
  *r = c->bus;
}
