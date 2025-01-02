#include "Logical.h"
#include "CPU.h"
#include <stdint.h>

void andImmediate(CPU *cpu) {
  cpu->A &= readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andZeroPage(CPU *cpu) {
  cpu->A &= readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andZeroPageX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  cpu->A &= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A &= readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A &= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A &= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andIndirectX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A &= readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void andIndirectY(CPU *cpu) {
  uint8_t address = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, address);
  uint8_t highByte = readMemory(cpu, address + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A &= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void aslAccumulator(CPU *cpu) {
  uint8_t previous = cpu->A;
  cpu->A <<= 1;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7) | ((previous >> 7) & 1);
}

void aslZeroPage(CPU *cpu) {
  uint16_t address = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, address);
  uint8_t previous = data;
  data <<= 1;
  writeMemory(cpu, address, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | (((data >> 7) & 1) << 7) | ((previous >> 7) & 1);
}

void aslZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data <<= 1;
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | (((data >> 7) & 1) << 7) | ((previous >> 7) & 1);
}

void aslAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAddress);
  uint8_t previous = data;
  data <<= 1;
  writeMemory(cpu, fullAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | (((data >> 7) & 1) << 7) | ((previous >> 7) & 1);
}

void aslAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data <<= 1;
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | (((data >> 7) & 1) << 7) | ((previous >> 7) & 1);
}

void eorImmediate(CPU *cpu) {
  cpu->A ^= readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void eorZeroPage(CPU *cpu) {
  cpu->A ^= readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void eorZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  cpu->A ^= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void eorAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A ^= readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void eorAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A ^= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void eorAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A ^= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void eorIndirectX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A ^= readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void eorIndirectY(CPU *cpu) {
  uint8_t address = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, address);
  uint8_t highByte = readMemory(cpu, address + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A ^= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void oraImmediate(CPU *cpu) {
  cpu->A |= readMemory(cpu, cpu->PC++);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void oraZeroPage(CPU *cpu) {
  cpu->A |= readMemory(cpu, readMemory(cpu, cpu->PC++));
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void oraZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  cpu->A |= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= ((cpu->A == 0) << 1) | (((cpu->A >> 7) & 1) << 7);
}

void oraAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A |= readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void oraAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A |= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void oraAbsoluteY(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A |= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void oraIndirectX(CPU *cpu) {
  uint8_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t lowByte = readMemory(cpu, indexAddress);
  uint8_t highByte = readMemory(cpu, indexAddress + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  cpu->A |= readMemory(cpu, fullAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void oraIndirectY(CPU *cpu) {
  uint8_t address = readMemory(cpu, cpu->PC++);
  uint8_t lowByte = readMemory(cpu, address);
  uint8_t highByte = readMemory(cpu, address + 1);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->Y;
  if ((indexAddress >> 8) != (fullAddress >> 8)) {
    cpu->cycles++;
  }
  cpu->A |= readMemory(cpu, indexAddress);
  cpu->P &= ~((1 << 1) | (1 << 7));
  cpu->P |= (((cpu->A == 0) << 1) | ((cpu->A >> 7) & 1) << 7);
}

void lsrAccumulator(CPU *cpu) {
  uint8_t previous = cpu->A;
  cpu->A >>= 1;
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((cpu->A == 0) << 1) | (previous & 1);
}

void lsrZeroPage(CPU *cpu) {
  uint16_t address = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, address);
  uint8_t previous = data;
  data >>= 1;
  writeMemory(cpu, address, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1);
}

void lsrZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, (cpu->PC++)) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data >>= 1;
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1);
}

void lsrAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAddress);
  uint8_t previous = data;
  data >>= 1;
  writeMemory(cpu, fullAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1);
}

void lsrAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data >>= 1;
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1);
}

void rolAccumulator(CPU *cpu) {
  uint8_t previous = cpu->A;
  cpu->A <<= 1;
  cpu->A += (cpu->P & 1);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((cpu->A == 0) << 1) | ((previous >> 7) & 1) | (((cpu->A >> 7) & 1) << 7);
}

void rolZeroPage(CPU *cpu) {
  uint8_t address = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, address);
  uint8_t previous = data;
  data <<= 1;
  data += (cpu->P & 1);
  writeMemory(cpu, address, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | ((previous >> 7) & 1) | (((data >> 7) & 1) << 7);
}

void rolZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data <<= 1;
  data += (cpu->P & 1);
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | ((previous >> 7) & 1) | (((data >> 7) & 1) << 7);
}

void rolAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAddress);
  uint8_t previous = data;
  data <<= 1;
  data += (cpu->P & 1);
  writeMemory(cpu, fullAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | ((previous >> 7) & 1) | (((data >> 7) & 1) << 7);
}

void rolAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data <<= 1;
  data += (cpu->P & 1);
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |=
      ((data == 0) << 1) | ((previous >> 7) & 1) | (((data >> 7) & 1) << 7);
}

void rorAccumulator(CPU *cpu) {
  uint8_t previous = cpu->A;
  cpu->A >>= 1;
  cpu->A |= ((cpu->P & 1) << 7);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((cpu->A == 0) << 1) | (previous & 1) | (((cpu->A >> 7) & 1) << 7);
}

void rorZeroPage(CPU *cpu) {
  uint8_t address = readMemory(cpu, cpu->PC++);
  uint8_t data = readMemory(cpu, address);
  uint8_t previous = data;
  data >>= 1;
  data |= ((cpu->P & 1) << 7);
  writeMemory(cpu, address, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1) | (((data >> 7) & 1) << 7);
}

void rorZeroPageX(CPU *cpu) {
  uint16_t indexAddress = readMemory(cpu, cpu->PC++) + cpu->X;
  if (indexAddress > 0xFF) {
    indexAddress &= 0xFF;
  }
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data >>= 1;
  data |= ((cpu->P & 1) << 7);
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1) | (((data >> 7) & 1) << 7);
}

void rorAbsolute(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint8_t data = readMemory(cpu, fullAddress);
  uint8_t previous = data;
  data >>= 1;
  data |= ((cpu->P & 1) << 7);
  writeMemory(cpu, fullAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1) | (((data >> 7) & 1) << 7);
}

void rorAbsoluteX(CPU *cpu) {
  uint8_t lowByte = readMemory(cpu, cpu->PC++);
  uint8_t highByte = readMemory(cpu, cpu->PC++);
  uint16_t fullAddress = (highByte << 8) | lowByte;
  uint16_t indexAddress = fullAddress + cpu->X;
  uint8_t data = readMemory(cpu, indexAddress);
  uint8_t previous = data;
  data >>= 1;
  data |= ((cpu->P & 1) << 7);
  writeMemory(cpu, indexAddress, data);
  cpu->P &= ~((1 << 1) | (1 << 7) | 1);
  cpu->P |= ((data == 0) << 1) | (previous & 1) | (((data >> 7) & 1) << 7);
}
