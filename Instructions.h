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

#endif // !INSTRUCTIONS_H
