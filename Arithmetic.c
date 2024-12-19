#include "Arithmetic.h"

void adcImmediate(CPU *cpu) { return; }
void adcZeroPage(CPU *cpu) { return; }
void adcZeroPageX(CPU *cpu) { return; }
void adcAbsolute(CPU *cpu) { return; }
void adcAbsoluteX(CPU *cpu) { return; }
void adcAbsoluteY(CPU *cpu) { return; }
void adcIndirectX(CPU *cpu) { return; }
void adcIndirectY(CPU *cpu) { return; }

void decZeroPage(CPU *cpu) {
  uint8_t indexadress = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, indexadress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexadress, --data);
}

void decZeroPageX(CPU *cpu) {
  uint16_t indexAdress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAdress > 0xFF) {
    indexAdress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAdress, --data);
}

void decAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAdress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, fullAdress, --data);
}

void decAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAdress = (highByte << 8) | lowByte;
  fullAdress += cpu->X;
  uint8_t data = readMemory(cpu, fullAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, fullAdress, --data);
}

void decX(CPU *cpu) {
  cpu->X--;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void decY(CPU *cpu) {
  cpu->Y--;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void incZeroPage(CPU *cpu) {
  uint8_t indexadress = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, indexadress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexadress, ++data);
}

void incZeroPageX(CPU *cpu) {
  uint16_t indexAdress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAdress > 0xFF) {
    indexAdress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAdress, ++data);
}

void incAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAdress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, fullAdress, ++data);
}

void incAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAdress = (highByte << 8) | lowByte;
  fullAdress += cpu->X;
  uint8_t data = readMemory(cpu, fullAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, fullAdress, ++data);
}

void incX(CPU *cpu) {
  cpu->X++;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void incY(CPU *cpu) {
  cpu->Y++;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void sbcImmediate(CPU *cpu) { return; }
void sbcZeroPage(CPU *cpu) { return; }
void sbcZeroPageX(CPU *cpu) { return; }
void sbcAbsolute(CPU *cpu) { return; }
void sbcAbsoluteX(CPU *cpu) { return; }
void sbcAbsoluteY(CPU *cpu) { return; }
void sbcIndirectX(CPU *cpu) { return; }
void sbcIndirectY(CPU *cpu) { return; }
