#ifndef COMPARE_H
#define COMPARE_H
#include "CPU.h"

// CMP - Compare
void cmpImmediate(CPU *cpu); // done
void cmpZeroPage(CPU *cpu);  // done
void cmpZeroPageX(CPU *cpu); // done
void cmpAbsolute(CPU *cpu);  // done
void cmpAbsoluteX(CPU *cpu); // done
void cmpAbsoluteY(CPU *cpu); // done
void cmpIndirectX(CPU *cpu); // done
void cmpIndirectY(CPU *cpu); // done

// CPX - Compare X Register
void cpxImmediate(CPU *cpu); // done
void cpxZeroPage(CPU *cpu);  // done
void cpxAbsolute(CPU *cpu);  // done

// CPY - Compare Y Register
void cpyImmediate(CPU *cpu); // done
void cpyZeroPage(CPU *cpu);  // done
void cpyAbsolute(CPU *cpu);  // done

#endif // !COMPARE_H
