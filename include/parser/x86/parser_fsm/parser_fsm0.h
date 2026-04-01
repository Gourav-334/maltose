/* Including guard to avoid multiple inclusions. */

#ifndef PARSER_FSM0_H
	#define PARSER_FSM0_H





/* Including required headers. */

#include "../../../data_structs/linked_list/ll_struct.h"










/* Declaring functions. */

void parser_fsm0(
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr,		// Linked lists involving parameters.
	unsigned short int start, signed short int *state										// FSM-specific parameters.
);		// Handles state 0-9 of pattern FSM.










/* Closing the guard macro. */

#endif