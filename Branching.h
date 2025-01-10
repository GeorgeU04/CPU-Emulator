#ifndef BRANCHING_H
#define BRANCHING_H
#include "CPU.h"

// BCC - Branch if Carry Clear
void bcc(CPU *cpu); // done

// BCS - Branch if Carry Set
void bcs(CPU *cpu); // done

// BEQ - Branch if Equal
void beq(CPU *cpu); // done

// BMI - Branch if Minus
void bmi(CPU *cpu); // done

// BNE - Branch if Not Equal
void bne(CPU *cpu); // done

// BPL - Branch if Positive
void bpl(CPU *cpu); // done

// BRK - Force Interrupt
void brk(CPU *cpu); // done

// BVC - Branch if Overflow Clear
void bvc(CPU *cpu); // done

// BVS - Branch if Overflow Set
void bvs(CPU *cpu); // done

// JMP - Jump
void jmpAbsolute(CPU *cpu); // done
void jmpIndirect(CPU *cpu); // done

// JSR - Jump to Subroutine
void jsr(CPU *cpu); // done

// RTI - Return from Interrupt
void rti(CPU *cpu); // done

// RTS - Return from Subroutine
void rts(CPU *cpu); // done

#endif // !BRANCHING_H
