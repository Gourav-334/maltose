/* Including required headers. */

#include "../../../include/data_structs/linked_list/ll_struct.h"
#include "../../../include/parser/x86/patt_fsm_main.h"
#include "../../../include/parser/x86/patt_fsm/patt_fsm0.h"
#include "../../../include/parser/x86/patt_state_handler.h"
#include "../../../include/lexer/x86/token_store.h"

#include <stdio.h>			// Required for providing feedback to mode.










/* Central Finite State Machine handler. */

bool patt_fsm_main(Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, unsigned short int start, char *mode)
{
	/* Variable declarations/definitions. */

	Ll_node *token_ptr = token -> head;
	Ll_node *categ_ptr = categ -> head;
	Ll_node *sub_categ_ptr = sub_categ -> head;
	Ll_node *type_ptr = type -> head;


	signed short int state = 0;





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

	for (int i=start; i<token->total; i++)
	{
		/* Giving feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: start=%d : token->total=%d : i_token_fsm=%hu : state=%hd : symbol=%c\n",
				start, token->total, i_token_fsm, state, *(str+i_token_fsm));
		}





		/* Switch cases to decide which part handles symbol. */

		switch(state/10)
		{
			case 0: patt_fsm0(token_ptr, categ_ptr, sub_categ_ptr, type_ptr, i_token_fsm, &state); break;
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
		printf("STAT :: Final state :: start=%d : token->total=%d : state=%hd\n",
			start, token->total, state);
	}





	/* Calling state handler to provide feedback. */

	return handle_patt_fsm_state(&state, token_ptr, categ_ptr, sub_categ_ptr, type_ptr, "user");
}