#ifndef LOAD_STORE_H
#define LOAD_STORE_H
#include "CPU.h"

// LDA - Load Accumulator
void ldaImmediate(CPU *cpu); // done
void ldaZeroPage(CPU *cpu);  // done
void ldaZeroPageX(CPU *cpu); // done
void ldaAbsolute(CPU *cpu);  // done
void ldaAbsoluteX(CPU *cpu);
void ldaAbsoluteY(CPU *cpu);
void ldaIndirectX(CPU *cpu);
void ldaIndirectY(CPU *cpu);

// LDX - Load X Register
void ldxImmediate(CPU *cpu);
void ldxZeroPage(CPU *cpu);
void ldxZeroPageY(CPU *cpu);
void ldxAbsolute(CPU *cpu);
void ldxAbsoluteY(CPU *cpu);

// LDY - Load Y Register
void ldyImmediate(CPU *cpu);
void ldyZeroPage(CPU *cpu);
void ldyZeroPageX(CPU *cpu);
void ldyAbsolute(CPU *cpu);
void ldyAbsoluteX(CPU *cpu);

// STA - Store Accumulator
void staZeroPage(CPU *cpu); // done
void staZeroPageX(CPU *cpu);
void staAbsolute(CPU *cpu);
void staAbsoluteX(CPU *cpu);
void staAbsoluteY(CPU *cpu);
void staIndirectX(CPU *cpu);
void staIndirectY(CPU *cpu);

// STX - Store X Register
void stxZeroPage(CPU *cpu);
void stxZeroPageY(CPU *cpu);
void stxAbsolute(CPU *cpu);

// STY - Store Y Register
void styZeroPage(CPU *cpu);
void styZeroPageX(CPU *cpu);
void styAbsolute(CPU *cpu);

// TAX - Transfer Accumulator to X
void tax(CPU *cpu);

// TAY - Transfer Accumulator to Y
void tay(CPU *cpu);

// TXA - Transfer X to Accumulator
void txa(CPU *cpu);

// TYA - Transfer Y to Accumulator
void tya(CPU *cpu);

#endif // !LOAD_STORE_H
