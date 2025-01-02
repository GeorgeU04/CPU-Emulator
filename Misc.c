#include "Misc.h"
#include "CPU.h"
#include <stdint.h>

void clc(CPU *cpu) { cpu->P &= 0xFE; }
void cld(CPU *cpu) { cpu->P &= ~(1 << 3); }
void cli(CPU *cpu) { cpu->P &= ~(1 << 2); }
void clv(CPU *cpu) { cpu->P &= ~(1 << 6); }

void sec(CPU *cpu) { cpu->P |= 1; }
void sed(CPU *cpu) { cpu->P |= (1 << 3); }
void sei(CPU *cpu) { cpu->P |= (1 << 2); }

void bitZeroPage(CPU *cpu) {
  uint8_t value = readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 6) | (1 << 7));
  cpu->P |= (((cpu->A & value) == 0) << 1) | (((value >> 7) & 1) << 7) |
            (((value >> 6) & 1) << 6);
}

void bitAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t value = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 6) | (1 << 7));
  cpu->P |= (((cpu->A & value) == 0) << 1) | (((value >> 7) & 1) << 7) |
            (((value >> 6) & 1) << 6);
}

void nop(CPU *cpu) { return; }
