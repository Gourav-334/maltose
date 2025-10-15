/* Including guards to avoid multiple inclusions. */

#ifndef COMMON_STORAGE_H
	#define COMMON_STORAGE_H





/* Shortcut numerical representations for various data types. */

#define CHARACTER 1				// Character
#define STRING 2 				// String
#define SHORT_INTEGER 3 		// Short
#define INTEGER 4				// Integer
#define LONG_INTEGER 5 			// Long










/* For lexical components. */

extern int point;
extern int row;
extern int column;

extern long int str_len;
extern unsigned short int i_token_fsm;
extern unsigned short int point_shift;










/* Closing guard macros. */

#endif