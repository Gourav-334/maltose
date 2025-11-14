/* Including required headers. */

#include "../../../../include/parser/x86/patt_fsm/patt_fsm0.h"
#include "../../../../include/parser/x86/section_store.h"

#include <string.h>			// For comparing strings with each other.










/* 1st part of pattern finding FSM. */

void patt_fsm0(Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *subcateg_ptr, Ll_node *type_ptr, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 0:
			if (!strcmp(token->data,"\n") || !strcmp(token->data,"\t")) {*state = 0;}
			else if (!strcmp(subcateg->data,"section")) {*state = 1;}
			else {*state = -7;}

			break;


		case 1:
			if (!strcmp(token->data,"\t")) {*state = 1;}
			else if (!strcmp(token->data,"(")) {*state = 2;}
			else {*state = -1;}

			break;


		case 2:
			if (!strcmp(token->data,"\t")) {*state = 2;}
			else if (!strcmp(subcateg->data,"section")) {*state = 3;}
			else {*state = -2;}

			break;


		case 3:
			if (!strcmp(token->data,"\t")) {*state = 3;}
			else if (!strcmp(token->data,")")) {*state = 4;}
			else {*state = -3;}

			break;


		case 4:
			if (!strcmp(token->data,"\n") || !strcmp(token->data,"\t")) {*state = 4;}
			else if (!strcmp(token->data,"{")) {*state = 5;}
			else {*state = -4;}

			break;


		case 5:
			if (!strcmp(token->data,"\t") || !strcmp(token->data,"\t")) {*state = 5;}
			else if (!strcmp(token->data,"\n")) {*state = 6;}
			else {*state = -5;}

			break;


		case 6:
			if (!strcmp(token->data,"}")) {*state = 7;}
			else {*state = 6;}

			break;


		case 7:
			if (!strcmp(token->data,"\t")) {*state = 7;}
			else if (!strcmp(token->data,"\n")) {*state = 8;}
			else {*state = -7;}

			break;


		case 8:
			if (!strcmp(token->data,"\t") || !strcmp(token->data,"\n")) {*state = 8;}
			else if (!strcmp(token->data,"section")) {*state = 1;}
			else {*state = -7;}

			break;
	}
}