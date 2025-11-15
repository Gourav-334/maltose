/* Including guards to avoid multiple inclusions. */

#ifndef COMMON_STORAGE_H
	#define COMMON_STORAGE_H





/* Shortcut numerical representations for various data types. */

#define CHARACTER 1				// Character
#define STRING 2 				// String
#define SHORT_INTEGER 3 		// Short
#define INTEGER 4				// Integer
#define LONG_INTEGER 5 			// Long
#define FLOAT_POINT 6			// Floating-point
#define DOUBLE 7				// Double
#define LONG_DOUBLE 8			// Long double










/* For lexical components. */

extern int point;
extern int row;
extern int column;

extern long int str_len;
extern long int newlines;
extern unsigned short int i_token_fsm;
extern unsigned short int point_shift;










/* Closing guard macros. */

#endif