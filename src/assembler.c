#include<string.h>
#include<stdio.h>

#include "../include/assembler.h"

static opcode get_opcode(char *str) {
  if(strcmp(str, "NOP") == 0) return NOP;
  if(strcmp(str, "LDA") == 0) return LDA;
  if(strcmp(str, "ADD") == 0) return ADD;
  if(strcmp(str, "SUB") == 0) return SUB;
  if(strcmp(str, "STA") == 0) return STA;
  if(strcmp(str, "LDI") == 0) return LDI;
  if(strcmp(str, "JMP") == 0) return JMP;
  if(strcmp(str, "JC") == 0)  return JC;
  if(strcmp(str, "JZ") == 0)  return JZ;
  if(strcmp(str, "OUT") == 0) return OUT;
  if(strcmp(str, "HLT") == 0) return HLT;
}

static int get_token_count(char *str, char delim) {
  int count = 0;

  for(int i = 0; i < strlen(str); i++) {
    if(str[i] == delim) {
      count++;
    }
  }

  return count;
}

static char **get_lines(char *str, int count) {
  char **lines = malloc(sizeof(char*) * count);

  char *line = strtok(str, "\n");
  for(int i = 0; line != NULL; i++) {
    lines[i] = line;
    line = strtok(NULL, "\n");
  }

  return lines;
}

static uint8_t get_instruction(char *str) {
  opcode op = 0;
  uint8_t arg = 0;

  char *token = strtok(str, " ");
  op = get_opcode(token);
  token = strtok(NULL, " ");
  if(token != NULL) {
    arg = atoi(token);
  }

  uint8_t instruction = (arg << 4) | (op & 0x0F);
  return instruction;
}

uint8_t *assemble(char *str) {
  int count = get_token_count(str, '\n');
  char **lines = get_lines(str, count);

  uint8_t *byte_code = malloc(sizeof(uint8_t) * count);
  if(byte_code == NULL) {
    puts("Failed to allocate memory");
    return NULL;
  }

  for(int i = 0; i < count; i++) {
    byte_code[i] = get_instruction(lines[i]);
  }

  return byte_code;
}

static int get_file_size(FILE *file) {
  char ch;
  int count = 0;
  while ((ch = fgetc(file)) != EOF) {
    count++;
  }
  rewind(file);

  return count;
}

uint8_t *assemble_file(char *path) {
  FILE *file = fopen(path, "r");

  if(file == NULL) {
    puts("Failed to open file");
    return NULL;
  }

  int length = get_file_size(file);
  char *contents = malloc(sizeof(char) * (length + 1));
  if(contents == NULL) {
    puts("Failed to allocate memory");
    return NULL;
  }

  fread(contents, sizeof(char), length, file);
  uint8_t *byte_code = assemble(contents);
  
  fclose(file);

  return byte_code;
}
