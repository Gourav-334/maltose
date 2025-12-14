/* Adding header(s) for unit testing. */

#include "../include/bin_gen/x86-linux/bin_sec_store.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	printf("Section .RODATA store: %p\n", sec_rodata_store);
	printf("Section .BSS store: %p\n", sec_bss_store);
	printf("Section .RODATA store: %p\n\n", sec_rodata_store);

	printf(".RODATA size: %zu\n", sec_rodata_size);
	printf(".RELA.TEXT size: %zu\n", sec_rela_text_size);


	return 0;
}