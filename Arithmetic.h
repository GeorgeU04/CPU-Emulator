#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "CPU.h"

// ADC - Add with Carry
void adcImmediate(CPU *cpu); // done
void adcZeroPage(CPU *cpu);  // done
void adcZeroPageX(CPU *cpu); // done
void adcAbsolute(CPU *cpu);  // done
void adcAbsoluteX(CPU *cpu); // done
void adcAbsoluteY(CPU *cpu); // done
void adcIndirectX(CPU *cpu); // done
void adcIndirectY(CPU *cpu); // done

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
void sbcImmediate(CPU *cpu); // done
void sbcZeroPage(CPU *cpu);  // done
void sbcZeroPageX(CPU *cpu); // done
void sbcAbsolute(CPU *cpu);  // done
void sbcAbsoluteX(CPU *cpu); // done
void sbcAbsoluteY(CPU *cpu); // done
void sbcIndirectX(CPU *cpu); // done
void sbcIndirectY(CPU *cpu); // done

#endif // !ARITHMETIC_H
