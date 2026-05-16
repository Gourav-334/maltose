/* Including required headers. */

#include "../../../include/bin_gen/x86-linux/specs_assign.h"
#include "../../../include/bin_gen/x86-linux/specs_store.h"










/* Extracts information & assigns specs to intended variables. */

bool assign_specs(void)
{
	/* Filling ELF header information. */

	elf_header.e_ident[EI_MAG0] = 0x7f;				// ELF magic numbers
	elf_header.e_ident[EI_MAG1] = 'E';				// Magic 'E'
	elf_header.e_ident[EI_MAG2] = 'L';				// Magic 'L'
	elf_header.e_ident[EI_MAG3] = 'F';				// Magic 'F'
	elf_header.e_ident[EI_CLASS] = ELFCLASS64;		// 64-bit ELF class
	elf_header.e_ident[EI_DATA] = ENDIANNESS;		// Detected in header file
	elf_header.e_ident[EI_VERSION] = EV_CURRENT;	// Current version
	elf_header.e_ident[EI_OSABI] = ELFOSABI_SYSV;	// Linux SysV ABI
	elf_header.e_ident[EI_PAD] = 0x0;				// No padding
	elf_header.e_type = ET_REL;						// Object file
	elf_header.e_machine = EM_X86_64;				// x86-64 processor
	elf_header.e_version = EV_CURRENT;				// Current version (again)
	elf_header.e_entry = OBJ_ENTRY;					// Entry point for object files
	elf_header.e_phoff = 0x0;						// Object files don't contain any
	elf_header.e_shoff = sizeof(Elf64_Ehdr);		// Immediately after ELF header
	elf_header.e_flags = 0x0;						// x86-64 don't use flags
	elf_header.e_ehsize = sizeof(Elf64_Ehdr);		// ELF header struct size
	elf_header.e_phentsize = 0x0;					// Program header struct size
	elf_header.e_phnum = 0x0;						// No segments in object file at all
	elf_header.e_shentsize = sizeof(Elf64_Shdr);	// Same as the SHDR structure
	elf_header.e_shnum = 0x14;						// Kept GCC/Clang compatible
	elf_header.e_shstrndx = 0x13;					// On 13th index (GCC/Clang compatible)
}