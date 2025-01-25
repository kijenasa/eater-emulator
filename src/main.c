#include<stdlib.h>
#include<stdio.h>

#include "../include/cpu.h"
#include "../include/assembler.h"

int main(int argc, char *argv[]) {
  cpu *c = cpu_new();

  if(argc > 1) {
    uint8_t *byt = assemble_file(argv[1]);
    load_memory(c, byt);
  }

  execute_program(c);

  cpu_free(c);
  return EXIT_SUCCESS;
}
