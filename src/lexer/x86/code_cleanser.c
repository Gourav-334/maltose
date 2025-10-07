/* Including required headers. */

#include "../../../include/lexer/x86/code_cleanser.h"
#include "../../../include/lexer/x86/token_recog.h"
#include "../../../include/utils/str_verif/ill_char_scan.h"
#include "../../../include/utils/str_ops/push_alloc.h"
#include "../../../include/utils/str_ops/pop_dealloc.h"
#include "../../../include/file_loader.h"

#include <stdio.h>			// For providing feedback as per chosen mode.
#include <stdlib.h>			// For dynamic memory manipulation on strings.
#include <string.h>			// For calculating length of string(s).










/* Cleans code & churns out tokens/lexemes from it. */

void cleanse_code(char *fstream, char *mode)
{
	/* Variable declarations/definitions. */

	char *deli = " \t(){}=\",[]+-*/<>@~?|!\0";
	char termn = '\n';
	char *charstr = NULL;
	long int charstr_len;
	char *stack = NULL;
	int row=1, col=0;
	bool byte_pop = false;



	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;
	enum State{DELI, NDELI, TERMN} S;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return;
	}










	/* Setting 'stack' string to function dynamically. */

	stack = malloc(1*sizeof(char));
	if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

	*stack = '\0';





	/* Making character string dynamically enabled. */

	charstr = malloc(2*sizeof(char));

	*charstr = *fstream;
	*(charstr+1) = '\0';

	charstr_len = strlen(charstr);





	/* Checking the first character of the filestream. */

	col++;

	if (scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
	{
		S = DELI;
		push_alloc(&stack, *charstr, "dev");
	}
	else if (*charstr==termn)
	{
		S = TERMN;
		token_recog("\n");
	}
	else
	{
		S = NDELI;
		push_alloc(&stack, *charstr, "dev");
	}



	






	/* Reading the filestream byte-by-byte. */

	for (int i=1; i<file_size; i++)
	{
		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: S=%d :: stack=\"%s\"\n",
				i-1, *(fstream+i-1), *charstr, S, stack);
		}





		/* Setting the character string as the current character in iteration. */

		*charstr = *(fstream+i);










		/* If a delimiter was being read. */

		if (S==DELI)
		{
			/* (Delimiter was being read) + (Delimter is encountered) */

			if (scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
			{
				push_alloc(&stack, *charstr, "dev");
				col++;
			}





			/* (Delimiter was being read) + (Terminator is encountered) */

			else if (*charstr==termn)
			{
				/* Proceeding only if stack contains something (not empty). */

				if (stack!=NULL)
				{
					/* Checking that if the delimiter susbests might be valid. */

					while (token_recog(stack)!=true && *stack!='\0')	////////////////// LOOP LOGIC ISSUE/////////////////
					{
						byte_pop = true;

						pop_dealloc(&stack, "debug");
						col--; i--;
					}
					free(stack); stack = NULL;



					/* Recentering scanning to correct position (if changed). */

					if (byte_pop==false)
					{
						S = TERMN;
						token_recog("\n");

						row++; col=0;
					}
					else if (byte_pop==true)
					{
						byte_pop = false;
						col--; i--;

						continue;
					}
				}
			}





			/* (Delimiter was being read) + (Non-delimter is encountered) */

			else
			{
				/* Proceeding only if stack contains something (not empty). */

				if (stack!=NULL)
				{
					/* Checking that if the delimiter susbests might be valid. */

					while (token_recog(stack)!=true && *stack!='\0')	////////////////// LOOP LOGIC ISSUE/////////////////
					{
						byte_pop = true;

						pop_dealloc(&stack, "debug");
						col--; i--;
					}
					free(stack); stack = NULL;



					/* Recentering scanning to correct position (if changed). */

					if (byte_pop==false)
					{
						stack = malloc(1*sizeof(char));
						if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

						*stack = '\0';

						S = NDELI;
						push_alloc(&stack, *charstr, "dev");
						col++;
					}
					else if (byte_pop==true)
					{
						byte_pop = false;
						col--; i--;

						continue;
					}
				}
			}
		}










		/* Else if a non-delimeter was being read. */

		else if (S==NDELI)
		{
			/* (Non-delimiter was being read) + (Delimter is encountered) */

			if (scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
			{
				if (stack!=NULL)
				{
					token_recog(stack);
					free(stack); stack = NULL;

					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = DELI;
					push_alloc(&stack, *charstr, "dev");
					col++;
				}
			}





			/* (Non-delimiter was being read) + (Terminator is encountered) */

			else if (*charstr==termn)
			{
				if (stack!=NULL)
				{
					token_recog(stack);
					free(stack); stack = NULL;


					S = TERMN;
					token_recog("\n");
					row++; col=0;
				}
			}





			/* (Non-delimiter was being read) + (Non-delimeter is encountered) */

			else {push_alloc(&stack, *charstr, "dev"); col++;}
		}










		/* Else if a terminator was being read. */

		else if (S==TERMN)
		{
			/* (Terminator was being read) + (Delimter is encountered) */

			if (scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
			{
				if (stack!=NULL)
				{
					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = DELI;
					push_alloc(&stack, *charstr, "dev");
					col++;
				}
			}





			/* (Terminator was being read) + (Terminator is encountered) */

			else if (*charstr==termn)
			{
				token_recog("\n");
				row++;
			}





			/* (Terminator was being read) + (Non-delimter is encountered) */

			else
			{
				if (stack!=NULL)
				{
					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = NDELI;
					push_alloc(&stack, *charstr, "dev");
					col++;
				}
			}
		}










		/* Final iteration's token verification & reversing iteration for unmatching. */

		if ((i==file_size-1) && (stack!=NULL))
		{
			/* If final state was delimiter. */

			if (S==DELI)
			{
				/* Checking that if the delimiter susbests might be valid. */

				while (token_recog(stack)!=true && *stack!='\0')	////////////////// LOOP LOGIC ISSUE/////////////////
				{
					byte_pop = true;

					pop_dealloc(&stack, "debug");
					col--; i--;
				}
				free(stack); stack = NULL;



				/* Recentering scanning to correct position (if changed). */

				if (byte_pop==false)
				{
					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = NDELI;
					push_alloc(&stack, *charstr, "dev");
					col++;
				}
				else if (byte_pop==true)
				{
					byte_pop = false;
					col--; i--;

					continue;
				}
			}





			/* Else if final state is non-delimeter. */

			else if (S==NDELI)
			{
				token_recog(stack);
				free(stack); stack = NULL;
			}
		}
	}
}