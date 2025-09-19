/* Including required headers. */

#include "../include/file_loader.h"

#include <stdio.h>		// For providing feedback as per selected mode.
#include <stdlib.h>		// For allocating memory for filestream in RAM.
#include <string.h>		// For comparing matching of strings.










/* Variables/constant definitions. */

char *fstream = NULL;
long int file_size = 0;










/* Loads file from disk to RAM. */

bool load_file(char *path, char *mode)
{
	/* Variables declarations/definitions. */

	FILE *file = NULL;
	size_t bytes_read;





	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return false;
	}










	/* Opening the file to load stream. */

	file = fopen(path, "r");


	/* Checking if the file really exists or not. */

	if (file==NULL) {perror("ERROR"); return false;}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK :: File pointed through %p.\n", file);}
	}










	/* Calculating total bytes in file. */

	if (fseek(file, 0, SEEK_END)!=0) {perror("ERROR"); return false;}
	else
	{
		file_size = ftell(file);
		if (file_size<0) {perror("ERROR"); return false;}
		else
		{
			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG) {printf("OK :: Cursor moved to END :: Code %d\n", SEEK_END);}
		}
	}





	if (fseek(file, 0, SEEK_SET)!=0) {perror("ERROR"); return false;}
	else
	{
		file_size -= ftell(file);
		if (file_size<0) {perror("ERROR"); return false;}
		else
		{
			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG) {printf("OK :: Cursor moved to START :: Code %d\n", SEEK_SET);}
		}
	}










	/* Dynamically allocate space for filestream. */

	fstream = malloc(file_size*sizeof(char));


	if (fstream==NULL)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Problem allocating memory for filestream in RAM!\n");}
		else if (M==DEBUG) {printf("ERROR :: Failed to allocate memory for filestream at %p!\n", fstream);}

		return false;
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {printf("OK: Allocated memory for filestream in RAM!\n");}
		else if (M==DEBUG) {printf("OK :: Successfully allocated memory for filestream at %p!\n", fstream);}
	}








	

	/* Loading contents of file to RAM as filestream. */

	bytes_read = fread(fstream, sizeof(char), (size_t)file_size, file);


	if (bytes_read!=(size_t)file_size)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Problem reading all file contents!\n");}
		else if (M==DEBUG) {printf("ERROR :: Partial reads :: %zu/%zu bytes read\n", bytes_read, file_size);}

		return false;
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK :: Full reads :: %zu/%zu bytes read\n", bytes_read, file_size);}
	}





	/* Returning 'true' for successful loading of stream. */

	return true;
}