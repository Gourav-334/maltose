/* Including required headers. */

#include "../../../../include/common_store.h"
#include "../../../../include/parser/x86/parser_fsm/parser_fsm0.h"
#include "../../../../include/parser/x86/section_store.h"
#include "../../../../include/lexer/x86/token_store.h"

#include <stdio.h>			// For displaying feedbacks & errors on terminal.
#include <string.h>			// For comparing strings with each other.
#include <stdlib.h>			// For storing section addresses contagiously.










/* 1st part of parser FSM. */

void parser_fsm0(Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, unsigned short int start, signed short int *state)
{
	/* Transition to next state. */

	switch(*state)
	{
		case 0: break;
	}
}