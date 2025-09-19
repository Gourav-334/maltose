/* Including required headers. */

#include "../../../include/cmd_interp/cmd_fsm/cmd_fsm0.h"










/* 1st part of command interpreter FSM. */

void cmd_fsm0(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 0:
			if (*(str+start)=='d' || *(str+start)=='D') {*state = 1;}
			else if (*(str+start)=='l' || *(str+start)=='L') {*state = 5;}
			else if (*(str+start)=='m' || *(str+start)=='M') {*state = 8;}
			else if (*(str+start)=='n' || *(str+start)=='N') {*state = 11;}
			else if (*(str+start)=='h' || *(str+start)=='H') {*state = 14;}
			else {*state = -1;}

			break;


		case 1:
			if (*(str+start)=='e' || *(str+start)=='E') {*state = 2;}
			else {*state = -2;}

			break;


		case 2:
			if (*(str+start)=='b' || *(str+start)=='B') {*state = 3;}
			else if (*(str+start)=='v' || *(str+start)=='V') {*state = 4;}
			else {*state = -2;}

			break;


		case 3:
			*state = -2;

			break;


		case 4:
			*state = -3;

			break;


		case 5:
			if (*(str+start)=='o' || *(str+start)=='O') {*state = 6;}
			else {*state = -4;}

			break;


		case 6:
			if (*(str+start)=='g' || *(str+start)=='G') {*state = 7;}
			else {*state = -4;}

			break;


		case 7:
			*state = -4;

			break;


		case 8:
			if (*(str+start)=='o' || *(str+start)=='O') {*state = 9;}
			else {*state = -5;}

			break;


		case 9:
			if (*(str+start)=='d' || *(str+start)=='D') {*state = 10;}
			else {*state = -5;}

			break;
	}
}