/* Including required headers. */

#include "../../../include/lexer/x86/token_fsm_main.h"
#include "../../../include/lexer/x86/token_fsm/token_fsm0.h"
#include "../../../include/lexer/x86/token_fsm/token_fsm1.h"
#include "../../../include/lexer/x86/token_fsm/token_fsm2.h"
#include "../../../include/lexer/x86/fsm_state_handler.h"

#include <stdio.h>			// Required for providing feedback to mode.
#include <string.h>			// Required to measure string length.










/* Central Finite State Machine handler. */

bool token_fsm_main(char *str, unsigned short int start, int point, int row, int column, char *mode)
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
			case 0: token_fsm0(str, i, &state); break;
			case 1: token_fsm1(str, i, &state); break;
			case 2: token_fsm2(str, i, &state); break;
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

	return handle_token_fsm_state(&state, str, point, row, column, "user");
}