/* Including required headers. */

#include "../../../include/common_store.h"
#include "../../../include/lexer/x86/token_fsm_main.h"
#include "../../../include/lexer/x86/token_fsm/token_fsm0.h"
#include "../../../include/lexer/x86/token_fsm/token_fsm1.h"
#include "../../../include/lexer/x86/token_fsm/token_fsm2.h"
#include "../../../include/lexer/x86/fsm_state_handler.h"

#include <stdio.h>			// Required for providing feedback to mode.
#include <string.h>			// Required to measure string length.










/* Central Finite State Machine handler. */

bool token_fsm_main(char *str, unsigned short int start, char *mode)
{
	/* Variable declarations/definitions. */

	str_len = strlen(str);
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

	i_token_fsm = 0;

	for (i_token_fsm=start; i_token_fsm<str_len; i_token_fsm++)
	{
		/* Giving feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: start=%d : str_len=%ld : i_token_fsm=%hu : state=%hd : symbol=%c\n",
				start, str_len, i_token_fsm, state, *(str+i_token_fsm));
		}





		/* Shifting point's value for error states. */

		//if ((*state==) || && point_shift==0)





		/* Switch cases to decide which part handles symbol. */

		switch(state/10)
		{
			case 0: token_fsm0(str, i_token_fsm, &state); break;
			case 1: token_fsm1(str, i_token_fsm, &state); break;
			case 2: token_fsm2(str, i_token_fsm, &state); break;
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

	point -= point_shift;

	return handle_token_fsm_state(&state, str, "user");
}