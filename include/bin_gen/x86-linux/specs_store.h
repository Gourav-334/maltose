/* Guards to avoid multiple inclusions. */

#ifndef SPECS_STORE_H
	#define SPECS_STORE_H

#define TOTAL_SEC 0x12
#define SEC_NULL 0x0
#define SEC_TEXT 0x1
#define SEC_RELA_TEXT 0x2
#define SEC_DATA 0x3
#define SEC_BSS 0x4
#define SEC_RODATA 0x5
#define SEC_SYMTAB 0x6
#define SEC_STRTAB 0x7
#define SEC_SHSTRTAB 0x8
#define SEC_COMMENT 0x9
#define SEC_GNU_STACK 0xa
#define SEC_DEBUG 0xb





/* Including required headers. */

#include <elf.h>










/* Structure instances */

extern Elf64_Ehdr elf_header;					// Stores ELF header information.
extern Elf64_Shdr sec_header[TOTAL_SEC];		// Stores section header information.
extern Elf64_Sym *symtab;						// Stores contagious symbol tables.
extern Elf64_Rel rel_data[TOTAL_SEC];			// Stores contagious relocation data.



/* Variables/constants */

extern int sym_count;










/* Closing guard macros. */

#endif