/* Including required headers. */

#include "../include/cmd_interp/cmd_valid.h"

#include <stdlib.h>



int main(int argc, char *argv[])
{
	cmd_valid(argc, **argv, "user");


	return EXIT_SUCCESS;
}