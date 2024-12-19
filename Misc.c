#include "Misc.h"

void clc(CPU *cpu) { cpu->P &= 0xFE; }
void cld(CPU *cpu) { cpu->P &= ~(1 << 3); }
void cli(CPU *cpu) { cpu->P &= ~(1 << 2); }
void clv(CPU *cpu) { cpu->P &= ~(1 << 6); }

void sec(CPU *cpu) { cpu->P |= 1; }
void sed(CPU *cpu) { cpu->P |= (1 << 3); }
void sei(CPU *cpu) { cpu->P |= (1 << 2); }

void bitZeroPage(CPU *cpu) { return; }
void bitAbsolute(CPU *cpu) { return; }

void nop(CPU *cpu) { return; }
