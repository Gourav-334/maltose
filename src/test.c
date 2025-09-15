/* Adding header(s) for unit testing. */

#include "../include/utils/file_sys/path_valid.h"

#include <stdio.h>
#include <string.h>



int main()
{
	char *path = NULL;
	
	path_valid("build/", true, "debug");


	return 0;
}
