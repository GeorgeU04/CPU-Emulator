#include "CPU.h"
#include "Instructions.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flags[] = {'C', 'Z', 'I', 'D', 'B', ' ', 'V', 'N'};

uint8_t readMemory(CPU *cpu, uint16_t address) {
  if (address > 65535) {
    fprintf(stderr, "[ERROR]: Memory Adress Out of Bounds\n");
    exit(EXIT_FAILURE);
  }
  return cpu->memory[address];
}

void writeMemory(CPU *cpu, uint16_t address, uint8_t value) {
  if (address > 65535) {
    fprintf(stderr, "[ERROR]: Memory Adress Out of Bounds\n");
    exit(EXIT_FAILURE);
  }
  cpu->memory[address] = value;
}

void reset(CPU *cpu) {
  cpu->PC = readMemory(cpu, 0xFFFC) | (readMemory(cpu, 0xFFFD) << 8);
  cpu->P = 0b00110100;
  cpu->SP = 0xFD;
  cpu->A = 0;
  cpu->X = 0;
  cpu->Y = 0;
  cpu->cycles = 0;
}

void initializeMemory(CPU *cpu) {
  memset(cpu->memory, 0, 0x0800);
  cpu->memory[0xFFFC] = 0x00; // Low byte of reset vector
  cpu->memory[0xFFFD] = 0x06; // High byte of reset vecto}
}

void run(CPU *cpu) {
  initInstructionTable();
  while (1) {
    if (cpu->PC < 0x0000 || cpu->PC > 0xFFFF) {
      fprintf(stderr, "PC out of bounds: %04X\n", cpu->PC);
      exit(EXIT_FAILURE);
    }
    uint8_t opcode = readMemory(cpu, cpu->PC++);
    if (opcode == 0)
      break;
    executeInstruction(cpu, opcode);
    printf("Accumulator: %" PRIu8 "\n", cpu->A);
    printf("X: %" PRIu8 "\n", cpu->X);
    printf("Y: %" PRIu8 "\n", cpu->Y);
    printf("Cycles: %" PRId64 "\n", cpu->cycles);
    printf("Flags:\n");
    for (int8_t i = 7; i >= 0; --i) {
      printf("%c %" PRIu8 "\n", flags[i], (cpu->P >> i) & 1);
    }
  }
}

void executeInstruction(CPU *cpu, uint8_t opcode) {
  Instruction instruction = instructionTable[opcode];
  printf("Executing %s (0x%02X)\n", instruction.name, opcode);
  if (instruction.handler) {
    instruction.handler(cpu);
    cpu->cycles += instruction.cycles;
  } else {
    fprintf(stderr, "[ERROR]: Unknown Opcode\n");
  }
}
