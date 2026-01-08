/* Including guards to avoid multiple inclusions. */

#ifndef SECTION_STORE_H
	#define SECTION_STORE_H

#define TOTAL_OFFSETS 5
#define TOKEN_BEGIN_OFFSET 0
#define TOKEN_END_OFFSET 1
#define CATEG_OFFSET 2
#define SUB_CATEG_OFFSET 3
#define TYPE_OFFSET 4





/* Including required headers. */

#include "../../data_structs/linked_list/ll_struct.h"

#include <stdint.h>			// For using pointer special data type.










/* Declaring variables. */

extern uintptr_t *sec_text;				// Array of elements pointing to token address of start/end of .TEXT section.
extern uintptr_t *sec_data;				// Array of elements pointing to token address of start/end of .DATA section.
extern uintptr_t *sec_bss;				// Array of elements pointing to token address of start/end of .BSS section.
extern uintptr_t *sec_rodata;			// Array of elements pointing to token address of start/end of .RODATA section.

extern uintptr_t *sec_ptr;				// Pointer to one of the array containing entry/exit to its corresponding section.


extern long int sec_text_blocks;		// Counts number of .TEXT block appearances.
extern long int sec_data_blocks;		// Counts number of .DATA block appearances.
extern long int sec_bss_blocks;			// Counts number of .BSS block appearances.
extern long int sec_rodata_blocks;		// Counts number of .RODATA block appearances.

extern long int *sec_block_count;		// Pointer to one of the section counter.


extern long int active_braces;			// Counts the number of curly braces opened.










/* Closing guard macros. */

#endif