/* Guards to avoid multiple inclusions. */

#ifndef PARSER_STATE_HANDLER_H
	#define PARSER_STATE_HANDLER_H





/* Including required headers. */

#include "../../../include/data_structs/linked_list/ll_struct.h"

#include <stdbool.h>		// For returning boolean value as per execution.










/* Functions declaration. */

bool handle_parser_fsm_state(
	signed short int *state,
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr,
	char *mode
);		// Decides what to do with final state of FSM.










/* Closing guard macros. */

#endif