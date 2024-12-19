#ifndef BRANCHING_H
#define BRANCHING_H
#include "CPU.h"

// BCC - Branch if Carry Clear
void bcc(CPU *cpu);

// BCS - Branch if Carry Set
void bcs(CPU *cpu);

// BEQ - Branch if Equal
void beq(CPU *cpu);

// BMI - Branch if Minus
void bmi(CPU *cpu);

// BNE - Branch if Not Equal
void bne(CPU *cpu);

// BPL - Branch if Positive
void bpl(CPU *cpu);

// BRK - Force Interrupt
void brk(CPU *cpu);

// BVC - Branch if Overflow Clear
void bvc(CPU *cpu);

// BVS - Branch if Overflow Set
void bvs(CPU *cpu);

// JMP - Jump
void jmpAbsolute(CPU *cpu);
void jmpIndirect(CPU *cpu);

// JSR - Jump to Subroutine
void jsr(CPU *cpu);

// RTI - Return from Interrupt
void rti(CPU *cpu);

// RTS - Return from Subroutine
void rts(CPU *cpu);

#endif // !BRANCHING_H
