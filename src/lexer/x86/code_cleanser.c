/* Including required headers. */

#include "../../../include/common_store.h"
#include "../../../include/data_structs/linked_list/ll_struct.h"
#include "../../../include/data_structs/linked_list/inserter.h"
#include "../../../include/lexer/x86/code_cleanser.h"
#include "../../../include/lexer/x86/token_recog.h"
#include "../../../include/lexer/x86/token_store.h"
#include "../../../include/manuals/audit_msng.h"
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

	char *charstr = NULL;
	char *stack = NULL;
	char *deli = " `~!@#$%^&*()-=+[{]}\\|;:\'\",<>/?\t\0";
	char termn = '\n';
	long int charstr_len = 1 + 1;



	/* Global variables re-declarations. */

	row = 1;
	column = 0;



	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;
	enum State{TERMN, DELI, NDELI} S;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return;
	}










	/* Making the character string & stack dynamically operable. */

	charstr = malloc(2*sizeof(char));
	if (charstr==NULL) {printf("ERROR: Problem allocating memory dynamically!\n");}

	*(charstr + (charstr_len-1)) = '\0';


	stack = malloc(1*sizeof(char));
	if (stack==NULL) {printf("ERROR: Problem allocating memory dynamically!\n");}

	*stack = '\0';










	/* Reading loop */

	for (point=0; point<file_size; point++)
	{
		/* Reading loop :: Syncing char & stream */

		*charstr = *(fstream + point);



		/* Reading loop :: Setting state for new char encounter */

		column++;

		if (*charstr==termn) {S = TERMN;}
		else if (scan_ill_chars(charstr, charstr_len, deli, "dev")) {S = DELI;}
		else {S = NDELI;}


		/* Reading loop :: Providing feedback */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
				__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
		}










		/* Reading loop :: Identifying char type */

		if (S==TERMN)		/* Reading loop :: Identifying char type :: Terminator mode */
		{
			row++; column=0;
			token_recog("\n");


			/* Reading loop :: Providing feedback */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG)
			{
				printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
					__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
			}
		}
		else if (S==DELI)		/* Reading loop :: Identifying char type :: Delimiter mode */
		{
			/* Reading loop :: Identifying char type :: Delimiter mode :: Special delimiter */

			if (*charstr==';' || *charstr=='\'' || *charstr=='\"')
			{
				switch (*charstr)
				{
					/* .. :: .. :: .. :: .. :: Comment line. */

					case ';':

						while (!(*charstr=='\n' || *charstr=='\0'))
						{
							column++; point++;
							*charstr = *(fstream + point);


							/* Reading loop :: Providing feedback */

							if (M==DEV) {}
							else if (M==USER) {}
							else if (M==DEBUG)
							{
								printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
									__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
							}
						}


						break;



					/*  .. :: .. :: .. :: .. :: Character encloser. */

					case '\'':
						
						do
						{
							column++; point++;
							*charstr = *(fstream + point);

							if (*charstr=='\n') {row++; column=0;}
							if (*charstr!='\'') {push_alloc(&stack, *charstr, "dev");}


							/* Reading loop :: Providing feedback */

							if (M==DEV) {}
							else if (M==USER) {}
							else if (M==DEBUG)
							{
								printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
									__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
							}
						}
						while (!(*charstr=='\'' || *charstr=='\0'));


						/*  .. :: .. :: .. :: .. :: .. :: Ensuring char enclosers presence */

						if (*charstr!='\'')
						{
							msg_audit_res(fstream, src_filename,
								point, row, column,
								"ERROR\0", "Lexical\0",
								"Character encloser opened but never closed!\0",
								"user"
							);
						}
						else
						{
							insert_node(&token, stack, true, "dev");
							insert_node(&categ, "literal", true, "dev");
							insert_node(&sub_categ, "ascii", true, "dev");
							insert_node(&type, "char", true, "dev");
						}


						break;



					/*  .. :: .. :: .. :: .. :: String encloser. */

					case '\"':
						
						do
						{
							column++; point++;
							*charstr = *(fstream + point);

							if (*charstr=='\n') {row++; column=0;}
							if (*charstr!='\"') {push_alloc(&stack, *charstr, "dev");}


							/* Reading loop :: Providing feedback */

							if (M==DEV) {}
							else if (M==USER) {}
							else if (M==DEBUG)
							{
								printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
									__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
							}
						}
						while (!(*charstr=='\"' || *charstr=='\0'));


						/*  .. :: .. :: .. :: .. :: .. :: Ensuring string enclosers presence */

						if (*charstr!='\"')
						{
							msg_audit_res(fstream, src_filename,
								point, row, column,
								"ERROR\0", "Lexical\0",
								"String encloser opened but never closed!\0",
								"user"
							);
						}
						else
						{
							insert_node(&token, stack, true, "dev");
							insert_node(&categ, "literal", true, "dev");
							insert_node(&sub_categ, "ascii", true, "dev");
							insert_node(&type, "string", true, "dev");
						}


						break;
				}



				/* For freshly reading new encounter, without risk of re-reading from second encloser again */

				if (!(*charstr=='\'' || *charstr=='\"')) {point--;}


				/* Freeing the stack with old data. */

				free(stack); stack = NULL;
				stack = malloc(1*sizeof(char));
				*stack = '\0';
			}



			/* Reading loop :: Identifying char type :: Delimiter mode :: Ordinary delimter */

			else
			{
				while (!(*charstr=='\n' || *charstr=='\0') && scan_ill_chars(charstr, charstr_len, deli, "dev")==true)
				{
					point++; column++;
					push_alloc(&stack, *charstr, "dev");

					*charstr = *(fstream + point);


					/* Reading loop :: Providing feedback */

					if (M==DEV) {}
					else if (M==USER) {}
					else if (M==DEBUG)
					{
						printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
							__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
					}
				} point--;



				column--;		// Returning back to last character of flow.



				while (!(token_recog(stack)==true || *stack=='\0'))
				{
					point--; column--;
					pop_dealloc(&stack, "dev");
				}



				/*  .. :: .. :: .. :: .. :: .. :: Ensuring token is valid */

				if (*stack=='\0' && *fstream!='\0')
				{
					msg_audit_res(fstream, src_filename,
						point, row, column,
						"ERROR\0", "Lexical\0",
						"Unknown character encountered!\0",
						"user"
					);

					point++;
				}


				free(stack); stack = NULL;
				stack = malloc(1*sizeof(char));
				*stack = '\0';
			}
		}
		else if (S==NDELI)		/* Reading loop :: Identifying char type :: Non-delimiter mode */
		{
			while (!(*charstr=='\n' || scan_ill_chars(charstr, charstr_len, deli, "dev")==true || *charstr=='\0'))
			{
				point++; column++;
				push_alloc(&stack, *charstr, "dev");

				*charstr = *(fstream + point);


				/* Reading loop :: Providing feedback */

				if (M==DEV) {}
				else if (M==USER) {}
				else if (M==DEBUG)
				{
					printf("STAT:%d :: %d:%d :: fstream[%d]=\'%c\' :: *charstr=\'%c\' :: stack=\"%s\" :: S=%d\n",
						__LINE__, row, column, point, *(fstream+point), *charstr, stack, S);
				}
			}


			column--;		// Returning back to last character of flow.


			token_recog(stack);

			free(stack); stack = NULL;
			stack = malloc(1*sizeof(char));
			*stack = '\0';


			/* Moving back by 1 to read flow-breaking character. */

			point--;
		}
	}
}