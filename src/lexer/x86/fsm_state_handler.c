/* Including required headers. */

#include "../../include/lexer/x86/fsm_state_handler.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Command interpreter's FSM state handler. */

bool handle_token_fsm_state(signed short int *state, char *flag, char *mode)
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
	else if (M==DEBUG) {printf("STAT :: state=%hd :: flag=\"%s\"\n", *state, flag);}





	/* Handling non-trap states. */

	if (*state>=0)
	{
		if (*state==0)
		{
			printf("ERROR: Flag passed can't be empty!\n");
			func_ret = false;
		}



		else if (*state>=1 && *state<=2)
		{
			printf("ERROR: No flag named \'%s\' exists! Did you meant \"deb\" or \"dev\"?\n", flag);
			func_ret = false;
		}



		else if (*state==3)
		{
			if (flag_deb.status==false) {flag_deb.status = true; printf("OK: Flag \"deb\" is now active.\n");}
			else if (flag_deb.status==true) {printf("ERROR: Flag \"deb\" passed multiple times!\n"); func_ret = false;}
		}



		else if (*state==4)
		{
			if (flag_dev.status==false) {flag_dev.status = true; printf("OK: Flag \"dev\" is now active.\n");}
			else if (flag_dev.status==true) {printf("ERROR: Flag \"dev\" passed multiple times!\n"); func_ret = false;}
		}



		else if (*state>=5 && *state<=6)
		{
			printf("ERROR: No flag named \'%s\' exists! Did you meant \"log\"?\n", flag);
			func_ret = false;
		}



		else if (*state==7)
		{
			if (flag_log.status==false) {flag_log.status = true; printf("OK: Flag \"log\" is now active.\n");}
			else if (flag_log.status==true) {printf("ERROR: Flag \"log\" passed multiple times!\n"); func_ret = false;}
		}



		else if (*state>=8 && *state<=9)
		{
			printf("ERROR: No flag named \'%s\' exists! Did you meant \"mod\"?\n", flag);
			func_ret = false;
		}



		else if (*state==10)
		{
			if (flag_mod.status==false) {flag_mod.status = true; printf("OK: Flag \"mod\" is now active.\n");}
			else if (flag_mod.status==true) {printf("ERROR: Flag \"mod\" passed multiple times!\n"); func_ret = false;}
		}



		else if (*state>=11 && *state<=12)
		{
			printf("ERROR: No flag named \'%s\' exists! Did you meant \"nwr\"?\n", flag);
			func_ret = false;
		}



		else if (*state==13)
		{
			if (flag_nwr.status==false) {flag_nwr.status = true; printf("OK: Flag \"nwr\" is now active.\n");}
			else if (flag_nwr.status==true) {printf("ERROR: Flag \"nwr\" passed multiple times!\n"); func_ret = false;}
		}



		else if (*state>=14 && *state<=16)
		{
			printf("ERROR: No flag named \'%s\' exists! Did you meant \"help\"?\n", flag);
			func_ret = false;
		}



		else if (*state==17)
		{
			if (flag_help.status==false) {flag_help.status = true; cmd_help_repr(); cmd_help_rules(); cmd_help_flags();}
			else if (flag_help.status==true) {printf("ERROR: Flag \"help\" passed multiple times!\n"); func_ret = false;}
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
			case -1: printf("ERROR: No flag named \"%s\" exists!\n", flag); break;
			case -2: printf("ERROR: No flag named \"%s\" exists! Did you meant \"deb\"?\n", flag); break;
			case -3: printf("ERROR: No flag named \"%s\" exists! Did you meant \"dev\"?\n", flag); break;
			case -4: printf("ERROR: No flag named \"%s\" exists! Did you meant \"log\"?\n", flag); break;
			case -5: printf("ERROR: No flag named \"%s\" exists! Did you meant \"mod\"?\n", flag); break;
			case -6: printf("ERROR: No flag named \"%s\" exists! Did you meant \"nwr\"?\n", flag); break;
			case -7: printf("ERROR: No flag named \"%s\" exists! Did you meant \"help\"?\n", flag); break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}