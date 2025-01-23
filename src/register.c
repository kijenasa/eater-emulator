#include "../include/cpu.h"
#include "../include/register.h"

static uint8_t register_write(uint8_t *r, uint8_t value) {
  *r = value;
}

void register_out(cpu *c, uint8_t *r) {
  register_write(c->bus, *r);
}

void register_in(cpu *c, uint8_t *r) {
  register_write(r, c->bus);
}
