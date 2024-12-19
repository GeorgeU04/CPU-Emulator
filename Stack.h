#ifndef STACK_H
#define STACK_H
#include "CPU.h"

// PHA - Push Accumulator
void pha(CPU *cpu);

// PHP - Push Processor Status
void php(CPU *cpu);

// PLA - Pull Accumulator
void pla(CPU *cpu);

// PLP - Pull Processor Status
void plp(CPU *cpu);

// TSX - Transfer Stack Pointer to X
void tsx(CPU *cpu);

// TXS - Transfer X to Stack Pointer
void txs(CPU *cpu);

#endif // !STACK_H
