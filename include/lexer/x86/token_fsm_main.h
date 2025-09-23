/* Including guard to avoid multiple inclusions. */

#ifndef TOKEN_FSM_MAIN_H
	#define TOKEN_FSM_MAIN_H





/* Including required functions. */

#include <stdbool.h>		// For returning boolean values.










/* Declaring functions. */

bool token_fsm_main(char *str, unsigned short int start, char *mode);		// FSM handler, decides which part of FSM must be provided next symbol.










/* Closing the guard macros. */

#endif