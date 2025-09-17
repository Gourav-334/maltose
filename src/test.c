/* Adding header(s) for unit testing. */

#include "../include/cmd_interpreter/fsm_state_handler.h"

#include <stdio.h>



int main()
{
	signed short int state = 0;

	handle_fsm_state(&state, "{FLAG}", "debug"); state = 1;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 2;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 3;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 4;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 5;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 6;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 7;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 8;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 9;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 10;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 11;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 12;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = 13;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = -1;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = -2;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = -3;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = -4;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = -5;
	handle_fsm_state(&state, "{FLAG}", "debug"); state = -6;
	handle_fsm_state(&state, "{FLAG}", "debug");


	return 0;
}
