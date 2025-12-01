/* Including required headers. */

#include "../../include/manuals/cmd_help.h"

#include <stdio.h>		// For displaying messages on terminal.
#include <string.h>		// For using certain string-related functions.










/* Pseudo representation of command usage. */

void cmd_help_repr(void)
{
	printf("\n");
	printf("PSEUDO REPRESENTATION\n");
	for (long int i=0; i<strlen("PSEUDO REPRESENTATION\n")-1; i++)
	{
		printf("-");
	} printf("\n\n");

	printf("<dec-as> <dest_file> <src_file> -<flag1> -<flag2> ... -<flagN>\n\n");
	printf("- \"<dec-as>\": 1st argument (compulsory), is the reference to assembler binary (relative, absolute, or symbolic).\n");
	printf("- \"<dest_file>\": 2nd argument (compulsory), is the name of destination file to be created with its path (relative or absolute).\n");
	printf("- \"<src_file>\": 3rd argument (compulsory), is the name of existing source file with its path (relative or absolute).\n");
	printf("- \"<flag1>\", \"<flag2>\", \"<flagN>\", etc: Are flags (starting with \'-\') passed to assembler for enabling/disabling certain features.\n");
	printf("- \"...\": Represents that more might flags might have been added, and not literal usage.\n");
	printf("\n\n");
}










/* Rules when passing arguments. */

void cmd_help_rules(void)
{
	printf("COMMAND USAGE RULES\n");
	for (long int i=0; i<strlen("COMMAND USAGE RULES\n")-1; i++)
	{
		printf("-");
	} printf("\n\n");

	printf("- Minimum number of arguments allowed are %d (assembler binary, destination path, and source path).\n", MIN_ARGS);
	printf("- Maximum number of arguments allowed are %d (minimum compulsory & flags).\n", MAX_ARGS);
	printf("- Each flag must be passed once (uppercase, lowercase, or mixed), and start with \'-\' (like \"-log\", \"-nwr\", etc).\n");
	printf("\n\n");
}










/* Flags definition & uses. */

void cmd_help_flags(void)
{
	printf("FLAGS DEFINITION\n");
	for (long int i=0; i<strlen("FLAGS DEFINITION\n")-1; i++)
	{
		printf("-");
	} printf("\n\n");

	printf("- \"deb\": Enables debugging information, which are added to the final object binaries.\n");
	printf("- \"dev\": Enables developer option, to audit inner working and state transitions.\n");
	printf("- \"log\": Logs all the terminal output to a file, for later review/ case studies.\n");
	printf("- \"mod\": Assembles flat binary to run in bare metal environment.\n");
	printf("- \"nwr\": Disables warnings across the assembler, and shows only errors.\n");
	printf("\n\n");
}