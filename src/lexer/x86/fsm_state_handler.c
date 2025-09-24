/* Including required headers. */

#include "../../../include/lexer/x86/fsm_state_handler.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Command interpreter's FSM state handler. */

bool handle_token_fsm_state(signed short int *state, char *token, char *mode)
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
	else if (M==DEBUG) {printf("STAT :: state=%hd :: token=\"%s\"\n", *state, token);}





	/* Handling non-trap states. */

	if (*state>=0)
	{
		if (*state==0)
		{
			printf("ERROR: Token passed can't be empty!\n");
			func_ret = false;
		}



		else if (*state==1)
		{
			printf("ERROR: Sign without a value!\n");
			func_ret = false;
		}



		else if (*state>=2 && *state<=3)
		{
			printf("OK: Decimal value detected.\n");
			func_ret = false;
		}



		else if (*state==4)
		{
			printf("OK: Binary value detected.\n");
			func_ret = false;
		}


		else if (*state==5)
		{
			printf("OK: Decimal value detected.\n");
			func_ret = false;
		}



		else if (*state==6)
		{
			printf("OK: Octal value detected.\n");
			func_ret = false;
		}



		else if (*state==7)
		{
			printf("OK: Decimal value detected.\n");
			func_ret = false;
		}



		else if (*state==8)
		{
			printf("ERROR: Float without fraction part passed!\n");
			func_ret = false;
		}



		else if (*state==9)
		{
			printf("OK: Float value detected.\n");
			func_ret = false;
		}



		else if (*state==10)
		{
			printf("ERROR: Incomplete hex value!\n");
			func_ret = false;
		}



		else if (*state==11)
		{
			printf("OK: Hex value detected.\n");
			func_ret = false;
		}



		else if (*state==12)
		{
			printf("ERROR: Incomplete hex value!\n");
			func_ret = false;
		}



		else if (*state==13)
		{
			printf("OK: Hex value detected.\n");
			func_ret = false;
		}



		else if (*state==14)
		{
			printf("OK: An identifier detected.\n");
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
			case -3: printf("ERROR: Unwanted character in possibly binary value \"%s\"!\n", token); break;
			case -4: printf("ERROR: Unwanted character in possibly binary value \"%s\"!\n", token); break;
			case -5: printf("ERROR: Unwanted character in possibly octal value \"%s\"!\n", token); break;
			case -6: printf("ERROR: Unwanted character in possibly octal value \"%s\"!\n", token); break;
			case -7: printf("ERROR: Unwanted character in possibly decimal value \"%s\"!\n", token); break;
			case -8: printf("ERROR: Unwanted character in possibly float value \"%s\"!\n", token); break;
			case -9: printf("ERROR: Unwanted character in possibly float value \"%s\"!\n", token); break;
			case -10: printf("ERROR: Unwanted character in possibly hex value \"%s\"!\n", token); break;
			case -11: printf("ERROR: Unwanted character in possibly hex value \"%s\"!\n", token); break;
			case -13: printf("ERROR: Unwanted character in possibly hex value \"%s\"!\n", token); break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}