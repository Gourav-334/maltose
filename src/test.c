/* Adding header(s) for unit testing. */

#include "../include/lexer/x86/token_fsm_main.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	token_fsm_main("42", 0, "debug"); printf("\n");
	token_fsm_main("0", 0, "debug"); printf("\n");
	token_fsm_main("123456", 0, "debug"); printf("\n");
	token_fsm_main("-99", 0, "debug"); printf("\n");
	printf("------------------------------------------\n");

	token_fsm_main("3.14", 0, "debug"); printf("\n");
	token_fsm_main("0.0", 0, "debug"); printf("\n");
	token_fsm_main("-2.71828", 0, "debug"); printf("\n");
	token_fsm_main("6.022e23", 0, "debug"); printf("\n");
	token_fsm_main("-1.0E-10", 0, "debug"); printf("\n");
	printf("------------------------------------------\n");

	token_fsm_main("77o", 0, "debug"); printf("\n");
	token_fsm_main("55q", 0, "debug"); printf("\n");
	printf("------------------------------------------\n");

	token_fsm_main("0x2A", 0, "debug"); printf("\n");
	token_fsm_main("2Ah", 0, "debug"); printf("\n");
	token_fsm_main("-0xFF", 0, "debug"); printf("\n");
	token_fsm_main("0XdeadBEEF", 0, "debug"); printf("\n");
	printf("------------------------------------------\n");

	token_fsm_main("1010b", 0, "debug"); printf("\n");
	token_fsm_main("1101B", 0, "debug"); printf("\n");
	token_fsm_main("-101b", 0, "debug"); printf("\n");
	printf("------------------------------------------\n");


	return 0;
}
