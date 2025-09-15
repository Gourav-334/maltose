/* Including all the required libraries. */

#include "../../../include/utils/file_sys/path_valid.h"
#include "../../../include/utils/str_ops/push_alloc.h"

#include <stdio.h>			// Required for writing mode feedback on terminal.
#include <string.h>			// Required to use certains string related functions.










/* Checks if a path exists or not, as per existence of a file. */

bool path_valid(char *path, bool exist, char *mode)
{
	/* Variable declaration/defintions. */

	FILE *file = NULL;
	int rm_ret;



	/* Non-linear structure declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is being used. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!", mode);
		return false;
	}




	/* Adding filename to path if just directory name is passed. */

	if (*(path+strlen(path)-1)=='/')
	{
		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: Path \"%s\" doesn't contain filename.\n", path);
		}



		/* Pushing a character-sized filename to path. */

		push_alloc(&path, 'c', "debug");
		exist = false;
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: Path \"%s\" contains filename.\n", path);
		}
	}





	/* If given path with file is expected to already exist. */

	if (exist==true)
	{
		/* Attempting to read the file to know if it exists. */

		file = fopen(path, "r");



		/* Checking if file opened or not. */

		if (file==NULL) {perror("ERROR"); return false;}
		else
		{
			if (M==DEV) {}
			else if (M==USER)
			{
				printf("OK: File \"%s\" exists.\n", path);
			}
			else if (M=DEBUG)
			{
				printf("OK :: Read operation successful on \"%s\"!\n", path);
			}



			fclose(file);
			return true;
		}
	}





	/* If given path with file doesn't exist yet. */

	else if (exist==false)
	{
		/* Checking if file from same name already exists. */

		file = fopen(path, "r");



		/* Checking if file opened or not. */

		if (file!=NULL)
		{
			if (M==DEV) {}
			else if (M==USER)
			{
				printf("WARN: File already exists as \"%s\".\n", path);
			}
			else if (M==USER)
			{
				printf("WARN :: Path \"%s\" already exists.\n", path);
			}


			fclose(file);
			return true;
		}
		else if (file==NULL)
		{
			/* Checking if file with same name wasn't found, or directory is non-existent. */

			file = fopen(path, "w");



			/* Checking if file was written or not. */

			if (file==NULL)
			{
				if (M==DEV) {}
				else if (M==USER)
				{
					printf("ERROR: Non-existing directory \"%s\" (without filename)!\n", path);
				}
				else if (M==USER)
				{
					printf("ERROR :: Write operation as \"%s\" failed!\n", path);
				}


				return false;
			}
			else
			{
				if (M==DEV) {}
				else if (M==USER)
				{
					printf("OK: File can exist as \"%s\".\n", path);
				}
				else if (M==USER)
				{
					printf("OK :: File \"%s\" can exist in future.\n", path);
				}



				/* Removing the newly created file (if was). */

				fclose(file);
				rm_ret = remove(path);



				/* Giving feedback as per mode. */

				if (rm_ret==-1) {perror("ERROR");}
				else if (rm_ret==0)
				{
					if (M==DEV) {}
					else if (M==USER)
					{
						printf("ERROR: Failed to remove test file \"%s\"!\n", path);
					}
					else if (M==DEBUG)
					{
						printf("ERROR :: Remove operation on \"%s\" failed!\n", path);
					}
				}


				return true;
			}
		}
	}
}