/* Including required headers. */

#include "../../../include/parser/x86/section_store.h"

#include <stdio.h>			// To use NULL's functionalities.










/* Defining variables. */

uintptr_t *sec_text = NULL;
uintptr_t *sec_data = NULL;
uintptr_t *sec_bss = NULL;
uintptr_t *sec_rodata = NULL;


uintptr_t *sec_ptr = NULL;


long int sec_text_blocks = 0;
long int sec_data_blocks = 0;
long int sec_bss_blocks = 0;
long int sec_rodata_blocks = 0;
long int *sec_block_count = NULL;


long int active_braces = 0;