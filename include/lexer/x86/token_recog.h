/* Including guard to avoid multiple inclusions. */

#ifndef	TOKEN_RECOG_H
	#define TOKEN_RECOG_H





/* Including required headers. */

#include <stdbool.h>		// To use boolean return type.










/* Recognizes token & stores related information. */

bool token_recog(char *str, int point, int row, int column);










/* Closing guard macros. */

#endif