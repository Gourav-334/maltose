/* Guards to avoid multiple inclusions. */

#ifndef SPECS_STORE_H
	#define SPECS_STORE_H

#define TOTAL_SEC 0x13
#define SEC_NULL 0x0
#define SEC_TEXT 0x1
#define SEC_DATA 0x2
#define SEC_BSS 0x3
#define SEC_RODATA 0x4
#define SEC_COMMENT 0x5
#define SEC_GNU_STACK 0x6
#define SEC_GNU_BUILD 0x7
#define SEC_RLA_TEXT 0x8
#define SEC_DATA_RO 0x9
#define SEC_EH_FRAME 0xa
#define SEC_SYMTAB 0xb
#define SEC_STRTAB 0xc
#define SEC_SHSTRTAB 0xd





/* Including required headers. */

#include <elf.h>










/* Structure instances */

extern Elf64_Ehdr elf_header;					// Stores ELF header information.
extern Elf64_Shdr sec_header[TOTAL_SEC];		// Stores section header information.










/* Closing guard macros. */

#endif