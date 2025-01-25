#include<stdlib.h>
#include<stdio.h>

#include "../include/cpu.h"
#include "../include/assembler.h"

int main(int argc, char *argv[]) {
  char in[] = "LDI 1";
  uint8_t byt = *assemble(in);
  printf("%d 0x%x\n", byt, byt);
  cpu *c = cpu_new();
  c->memory[0] = byt;
  execute_program(c, VISUAL);

  cpu_free(c);
  return EXIT_SUCCESS;
}
