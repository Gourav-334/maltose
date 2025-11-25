/* Including required headers. */

#include "../../../include/bin_gen/x86/specs_store.h"

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





Elf64_Phdr prog_header = {			// Stores program header information.
	.p_type = 0x0,
	.p_flags = 0x0,
	.p_offset = 0x0,
	.p_vaddr = 0x0,
	.p_paddr = 0x0,
	.p_filesz = 0x0,
	.p_memsz = 0x0,
	.p_align = 0x0
};





Elf64_Shdr sec_header = {			// Stores section header information.
	.sh_name = 0x0,
	.sh_type = 0x0,
	.sh_flags = 0x0,
	.sh_addr = 0x0,
	.sh_offset = 0x0,
	.sh_size = 0x0,
	.sh_link = 0x0,
	.sh_info = 0x0,
	.sh_addralign = 0x0,
	.sh_entsize = 0x0
};