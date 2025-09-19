/* Including guard to avoid multiple inclusions. */

#ifndef CMD_FSM_MAIN_H
	#define CMD_FSM_MAIN_H





/* Including required functions. */

#include <stdbool.h>		// For returning boolean values.










/* Declaring functions. */

bool cmd_fsm_main(char *str, unsigned short int start, char *mode);		// FSM handler, decides which part of assembler must be provided next symbol.










/* Closing the guard macros. */

#endif