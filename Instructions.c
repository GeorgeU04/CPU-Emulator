#include "Instructions.h"
#include "CPU.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

Instruction instructionTable[256];

void initInstructionTable() {
  for (int32_t i = 0; i < 256; ++i) {
    instructionTable[i] = (Instruction){"???", NULL, 0, 0};
  }

  instructionTable[0xA9] = (Instruction){"LDA", lda_Immediate, 2, Immediate};
  instructionTable[0xA5] = (Instruction){"LDA", lda_ZeroPage, 3, ZeroPage};
  instructionTable[0xB5] =
      (Instruction){"LDA", lda_ZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0xAD] = (Instruction){"LDA", lda_Absolute, 4, Absolute};
  instructionTable[0xBD] = (Instruction){"LDA", lda_AbsoluteX, 4, Absolute};
  instructionTable[0xB9] = (Instruction){"LDA", lda_AbsoluteY, 4, Absolute};
  instructionTable[0xA1] = (Instruction){"LDA", lda_IndirectX, 6, Absolute};
  instructionTable[0xB1] = (Instruction){"LDA", lda_IndirectY, 5, Absolute};

  instructionTable[0x18] = (Instruction){"CLC", clc, 2, Implied};
  instructionTable[0xD8] = (Instruction){"CLD", cld, 2, Implied};
  instructionTable[0x58] = (Instruction){"CLI", cli, 2, Implied};
  instructionTable[0xB8] = (Instruction){"CLV", clv, 2, Implied};

  instructionTable[0xC8] = (Instruction){"INY", incY, 2, Implied};
  instructionTable[0xE8] = (Instruction){"INX", incX, 2, Implied};
}

void lda_Immediate(CPU *cpu) {
  cpu->A = readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_ZeroPage(CPU *cpu) {
  cpu->A = readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_ZeroPageX(CPU *cpu) {
  uint16_t indexAdress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAdress > 0xFF) {
    indexAdress &= 0xFF;
  }
  cpu->A = readMemory(cpu, indexAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_Absolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAdress = (highByte << 8) | lowByte;
  cpu->A = readMemory(cpu, fullAdress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_AbsoluteX(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_AbsoluteY(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_IndirectX(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void lda_IndirectY(CPU *cpu) {
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void clc(CPU *cpu) { cpu->P &= 0xFE; }
void cld(CPU *cpu) { cpu->P &= ~(1 << 3); }
void cli(CPU *cpu) { cpu->P &= ~(1 << 2); }
void clv(CPU *cpu) { cpu->P &= ~(1 << 6); }

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

void inc(CPU *cpu);
