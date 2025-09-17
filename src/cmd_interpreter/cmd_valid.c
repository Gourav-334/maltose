/* Including required headers. */

#include "../../include/cmd_interpreter/cmd_valid.h"

#include <stdio.h>		// For providing feedback as per mode.










void cmd_valid(int argc, char **argv, char *mode)
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
		return;
	}





	/* Feedback for the number of arguments passed. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG) {printf("STAT: Total %d arguments passed to assembler.\n", argc);}





	/* Checking total number of arguments. */

	if (argc==1) {}
}