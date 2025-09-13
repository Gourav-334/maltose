/* Including the corresponding header file. */

#include "../../../include/utility/ill_char_scan.h"










/* Scans for illegal characters in a given string. */

bool scan_ill_chars(char *str, long int len, char *ill_chars, char *mode)
{
	/* Variable declarations/definitions. */

	long int total_ill_chars = 0;
	char *trash = NULL;
	long int trash_len = 1;



	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;



	/* Keeping a default byte in 'trash'. */

	trash = malloc(1*sizeof(char));
	trash[trash_len-1] = '\0';



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

			if (str[i]!=ill_chars[j])
			{
				if (M==DEV) {continue;}
				else if (M==USER) {continue;}
				else if (M==DEBUG)
				{
					/* Writing transparent details about indices, characters, and match result. */

					printf("OK :: str[%ld]=%c : ill_chars[%ld]=%c :: Not illegal match.\n",
						i, str[i], j, ill_chars[j]);
				}
			}



			/* If character matching is found illegal. */

			else if (str[i]==ill_chars[j])
			{
				total_ill_chars++;


				if (M==DEV) {return true;}
				else if (M==USER)
				{
					/* Allocating an extra byte to add new illegar char. */

					trash = realloc(trash, (size_t)(trash_len+1));
					trash_len++;

					
					/* Detecting reallocation error (if any). */

					if (trash==NULL) {perror("ERROR"); return false;}
					else
					{
						trash[trash_len-2] = str[i];
						trash[trash_len-1] = '\0';
					}


					/* Not further scanning same character, moving to next. */

					break;
				}
				else if (M==DEBUG)
				{
					/* Writing transparent deatils about indices, characters, and match result. */

					printf("ERROR :: str[%ld]=%c : ill_chars[%ld]=%c :: Illegal match!\n",
						i, str[i], j, ill_chars[j]);
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
			printf("OK: No illegal character usage found.\n");
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
			printf("OK: No illegal character usage found.\n");
			return false;
		}
		else if (total_ill_chars>0)
		{
			printf("ERROR: Total %d illegal characters found in string \"%s\"!",
				total_ill_chars, str);
		}
	}



	/* Deallocating unwanted resources. */

	if(trash!=NULL) {free(trash);}
}