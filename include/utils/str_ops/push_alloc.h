/* Macro to avoid multiple header inclusion. */

#ifndef PUSH_ALLOC_H
	#define PUSH_ALLOC_H





/* Including required headers. */

#include <stdio.h>			// Required for using libc's optimized functions.
#include <string.h>			// Required to use certain functions related to stings.
#include <stdlib.h>			// Required to allocate memory for target string.




/* Declaration of functions. */

void push_alloc(char *str, char c, char *mode);





/* Closing the safe inclusion macro. */

#endif