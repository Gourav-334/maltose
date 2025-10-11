/* Including all required headers. */

#include "../../include/manuals/audit_msng.h"
#include "../../include/utils/str_ops/push_alloc.h"

#include <stdio.h>			// For displaying output on console/terminal.
#include <stdlib.h>			// For dynamically allocating memory for buffers.
#include <string.h>			// For copying & pasting string data.










/* Prints audit message on console/terminal. */

void msg_audit_res(char *code, char *filename, int point, int row, int column, char *type, char *stage, char *just, char *mode)
{
	/* Variables declarations/definitions. */

	int i = point;
	int start, end;
	int count;

	char *loc = NULL;
	char *ts_cursor = NULL;



	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return;
	}










	/* Detecting the distance between point & previous terminator/ start of tape. */

	if (i>0)
	{
		do
		{
			/* Providing feedback as per the chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG) {printf("STAT:%d :: Moving to start :: *(code+%d)=\'%c\'\n", __LINE__, i, *(code+i));}


			i--;
		}
		while (!(*(code+i)=='\n' || i==0));
	}


	/* Moving forward to first symbol in line (if not first line). */

	if (*(code+i)=='\n') {i++;}

	start = i;





	/* Counting the chararacters in second half of the line. */

	i = point;

	while (!(*(code+i)=='\n' || *(code+i)=='\0'))
	{
		/* Providing feedback as per the chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("STAT:%d :: Moving to end :: *(code+%d)=\'%c\'\n", __LINE__, i, *(code+i));}

		i++;
	}

	end = i;
	count = end - start + 1;





	/* Providing feedback as per the chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG)
	{
		printf("STAT:%d :: i=%d, row=%d, column=%d :: start=%d, end=%d, count=%d\n",
			__LINE__, i, row, column, start, end, count);

		printf("STAT:%d :: *start=\'%c\' :: *point=\'%c\' :: *end=\'%c\'\n",
			__LINE__, *(code+start), *(code+point), *(code+end));
	}










	/* Reading the line into buffer. */

	i = start;

	loc = malloc((size_t)count*sizeof(char));
	if (loc==NULL) {printf("ERROR: Problem allocating memory dynamically!\n");}

	strncpy(loc, (code + start), (size_t)count);
	*(loc + count) = '\0';


	/* Replacing tabspaces in LOC with whitespaces for synced view. */

	for (int iter=0; iter<count; iter++) {if (*(loc+iter)=='\t') {*(loc + iter) = ' ';}}


	/* Adding an endline at the end of LOC if one is not there already. */

	if (*(loc+count-1)!='\n') {push_alloc(&loc, '\n', "dev");}





	/* Setting the troubleshooting cursor. */

	if (count>0)
	{
		ts_cursor = malloc((size_t)count*sizeof(char));
		if (loc==NULL) {printf("ERROR: Problem allocating memory dynamically!\n");}

		memset(ts_cursor, ' ', (point - start));
		*(ts_cursor + (point - start)) = '^';

		if (point!=end) {memset((ts_cursor + (point - start + 1)), '~', (end - point));}
		*(ts_cursor + count - 1) = '\0';
	}





	/* Providing feedback as per chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG)
	{
		printf("STAT:%d :: After allocation :: *loc=\'%c\'\n", __LINE__, *loc);
	}










	/* Printing the audit message on console. */

	printf("%s\n%s (%s) :: Line=%d:%d :: %s\n%s", filename, type, stage, row, column, just, loc);
	if (count>1) {printf("%s\n\n", ts_cursor);}
}