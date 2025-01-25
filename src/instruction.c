#include "../include/instruction.h"
#include<stdio.h>

uint8_t get_parameter(uint8_t instruction) {
  uint8_t param = instruction >> 4;

  return param;
}
