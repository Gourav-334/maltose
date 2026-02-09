/* Including required headers. */

#include "../../../include/data_structs/linked_list/ll_struct.h"
#include "../../../include/parser/x86/parser_fsm_main.h"
#include "../../../include/parser/x86/parser_fsm/parser_fsm0.h"
#include "../../../include/parser/x86/parser_state_handler.h"
#include "../../../include/parser/x86/section_store.h"
#include "../../../include/lexer/x86/token_store.h"

#include <stdio.h>			// Required for providing feedback to mode.
#include <string.h>			// Required for measuring length of string.










/* Central Finite State Machine handler. */

bool parser_fsm_main(Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, uintptr_t *sec_ptr, long int sec_block_count, unsigned int start, char *mode)
{
	/* Variable declarations/definitions. */

	signed int state = 0;
	uintptr_t *sec_ptr_end = *(sec_ptr + TOKEN_END_OFFSET);
	long int count = 1;





	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return false;
	}





	/* Primary state transition loop. */

	for (int i=start; sec_ptr!=sec_ptr_end && count!=sec_block_count; i++)
	{
		/* Giving feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: start=%d : sec_ptr=%p : state=%hd : symbol=%s\n",
				start, sec_ptr, state, token_ptr->data);
		}





		/* Switch cases to decide which part handles symbol. */

		switch(state/10)
		{
			case 0: parser_fsm0(sec_ptr, sec_block_count, start, &state); break; // START FROM HERE //
		}





		/* Moving to next token. */

		token_ptr = token_ptr -> next;
		categ_ptr = categ_ptr -> next;
		sub_categ_ptr = sub_categ_ptr -> next;
		type_ptr = type_ptr -> next;
	}





	/* Giving feedback as per chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG)
	{
		printf("STAT :: Final state :: start=%d : token=%p : state=%hd\n",
			start, sec_ptr, state);
	}





	/* Calling state handler to provide feedback. */

	return handle_parser_fsm_state(&state, sec_ptr, sec_block_count, "dev");
}