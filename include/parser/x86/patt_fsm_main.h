/* Including guard to avoid multiple inclusions. */

#ifndef PATT_FSM_MAIN_H
	#define PATT_FSM_MAIN_H





/* Including required functions. */

#include <stdbool.h>		// For returning boolean values.










/* Declaring functions. */

bool patt_fsm_main(
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr,		// Linked lists involving parameters.
	unsigned short int start, char *mode													// FSM-specific parameters.
);		// FSM handler, decides which part of FSM must be provided next symbol.










/* Closing the guard macros. */

#endif