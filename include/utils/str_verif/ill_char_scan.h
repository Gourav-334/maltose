/* Macro to avoid multiple header inclusion. */

#ifndef ILL_CHAR_SCAN_H
	#define ILL_CHAR_SCAN_H





/* Including required headers. */

#include <stdbool.h>		// Required to use boolean as a convenient option over bandaging.










/* Declaration of functions. */

bool scan_ill_chars(char *str, long int len, char *ill_chars, char *mode);		// Scans for unwanted characters in a string.










/* Closing the safe inclusion macro. */

#endif
