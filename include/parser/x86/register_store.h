/* Including guard to avoid multiple inclusions. */

#ifndef REGISTER_STORE_H
	#define REGISTER_STORE_H





/* Including required headers. */

#include <stdint.h>			// For defining architecturally consistent sized variables.










/* Register definitions (self-explanatory). */

extern uint8_t ah;
extern uint8_t al;
extern uint16_t ax;
extern uint8_t bh;
extern uint8_t bl;
extern uint16_t bp;
extern uint8_t bpl;
extern uint16_t bx;
extern uint8_t cl;
extern uint8_t ch;
extern uint16_t cx;
extern uint8_t dh;
extern uint16_t di;
extern uint8_t dil;
extern uint8_t dl;
extern uint16_t dx;
extern uint32_t eax;
extern uint32_t ebp;
extern uint32_t ebx;
extern uint32_t ecx;
extern uint32_t edi;
extern uint32_t edx;
extern uint32_t eflag;
extern uint32_t esi;
extern uint32_t esp;
extern uint16_t fpflag;
extern uint64_t r10;
extern uint16_t r10b;
extern uint32_t r10w;
extern uint64_t r11;
extern uint16_t r11b;
extern uint32_t r11w;
extern uint64_t r12;
extern uint16_t r12b;
extern uint32_t r12w;
extern uint64_t r13;
extern uint16_t r13b;
extern uint32_t r13w;
extern uint64_t r14;
extern uint16_t r14b;
extern uint32_t r14w;
extern uint64_t r15;
extern uint16_t r15b;
extern uint32_t r15w;
extern uint64_t r8;
extern uint16_t r8b;
extern uint32_t r8w;
extern uint64_t r9;
extern uint16_t r9b;
extern uint32_t r9w;
extern uint64_t rax;
extern uint64_t rbp;
extern uint64_t rbx;
extern uint64_t rcx;
extern uint64_t rdi;
extern uint64_t rdx;
extern uint64_t rflag;
extern uint64_t rsi;
extern uint64_t rsp;
extern uint16_t si;
extern uint8_t sil;
extern uint16_t sp;





/* Table pointing registers. */

struct GDTR {uint16_t limit; uint32_t base;} __attribute__((packed));
struct IDTR {uint16_t limit; uint32_t base;} __attribute__((packed));











/* Closing guard macros. */

#endif