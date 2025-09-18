/* Including required headers. */

#include "../../include/cmd_interpreter/cmd_valid.h"
#include "../../include/cmd_interpreter/cmd_fsm_main.h"
#include "../../include/utils/str_verif/ill_char_scan.h"
#include "../../include/utils/file_sys/path_valid.h"

#include <stdio.h>		 	// For providing feedback as per mode.
#include <string.h>			// For measuring a string's size.










bool cmd_valid(int argc, char *argv[], char *mode)
{
	/* Variable declarations/definitions. */

	bool func_ret = true;





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





	/* Feedback for the number of arguments passed. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG) {printf("STAT :: Total %d arguments passed to assembler.\n", argc);}





	/* Checking total number of arguments. */

	if (argc==1) {printf("ERROR: Assembler requires passing source and destination path!\n"); return false;}
	else if (argc==2) {printf("ERROR: Assembler requires passing source path too!\n"); return false;}
	else if (argc>=3 && argc<=MAX_ARGS)
	{
		/* Checking if destination file exist, along with correct naming (as per UNIX convention). */

		if (scan_ill_chars(argv[1], strlen(argv[1]), "\0/", "user")==true) {func_ret = false;}
		if (path_valid(argv[1], false, "user")==false) {func_ret = false;}



		/* Checking if source file exist, along with correct naming (as per UNIX convention). */

		if (scan_ill_chars(argv[2], strlen(argv[2]), "\0/", "user")==true) {func_ret = false;}
		if (path_valid(argv[2], true, "user")==false) {func_ret = false;}





		/* Handling flags (if any). */

		if (argc>3)
		{
			for (int i=3; i<argc; i++)
			{
				/* Giving feedback as per mode. */

				if (M==DEV) {}
				else if (M==USER) {}
				else if (M==DEBUG)
				{
					printf("STAT :: argc=%d :: argv[%d]=%s :: func_ret=%b\n",
						argc, i, argv[i], func_ret);
				}



				/* Analysing passed flag format. */

				if (*argv[i]=='-')
				{
					if (cmd_fsm_main(argv[i], 1, "user")==false) {func_ret = false;}
				}
				else if (*argv[i]!='-')
				{
					printf("ERROR: Wrong format \"%s\" flag names must start with \'-\'!\n", argv[i]);
					func_ret = false;

					continue;
				}
			}
		}
	}
	else if (argc>MAX_ARGS)
	{
		printf("ERROR: Max argument limit of %d surpassed with %d arguments!\n", MAX_ARGS, argc);
		return false;
	}





	/* Providing feedback as per the mode. */

	if (func_ret==true)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("OK: No flaws found in passed arguments to assembler.\n");}
		else if (M==DEBUG) {printf("OK :: No flaws found in passed arguments to assembler.\n");}
	}
	else if (func_ret==false)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Flaws found in passed arguments to assembler!\n");}
		else if (M==DEBUG) {printf("ERROR :: Flaws found in passed arguments to assembler!\n");}
	}



	/* Returning success/failure of command analysis. */

	return func_ret;
}