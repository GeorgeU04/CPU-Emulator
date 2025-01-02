#ifndef LOGICAL_H
#include "CPU.h"

// AND - Logical AND
void andImmediate(CPU *cpu); // done
void andZeroPage(CPU *cpu);  // done
void andZeroPageX(CPU *cpu); // done
void andAbsolute(CPU *cpu);  // done
void andAbsoluteX(CPU *cpu); // done
void andAbsoluteY(CPU *cpu); // done
void andIndirectX(CPU *cpu); // done
void andIndirectY(CPU *cpu); // done

// ASL - Arithmetic Shift Left
void aslAccumulator(CPU *cpu); // done
void aslZeroPage(CPU *cpu);    // done
void aslZeroPageX(CPU *cpu);   // done
void aslAbsolute(CPU *cpu);    // done
void aslAbsoluteX(CPU *cpu);   // done

// EOR - Exclusive OR
void eorImmediate(CPU *cpu); // done
void eorZeroPage(CPU *cpu);  // done
void eorZeroPageX(CPU *cpu); // done
void eorAbsolute(CPU *cpu);  // done
void eorAbsoluteX(CPU *cpu); // done
void eorAbsoluteY(CPU *cpu); // done
void eorIndirectX(CPU *cpu); // done
void eorIndirectY(CPU *cpu); // done

// ORA - Logical Inclusive OR
void oraImmediate(CPU *cpu); // done
void oraZeroPage(CPU *cpu);  // done
void oraZeroPageX(CPU *cpu); // done
void oraAbsolute(CPU *cpu);  // done
void oraAbsoluteX(CPU *cpu); // done
void oraAbsoluteY(CPU *cpu); // done
void oraIndirectX(CPU *cpu); // done
void oraIndirectY(CPU *cpu); // done

// LSR - Logical Shift Right
void lsrAccumulator(CPU *cpu); // done
void lsrZeroPage(CPU *cpu);    // done
void lsrZeroPageX(CPU *cpu);   // done
void lsrAbsolute(CPU *cpu);    // done
void lsrAbsoluteX(CPU *cpu);   // done

// ROL - Rotate Left
void rolAccumulator(CPU *cpu); // done
void rolZeroPage(CPU *cpu);    // done
void rolZeroPageX(CPU *cpu);   // done
void rolAbsolute(CPU *cpu);    // done
void rolAbsoluteX(CPU *cpu);   // done

// ROR - Rotate Right
void rorAccumulator(CPU *cpu); // done
void rorZeroPage(CPU *cpu);    // done
void rorZeroPageX(CPU *cpu);   // done
void rorAbsolute(CPU *cpu);    // done
void rorAbsoluteX(CPU *cpu);   // done

#endif // !LOGICAL_H
