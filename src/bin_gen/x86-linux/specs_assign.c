/* Including required headers. */

#include "../../../include/bin_gen/specs_assign.h"
#include "../../../include/bin_gen/specs_store.h"










/* Extracts information & assigns specs to intended variables. */

bool assign_spec()
{
	/* Filling ELF header information. */

	.e_ident[EI_MAG0] = 0x7f;				// ELF magic numbers
	.e_ident[EI_MAG1] = 'E';
	.e_ident[EI_MAG2] = 'L';
	.e_ident[EI_MAG3] = 'F';
	.e_ident[EI_CLASS] = ELFCLASS64;		// 64-bit ELF
	.e_ident[EI_DATA] = ELFDATA2LSB;		// Little-endian
	.e_ident[EI_VERSION] = EV_CURRENT;		// Current version
	.e_ident[EI_OSABI] = ELFOSABI_SYSV;		// Linux SysV ABI
	.e_ident[EI_PAD] = 0;					// No padding
	.e_type = ET_REL;						// Object file
	.e_machine = EM_X86_64;					// x86-64 processor
	.e_version = EV_CURRENT;				// Current version (again)
	.e_entry = LOAD_ADDR;					// Using conventional address
	.e_phoff = sizeof(Elf64_Ehdr);			// Immediately after ELF header
	.e_shoff = 0;							// Tiny binary
	.e_flags = 0;							// x86-64 don't use flags
	.e_ehsize = sizeof(Elf64_Ehdr);			// ELF header struct size
	.e_phentsize = sizeof (Elf64_Phdr);		// Program header struct size
	.e_phnum = 1;							// 1 by deafault
	.e_shnum = 0;							// Number of sections
	.e_shstrndx = SHN_UNDEF;				// Undefined by default
}