#include "CPU.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void parseASMCode(CPU *cpu) {
  FILE *file = fopen("test.bin", "rb");
  if (!file) {
    fprintf(stderr, "[ERROR]: Could not open file\n");
    exit(EXIT_FAILURE);
  }
  struct stat st;
  if (stat("test.bin", &st) == -1) {
    fprintf(stderr, "[ERROR]: Could not read file length\n");
    exit(EXIT_FAILURE);
  }
  int64_t size = st.st_size;
  printf("Size: %" PRId64 "\n", size);
  if (size > 0 && size <= 65536) {
    if (fread(cpu->memory + 0x0600, 1, size, file) != size) {
      fprintf(stderr, "[ERROR]: Could not write to memory\n");
      exit(EXIT_FAILURE);
    }
  } else {
    fprintf(stderr, "[ERROR]: File size too large\n");
    exit(EXIT_FAILURE);
  }
  fclose(file);
}

int main(void) {
  printf("Welcome to George's Emulator!\n");
  CPU cpu = {0};
  initializeMemory(&cpu);
  parseASMCode(&cpu);
  reset(&cpu);
  run(&cpu);
  return 0;
}
