#include "Load_Store.h"

void ldaImmediate(CPU *cpu) {
  cpu->A = readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaZeroPage(CPU *cpu) {
  cpu->A = readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaZeroPageX(CPU *cpu) {
  uint16_t indexAdress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAdress > 0xFF) {
    indexAdress &= 0xFF;
  }
  cpu->A = readMemory(cpu, indexAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAdress = (highByte << 8) | lowByte;
  cpu->A = readMemory(cpu, fullAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaAbsoluteX(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaAbsoluteY(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaIndirectX(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaIndirectY(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldxImmediate(CPU *cpu) { return; }
void ldxZeroPage(CPU *cpu) { return; }
void ldxZeroPageY(CPU *cpu) { return; }
void ldxAbsolute(CPU *cpu) { return; }
void ldxAbsoluteY(CPU *cpu) { return; }

void ldyImmediate(CPU *cpu) { return; }
void ldyZeroPage(CPU *cpu) { return; }
void ldyZeroPageX(CPU *cpu) { return; }
void ldyAbsolute(CPU *cpu) { return; }
void ldyAbsoluteX(CPU *cpu) { return; }

void staZeroPage(CPU *cpu) {
  uint8_t indexAdress = readMemory(cpu, cpu->PC++);
  writeMemory(cpu, indexAdress, cpu->A);
}
void staZeroPageX(CPU *cpu) { return; }
void staAbsolute(CPU *cpu) { return; }
void staAbsoluteX(CPU *cpu) { return; }
void staAbsoluteY(CPU *cpu) { return; }
void staIndirectX(CPU *cpu) { return; }
void staIndirectY(CPU *cpu) { return; }

void stxZeroPage(CPU *cpu) { return; }
void stxZeroPageY(CPU *cpu) { return; }
void stxAbsolute(CPU *cpu) { return; }

void styZeroPage(CPU *cpu) { return; }
void styZeroPageX(CPU *cpu) { return; }
void styAbsolute(CPU *cpu) { return; }

void tax(CPU *cpu) { return; }

void tay(CPU *cpu) { return; }

void txa(CPU *cpu) { return; }

void tya(CPU *cpu) { return; }
