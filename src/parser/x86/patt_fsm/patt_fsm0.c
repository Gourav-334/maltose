/* Including required headers. */

#include "../../../../include/common_store.h"
#include "../../../../include/parser/x86/patt_fsm/patt_fsm0.h"
#include "../../../../include/parser/x86/section_store.h"
#include "../../../../include/lexer/x86/token_store.h"

#include <stdio.h>			// For displaying feedbacks & errors on terminal.
#include <string.h>			// For comparing strings with each other.
#include <stdlib.h>			// For storing section addresses contagiously.










/* 1st part of pattern finding FSM. */

void patt_fsm0(Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, unsigned short int start, signed short int *state)
{
	/* Enumeration for knowing current section. */

	enum Section{SEC_TEXT, SEC_DATA, SEC_BSS, SEC_RODATA} Sec;





	/* Transition to next state. */

	switch(*state)
	{
		case 0:
			if (!strcmp(token_ptr->data,"\n") || !strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," "))
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				*state = 0;
			}
			else if (!strcmp(token_ptr->data,"section")) {*state = 1;}
			else {*state = -7;}

			break;





		case 1:
			if (!strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," ")) {*state = 1;}
			else if (!strcmp(token_ptr->data,"(")) {*state = 2;}
			else
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				*state = -1;
			}

			break;





		case 2:
			if (!strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," ")) {*state = 2;}
			else if (!strcmp(sub_categ_ptr->data,"section"))
			{
				/* Checking which section was requested. */

				if (!strcmp(token_ptr->data,".text")) {Sec = SEC_TEXT;}
				else if (!strcmp(token_ptr->data,".data")) {Sec = SEC_DATA;}
				else if (!strcmp(token_ptr->data,".bss")) {Sec = SEC_BSS;}
				else if (!strcmp(token_ptr->data,".rodata")) {Sec = SEC_RODATA;}

				*state = 3;
			}
			else
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				*state = -2;
			}

			break;





		case 3:
			if (!strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," ")) {*state = 3;}
			else if (!strcmp(token_ptr->data,")")) {*state = 4;}
			else
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				*state = -3;
			}

			break;





		case 4:
			if (!strcmp(token_ptr->data,"\n") || !strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," "))
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				*state = 4;
			}
			else if (!strcmp(token_ptr->data,"{"))
			{
				/* Increasing count of total opened curly braces. */

				active_braces++;



				/* Focusing on required pointer & counter. */

				switch (Sec)
				{
					case SEC_TEXT: sec_ptr = sec_text; sec_block_count = &sec_text_blocks; break;
					case SEC_DATA: sec_ptr = sec_data; sec_block_count = &sec_data_blocks; break;
					case SEC_BSS: sec_ptr = sec_bss; sec_block_count = &sec_bss_blocks; break;
					case SEC_RODATA: sec_ptr = sec_rodata; sec_block_count = &sec_rodata_blocks; break;
				}



				/* Reallocating & storing pointers to sections. */

				if (sec_ptr==NULL) {sec_ptr = calloc(2, sizeof(uintptr_t));}
				else {sec_ptr = realloc(sec_ptr, ((size_t)(*sec_block_count*TOTAL_OFFSETS))*sizeof(uintptr_t));}


				if (sec_ptr==NULL) {printf("ERROR: Couldn't expand memory for section addresses.\n"); *state = -6;}
				else
				{
					*(sec_ptr + (*sec_block_count*TOTAL_OFFSETS) + TOKEN_BEGIN_OFFSET) = (uintptr_t)token_ptr;
					*(sec_ptr + (*sec_block_count*TOTAL_OFFSETS) + CATEG_OFFSET) = (uintptr_t)categ_ptr;
					*(sec_ptr + (*sec_block_count*TOTAL_OFFSETS) + SUB_CATEG_OFFSET) = (uintptr_t)sub_categ_ptr;
					*(sec_ptr + (*sec_block_count*TOTAL_OFFSETS) + TYPE_OFFSET) = (uintptr_t)token_ptr;
					*sec_block_count += 1;

					*state = 5;
				}
			}
			else {*state = -4;}

			break;





		case 5:
			if (!strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," ")) {*state = 5;}
			else if (!strcmp(token_ptr->data,"\n")) {newlines++; *state = 6;}
			else {*state = -5;}

			break;





		case 6:
			if (!strcmp(token_ptr->data,"}"))
			{
				/* Judging whether closed braces is for section or sub-routine. */

				switch (active_braces)
				{
					case 1:
						*(sec_ptr + (*sec_block_count*TOTAL_OFFSETS) + TOKEN_END_OFFSET) = (uintptr_t)token_ptr;
						*state = 7;

						break;
				}



				/* Deacreasing count of total opened curly braces. */

				active_braces--;
			}
			else
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				else if (!strcmp(token_ptr->data,"{")) {active_braces++;}
				*state = 6;
			}

			break;





		case 7:
			if (!strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data," ")) {*state = 7;}
			else if (!strcmp(token_ptr->data,"\n")) {newlines++; *state = 8;}
			else {*state = -7;}

			break;





		case 8:
			if (!strcmp(token_ptr->data,"\t") || !strcmp(token_ptr->data,"\n") || !strcmp(token_ptr->data," "))
			{
				if (!strcmp(token_ptr->data,"\n")) {newlines++;}
				*state = 8;
			}
			else if (!strcmp(token_ptr->data,"section")) {*state = 1;}
			else {*state = -7;}

			break;
	}
}