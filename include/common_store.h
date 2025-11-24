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

extern int point;			// Point of trigger in the string.
extern int row;				// Row of point of trigger.
extern int column;			// Column of point of trigger.

extern long int str_len;			// Length of the passed string.
extern long int newlines;			// Counts number of newlines encountered.

extern unsigned short int i_token_fsm;			// Globally accessible variable for loop counts.
extern unsigned short int point_shift;			// Bytes to shift by from point of trigger.










/* Closing guard macros. */

#endif