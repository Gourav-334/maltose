/* Including guard to avoid multiple inclusions. */

#ifndef PATT_FSM0_H
	#define PATT_FSM0_H





/* Including required headers. */

#include "../../../data_structs/linked_list/ll_struct.h"










/* Declaring functions. */

void patt_fsm0(
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *subcateg_ptr, Ll_node *type_ptr,
	unsigned short int start, signed short int *state
);		// Handles state 0-9 of pattern FSM.










/* Closing the guard macro. */

#endif