#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "CPU.h"

// ADC - Add with Carry
void adcImmediate(CPU *cpu);
void adcZeroPage(CPU *cpu);
void adcZeroPageX(CPU *cpu);
void adcAbsolute(CPU *cpu);
void adcAbsoluteX(CPU *cpu);
void adcAbsoluteY(CPU *cpu);
void adcIndirectX(CPU *cpu);
void adcIndirectY(CPU *cpu);

// DEC - Decrement Memory
void decZeroPage(CPU *cpu);  // done
void decZeroPageX(CPU *cpu); // done
void decAbsolute(CPU *cpu);  // done
void decAbsoluteX(CPU *cpu); // done

// DEX - Decrement X Register
void decX(CPU *cpu); // done

// DEY - Decrement Y Register
void decY(CPU *cpu); // done

// INC - Increment Memory
void incZeroPage(CPU *cpu);  // done
void incZeroPageX(CPU *cpu); // done
void incAbsolute(CPU *cpu);  // done
void incAbsoluteX(CPU *cpu); // done

// INX - Increment X Register
void incX(CPU *cpu); // done

// INY - Increment Y Register
void incY(CPU *cpu); // done

// SBC - Subtract with Carry
void sbcImmediate(CPU *cpu);
void sbcZeroPage(CPU *cpu);
void sbcZeroPageX(CPU *cpu);
void sbcAbsolute(CPU *cpu);
void sbcAbsoluteX(CPU *cpu);
void sbcAbsoluteY(CPU *cpu);
void sbcIndirectX(CPU *cpu);
void sbcIndirectY(CPU *cpu);

#endif // !ARITHMETIC_H
