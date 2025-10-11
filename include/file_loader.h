/* Including guard to avoid multiple inclusions. */

#ifndef FILE_LOADER_H
	#define FILE_LOADER_H





/* Including required headers. */

#include <stdbool.h>		// Required to return boolean type.










/* Declaring variables. */

extern char *fstream;			// Pointer to filestream present in memory.
extern char *src_filename;		// Name of the source assembly file.
extern long int file_size;		// Size of the filestream in memory.





/* Functions declaration. */

bool load_file(char *path, char *mode);		// Loads file from disk to RAM.










/* Closing guard macros. */

#endif