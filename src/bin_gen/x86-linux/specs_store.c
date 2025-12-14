/* Including required headers. */

#include "../../../include/bin_gen/x86-linux/specs_store.h"

#include <stddef.h>			// To use NULL for certain structure members.










/* Structure instances */

Elf64_Ehdr elf_header = {			// Stores ELF header information.
	.e_ident = {0},
	.e_type = 0x0,
	.e_machine = 0x0,
	.e_version = 0x0,
	.e_entry = 0x0,
	.e_phoff = 0x0,
	.e_shoff = 0x0,
	.e_flags = 0x0,
	.e_ehsize = 0x0,
	.e_phentsize = 0x0,
	.e_phnum = 0x0,
	.e_shentsize = 0x0,
	.e_shnum = 0x0,
	.e_shstrndx = 0x0
};





Elf64_Shdr sec_header[TOTAL_SEC] = {0};			// Array of section headers.
Elf64_Sym *symtab = NULL;						// Contagious collection of symbols.
Elf64_Rel rel_data[TOTAL_SEC] = {0};			// Relocation data for each section.