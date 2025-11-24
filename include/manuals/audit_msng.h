/* Including guards to avoid multiple inclusion. */

#ifndef AUDIT_MSNG_H
	#define AUDIT_MSNG_H










/* Function declarations. */

void msg_audit_res(
	char *code, char *filename,				// Compulsory/subject input parameters.
	int point, int row, int column,			// Parameters related to the position in string/code.
	char *type, char *stage,				// Details or metadata about feedback.
	char *just,								// Justification for providing the feedback.
	char *mode								// Programmer chosen mode for feedback.
);










/* Closing guard macros. */

#endif