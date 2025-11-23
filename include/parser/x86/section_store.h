/* Including guards to avoid multiple inclusions. */

#ifndef SECTION_STORE_H
	#define SECTION_STORE_H





/* Including required headers. */

#include "../../data_structs/linked_list/ll_struct.h"

#include <stdint.h>			// For using pointer special data type.










/* Declaring variables. */

extern uintptr_t *sec_text;
extern uintptr_t *sec_data;
extern uintptr_t *sec_bss;
extern uintptr_t *sec_rodata;


extern uintptr_t *sec_ptr;


extern long int sec_text_blocks;
extern long int sec_data_blocks;
extern long int sec_bss_blocks;
extern long int sec_rodata_blocks;
extern long int *sec_block_count;


extern long int active_braces;










/* Closing guard macros. */

#endif