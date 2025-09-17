/* Including required headers. */

#include "../../include/cmd_interpreter/fsm_state_handler.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Command interpreter's FSM state handler. */

bool handle_fsm_state(signed short int *state, char *flag, char *mode)
{
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
		if (*state==0) {printf("ERROR: Flag passed can't be empty!\n");}
		else if (*state>=1 && *state<=2) {printf("ERROR: No flag named \'%s\' exists! Did you meant \'-deb\' or \'-dev\'?\n", flag);}
		else if (*state==3) {printf("OK: Flag \'-deb\' is now active.\n");}
		else if (*state==4) {printf("OK: Flag \'-dev\' is now active.\n");}
		else if (*state>=5 && *state<=6) {printf("ERROR: No flag named \'%s\' exists! Did you meant \'-log\'?\n", flag);}
		else if (*state==7) {printf("OK: Flag \'-log\' is now active.\n");}
		else if (*state>=8 && *state<=9) {printf("ERROR: No flag named \'%s\' exists! Did you meant \'-mod\'?\n", flag);}
		else if (*state==10) {printf("OK: Flag \'-mod\' is now active.\n");}
		else if (*state>=11 && *state<=12) {printf("ERROR: No flag named \'%s\' exists! Did you meant \'-nwr\'?\n", flag);}
		else if (*state==13) {printf("OK: Flag \'-nwr\' is now active.\n");}
	}





	/* Handling dump states. */

	switch(*state)
	{
		case -1: printf("ERROR: No flag named \'%s\' exists!\n", flag); break;
		case -2: printf("ERROR: No flag named \'%s\' exists! Did you meant \'-deb\'?\n", flag); break;
		case -3: printf("ERROR: No flag named \'%s\' exists! Did you meant \'-dev\'?\n", flag); break;
		case -4: printf("ERROR: No flag named \'%s\' exists! Did you meant \'-log\'?\n", flag); break;
		case -5: printf("ERROR: No flag named \'%s\' exists! Did you meant \'-mod\'?\n", flag); break;
		case -6: printf("ERROR: No flag named \'%s\' exists! Did you meant \'-nwr\'?\n", flag); break;
	}
}