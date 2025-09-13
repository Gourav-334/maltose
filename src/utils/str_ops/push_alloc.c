/* Including required headers. */

#include "../../../include/utils/str_ops/push_alloc.h"

#include <stdio.h>			// Required for using libc's optimized functions.
#include <string.h>			// Required to use certain functions related to stings.
#include <stdlib.h>			// Required to allocate memory for target string.










/* Pushes a character to the end of the string, dynamically. */

void push_alloc(char **str, char c, char *mode)
{
	/* Variables declarations/definitions. */

	long int str_len;		// String length (including null terminator).





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





	/* Checking if the string is empty or not. */

	if (*str==NULL)
	{
		str_len = 0;



		/* Providing feedback as per the mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: Target string is either empty, or pointing to NULL.\n");
		}





		/* Allocating intial byte for the string. */

		*str = malloc(1*sizeof(char));


		/* Making sure that memory is allocated. */

		if (*str==NULL) {perror("ERROR"); return;}
		else
		{
			*(*str+str_len) = '\0';
			str_len++;



			/* Providing feedback for successful allocation as per mode. */

			if (M==DEV) {}
			else if (M==USER)
			{
				printf("OK: No problem initiating byte for string.\n");
			}
			else if (M==DEBUG)
			{
				printf("OK :: Initial byte allocated :: str[%ld]:\'%c\'\n",
					str_len-1, *(*str+str_len-1));
			}
		}
	}
	else
	{
		str_len = strlen(*str) + 1;		// +1 to include '\0' which 'strlen()' doesn't count.



		/* Providing feedback as per the mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: String is not empty :: str:\"%s\" :: str_len:%ld\n",
				*str, str_len);
		}
	}





	/* Allocating compulsory byte & pushing the character. */

	*str = realloc(*str, (size_t)(str_len+1));



	/* Making sure that memory is allocated. */

	if (*str==NULL) {perror("ERROR"); return;}
	else
	{
		str_len++;

		*(*str+str_len-2) = c;
		*(*str+str_len-1) = '\0';



		/* Feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER)
		{
			printf("OK: No problem expanding string coverage by 1 byte.\n");
		}
		else if (M==DEBUG)
		{
			printf("OK :: Pushed char \'%c\' :: str:\"%s\" :: str[%ld]:\'%c\' :: str[%ld]:\'%c\' :: len:%ld\n",
				c, *str, str_len-2, *(*str+str_len-2), str_len-1, *(*str+str_len-1), str_len);
		}
	}
}