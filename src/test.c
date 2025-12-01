/* Adding header(s) for unit testing. */

#include "../include/bin_gen/x86-linux/specs_store.h"
#include "../include/bin_gen/x86-linux/specs_assign.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	assign_specs();
	printf("ELFHDR:SHNUM :: %x\n", elf_header.e_shnum);


	return 0;
}