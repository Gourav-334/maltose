/* Guards to avoid multiple inclusions. */

#ifndef SPECS_STORE_H
	#define SPECS_STORE_H





/* Including required headers. */

#include <elf.h>










/* Structure instances */

extern Elf64_Ehdr elf_header;			// Stores ELF header information.
extern Elf64_Phdr prog_header;			// Stores program header information.
extern Elf64_Shdr sec_header;			// Stores section header information.










/* Closing guard macros. */

#endif