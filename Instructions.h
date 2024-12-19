#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "CPU.h"
#include <stdint.h>

typedef enum {
  Implied,
  Immediate,
  Absolute,
  AbsoluteXIndexed,
  AbsoluteYIndexed,
  ZeroPage,
  ZeroPageXIndexed,
  ZeroPageYIndexed,
  Indirect,
  IndirectXIndexed,
  IndirectYIndexed,
  Relative,
  Accumulator
} adressingMode;

typedef struct {
  const char *name;
  void (*handler)(CPU *cpu);
  uint8_t cycles;
  adressingMode mode;
} Instruction;

extern Instruction instructionTable[256];

void initInstructionTable();

// ADC - Add with Carry
void adcImmediate(CPU *cpu);
void adcZeroPage(CPU *cpu);
void adcZeroPageX(CPU *cpu);
void adcAbsolute(CPU *cpu);
void adcAbsoluteX(CPU *cpu);
void adcAbsoluteY(CPU *cpu);
void adcIndirectX(CPU *cpu);
void adcIndirectY(CPU *cpu);

// AND - Logical AND
void andImmediate(CPU *cpu);
void andZeroPage(CPU *cpu);
void andZeroPageX(CPU *cpu);
void andAbsolute(CPU *cpu);
void andAbsoluteX(CPU *cpu);
void andAbsoluteY(CPU *cpu);
void andIndirectX(CPU *cpu);
void andIndirectY(CPU *cpu);

// ASL - Arithmetic Shift Left
void aslAccumulator(CPU *cpu);
void aslZeroPage(CPU *cpu);
void aslZeroPageX(CPU *cpu);
void aslAbsolute(CPU *cpu);
void aslAbsoluteX(CPU *cpu);

// BCC - Branch if Carry Clear
void bcc(CPU *cpu);

// BCS - Branch if Carry Set
void bcs(CPU *cpu);

// BEQ - Branch if Equal
void beq(CPU *cpu);

// BIT - Test Bits
void bitZeroPage(CPU *cpu);
void bitAbsolute(CPU *cpu);

// BMI - Branch if Minus
void bmi(CPU *cpu);

// BNE - Branch if Not Equal
void bne(CPU *cpu);

// BPL - Branch if Positive
void bpl(CPU *cpu);

// BRK - Force Interrupt
void brk(CPU *cpu);

// BVC - Branch if Overflow Clear
void bvc(CPU *cpu);

// BVS - Branch if Overflow Set
void bvs(CPU *cpu);

// CLC - Clear Carry Flag
void clc(CPU *cpu); // done

// CLD - Clear Decimal Mode
void cld(CPU *cpu); // done

// CLI - Clear Interrupt Disable
void cli(CPU *cpu); // done

// CLV - Clear Overflow Flag
void clv(CPU *cpu); // done

// CMP - Compare
void cmpImmediate(CPU *cpu);
void cmpZeroPage(CPU *cpu);
void cmpZeroPageX(CPU *cpu);
void cmpAbsolute(CPU *cpu);
void cmpAbsoluteX(CPU *cpu);
void cmpAbsoluteY(CPU *cpu);
void cmpIndirectX(CPU *cpu);
void cmpIndirectY(CPU *cpu);

// CPX - Compare X Register
void cpxImmediate(CPU *cpu);
void cpxZeroPage(CPU *cpu);
void cpxAbsolute(CPU *cpu);

// CPY - Compare Y Register
void cpyImmediate(CPU *cpu);
void cpyZeroPage(CPU *cpu);
void cpyAbsolute(CPU *cpu);

// DEC - Decrement Memory
void decZeroPage(CPU *cpu);  // done
void decZeroPageX(CPU *cpu); // done
void decAbsolute(CPU *cpu);  // done
void decAbsoluteX(CPU *cpu); // done

// DEX - Decrement X Register
void decX(CPU *cpu); // done

// DEY - Decrement Y Register
void decY(CPU *cpu); // done

// EOR - Exclusive OR
void eorImmediate(CPU *cpu);
void eorZeroPage(CPU *cpu);
void eorZeroPageX(CPU *cpu);
void eorAbsolute(CPU *cpu);
void eorAbsoluteX(CPU *cpu);
void eorAbsoluteY(CPU *cpu);
void eorIndirectX(CPU *cpu);
void eorIndirectY(CPU *cpu);

// INC - Increment Memory
void incZeroPage(CPU *cpu);  // done
void incZeroPageX(CPU *cpu); // done
void incAbsolute(CPU *cpu);  // done
void incAbsoluteX(CPU *cpu); // done

// INX - Increment X Register
void incX(CPU *cpu); // done

// INY - Increment Y Register
void incY(CPU *cpu); // done

// JMP - Jump
void jmpAbsolute(CPU *cpu);
void jmpIndirect(CPU *cpu);

// JSR - Jump to Subroutine
void jsr(CPU *cpu);

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

// LSR - Logical Shift Right
void lsrAccumulator(CPU *cpu);
void lsrZeroPage(CPU *cpu);
void lsrZeroPageX(CPU *cpu);
void lsrAbsolute(CPU *cpu);
void lsrAbsoluteX(CPU *cpu);

// NOP - No Operation
void nop(CPU *cpu);

// ORA - Logical Inclusive OR
void oraImmediate(CPU *cpu);
void oraZeroPage(CPU *cpu);
void oraZeroPageX(CPU *cpu);
void oraAbsolute(CPU *cpu);
void oraAbsoluteX(CPU *cpu);
void oraAbsoluteY(CPU *cpu);
void oraIndirectX(CPU *cpu);
void oraIndirectY(CPU *cpu);

// PHA - Push Accumulator
void pha(CPU *cpu);

// PHP - Push Processor Status
void php(CPU *cpu);

// PLA - Pull Accumulator
void pla(CPU *cpu);

// PLP - Pull Processor Status
void plp(CPU *cpu);

// ROL - Rotate Left
void rolAccumulator(CPU *cpu);
void rolZeroPage(CPU *cpu);
void rolZeroPageX(CPU *cpu);
void rolAbsolute(CPU *cpu);
void rolAbsoluteX(CPU *cpu);

// ROR - Rotate Right
void rorAccumulator(CPU *cpu);
void rorZeroPage(CPU *cpu);
void rorZeroPageX(CPU *cpu);
void rorAbsolute(CPU *cpu);
void rorAbsoluteX(CPU *cpu);

// RTI - Return from Interrupt
void rti(CPU *cpu);

// RTS - Return from Subroutine
void rts(CPU *cpu);

// SBC - Subtract with Carry
void sbcImmediate(CPU *cpu);
void sbcZeroPage(CPU *cpu);
void sbcZeroPageX(CPU *cpu);
void sbcAbsolute(CPU *cpu);
void sbcAbsoluteX(CPU *cpu);
void sbcAbsoluteY(CPU *cpu);
void sbcIndirectX(CPU *cpu);
void sbcIndirectY(CPU *cpu);

// SEC - Set Carry Flag
void sec(CPU *cpu); // done

// SED - Set Decimal Flag
void sed(CPU *cpu); // done

// SEI - Set Interrupt Disable
void sei(CPU *cpu); // done

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

// TSX - Transfer Stack Pointer to X
void tsx(CPU *cpu);

// TXA - Transfer X to Accumulator
void txa(CPU *cpu);

// TXS - Transfer X to Stack Pointer
void txs(CPU *cpu);

// TYA - Transfer Y to Accumulator
void tya(CPU *cpu);

#endif // !INSTRUCTIONS_H
