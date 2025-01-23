#include "../include/cpu.h"
#include "../include/register.h"
#include "../include/bus.h"

static uint8_t register_read(cpu *c) {
  return c->program_counter;
}

static uint8_t register_write(cpu *c, uint8_t value) {
  c->program_counter = value;
}

void register_out(reg *r) {
  bus_write(c, program_counter_read(c));
}

void register_in(reg *r) {
  register_write(c, bus_read(c));
}
