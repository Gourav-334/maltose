/* Including corresponding header for the source file. */

#include "../../../include/utils/str_ops/push_alloc.h"











/* Pushes a character to the end of the string, dynamically. */

void push_alloc(char *str, char c, char *mode)
{
	/* Variables declarations/definitions. */

	long int len = 0;





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





	/* Checking if the string is emtpy or not. */

	if (str==NULL)
	{
		/* Providing feedback as per the mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: Target string is either empty, or pointing to NULL.\n");
		}





		/* Allocating intial byte for the string. */

		str = malloc(1*sizeof(char));


		/* Making sure that memory is allocated. */

		if (str==NULL) {perror("ERROR"); return;}
		else
		{
			len = strlen(str);


			/* Providing feedback for successful allocation as per mode. */

			if (M==DEV) {}
			else if (M==USER)
			{
				printf("OK: No problem initiating byte for string.\n");
			}
			else if (M==DEBUG)
			{
				printf("OK :: str[%ld]:\'%c\'\n", len-1, str[len-1]);
			}
		}
	}





	/* Allocating compulsory byte & pushing the character. */

	str = realloc(str, (size_t)(len+1));



	/* Making sure that memory is allocated. */

	if (str==NULL) {perror("ERROR"); return;}


	/* Providing feedback for successful allocation as per mode. */

	else
	{
		len++;


		if (M==DEV) {}
		else if (M==USER)
		{
			printf("OK: No problem expanding string coverage by 1 byte.\n");
		}
		else if (M==DEBUG)
		{
			printf("OK :: str[%ld]:\'%c\' :: str[%ld]:\'%c\'\n",
				len-2, str[len-2], len-1, str[len-1]);
		}
	}
}