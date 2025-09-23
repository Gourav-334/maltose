/* Including required headers. */

#include "../../../../include/lexer/x86/token_fsm/token_fsm0.h"










/* 1st part of command interpreter FSM. */

void token_fsm0(char *str, unsigned short int start, signed short int *state)
{
	switch(*state)
	{
		case 0:
			if (*(str+start)=='+' || *(str+start)=='-') {*state = 1;}
			else if (*(str+start)=='0') {*state = 2;}
			else if (*(str+start)=='1') {*state = 3;}
			else if (*(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7') {*state = 5;}
			else if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='a' || *(str+start)=='A' || *(str+start)=='b' || *(str+start)=='B' || *(str+start)=='c' || *(str+start)=='C' || *(str+start)=='d' || *(str+start)=='D' || *(str+start)=='e' || *(str+start)=='E' || *(str+start)=='f' || *(str+start)=='F') {*state = 12;}
			else {*state = 14;}

			break;


		case 1:
			if (*(str+start)=='0') {*state = 2;}
			else if (*(str+start)=='1') {*state = 3;}
			else if (*(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7') {*state = 5;}
			else if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='a' || *(str+start)=='A' || *(str+start)=='b' || *(str+start)=='B' || *(str+start)=='c' || *(str+start)=='C' || *(str+start)=='d' || *(str+start)=='D' || *(str+start)=='e' || *(str+start)=='E' || *(str+start)=='f' || *(str+start)=='F') {*state = 12;}
			else {*state = -3;}

			break;


		case 2:
			if (*(str+start)=='0' || *(str+start)=='1') {*state = 3;}
			else if (*(str+start)=='b' || *(str+start)=='B') {*state = 4;}
			else if (*(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7') {*state = 5;}
			else if (*(str+start)=='o' || *(str+start)=='O' || *(str+start)=='q' || *(str+start)=='Q') {*state = 6;}
			else if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else if (*(str+start)=='x' || *(str+start)=='X') {*state = 10;}
			else if (*(str+start)=='a' || *(str+start)=='A' || *(str+start)=='b' || *(str+start)=='B' || *(str+start)=='c' || *(str+start)=='C' || *(str+start)=='d' || *(str+start)=='D' || *(str+start)=='e' || *(str+start)=='E' || *(str+start)=='f' || *(str+start)=='F') {*state = 12;}
			else if (*(str+start)=='h' || *(str+start)=='H') {*state = 13;}
			else {*state = -3;}

			break;


		case 3:
			if (*(str+start)=='0' || *(str+start)=='1') {*state = 3;}
			else if (*(str+start)=='b' || *(str+start)=='B') {*state = 4;}
			else if (*(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7') {*state = 5;}
			else if (*(str+start)=='o' || *(str+start)=='O' || *(str+start)=='q' || *(str+start)=='Q') {*state = 6;}
			else if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else if (*(str+start)=='a' || *(str+start)=='A' || *(str+start)=='b' || *(str+start)=='B' || *(str+start)=='c' || *(str+start)=='C' || *(str+start)=='d' || *(str+start)=='D' || *(str+start)=='e' || *(str+start)=='E' || *(str+start)=='f' || *(str+start)=='F') {*state = 12;}
			else if (*(str+start)=='h' || *(str+start)=='H') {*state = 13;}
			else {*state = -3;}

			break;


		case 4:
			*state = -4;

			break;


		case 5:
			if (*(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7') {*state = 5;}
			else if (*(str+start)=='o' || *(str+start)=='O' || *(str+start)=='q' || *(str+start)=='Q') {*state = 6;}
			else if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else if (*(str+start)=='a' || *(str+start)=='A' || *(str+start)=='b' || *(str+start)=='B' || *(str+start)=='c' || *(str+start)=='C' || *(str+start)=='d' || *(str+start)=='D' || *(str+start)=='e' || *(str+start)=='E' || *(str+start)=='f' || *(str+start)=='F') {*state = 12;}
			else if (*(str+start)=='h' || *(str+start)=='H') {*state = 13;}
			else {*state = -5;}

			break;


		case 6:
			*state = -6;

			break;


		case 7:
			if (*(str+start)=='8' || *(str+start)=='9') {*state = 7;}
			else if (*(str+start)=='.') {*state = 8;}
			else if (*(str+start)=='a' || *(str+start)=='A' || *(str+start)=='b' || *(str+start)=='B' || *(str+start)=='c' || *(str+start)=='C' || *(str+start)=='d' || *(str+start)=='D' || *(str+start)=='e' || *(str+start)=='E' || *(str+start)=='f' || *(str+start)=='F') {*state = 12;}
			else if (*(str+start)=='h' || *(str+start)=='H') {*state = 13;}
			else {*state = -7;}

			break;


		case 8:
			if (*(str+start)=='0' || *(str+start)=='1' || *(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7' || *(str+start)=='8' || *(str+start)=='9') {*state = 9;}
			else {*state = -8;}

			break;


		case 9:
			if (*(str+start)=='0' || *(str+start)=='1' || *(str+start)=='2' || *(str+start)=='3' || *(str+start)=='4' || *(str+start)=='5' || *(str+start)=='6' || *(str+start)=='7' || *(str+start)=='8' || *(str+start)=='9') {*state = 9;}
			else {*state = -9;}

			break;
	}
}