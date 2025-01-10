#include "Stack.h"
#include "CPU.h"

void pha(CPU *cpu) { writeMemory(cpu, 0x0100 + cpu->SP--, cpu->A); }

void php(CPU *cpu) { writeMemory(cpu, 0x0100 + cpu->SP--, cpu->P | (1 << 4)); }

void pla(CPU *cpu) {
  cpu->A = readMemory(cpu, 0x0100 + ++cpu->SP);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void plp(CPU *cpu) { cpu->P = readMemory(cpu, 0x0100 + ++cpu->SP) & 0xCF; }

void tsx(CPU *cpu) {
  cpu->X = cpu->SP;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void txs(CPU *cpu) { cpu->SP = cpu->X; }
