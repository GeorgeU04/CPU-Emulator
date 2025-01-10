#include "Branching.h"
#include "CPU.h"
#include <stdint.h>

void branchGeneral(CPU *cpu, uint8_t condition) {
  if (condition) {
    cpu->cycles++;
    int8_t offset = readMemory(cpu, cpu->PC++);
    uint16_t oldPC = cpu->PC;
    cpu->PC += offset;
    if ((cpu->PC >> 8) != (oldPC >> 8))
      cpu->cycles++;
  }
}

void bcc(CPU *cpu) { branchGeneral(cpu, ((cpu->P & 1) == 0)); }

void bcs(CPU *cpu) { branchGeneral(cpu, (cpu->P & 1)); }

void beq(CPU *cpu) { branchGeneral(cpu, ((cpu->P >> 1) & 1)); }

void bne(CPU *cpu) { branchGeneral(cpu, (((cpu->P >> 1) & 1) == 0)); }

void bmi(CPU *cpu) { branchGeneral(cpu, ((cpu->P >> 7) & 1)); }

void bpl(CPU *cpu) { branchGeneral(cpu, (((cpu->P >> 7) & 1) == 0)); }

void brk(CPU *cpu) {
  cpu->P |= (1 << 4);
  writeMemory(cpu, 0x0100 + cpu->SP--, (cpu->PC >> 8));
  writeMemory(cpu, 0x0100 + cpu->SP--, cpu->PC);
  writeMemory(cpu, 0x0100 + cpu->SP--, cpu->P);
  cpu->P |= (1 << 2);
  uint8_t lowByte = readMemory(cpu, 0xFFFE);
  uint8_t highByte = readMemory(cpu, 0xFFFF);
  cpu->PC = (highByte << 8) | lowByte;
}

void bvs(CPU *cpu) { branchGeneral(cpu, ((cpu->P >> 6) & 1)); }

void bvc(CPU *cpu) { branchGeneral(cpu, (((cpu->P >> 6) & 1) == 0)); }

void jmpAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->PC = fullAddress;
}

void jmpIndirect(CPU *cpu) {
  uint8_t lowPointer = readMemory(cpu, cpu->PC++);
  uint8_t highPointer = readMemory(cpu, cpu->PC++);
  uint16_t pointer = (highPointer << 8) | lowPointer;
  uint8_t lowByte = readMemory(cpu, pointer);
  uint8_t highByte = readMemory(
      cpu, (pointer & 0xFF00) | ((pointer + 1) & 0x00FF)); // Wraparound bug
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->PC = fullAddress;
}

void jsr(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t returnAddress = cpu->PC - 1;
  writeMemory(cpu, 0x0100 + cpu->SP--, (returnAddress >> 8) & 0xFF);
  writeMemory(cpu, 0x0100 + cpu->SP--, returnAddress & 0xFF);
  cpu->PC = fullAddress;
}

void rti(CPU *cpu) {
  cpu->P = readMemory(cpu, ++cpu->SP) & 0xCF;
  uint8_t lowByte = readMemory(cpu, 0x0100 + ++cpu->SP);
  uint8_t highByte = readMemory(cpu, 0x0100 + ++cpu->SP);
  cpu->PC = (highByte << 8) | lowByte;
}

void rts(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, 0x0100 + ++cpu->SP);
  uint8_t highByte = readMemory(cpu, 0x0100 + ++cpu->SP);
  cpu->PC = (highByte << 8) | lowByte;
  cpu->PC++;
}
