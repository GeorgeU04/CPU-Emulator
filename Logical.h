#ifndef LOGICAL_H
#include "CPU.h"

// AND - Logical AND
void andImmediate(CPU *cpu);
void andZeroPage(CPU *cpu);
void andZeroPageX(CPU *cpu);
void andAbsolute(CPU *cpu);
void andAbsoluteX(CPU *cpu);
void andAbsoluteY(CPU *cpu);
void andIndirectX(CPU *cpu);
void andIndirectY(CPU *cpu);

// ASL - Arithmetic Shift Left
void aslAccumulator(CPU *cpu);
void aslZeroPage(CPU *cpu);
void aslZeroPageX(CPU *cpu);
void aslAbsolute(CPU *cpu);
void aslAbsoluteX(CPU *cpu);

// EOR - Exclusive OR
void eorImmediate(CPU *cpu);
void eorZeroPage(CPU *cpu);
void eorZeroPageX(CPU *cpu);
void eorAbsolute(CPU *cpu);
void eorAbsoluteX(CPU *cpu);
void eorAbsoluteY(CPU *cpu);
void eorIndirectX(CPU *cpu);
void eorIndirectY(CPU *cpu);

// ORA - Logical Inclusive OR
void oraImmediate(CPU *cpu);
void oraZeroPage(CPU *cpu);
void oraZeroPageX(CPU *cpu);
void oraAbsolute(CPU *cpu);
void oraAbsoluteX(CPU *cpu);
void oraAbsoluteY(CPU *cpu);
void oraIndirectX(CPU *cpu);
void oraIndirectY(CPU *cpu);

// LSR - Logical Shift Right
void lsrAccumulator(CPU *cpu);
void lsrZeroPage(CPU *cpu);
void lsrZeroPageX(CPU *cpu);
void lsrAbsolute(CPU *cpu);
void lsrAbsoluteX(CPU *cpu);

// ROL - Rotate Left
void rolAccumulator(CPU *cpu);
void rolZeroPage(CPU *cpu);
void rolZeroPageX(CPU *cpu);
void rolAbsolute(CPU *cpu);
void rolAbsoluteX(CPU *cpu);

// ROR - Rotate Right
void rorAccumulator(CPU *cpu);
void rorZeroPage(CPU *cpu);
void rorZeroPageX(CPU *cpu);
void rorAbsolute(CPU *cpu);
void rorAbsoluteX(CPU *cpu);

#endif // !LOGICAL_H
