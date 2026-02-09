/* Including guard to avoid multiple inclusions. */

#ifndef PARSER_FSM_MAIN_H
	#define PARSER_FSM_MAIN_H





/* Including required functions. */

#include <stdbool.h>		// For returning boolean values.

#include "section_store.h"		// To import macros telling pointer locations.










/* Declaring functions. */

bool parser_fsm_main(
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr,
	uintptr_t *sec_ptr, long int sec_block_count, unsigned int start, char *mode);
	// Assembly point of parser FSM parts & state handler.










/* Closing the guard macros. */

#endif