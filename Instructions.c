#include "Instructions.h"
#include "Arithmetic.h"
#include "Branching.h"
#include "Compare.h"
#include "Load_Store.h"
#include "Logical.h"
#include "Misc.h"
#include "Stack.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

Instruction instructionTable[256];

void initInstructionTable() {
  for (int32_t i = 0; i < 256; ++i) {
    instructionTable[i] = (Instruction){"???", NULL, 0, 0};
  }

  // LDA - Load Accumulator
  instructionTable[0xA9] = (Instruction){"LDA", ldaImmediate, 2, Immediate};
  instructionTable[0xA5] = (Instruction){"LDA", ldaZeroPage, 3, ZeroPage};
  instructionTable[0xB5] =
      (Instruction){"LDA", ldaZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0xAD] = (Instruction){"LDA", ldaAbsolute, 4, Absolute};
  instructionTable[0xBD] = (Instruction){"LDA", ldaAbsoluteX, 4, Absolute};
  instructionTable[0xB9] = (Instruction){"LDA", ldaAbsoluteY, 4, Absolute};
  instructionTable[0xA1] = (Instruction){"LDA", ldaIndirectX, 6, Absolute};
  instructionTable[0xB1] = (Instruction){"LDA", ldaIndirectY, 5, Absolute};

  // CLC - Clear Carry Flag
  instructionTable[0x18] = (Instruction){"CLC", clc, 2, Implied};

  // CLD - Clear Decimal Flag
  instructionTable[0xD8] = (Instruction){"CLD", cld, 2, Implied};

  // CLI - Clear Interrupt Flag
  instructionTable[0x58] = (Instruction){"CLI", cli, 2, Implied};

  // CLV - Clear Overflow Flag
  instructionTable[0xB8] = (Instruction){"CLV", clv, 2, Implied};

  // SEC - Set Carry Flag
  instructionTable[0x38] = (Instruction){"SEC", sec, 2, Implied};

  // SED - Set Decimal Flag
  instructionTable[0xF8] = (Instruction){"SED", sed, 2, Implied};

  // SEI - Set Interrupt Flag
  instructionTable[0x78] = (Instruction){"SEI", sei, 2, Implied};

  // INY - Increment Y Register
  instructionTable[0xC8] = (Instruction){"INY", incY, 2, Implied};

  // INX - Increment X Register
  instructionTable[0xE8] = (Instruction){"INX", incX, 2, Implied};

  // INC - Increment Memory
  instructionTable[0xE6] = (Instruction){"INC", incZeroPage, 5, ZeroPage};
  instructionTable[0xF6] =
      (Instruction){"INC", incZeroPageX, 6, ZeroPageXIndexed};
  instructionTable[0xEE] = (Instruction){"INC", incAbsolute, 6, Absolute};
  instructionTable[0xFE] =
      (Instruction){"INC", incAbsoluteX, 7, AbsoluteXIndexed};

  // DEX - Decrement X Register
  instructionTable[0xCA] = (Instruction){"DEX", decX, 2, Implied};

  // DEY - Decrement Y Register
  instructionTable[0x88] = (Instruction){"DEY", decY, 2, Implied};

  // DEC - Decrement Memory
  instructionTable[0xC6] = (Instruction){"DEC", decZeroPage, 5, ZeroPage};
  instructionTable[0xD6] =
      (Instruction){"DEC", decZeroPageX, 6, ZeroPageXIndexed};
  instructionTable[0xCE] = (Instruction){"DEC", decAbsolute, 6, Absolute};
  instructionTable[0xDE] =
      (Instruction){"DEC", decAbsoluteX, 7, AbsoluteXIndexed};

  // STA - Store Accumulator
  instructionTable[0x85] = (Instruction){"STA", staZeroPage, 3, ZeroPage};
  instructionTable[0x95] =
      (Instruction){"STA", staZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0x8D] = (Instruction){"STA", staAbsolute, 4, Absolute};
  instructionTable[0x9D] =
      (Instruction){"STA", staAbsoluteX, 5, AbsoluteXIndexed};
  instructionTable[0x99] =
      (Instruction){"STA", staAbsoluteY, 5, AbsoluteYIndexed};
  instructionTable[0x81] =
      (Instruction){"STA", staIndirectX, 6, IndirectXIndexed};
  instructionTable[0x91] =
      (Instruction){"STA", staIndirectY, 6, IndirectYIndexed};

  // ADC - Add with Carry
  instructionTable[0x69] = (Instruction){"ADC", adcImmediate, 2, Immediate};
  instructionTable[0x65] = (Instruction){"ADC", adcZeroPage, 3, ZeroPage};
  instructionTable[0x75] =
      (Instruction){"ADC", adcZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0x6D] = (Instruction){"ADC", adcAbsolute, 4, Absolute};
  instructionTable[0x7D] =
      (Instruction){"ADC", adcAbsoluteX, 4, AbsoluteXIndexed};
  instructionTable[0x79] =
      (Instruction){"ADC", adcAbsoluteY, 4, AbsoluteYIndexed};
  instructionTable[0x61] =
      (Instruction){"ADC", adcIndirectX, 6, IndirectXIndexed};
  instructionTable[0x71] =
      (Instruction){"ADC", adcIndirectY, 5, IndirectYIndexed};

  // AND - Logical AND
  instructionTable[0x29] = (Instruction){"AND", andImmediate, 2, Immediate};
  instructionTable[0x25] = (Instruction){"AND", andZeroPage, 3, ZeroPage};
  instructionTable[0x35] =
      (Instruction){"AND", andZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0x2D] = (Instruction){"AND", andAbsolute, 4, Absolute};
  instructionTable[0x3D] =
      (Instruction){"AND", andAbsoluteX, 4, AbsoluteXIndexed};
  instructionTable[0x39] =
      (Instruction){"AND", andAbsoluteY, 4, AbsoluteYIndexed};
  instructionTable[0x21] =
      (Instruction){"AND", andIndirectX, 6, IndirectXIndexed};
  instructionTable[0x31] =
      (Instruction){"AND", andIndirectY, 5, IndirectYIndexed};

  // ASL - Arithmetic Shift Left
  instructionTable[0x0A] = (Instruction){"ASL", aslAccumulator, 2, Accumulator};
  instructionTable[0x06] = (Instruction){"ASL", aslZeroPage, 5, ZeroPage};
  instructionTable[0x16] =
      (Instruction){"ASL", aslZeroPageX, 6, ZeroPageXIndexed};
  instructionTable[0x0E] = (Instruction){"ASL", aslAbsolute, 6, Absolute};
  instructionTable[0x1E] =
      (Instruction){"ASL", aslAbsoluteX, 7, AbsoluteXIndexed};

  // BCC - Branch if Carry Clear
  instructionTable[0x90] = (Instruction){"BCC", bcc, 2, Relative};

  // BCS - Branch if Carry Set
  instructionTable[0xB0] = (Instruction){"BCS", bcs, 2, Relative};

  // BEQ - Branch if Equal
  instructionTable[0xF0] = (Instruction){"BEQ", beq, 2, Relative};

  // BIT - Test Bits
  instructionTable[0x24] = (Instruction){"BIT", bitZeroPage, 3, ZeroPage};
  instructionTable[0x2C] = (Instruction){"BIT", bitAbsolute, 4, Absolute};

  // BMI - Branch if Minus
  instructionTable[0x30] = (Instruction){"BMI", bmi, 2, Relative};

  // BNE - Branch if Not Equal
  instructionTable[0xD0] = (Instruction){"BNE", bne, 2, Relative};

  // BPL - Branch if Positive
  instructionTable[0x10] = (Instruction){"BPL", bpl, 2, Relative};

  // BRK - Force Interrupt
  instructionTable[0x00] = (Instruction){"BRK", brk, 7, Implied};

  // BVC - Branch if Overflow Clear
  instructionTable[0x50] = (Instruction){"BVC", bvc, 2, Relative};

  // BVS - Branch if Overflow Set
  instructionTable[0x70] = (Instruction){"BVS", bvs, 2, Relative};

  // CMP - Compare
  instructionTable[0xC9] = (Instruction){"CMP", cmpImmediate, 2, Immediate};
  instructionTable[0xC5] = (Instruction){"CMP", cmpZeroPage, 3, ZeroPage};
  instructionTable[0xD5] =
      (Instruction){"CMP", cmpZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0xCD] = (Instruction){"CMP", cmpAbsolute, 4, Absolute};
  instructionTable[0xDD] =
      (Instruction){"CMP", cmpAbsoluteX, 4, AbsoluteXIndexed};
  instructionTable[0xD9] =
      (Instruction){"CMP", cmpAbsoluteY, 4, AbsoluteYIndexed};
  instructionTable[0xC1] =
      (Instruction){"CMP", cmpIndirectX, 6, IndirectXIndexed};
  instructionTable[0xD1] =
      (Instruction){"CMP", cmpIndirectY, 5, IndirectYIndexed};

  // CPX - Compare X Register
  instructionTable[0xE0] = (Instruction){"CPX", cpxImmediate, 2, Immediate};
  instructionTable[0xE4] = (Instruction){"CPX", cpxZeroPage, 3, ZeroPage};
  instructionTable[0xEC] = (Instruction){"CPX", cpxAbsolute, 4, Absolute};

  // CPY - Compare Y Register
  instructionTable[0xC0] = (Instruction){"CPY", cpyImmediate, 2, Immediate};
  instructionTable[0xC4] = (Instruction){"CPY", cpyZeroPage, 3, ZeroPage};
  instructionTable[0xCC] = (Instruction){"CPY", cpyAbsolute, 4, Absolute};

  // EOR - Exclusive OR
  instructionTable[0x49] = (Instruction){"EOR", eorImmediate, 2, Immediate};
  instructionTable[0x45] = (Instruction){"EOR", eorZeroPage, 3, ZeroPage};
  instructionTable[0x55] =
      (Instruction){"EOR", eorZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0x4D] = (Instruction){"EOR", eorAbsolute, 4, Absolute};
  instructionTable[0x5D] =
      (Instruction){"EOR", eorAbsoluteX, 4, AbsoluteXIndexed};
  instructionTable[0x59] =
      (Instruction){"EOR", eorAbsoluteY, 4, AbsoluteYIndexed};
  instructionTable[0x41] =
      (Instruction){"EOR", eorIndirectX, 6, IndirectXIndexed};
  instructionTable[0x51] =
      (Instruction){"EOR", eorIndirectY, 5, IndirectYIndexed};

  // JMP - Jump
  instructionTable[0x4C] = (Instruction){"JMP", jmpAbsolute, 3, Absolute};
  instructionTable[0x6C] = (Instruction){"JMP", jmpIndirect, 5, Indirect};

  // JSR
  instructionTable[0x20] = (Instruction){"JSR", jsr, 6, Absolute};

  // LDX - Load X Register
  instructionTable[0xA2] = (Instruction){"LDX", ldxImmediate, 2, Immediate};
  instructionTable[0xA6] = (Instruction){"LDX", ldxZeroPage, 3, ZeroPage};
  instructionTable[0xB6] =
      (Instruction){"LDX", ldxZeroPageY, 4, ZeroPageYIndexed};
  instructionTable[0xAE] = (Instruction){"LDX", ldxAbsolute, 4, Absolute};
  instructionTable[0xBE] =
      (Instruction){"LDX", ldxAbsoluteY, 4, AbsoluteYIndexed};

  // LDY - Load Y Register
  instructionTable[0xA0] = (Instruction){"LDY", ldyImmediate, 2, Immediate};
  instructionTable[0xA4] = (Instruction){"LDY", ldyZeroPage, 3, ZeroPage};
  instructionTable[0xB4] =
      (Instruction){"LDY", ldyZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0xAC] = (Instruction){"LDY", ldyAbsolute, 4, Absolute};
  instructionTable[0xBC] =
      (Instruction){"LDY", ldyAbsoluteX, 4, AbsoluteXIndexed};

  // LSR - Logical Shift Right
  instructionTable[0x4A] = (Instruction){"LSR", lsrAccumulator, 2, Accumulator};
  instructionTable[0x46] = (Instruction){"LSR", lsrZeroPage, 5, ZeroPage};
  instructionTable[0x56] =
      (Instruction){"LSR", lsrZeroPageX, 6, ZeroPageXIndexed};
  instructionTable[0x4E] = (Instruction){"LSR", lsrAbsolute, 6, Absolute};
  instructionTable[0x5E] =
      (Instruction){"LSR", lsrAbsoluteX, 7, AbsoluteXIndexed};

  // NOP - No Operation
  instructionTable[0xEA] = (Instruction){"NOP", nop, 2, Implied};

  // ORA - Logical Inclusive OR
  instructionTable[0x09] = (Instruction){"ORA", oraImmediate, 2, Immediate};
  instructionTable[0x05] = (Instruction){"ORA", oraZeroPage, 3, ZeroPage};
  instructionTable[0x15] =
      (Instruction){"ORA", oraZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0x0D] = (Instruction){"ORA", oraAbsolute, 4, Absolute};
  instructionTable[0x1D] =
      (Instruction){"ORA", oraAbsoluteX, 4, AbsoluteXIndexed};
  instructionTable[0x19] =
      (Instruction){"ORA", oraAbsoluteY, 4, AbsoluteYIndexed};
  instructionTable[0x01] =
      (Instruction){"ORA", oraIndirectX, 6, IndirectXIndexed};
  instructionTable[0x11] =
      (Instruction){"ORA", oraIndirectY, 5, IndirectYIndexed};

  // PHA - Push Accumulator
  instructionTable[0x48] = (Instruction){"PHA", pha, 3, Implied};

  // PHP - Push Processor Status
  instructionTable[0x08] = (Instruction){"PHP", php, 3, Implied};

  // PLA - Pull Accumulator
  instructionTable[0x68] = (Instruction){"PLA", pla, 4, Implied};

  // PLP - Pull Processor Status
  instructionTable[0x28] = (Instruction){"PLP", plp, 4, Implied};

  // ROL - Rotate Left
  instructionTable[0x2A] = (Instruction){"ROL", rolAccumulator, 2, Accumulator};
  instructionTable[0x26] = (Instruction){"ROL", rolZeroPage, 5, ZeroPage};
  instructionTable[0x36] =
      (Instruction){"ROL", rolZeroPageX, 6, ZeroPageXIndexed};
  instructionTable[0x2E] = (Instruction){"ROL", rolAbsolute, 6, Absolute};
  instructionTable[0x3E] =
      (Instruction){"ROL", rolAbsoluteX, 7, AbsoluteXIndexed};

  // ROR - Rotate Right
  instructionTable[0x6A] = (Instruction){"ROR", rorAccumulator, 2, Accumulator};
  instructionTable[0x66] = (Instruction){"ROR", rorZeroPage, 5, ZeroPage};
  instructionTable[0x76] =
      (Instruction){"ROR", rorZeroPageX, 6, ZeroPageXIndexed};
  instructionTable[0x6E] = (Instruction){"ROR", rorAbsolute, 6, Absolute};
  instructionTable[0x7E] =
      (Instruction){"ROR", rorAbsoluteX, 7, AbsoluteXIndexed};

  // RTI - Return from Interrupt
  instructionTable[0x40] = (Instruction){"RTI", rti, 6, Implied};

  // RTS - Return from Subroutine
  instructionTable[0x60] = (Instruction){"RTS", rts, 6, Implied};

  // SBC - Subtract with Carry
  instructionTable[0xE9] = (Instruction){"SBC", sbcImmediate, 2, Immediate};
  instructionTable[0xE5] = (Instruction){"SBC", sbcZeroPage, 3, ZeroPage};
  instructionTable[0xF5] =
      (Instruction){"SBC", sbcZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0xED] = (Instruction){"SBC", sbcAbsolute, 4, Absolute};
  instructionTable[0xFD] =
      (Instruction){"SBC", sbcAbsoluteX, 4, AbsoluteXIndexed};
  instructionTable[0xF9] =
      (Instruction){"SBC", sbcAbsoluteY, 4, AbsoluteYIndexed};
  instructionTable[0xE1] =
      (Instruction){"SBC", sbcIndirectX, 6, IndirectXIndexed};
  instructionTable[0xF1] =
      (Instruction){"SBC", sbcIndirectY, 5, IndirectYIndexed};

  // STX - Store X Register
  instructionTable[0x86] = (Instruction){"STX", stxZeroPage, 3, ZeroPage};
  instructionTable[0x96] =
      (Instruction){"STX", stxZeroPageY, 4, ZeroPageYIndexed};
  instructionTable[0x8E] = (Instruction){"STX", stxAbsolute, 4, Absolute};

  // STY - Store Y Register
  instructionTable[0x84] = (Instruction){"STY", styZeroPage, 3, ZeroPage};
  instructionTable[0x95] =
      (Instruction){"STY", styZeroPageX, 4, ZeroPageXIndexed};
  instructionTable[0x8C] = (Instruction){"STY", styAbsolute, 4, Absolute};

  // TAX - Transfer Accumulator to X
  instructionTable[0xAA] = (Instruction){"TAX", tax, 2, Implied};

  // TAY - Transfer Accumulator to Y
  instructionTable[0xA8] = (Instruction){"TAY", tay, 2, Implied};

  // TSX - Transfer Stack Pointer to X
  instructionTable[0xBA] = (Instruction){"TSX", tsx, 2, Implied};

  // TXA - Transfer X to Accumulator
  instructionTable[0x8A] = (Instruction){"TXA", txa, 2, Implied};

  // TXS - Transfer X to Stack Pointer
  instructionTable[0x9A] = (Instruction){"TXS", txs, 2, Implied};

  // TYA - Transfer Y to Accumulator
  instructionTable[0x8A] = (Instruction){"TYA", tya, 2, Implied};
}
