#ifndef COMPARE_H
#define COMPARE_H
#include "CPU.h"

// CMP - Compare
void cmpImmediate(CPU *cpu);
void cmpZeroPage(CPU *cpu);
void cmpZeroPageX(CPU *cpu);
void cmpAbsolute(CPU *cpu);
void cmpAbsoluteX(CPU *cpu);
void cmpAbsoluteY(CPU *cpu);
void cmpIndirectX(CPU *cpu);
void cmpIndirectY(CPU *cpu);

// CPX - Compare X Register
void cpxImmediate(CPU *cpu);
void cpxZeroPage(CPU *cpu);
void cpxAbsolute(CPU *cpu);

// CPY - Compare Y Register
void cpyImmediate(CPU *cpu);
void cpyZeroPage(CPU *cpu);
void cpyAbsolute(CPU *cpu);

#endif // !COMPARE_H
