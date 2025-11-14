/* Including required headers. */

#include "../../../include/parser/patt_state_handler.h"
#include "../../../include/data_structs/linked_list/ll_struct.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Command interpreter's FSM state handler. */

bool handle_patt_fsm_state(signed short int *state, Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *subcateg_ptr, Ll_node *type_ptr, char *mode);
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
	else if (M==DEBUG) {printf("STAT :: state=%hd :: token=\"%s\"\n", *state, str);}





	/* Handling non-trap states. */

	if (*state>=0)
	{
		if (*state==0)
		{
			//

			func_ret = false;
		}



		else if (*state==1)
		{
			//

			func_ret = false;
		}



		else if (*state>=2 && *state<=3)
		{
			//

			func_ret = true;
		}



		else if (*state==4)
		{
			//

			func_ret = true;
		}


		else if (*state==5)
		{
			//

			func_ret = true;
		}



		else if (*state==6)
		{
			//

			func_ret = true;
		}



		else if (*state==7)
		{
			//

			func_ret = true;
		}



		else if (*state==8)
		{
			//

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
			case -1: break;
			case -2: break;
			case -3: break;
			case -4: break;
			case -5: break;
			case -7: break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}