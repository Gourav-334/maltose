/* Including required headers. */

#include "../../../../include/common_store.h"
#include "../../../../include/parser/x86/patt_fsm/patt_fsm0.h"
#include "../../../../include/parser/x86/section_store.h"

#include <string.h>			// For comparing strings with each other.
#include <stdlib.h>			// For storing section addresses contagiously.










/* 1st part of pattern finding FSM. */

void patt_fsm0(Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 0:
			if (!strcmp(token->data,"\n") || !strcmp(token->data,"\t"))
			{
				if (!strcmp(token->data,"\n")) {newlines++;}
				*state = 0;
			}
			else if (!strcmp(token->data,"section")) {*state = 1;}
			else {*state = -7;}

			break;





		case 1:
			if (!strcmp(token->data,"\t")) {*state = 1;}
			else if (!strcmp(token->data,"(")) {*state = 2;}
			else {*state = -1;}

			break;





		case 2:
			if (!strcmp(token->data,"\t")) {*state = 2;}
			else if (!strcmp(sub_categ->data,"section"))
			{
				/* Checking which section was requested. */

				if (!strcmp(token->data,".text")) {SEC = SEC_TEXT;}
				else if (!strcmp(token->data,".data")) {SEC = SEC_DATA;}
				else if (!strcmp(token->data,".bss")) {SEC = SEC_BSS;}
				else if (!strcmp(token->data,".rodata")) {SEC = SEC_RODATA;}

				*state = 3;
			}
			else {*state = -2;}

			break;





		case 3:
			if (!strcmp(token->data,"\t")) {*state = 3;}
			else if (!strcmp(token->data,")")) {*state = 4;}
			else {*state = -3;}

			break;





		case 4:
			if (!strcmp(token->data,"\n") || !strcmp(token->data,"\t"))
			{
				if (!strcmp(token->data,"\n")) {newlines++;}
				*state = 4;
			}
			else if (!strcmp(token->data,"{"))
			{
				/* Focusing on required pointer & counter. */

				switch (SEC)
				{
					case SEC_TEXT: sec_ptr = sec_text; sec_block_count = &sec_text_blocks; break;
					case SEC_DATA: sec_ptr = sec_data; sec_block_count = &sec_data_blocks; break;
					case SEC_BSS: sec_ptr = sec_bss; sec_block_count = &sec_bss_blocks; break;
					case SEC_RODATA: sec_ptr = sec_rodata; sec_block_count = &sec_rodata_blocks; break;
				}



				/* Reallocating & storing pointers to sections. */

				if (sec_ptr==NULL) {sec_ptr = calloc(2, sizeof(uintptr_t));}
				else {sec_ptr = realloc(sec_ptr, (((size_t)(*sec_block_count))+2)*sizeof(uintptr_t));}


				if (sec_ptr==NULL) {printf("ERROR: Couldn't expand memory for section addresses.\n"); *state = -6;}
				else
				{
					*sec_block_count += 2;
					*(sec_ptr + sec_block_count - 2) = token_ptr;

					*state = 5;
				}
			}
			else {*state = -4;}

			break;





		case 5:
			if (!strcmp(token->data,"\t")) {*state = 5;}
			else if (!strcmp(token->data,"\n")) {newlines++; *state = 6;}
			else {*state = -5;}

			break;





		case 6:
			if (!strcmp(token->data,"}"))
			{
				*(sec_ptr + sec_block_count - 1) = token_ptr;
				*state = 7;
			}
			else {*state = 6;}

			break;





		case 7:
			if (!strcmp(token->data,"\t")) {*state = 7;}
			else if (!strcmp(token->data,"\n")) {newlines++; *state = 8;}
			else {*state = -7;}

			break;





		case 8:
			if (!strcmp(token->data,"\t") || !strcmp(token->data,"\n"))
			{
				if (!strcmp(token->data,"\n")) {newlines++;}
				*state = 8;
			}
			else if (!strcmp(token->data,"section")) {*state = 1;}
			else {*state = -7;}

			break;
	}
}