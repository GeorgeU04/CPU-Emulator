#ifndef STACK_H
#define STACK_H
#include "CPU.h"

// PHA - Push Accumulator
void pha(CPU *cpu); // done

// PHP - Push Processor Status
void php(CPU *cpu); // done

// PLA - Pull Accumulator
void pla(CPU *cpu); // done

// PLP - Pull Processor Status
void plp(CPU *cpu); // done

// TSX - Transfer Stack Pointer to X
void tsx(CPU *cpu); // done

// TXS - Transfer X to Stack Pointer
void txs(CPU *cpu); // done

#endif // !STACK_H
