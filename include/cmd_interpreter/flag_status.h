/* Adding guard to avoid multiple inclusions. */

#ifndef FLAG_STATUS_H
	#define FLAG_STATUS_H





/* Including required headers. */

#include <stdbool.h>		// Used to know status of a flag.










/* Declaring structures. */

struct Flag
{
	char *subtype;
	bool status;
};





/* Declaring instances of structures. */

extern struct Flag flag_deb;
extern struct Flag flag_dev;
extern struct Flag flag_log;
extern struct Flag flag_mod;
extern struct Flag flag_opt;
extern struct Flag flag_nwr;










/* Closing guard macros. */

#endif