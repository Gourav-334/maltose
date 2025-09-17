/* Adding header(s) for unit testing. */

#include "../include/cmd_interpreter/cmd_fsm_main.h"

#include <stdio.h>



int main()
{
	cmd_fsm_main("rand", 0, "debug"); printf("\n");
	cmd_fsm_main("deb", 0, "debug"); printf("\n");
	cmd_fsm_main("randdeb", 0, "debug"); printf("\n");
	cmd_fsm_main("debrand", 0, "debug"); printf("\n");
	cmd_fsm_main("randdebrand", 0, "debug"); printf("\n");
	cmd_fsm_main("debranddeb", 0, "debug"); printf("\n");
	cmd_fsm_main("debranddev", 0, "debug"); printf("\n"); printf("\n");

	cmd_fsm_main("rand", 0, "debug"); printf("\n");
	cmd_fsm_main("dev", 0, "debug"); printf("\n");
	cmd_fsm_main("randdev", 0, "debug"); printf("\n");
	cmd_fsm_main("devrand", 0, "debug"); printf("\n");
	cmd_fsm_main("randdevrand", 0, "debug"); printf("\n");
	cmd_fsm_main("devranddev", 0, "debug"); printf("\n");
	cmd_fsm_main("devrandlog", 0, "debug"); printf("\n"); printf("\n");

	cmd_fsm_main("rand", 0, "debug"); printf("\n");
	cmd_fsm_main("log", 0, "debug"); printf("\n");
	cmd_fsm_main("randlog", 0, "debug"); printf("\n");
	cmd_fsm_main("logrand", 0, "debug"); printf("\n");
	cmd_fsm_main("randlogrand", 0, "debug"); printf("\n");
	cmd_fsm_main("lograndlog", 0, "debug"); printf("\n");
	cmd_fsm_main("lograndmod", 0, "debug"); printf("\n"); printf("\n");

	cmd_fsm_main("rand", 0, "debug"); printf("\n");
	cmd_fsm_main("mod", 0, "debug"); printf("\n");
	cmd_fsm_main("randmod", 0, "debug"); printf("\n");
	cmd_fsm_main("modrand", 0, "debug"); printf("\n");
	cmd_fsm_main("randmodrand", 0, "debug"); printf("\n");
	cmd_fsm_main("modrandmod", 0, "debug"); printf("\n");
	cmd_fsm_main("modrandnwr", 0, "debug"); printf("\n"); printf("\n");

	cmd_fsm_main("rand", 0, "debug"); printf("\n");
	cmd_fsm_main("nwr", 0, "debug"); printf("\n");
	cmd_fsm_main("randnwr", 0, "debug"); printf("\n");
	cmd_fsm_main("nwrrand", 0, "debug"); printf("\n");
	cmd_fsm_main("randnwrrand", 0, "debug"); printf("\n");
	cmd_fsm_main("nwrrandnwr", 0, "debug"); printf("\n");
	cmd_fsm_main("nwrranddeb", 0, "debug"); printf("\n"); printf("\n");


	return 0;
}
