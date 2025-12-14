/* Guards to avoid multiple inclusions. */

#ifndef BIN_SEC_STORE_H
	#define BIN_SEC_STORE_H





/* Including required headers. */

#include <stdint.h>			// To use architecturally consistent data types.
#include <stddef.h>			// To use standard definitions without bloated imports.










/* Section storage units. */

extern uint8_t *sec_null_store;					// Stores contents of NULL section (no use - just convention).
extern uint8_t *sec_text_store;					// Stores contents of .text section.
extern uint8_t *sec_rela_text_store;			// Stores contents of .rela.text section.
extern uint8_t *sec_data_store;					// Stores contents of .data section.
extern uint8_t *sec_bss_store;					// Stores contents of .bss section.
extern uint8_t *sec_rodata_store;				// Stores contents of .rodata section.
extern uint8_t *sec_symtab_store;				// Stores contents of .symtab section.
extern uint8_t *sec_strtab_store;				// Stores contents of .strtab section.
extern uint8_t *sec_shstrtab_store;				// Stores contents of .shstrtab section.
extern uint8_t *sec_comment_store;				// Stores contents of .comment section.
extern uint8_t *sec_gnu_stack_store;			// Stores contents of .note_gnu-stack section.
extern uint8_t *sec_debug_store;				// Stores contents of .debug section.



/* Size counting units. */

extern size_t sec_null_size;					// Stores contents of NULL section (no use - just convention).
extern size_t sec_text_size;					// Stores contents of .text section.
extern size_t sec_rela_text_size;				// Stores contents of .rela.text section.
extern size_t sec_data_size;					// Stores contents of .data section.
extern size_t sec_bss_size;						// Stores contents of .bss section.
extern size_t sec_rodata_size;					// Stores contents of .rodata section.
extern size_t sec_symtab_size;					// Stores contents of .symtab section.
extern size_t sec_strtab_size;					// Stores contents of .strtab section.
extern size_t sec_shstrtab_size;				// Stores contents of .shstrtab section.
extern size_t sec_comment_size;					// Stores contents of .comment section.
extern size_t sec_gnu_stack_size;				// Stores contents of .note_gnu-stack section.
extern size_t sec_debug_size;					// Stores contents of .debug section.










/* Closing guard macros. */

#endif