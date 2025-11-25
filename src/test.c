/* Adding header(s) for unit testing. */

#include "../include/bin_gen/x86/specs_store.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	printf("SHDR:ADDRALIGN :: %ld\n", sec_header.sh_addralign);


	return 0;
}