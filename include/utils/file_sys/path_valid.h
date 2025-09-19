/* Setting up guard to avoid multiple inclusions. */

#ifndef PATH_VALID_H
	#define PATH_VALID_H





/* Including all the required libraries. */

#include <stdbool.h>		// Using boolean function & variables.










/* Function declarations. */

bool path_valid(char *path, bool exist, char *mode);		// Validate if a path exists/ can exist or not.










/* Closing the opened guard macro. */

#endif