/* Including guards to avoid multiple inclusion. */

#ifndef AUDIT_MSNG_H
	#define AUDIT_MSNG_H










/* Function declarations. */

void msg_audit_res(
	char *code, char *filename,
	int point, int row, int column,
	char *type, char *stage,
	char *just,
	char *mode
);










/* Closing guard macros. */

#endif