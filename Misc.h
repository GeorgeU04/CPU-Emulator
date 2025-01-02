#ifndef MISC_H
#define MISC_H
#include "CPU.h"

// BIT - Test Bits
void bitZeroPage(CPU *cpu); // done
void bitAbsolute(CPU *cpu); // done

// CLC - Clear Carry Flag
void clc(CPU *cpu); // done

// CLD - Clear Decimal Mode
void cld(CPU *cpu); // done

// CLI - Clear Interrupt Disable
void cli(CPU *cpu); // done

// CLV - Clear Overflow Flag
void clv(CPU *cpu); // done

// NOP - No Operation
void nop(CPU *cpu);

// SEC - Set Carry Flag
void sec(CPU *cpu); // done

// SED - Set Decimal Flag
void sed(CPU *cpu); // done

// SEI - Set Interrupt Disable
void sei(CPU *cpu); // done

#endif // !MISC_H
