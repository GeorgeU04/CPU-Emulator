#ifndef CPU_H
#define CPU_H
#include <stdint.h>

/*
 * FLAGS
 *  7 6 5 4 3 2 1 0
 *  N V   B D I Z C
 *  C = Carry
 *  Z = Zero
 *  I Interrupt Disable
 *  D = Decimal Mode
 *  B = Break Command
 *  V = Overflow
 *  N = Negative
 */

typedef struct {
  uint16_t PC;           // Program Counter
  uint8_t A;             // Accumulator
  uint8_t X;             // Register X
  uint8_t Y;             // Register Y
  uint8_t P;             // Processor Status
  uint8_t SP;            // Stack Pointer
  uint8_t memory[65536]; // Memory
  uint64_t cycles;
} CPU;

uint8_t readMemory(CPU *cpu, uint16_t address);
void writeMemory(CPU *cpu, uint16_t address, uint8_t value);
void reset(CPU *cpu);
void run(CPU *cpu);
void executeInstruction(CPU *cpu, uint8_t opcode);
void toggleFlags(CPU *cpu, uint8_t flags);
#endif
