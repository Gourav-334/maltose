/* Adding header(s) for unit testing. */

#include "../include/parser/x86/register_store.h"

#include <stdio.h>
#include <inttypes.h>



int main(int argc, char **argv)
{
	printf(
		"%" PRIu64 ", %" PRIu64 ", %" PRIu64 ", %" PRIu8 ", %" PRIu8 ", %" PRIu16 ", %" PRIu16 ", %" PRIu32 "\n",
		rax, rsp, rbp, bpl, ah, fpflag, r11w, eax
	);


	return 0;
}
