/* Including required headers. */

#include "../../../include/lexer/x86/code_cleanser.h"
#include "../../../include/lexer/x86/token_recog.h"
#include "../../../include/utils/str_verif/ill_char_scan.h"
#include "../../../include/utils/str_ops/push_alloc.h"
#include "../../../include/file_loader.h"

#include <stdio.h>			// For providing feedback as per chosen mode.
#include <stdlib.h>			// For dynamic memory manipulation on strings.
#include <string.h>			// For calculating length of string(s).










/* Cleans code & churns out tokens/lexemes from it. */

void cleanse_code(char *fstream, char *mode)
{
	/* Variable declarations/definitions. */

	char *deli = " (){}=\",[]+-*/<>@~?|!\0";
	char *termn = "\n\0";
	char *charstr = NULL;
	long int charstr_len;
	char *stack = NULL;



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

	if (scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
	{
		S = DELI;
		push_alloc(&stack, *charstr, "dev");
	}
	else if (scan_ill_chars(charstr, charstr_len, termn, "dev")==true)
	{
		S = TERMN;
		if (*charstr=='\n') {push_alloc(&stack, *charstr, "dev");}
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



		/* Taking decision as per the current reading state. */

		if (S==DELI)
		{
			/* Checking out if the state has actually changed for current character. */

			if (scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
			{
				push_alloc(&stack, *charstr, "dev");
			}
			else if (scan_ill_chars(charstr, charstr_len, termn, "dev")==true)
			{
				if (stack!=NULL)
				{
					token_recog(stack);
					free(stack); stack = NULL;

					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = TERMN;
					
					if (*charstr=='\t') {continue;}
					else if (*charstr=='\n') {push_alloc(&stack, *charstr, "dev");}
				}
			}
			else
			{
				if (stack!=NULL)
				{
					token_recog(stack);
					free(stack); stack = NULL;

					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = NDELI;
					push_alloc(&stack, *charstr, "dev");
				}
			}
		}
		else if (S==NDELI)
		{
			/* Checking out if the state has actually changed for current character. */

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
				}
			}
			else if (scan_ill_chars(charstr, charstr_len, termn, "dev")==true)
			{
				if (stack!=NULL)
				{
					token_recog(stack);
					free(stack); stack = NULL;

					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = TERMN;
					
					if (*charstr=='\t') {continue;}
					else if (*charstr=='\n') {push_alloc(&stack, *charstr, "dev");}
				}
			}
			else {push_alloc(&stack, *charstr, "dev");}
		}
		else if (S==TERMN)
		{
			/* Checking out if the state has actually changed for current character. */

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
				}
			}
			else if (scan_ill_chars(charstr, charstr_len, termn, "dev")==true)
			{
				if (*charstr=='\t') {continue;}
				else if (*charstr=='\n') {push_alloc(&stack, *charstr, "dev");}
			}
			else
			{
				if (stack!=NULL)
				{
					token_recog(stack);
					free(stack); stack = NULL;

					stack = malloc(1*sizeof(char));
					if (stack==NULL) {printf("ERROR: Problem allocating memory!\n"); return;}

					*stack = '\0';

					S = NDELI;
					push_alloc(&stack, *charstr, "dev");
				}
			}
		}
	}





	/* Pushing the last token from stack to FSM (recognizer). */

	if (stack!=NULL)
	{
		token_recog(stack);
		free(stack); stack = NULL;
	}
}