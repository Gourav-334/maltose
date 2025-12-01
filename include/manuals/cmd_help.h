/* Including guard to avoid multiple inclusions. */

#ifndef CMD_HELP_H
	#define CMD_HELP_H

#define MIN_ARGS 3
#define MAX_ARGS 8










/* Functions declaration. */

void cmd_help_repr(void);			// Pseudo representation of command usage.
void cmd_help_rules(void);			// Instructing rules for passing arguments to assembler.
void cmd_help_flags(void);			// Clarifying correct usage of flags.










/* Closing macro for guard. */

#endif