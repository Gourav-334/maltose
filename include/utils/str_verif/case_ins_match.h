/* Including guards to avoid multiple inclusions. */

#ifndef CASE_INS_MATCH_H
	#define CASE_INS_MATCH_H

#define LWR2UPR_DIFF 32			// Difference between same lowercase & uppercase ASCII character.
#define LOWERCASE 0				// Code for lowercase characters.
#define UPPERCASE 1				// Code for uppercase characters.
#define OTHER 2					// Code for other characters.





/* Including required headers. */

#include <stdbool.h>		// To use boolean parameter 'full_match'.










/* Declaring functions. */

int match_ins_case(char *str1, char *str2, bool full_match, char *mode);		// Matches two strings by ignoring the differences in their cases.










/* Closing guard macros safely. */

#endif