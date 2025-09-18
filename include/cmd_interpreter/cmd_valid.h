/* Including guard to avoid multiple inclusions. */

#ifndef CMD_VALID_H
	#define CMD_VALID_H

#define MIN_ARGS 3
#define MAX_ARGS 8





#include <stdbool.h>		// For using boolean return type.










/* Function declarations. */

bool cmd_valid(int argc, char **argv, char *mode);










/* Closing guard macros. */

#endif