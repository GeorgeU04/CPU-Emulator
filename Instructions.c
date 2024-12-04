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
}

void lda_Immediate(CPU *cpu) {
  cpu->A = readMemory(cpu, cpu->PC++);
  cpu->P |= ((cpu->A == 0) << 1) | (cpu->P << 7);
}

void lda_ZeroPage(CPU *cpu) {
  cpu->A = readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P |= ((cpu->A == 0) << 1) | (cpu->P << 7);
}

void lda_ZeroPageX(CPU *cpu) {
  uint16_t indexAdress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAdress > 0xFF) {
    indexAdress &= 0xFF;
  }
  cpu->A = readMemory(cpu, indexAdress);
  cpu->P |= ((cpu->A == 0) << 1) | (cpu->P << 7);
}
