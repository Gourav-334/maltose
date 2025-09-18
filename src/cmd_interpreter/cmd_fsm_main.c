/* Including required headers. */

#include "../../include/cmd_interpreter/cmd_fsm_main.h"
#include "../../include/cmd_interpreter/cmd_fsm/cmd_fsm0.h"
#include "../../include/cmd_interpreter/cmd_fsm/cmd_fsm1.h"
#include "../../include/cmd_interpreter/fsm_state_handler.h"

#include <stdio.h>			// Required for providing feedback to mode.
#include <string.h>			// Required to measure string length.










/* Central Finite State Machine handler. */

bool cmd_fsm_main(char *str, unsigned short int start, char *mode)
{
	/* Variable declarations/definitions. */

	long int str_len = strlen(str);
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

	for (unsigned short int i=start; i<str_len; i++)
	{
		/* Giving feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: start=%d : str_len=%ld : i=%hu : state=%hd : symbol=%c\n",
				start, str_len, i, state, *(str+i));
		}



		/* Switch cases to decide which part handles symbol. */

		switch(state/10)
		{
			case 0: cmd_fsm0(str, i, &state); break;
			case 1: cmd_fsm1(str, i, &state); break;
		}
	}





	/* Giving feedback as per chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG)
	{
		printf("STAT :: Final state :: start=%d : str_len=%ld : state=%hd\n",
			start, str_len, state);
	}





	/* Calling state handler to provide feedback. */

	return handle_fsm_state(&state, str, "user");
}