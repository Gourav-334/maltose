/* Including required headers. */

#include "../../../include/cmd_interp/cmd_fsm/cmd_fsm1.h"










/* 1st part of command interpreter FSM. */

void cmd_fsm1(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 10:
			*state = -5;

			break;


		case 11:
			if (*(str+start)=='w' || *(str+start)=='W') {*state = 12;}
			else {*state = -6;}

			break;


		case 12:
			if (*(str+start)=='r' || *(str+start)=='R') {*state = 13;}
			else {*state = -6;}

			break;


		case 13:
			*state = -6;

			break;


		case 14:
			if (*(str+start)=='e' || *(str+start)=='E') {*state = 15;}
			else {*state = -7;}

			break;


		case 15:
			if (*(str+start)=='l' || *(str+start)=='L') {*state = 16;}
			else {*state = -7;}

			break;


		case 16:
			if (*(str+start)=='p' || *(str+start)=='P') {*state = 17;}
			else {*state = -7;}

			break;


		case 17:
			*state = -7;

			break;
	}
}