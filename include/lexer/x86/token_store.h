/* Including guards to avoid multiple inclusions. */

#ifndef TOKEN_STORE_H
	#define TOKEN_STORE_H





/* Including required headers. */

#include "../../data_structs/linked_list/ll_struct.h"










/* Structure instances. */

extern Ll_recorder token;			// Linked list recorder for exact token values.
extern Ll_recorder categ;			// Linked list recorder for category of token.
extern Ll_recorder sub_categ;		// Linked list recorder for sub-category of token.
extern Ll_recorder type;			// Linked list recorder for type of token.










/* Closing guard macros. */

#endif