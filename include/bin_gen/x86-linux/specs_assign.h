/* Guards to avoid multiple inclusions. */

#ifndef SPECS_ASSIGN_H
	#define SPECS_ASSIGN_H

#define OBJ_ENTRY 0x0		// Entry for object files (nothing).





/* Macro-based operations */

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	#define ENDIANNESS ELFDATA2LSB

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	#define ENDIANNESS ELFDATA2MSB

#endif			// Detecting which endianness system uses.





/* Including required headers. */

#include <stdbool.h>		// For function to return a boolean variable.










/* Declaring functions. */

bool assign_specs(void);		// Extracts information & assigns specs to intended variables.










/* Closing guards */

#endif