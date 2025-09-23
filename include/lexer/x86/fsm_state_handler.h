/* Guards to avoid multiple inclusions. */

#ifndef TOKEN_FSM_STATE_HANDLER_H
	#define TOKEN_FSM_STATE_HANDLER_H





/* Including required headers. */

#include <stdbool.h>		// For returning boolean value as per execution.










/* Functions declaration. */

bool handle_token_fsm_state(signed short int *state, char *flag, char *mode);		// Decides what to do with final state of FSM.










/* Closing guard macros. */

#endif