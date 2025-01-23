#include "../include/alu.h"
#include "../include/register.h"

void alu_add(cpu *c) {
  int result = c->register_a + c->register_b;
  c->flags[IS_ZERO] = result == 0 ? 1 : 0;
  c->flags[CARRY] = result > 255 ? 1 : 0;
  register_out(c, (uint8_t) result);
}

void alu_sub(cpu *c) {
  int result = c->register_a - c->register_b;
  c->flags[IS_ZERO] = result == 0 ? 1 : 0;
  c->flags[CARRY] = result > 255 ? 1 : 0;
  register_out(c, (uint8_t) result);
}
