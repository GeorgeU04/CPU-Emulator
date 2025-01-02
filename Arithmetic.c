#include "Arithmetic.h"
#include "CPU.h"
#include <stdint.h>
#include <strings.h>

void adcImmediate(CPU *cpu) {
  uint8_t operand = readMemory(cpu, cpu->PC++);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcZeroPage(CPU *cpu) {
  uint8_t operand = readMemory(cpu, readMemory(cpu, cpu->PC++));
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcIndirectX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void adcIndirectY(CPU *cpu) {
  uint8_t Address = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, Address);
  uint8_t highByte = readMemory(cpu, Address + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void decZeroPage(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAddress, --data);
}

void decZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAddress, --data);
}

void decAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, fullAddress, --data);
}

void decAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress += cpu->X;
  uint8_t data = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAddress, --data);
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
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAddress, ++data);
}

void incZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAddress, ++data);
}

void incAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, fullAddress, ++data);
}

void incAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress += cpu->X;
  uint8_t data = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((data == 0) << 1) | (((data >> 7) & 1) << 7);
  writeMemory(cpu, indexAddress, ++data);
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

void sbcImmediate(CPU *cpu) {
  uint8_t operand = readMemory(cpu, cpu->PC++);
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcZeroPage(CPU *cpu) {
  uint8_t operand = readMemory(cpu, readMemory(cpu, cpu->PC++));
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcIndirectX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t operand = readMemory(cpu, fullAddress);
  uint8_t twosOperand = ~operand;
  uint16_t result = cpu->A + twosOperand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (twosOperand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void sbcIndirectY(CPU *cpu) {
  uint8_t Address = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, Address);
  uint8_t highByte = readMemory(cpu, Address + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  uint8_t operand = readMemory(cpu, indexAddress);
  uint16_t result = cpu->A + operand + (cpu->P & 1);
  cpu->P &= ~(1 | (1 << 1) | (1 << 6) | (1 << 7));
  if (((cpu->A & 0x80) == (operand & 0x80)) &&
      ((cpu->A & 0x80) != (result & 0x80))) {
    cpu->P |= (1 << 6);
  }
  if (result > 0xFF) {
    cpu->P |= 1;
    cpu->A = result & 0xFF;
  } else {
    cpu->A = result;
  }
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}
