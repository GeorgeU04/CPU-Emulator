#ifndef LOAD_STORE_H
#define LOAD_STORE_H
#include "CPU.h"

// LDA - Load Accumulator
void ldaImmediate(CPU *cpu); // done
void ldaZeroPage(CPU *cpu);  // done
void ldaZeroPageX(CPU *cpu); // done
void ldaAbsolute(CPU *cpu);  // done
void ldaAbsoluteX(CPU *cpu); // done
void ldaAbsoluteY(CPU *cpu); // done
void ldaIndirectX(CPU *cpu); // done
void ldaIndirectY(CPU *cpu); // done

// LDX - Load X Register
void ldxImmediate(CPU *cpu); // done
void ldxZeroPage(CPU *cpu);  // done
void ldxZeroPageY(CPU *cpu); // done
void ldxAbsolute(CPU *cpu);  // done
void ldxAbsoluteY(CPU *cpu); // done

// LDY - Load Y Register
void ldyImmediate(CPU *cpu); // done
void ldyZeroPage(CPU *cpu);  // done
void ldyZeroPageX(CPU *cpu); // done
void ldyAbsolute(CPU *cpu);  // done
void ldyAbsoluteX(CPU *cpu); // done

// STA - Store Accumulator
void staZeroPage(CPU *cpu);  // done
void staZeroPageX(CPU *cpu); // done
void staAbsolute(CPU *cpu);  // done
void staAbsoluteX(CPU *cpu); // done
void staAbsoluteY(CPU *cpu); // done
void staIndirectX(CPU *cpu); // done
void staIndirectY(CPU *cpu); // done

// STX - Store X Register
void stxZeroPage(CPU *cpu);  // done
void stxZeroPageY(CPU *cpu); // done
void stxAbsolute(CPU *cpu);  // done

// STY - Store Y Register
void styZeroPage(CPU *cpu);  // done
void styZeroPageX(CPU *cpu); // done
void styAbsolute(CPU *cpu);  // done

// TAX - Transfer Accumulator to X
void tax(CPU *cpu); // done

// TAY - Transfer Accumulator to Y
void tay(CPU *cpu); // done

// TXA - Transfer X to Accumulator
void txa(CPU *cpu); // done

// TYA - Transfer Y to Accumulator
void tya(CPU *cpu); // done

#endif // !LOAD_STORE_H
