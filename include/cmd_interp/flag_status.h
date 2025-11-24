/* Adding guard to avoid multiple inclusions. */

#ifndef FLAG_STATUS_H
	#define FLAG_STATUS_H





/* Including required headers. */

#include <stdbool.h>		// Used to know status of a flag.










/* Declaring structures. */

struct Flag
{
	char *subtype;		// Stores category of the flag.
	bool status;		// Tells whether the flag is set or not.
};





/* Declaring instances of structures. */

extern struct Flag flag_deb;		// Handles debugging flag.
extern struct Flag flag_dev;		// Handles developer flag.
extern struct Flag flag_log;		// Handles log flag.
extern struct Flag flag_mod;		// Handles metal mode flag.
extern struct Flag flag_nwr;		// Handles no warning flag.
extern struct Flag flag_help;		// Handles help manual flag.










/* Closing guard macros. */

#endif