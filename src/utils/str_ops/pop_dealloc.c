/* Including required libraries. */

#include "../../../include/utils/str_ops/pop_dealloc.h"

#include <stdio.h>			// For providing feedback as per chosen mode.
#include <stdlib.h>			// For reallocating memories.
#include <string.h>			// For measuring size of the string.










/* Deallocates a byte from the end of the string. */

void pop_dealloc(char **str, char *mode)
{
	/* Variable declarations/definitions. */

	long int str_len;



	/* Non-linear structure declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is being used. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!", mode);
		return;
	}





	/* Checking if the string if the string is empty or not. */

	if (**str=='\0')
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: String is already empty!\n");}
		else if (M==DEBUG) {printf("ERROR :: String is already empty!\n");}

		return;
	}
	else
	{
		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {printf("OK: String is not empty.\n");}
		else if (M==DEBUG) {printf("OK :: String is not empty.\n");}





		/* Calculating length of string & expelling trailing byte. */

		str_len = strlen(*str) + 1;
		*str = realloc(*str, (size_t)(str_len-1));



		/* Checking if memory is successfully reallocated or not. */

		if (*str==NULL)
		{
			if (M==DEV) {}
			else if (M==USER) {printf("ERROR: Failed to reallocate memory!\n");}
			else if (M==DEBUG) {printf("ERROR :: Failed to release trailing byte \'%c\'!\n", *(*str+str_len-1));}

			return;
		}
		else
		{
			if (M==DEV) {}
			else if (M==USER) {printf("OK: Trailing byte expelled successfully.\n");}
			else if (M==DEBUG) {printf("OK :: Size reduced by 1 byte :: str=%s :: str_len=%ld\n", *str, str_len);}
		}
		




		/* Setting expelled byte to '\0'. */

		str_len--;
		*(*str+str_len-1) = '\0';



		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {printf("OK: Memory deallocated successfully.\n");}
		else if (M==DEBUG) {printf("OK :: Memory deallocated :: str=%s :: str_len=%ld\n", *str, str_len);}
	}
}