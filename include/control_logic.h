#include "../include/cpu.h"

#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

void instruction_nop(cpu *c); 
void instruction_lda(cpu *c); 
void instruction_add(cpu *c); 
void instruction_sub(cpu *c); 
void instruction_sta(cpu *c); 
void instruction_ldi(cpu *c); 
void instruction_jmp(cpu *c); 
void instruction_jc(cpu *c);
void instruction_jz(cpu *c);
void instruction_out(cpu *c);
void instruction_hlt(cpu *c);

#endif
