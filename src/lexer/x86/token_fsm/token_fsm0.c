/* Including required headers. */

#include "../../../../include/common_store.h"
#include "../../../../include/lexer/x86/token_fsm/token_fsm0.h"










/* 1st part of token interpreter FSM. */

void token_fsm0(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 0:
			if (*(str+start)=='+' || *(str+start)=='-') {*state = 1;}
			else if (*(str+start)=='0') {*state = 2;}
			else if (*(str+start)=='1') {*state = 3;}
			else if (*(str+start)>='2' && *(str+start)<='7') {*state = 5;}
			else if (*(str+start)>='8' && *(str+start)<='9') {*state = 7;}
			else if (*(str+start)=='\'') {*state = 15;}
			else if (*(str+start)=='\"') {*state = 19;}
			else if ((*(str+start)>='a' && *(str+start)<='z') || (*(str+start)>='A' && *(str+start)<='Z') || *(str+start)=='_') {*state = 12;}
			else {*state = 14;}

			break;


		case 1:
			if (*(str+start)=='0') {*state = 2;}
			else if (*(str+start)=='1') {*state = 3;}
			else if (*(str+start)>='2' && *(str+start)<='7') {*state = 5;}
			else if (*(str+start)>='8' && *(str+start)<='9') {*state = 7;}
			else {*state = -3; point_shift = str_len - i_token_fsm;}

			break;


		case 2:
			if (*(str+start)=='0' || *(str+start)=='1') {*state = 3;}
			else if (*(str+start)=='b' || *(str+start)=='B') {*state = 4;}
			else if (*(str+start)>='2' && *(str+start)<='7') {*state = 5;}
			else if (*(str+start)=='o' || *(str+start)=='O' || *(str+start)=='q' || *(str+start)=='Q') {*state = 6;}
			else if (*(str+start)>='8' && *(str+start)<='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else if (*(str+start)=='x' || *(str+start)=='X') {*state = 10;}
			else {*state = -3; point_shift = str_len - i_token_fsm;}

			break;


		case 3:
			if (*(str+start)=='0' || *(str+start)=='1') {*state = 3;}
			else if (*(str+start)=='b' || *(str+start)=='B') {*state = 4;}
			else if (*(str+start)>='2' && *(str+start)<='7') {*state = 5;}
			else if (*(str+start)=='o' || *(str+start)=='O' || *(str+start)=='q' || *(str+start)=='Q') {*state = 6;}
			else if (*(str+start)>='8' && *(str+start)<='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else {*state = -3; point_shift = str_len - i_token_fsm;}

			break;


		case 4:
			*state = -4;
			point_shift = str_len - i_token_fsm;

			break;


		case 5:
			if (*(str+start)>='0' && *(str+start)<='7') {*state = 5;}
			else if (*(str+start)=='o' || *(str+start)=='O' || *(str+start)=='q' || *(str+start)=='Q') {*state = 6;}
			else if (*(str+start)>='8' && *(str+start)<='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else {*state = -5; point_shift = str_len - i_token_fsm;}

			break;


		case 6:
			*state = -6;
			point_shift = str_len - i_token_fsm;

			break;


		case 7:
			if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else {*state = -7; point_shift = str_len - i_token_fsm;}

			break;


		case 8:
			if (*(str+start)>='0' && *(str+start)<='9') {*state = 9;}
			else {*state = -8; point_shift = str_len - i_token_fsm;}

			break;


		case 9:
			if (*(str+start)>='0' && *(str+start)<='9') {*state = 9;}
			else {*state = -9; point_shift = str_len - i_token_fsm;}

			break;
	}
}