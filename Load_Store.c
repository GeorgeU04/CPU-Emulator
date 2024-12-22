#include "Load_Store.h"
#include "CPU.h"
#include <stdint.h>
#include <strings.h>

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
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  cpu->A = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAAddress = fullAddress + cpu->X;
  if ((fullAddress >> 8) != (indexAAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaIndirectX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldaIndirectY(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  fullAddress += cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void ldxImmediate(CPU *cpu) {
  cpu->X = readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void ldxZeroPage(CPU *cpu) {
  cpu->X = readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void ldxZeroPageY(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->Y;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  cpu->X = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void ldxAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->X = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void ldxAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->X = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void ldyImmediate(CPU *cpu) {
  cpu->Y = readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void ldyZeroPage(CPU *cpu) {
  cpu->Y = readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void ldyZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  cpu->Y = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void ldyAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->Y = readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void ldyAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((fullAddress >> 8) != (indexAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->Y = readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void staZeroPage(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  writeMemory(cpu, indexAddress, cpu->A);
}

void staZeroPageX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  writeMemory(cpu, indexAddress, cpu->A);
}

void staAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  writeMemory(cpu, fullAddress, cpu->A);
}

void staAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  fullAddress += cpu->X;
  writeMemory(cpu, fullAddress, cpu->A);
}

void staAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  fullAddress += cpu->Y;
  writeMemory(cpu, fullAddress, cpu->A);
}

void staIndirectX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  writeMemory(cpu, fullAddress, cpu->A);
}

void staIndirectY(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  fullAddress += cpu->Y;
  writeMemory(cpu, fullAddress, cpu->A);
}

void stxZeroPage(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  writeMemory(cpu, indexAddress, cpu->X);
}

void stxZeroPageY(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->Y;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  writeMemory(cpu, indexAddress, cpu->X);
}

void stxAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  writeMemory(cpu, fullAddress, cpu->X);
}

void styZeroPage(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++);
  writeMemory(cpu, indexAddress, cpu->Y);
}

void styZeroPageX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  writeMemory(cpu, indexAddress, cpu->Y);
}

void styAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  writeMemory(cpu, fullAddress, cpu->Y);
}

void tax(CPU *cpu) {
  cpu->X = cpu->A;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void tay(CPU *cpu) {
  cpu->Y = cpu->A;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}

void txa(CPU *cpu) {
  cpu->A = cpu->X;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->X == 0) << 1) | (((cpu->X >> 7) & 1) << 7);
}

void tya(CPU *cpu) {
  cpu->A = cpu->Y;
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->Y == 0) << 1) | (((cpu->Y >> 7) & 1) << 7);
}
