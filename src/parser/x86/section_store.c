/* Including required headers. */

#include "../../../include/parser/x86/section_store.h"

#include <stdio.h>			// To use NULL's functionalities.










/* Defining variables. */

Ll_recorder **sec_text = NULL;
Ll_recorder **sec_data = NULL;
Ll_recorder **sec_bss = NULL;
Ll_recorder **sec_rodata = NULL;