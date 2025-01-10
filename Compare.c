#include "Compare.h"
#include "CPU.h"
#include <stdint.h>

void cmpImmediate(CPU *cpu) {
  uint8_t operand = readMemory(cpu, cpu->PC++);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpZeroPage(CPU *cpu) {
  uint8_t operand = readMemory(cpu, readMemory(cpu, cpu->PC++));
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpIndirectX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cmpIndirectY(CPU *cpu) {
  uint8_t address = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, address);
  uint8_t highByte = readMemory(cpu, address + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t result = cpu->A - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->A >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cpxImmediate(CPU *cpu) {
  uint8_t operand = readMemory(cpu, cpu->PC++);
  uint8_t result = cpu->X - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->X >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cpxZeroPage(CPU *cpu) {
  uint8_t operand = readMemory(cpu, readMemory(cpu, cpu->PC++));
  uint8_t result = cpu->X - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->X >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cpxAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint8_t result = cpu->X - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->X >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cpyImmediate(CPU *cpu) {
  uint8_t operand = readMemory(cpu, cpu->PC++);
  uint8_t result = cpu->Y - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->Y >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cpyZeroPage(CPU *cpu) {
  uint8_t operand = readMemory(cpu, readMemory(cpu, cpu->PC++));
  uint8_t result = cpu->Y - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->Y >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}

void cpyAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint8_t result = cpu->Y - operand;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      (cpu->Y >= operand) | ((result == 0) << 1) | (((result >> 7) & 1) << 7);
}
