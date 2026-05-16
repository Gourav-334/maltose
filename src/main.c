/* Including required headers. */

#include "../include/cmd_interp/cmd_valid.h"
#include "../include/lexer/x86/code_cleanser.h"
#include "../include/file_loader.h"

#include <stdlib.h>



int main(int argc, char *argv[])
{
	cmd_valid(argc, **argv, "user");
	cleanse_code(fstream, "user");


	return EXIT_SUCCESS;
}