#include <stdio.h>			// Standard input-output header



/* The main window. */

int main(void)
{
	FILE *fptr = NULL;
	char *code = NULL;

	fptr = fopen("code.test", "r");

	if (fptr==NULL) {perror("ERROR");}
	else
	{
		while (!feof(fptr))
		{
			//
		}
	}



	return 0;
}