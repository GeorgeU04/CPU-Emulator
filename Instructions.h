#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "CPU.h"
#include <stdint.h>

typedef enum {
  Implied,
  Immediate,
  Absolute,
  AbsoluteXIndexed,
  AbsoluteYIndexed,
  ZeroPage,
  ZeroPageXIndexed,
  ZeroPageYIndexed,
  Indirect,
  IndirectXIndexed,
  IndirectYIndexed,
  Relative,
  Accumulator
} adressingMode;

typedef struct {
  const char *name;
  void (*handler)(CPU *cpu);
  uint8_t cycles;
  adressingMode mode;
} Instruction;

extern Instruction instructionTable[256];

void initInstructionTable();
void lda_Immediate(CPU *cpu);
void lda_ZeroPage(CPU *cpu);
void lda_ZeroPageX(CPU *cpu);
void lda_ZeroPageX(CPU *cpu);
void lda_Absolute(CPU *cpu);
void lda_AbsoluteX(CPU *cpu);
void lda_AbsoluteY(CPU *cpu);
void lda_IndirectX(CPU *cpu);
void lda_IndirectY(CPU *cpu);

void incX(CPU *cpu);
void incY(CPU *cpu);
void inc(CPU *cpu);
void inc_ZeroPage(CPU *cpu);
void incZeroPageX(CPU *cpu);
void incAbsolute(CPU *cpu);
void incAbsoluteX(CPU *cpu);

void clc(CPU *cpu);
void cld(CPU *cpu);
void cli(CPU *cpu);
void clv(CPU *cpu);

#endif // !INSTRUCTIONS_H
