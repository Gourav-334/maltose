/* Including required headers. */

#include "../../../../include/lexer/x86/token_fsm/token_fsm1.h"










/* 2nd part of token interpreter FSM. */

void token_fsm1(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 10:
			if ((*(str+start)>='0' && *(str+start)<='9') || (*(str+start)>='a' && *(str+start)<='f') || (*(str+start)>='A' && *(str+start)<='F')) {*state = 11;}
			else {*state = -10;}

			break;


		case 11:
			if ((*(str+start)>='0' && *(str+start)<='9') || (*(str+start)>='a' && *(str+start)<='f') || (*(str+start)>='A' && *(str+start)<='F')) {*state = 11;}
			else {*state = -11;}

			break;


		case 12:
			if ((*(str+start)>='a' && *(str+start)<='z') || (*(str+start)>='A' && *(str+start)<='Z') || (*(str+start)>='0' && *(str+start)<='9') || *(str+start)=='_') {*state = 12;}

			break;


		case 13:
			// VACANT STATE

			break;


		case 14:
			*state = -14;

			break;


		case 15:
			if (*(str+start)=='\'') {*state = 17;}
			else if (*(str+start)=='\\') {*state = 18;}
			else {*state = 16;}

			break;


		case 16:
			if (*(str+start)=='\'') {*state = 17;}
			else {*state = -16;}

			break;


		case 17:
			*state = -17;

			break;


		case 18:
			if (*(str+start)=='n' || *(str+start)=='t' || *(str+start)=='b' || *(str+start)=='a' || *(str+start)=='r' || *(str+start)=='\\' || *(str+start)=='\'' || *(str+start)=='\"') {*state = 17;}
			else {*state = -18;}

			break;


		case 19:
			if (*(str+start)=='\"') {*state = 21;}
			else {*state = 20;}

			break;
	}
}