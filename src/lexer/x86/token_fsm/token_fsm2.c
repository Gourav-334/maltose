/* Including required headers. */

#include "../../../../include/lexer/x86/token_fsm/token_fsm2.h"










/* 3rd part of token interpreter FSM. */

void token_fsm2(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 20:
			if (*(str+start)=='\"') {*state = 21;}
			else {*state = 20;}

			break;


		case 21:
			*state = -21;

			break;
	}
}