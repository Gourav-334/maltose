/* Including required headers. */

#include "../../../include/common_store.h"
#include "../../../include/parser/x86/parser_state_handler.h"
#include "../../../include/file_loader.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Parser FSM's state handler. */

bool handle_parser_fsm_state(signed short int *state, Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, char *mode)
{
	/* Variables declarations/definitions. */

	bool func_ret = true;





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










	/* Providing feedback as per mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG) {printf("STAT :: state=%hd :: &token=%p\n", *state, token_ptr);}





	/* Handling non-trap states. */

	if (*state>=0)
	{
		if (*state==0)
		{
			printf("%s\nERROR (Syntax) :: Line=%ld :: No section found in whole code!\n\n", src_filename, newlines);

			func_ret = false;
		}
	}





	/* Handling dump states. */

	else if (*state<0)
	{
		/* Confirmed error in passed string. */

		func_ret = false;



		/* Providing feedback as per state. */

		switch(*state)
		{
			case -1: printf("%s\nERROR (Syntax) :: Line=%ld :: Expected \'(\' after \'section\' but something else written!\n\n", src_filename, newlines); break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}