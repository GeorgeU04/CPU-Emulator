#include "CPU.h"
#include <stdio.h>

int main(void) {
  printf("Welcome to George's Emulator!\n");
  CPU cpu = {0};
  reset(&cpu);
  writeMemory(&cpu, cpu.PC, 0xB5);
  cpu.X = 0xFF;
  writeMemory(&cpu, cpu.PC + 1, 0x80);
  writeMemory(&cpu, 0x007F, 0x3);
  run(&cpu);
  return 0;
}
