/* Including required headers. */

#include "../../../../include/common_store.h"
#include "../../../../include/lexer/x86/token_fsm/token_fsm1.h"










/* 2nd part of token interpreter FSM. */

void token_fsm1(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 10:
			if ((*(str+start)>='0' && *(str+start)<='9') || (*(str+start)>='a' && *(str+start)<='f') || (*(str+start)>='A' && *(str+start)<='F')) {*state = 11;}
			else {*state = -10; point_shift = str_len - i_token_fsm;}

			break;


		case 11:
			if ((*(str+start)>='0' && *(str+start)<='9') || (*(str+start)>='a' && *(str+start)<='f') || (*(str+start)>='A' && *(str+start)<='F')) {*state = 11;}
			else {*state = -11; point_shift = str_len - i_token_fsm;}

			break;


		case 12:
			if ((*(str+start)>='a' && *(str+start)<='z') || (*(str+start)>='A' && *(str+start)<='Z') || (*(str+start)>='0' && *(str+start)<='9') || *(str+start)=='_') {*state = 12;}

			break;


		case 13:
			// VACANT STATE

			break;


		case 14:
			// *state = -14;
			// point_shift = str_len - i_token_fsm;

			break;


		case 15:
			// VACANT STATE

			break;


		case 16:
			// VACANT STATE

			break;


		case 17:
			// VACANT STATE

			break;


		case 18:
			// VACANT STATE

			break;


		case 19:
			// VACANT STATE

			break;
	}
}