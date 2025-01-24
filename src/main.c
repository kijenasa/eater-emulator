#include<stdlib.h>
#include<stdio.h>

#include "../include/cpu.h"

int main(int argc, char *argv[]) {
  cpu *c = cpu_new();

  execute_program(c, 1);

  cpu_free(c);
  return EXIT_SUCCESS;
}
