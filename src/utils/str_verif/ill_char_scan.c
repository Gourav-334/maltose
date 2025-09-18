/* Including required headers. */

#include "../../../include/utils/str_verif/ill_char_scan.h"
#include "../../../include/utils/str_ops/push_alloc.h"

#include <stdio.h>			// Required for using libc's optimized functions.
#include <string.h>			// Required to use certain functions related to stings.
#include <stdlib.h>			// Required to allocate memory for trash string.










/* Scans for illegal characters in a given string. */

bool scan_ill_chars(char *str, long int len, char *ill_chars, char *mode)
{
	/* Variable declarations/definitions. */

	long int total_ill_chars = 0;
	char *trash = NULL;



	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return false;
	}





	/* Illegal characters scanning loop. */

	for (long int i=0; i<len; i++)
	{
		for (long int j=0; j<strlen(ill_chars); j++)
		{
			/* If character matching is not illegal with current character. */

			if ((*(str+i))!=(*(ill_chars+j)))
			{
				if (M==DEV) {continue;}
				else if (M==USER) {continue;}
				else if (M==DEBUG)
				{
					/* Writing transparent details about indices, characters, and match result. */

					printf("OK :: Not illegal match :: str[%ld]=%c : ill_chars[%ld]=%c\n",
						i, *(str+i), j, *(ill_chars+j));
				}
			}



			/* If character matching is found illegal. */

			else if ((*(str+i))==(*(ill_chars+j)))
			{
				total_ill_chars++;


				if (M==DEV) {return true;}
				else if (M==USER)
				{
					/* Pushing the illegal character to the string. */

					push_alloc(&trash, *(ill_chars+j), "dev");



					/* Not further scanning same character, moving to next. */

					break;
				}
				else if (M==DEBUG)
				{
					/* Writing transparent deatils about indices, characters, and match result. */

					printf("ERROR :: Illegal match :: str[%ld]=%c : ill_chars[%ld]=%c\n",
						i, *(str+i), j, *(ill_chars+j));
				}
			}
		}
	}





	/* After whole scan has been completed. */

	if (M==DEV)
	{
		if (total_ill_chars==0) {return false;}
		else if (total_ill_chars>0) {return true;}
	}
	else if (M==USER)
	{
		if (total_ill_chars==0)
		{
			printf("OK: No illegal character usage found in \"%s\".\n", str);
			return false;
		}
		else if (total_ill_chars>0)
		{
			printf("ERROR: Illegal characters \"%s\" found in string \"%s\"!\n",
				trash, str);
			return true;
		}
	}
	else if (M==DEBUG)
	{
		if (total_ill_chars==0)
		{
			printf("OK: No illegal character usage found in \"%s\".\n", str);
			return false;
		}
		else if (total_ill_chars>0)
		{
			printf("ERROR: Total %ld illegal characters found in string \"%s\"!\n",
				total_ill_chars, str);
		}
	}



	/* Deallocating unwanted resources. */

	if(trash!=NULL) {free(trash);}
}