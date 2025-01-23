#include "../include/cpu.h"

#ifndef REGISTER_H
#define REGISTER_H

void register_out(cpu *c, uint8_t r); // write the contents of the register to the bus
void register_in(cpu *c, uint8_t *r); // write the contents of the bus to the register

#endif
