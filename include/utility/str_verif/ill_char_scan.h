/* Macro to avoid multiple header inclusion. */

#ifndef ILL_CHAR_SCAN_H
	#define ILL_CHAR_SCAN_H





/* Including required headers. */

#include <stdio.h>			// Required for using libc's optimized functions.
#include <string.h>			// Required to use certain functions related to stings.
#include <stdlib.h>			// Required to allocate memory for trash string.
#include <stdbool.h>		// Required to use boolean as a convenient option over bandaging.




/* Declaration of functions. */

bool scan_ill_chars(char *str, long int len, char *mode, char *ill_chars);		// Scans for unwanted characters in a string.





/* Closing the safe inclusion macro. */

#endif
