/* Including required headers. */

#include "../../../include/common_store.h"
#include "../../../include/parser/x86/patt_state_handler.h"
#include "../../../include/file_loader.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Command interpreter's FSM state handler. */

bool handle_patt_fsm_state(signed short int *state, Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *sub_categ_ptr, Ll_node *type_ptr, char *mode)
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
			printf("%s\nERROR (Semantic) :: Line=%ld :: No section found in whole code!\n\n", src_filename, newlines);

			func_ret = false;
		}



		else if (*state==1)
		{
			printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \'(\' after \'section\' but missing!\n\n", src_filename, newlines);

			func_ret = false;
		}



		else if (*state==2)
		{
			printf("%s\nERROR (Semantic) :: Line=%ld :: Expected section name after \'(\' but missing!\n\n", src_filename, newlines);

			func_ret = false;
		}



		else if (*state==3)
		{
			printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \')\' name after section name but missing!\n\n", src_filename, newlines);

			func_ret = false;
		}



		else if (*state==4)
		{
			printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \'{\' after \')\' but missing!\n\n", src_filename, newlines);

			func_ret = false;
		}


		else if (*state==5)
		{
			printf("%s\nERROR (Semantic) :: Line=%ld :: Expected change of line after \'{\' but missing!\n\n", src_filename, newlines);

			func_ret = false;
		}



		else if (*state==6)
		{
			printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \'}\' after section code but missing!\n\n", src_filename, newlines);

			func_ret = false;
		}



		else if (*state==7) {func_ret = true;}



		else if (*state==8) {func_ret = true;}
	}





	/* Handling dump states. */

	else if (*state<0)
	{
		/* Confirmed error in passed string. */

		func_ret = false;



		/* Providing feedback as per state. */

		switch(*state)
		{
			case -1: printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \'(\' after \'section\' but something else written!\n\n", src_filename, newlines); break;
			case -2: printf("%s\nERROR (Semantic) :: Line=%ld :: Expected section name after \'(\' but something else written!\n\n", src_filename, newlines); break;
			case -3: printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \')\' name after section name but something else written!\n\n", src_filename, newlines); break;
			case -4: printf("%s\nERROR (Semantic) :: Line=%ld :: Expected \'{\' after \')\' but something else written!\n\n", src_filename, newlines); break;
			case -5: printf("%s\nERROR (Semantic) :: Line=%ld :: Expected change of line after \'{\' but something else written!\n\n", src_filename, newlines); break;
			case -6: printf("%s\nERROR (Semantic) :: Line=%ld :: Couldn't expand memory for section addresses!\n\n", src_filename, newlines); break;
			case -7: printf("%s\nERROR (Semantic) :: Line=%ld :: Code written outside sections!\n\n", src_filename, newlines); break;
			case -8: printf("%s\nERROR (Semantic) :: Line=%ld :: Code written outside sections!\n\n", src_filename, newlines); break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}