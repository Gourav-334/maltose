/* Including required headers. */

#include "../../../include/bin_gen/x86-linux/bin_sec_store.h"










/* Section storage units. */

uint8_t *sec_null_store = NULL;					// Stores contents of NULL section (no use - just convention).
uint8_t *sec_text_store = NULL;					// Stores contents of .text section.
uint8_t *sec_rela_text_store = NULL;			// Stores contents of .rela.text section.
uint8_t *sec_data_store = NULL;					// Stores contents of .data section.
uint8_t *sec_bss_store = NULL;					// Stores contents of .bss section.
uint8_t *sec_rodata_store = NULL;				// Stores contents of .rodata section.
uint8_t *sec_symtab_store = NULL;				// Stores contents of .symtab section.
uint8_t *sec_strtab_store = NULL;				// Stores contents of .strtab section.
uint8_t *sec_shstrtab_store = NULL;				// Stores contents of .shstrtab section.
uint8_t *sec_comment_store = NULL;				// Stores contents of .comment section.
uint8_t *sec_gnu_stack_store = NULL;			// Stores contents of .note_gnu-stack section.
uint8_t *sec_debug_store = NULL;				// Stores contents of .debug section.



/* Size counting units. */

size_t sec_null_size = 0;					// Stores contents of NULL section (no use - just convention).
size_t sec_text_size = 0;					// Stores contents of .text section.
size_t sec_rela_text_size = 0;				// Stores contents of .rela.text section.
size_t sec_data_size = 0;					// Stores contents of .data section.
size_t sec_bss_size = 0;					// Stores contents of .bss section.
size_t sec_rodata_size = 0;					// Stores contents of .rodata section.
size_t sec_symtab_size = 0;					// Stores contents of .symtab section.
size_t sec_strtab_size = 0;					// Stores contents of .strtab section.
size_t sec_shstrtab_size = 0;				// Stores contents of .shstrtab section.
size_t sec_comment_size = 0;				// Stores contents of .comment section.
size_t sec_gnu_stack_size = 0;				// Stores contents of .note_gnu-stack section.
size_t sec_debug_size = 0;					// Stores contents of .debug section.