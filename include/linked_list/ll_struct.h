/* Including guard to avoid multiple inclusions. */

#ifndef LL_STRUCT_H
	#define LL_STRUCT_H










/* Declaring structures. */

typedef struct Ll_node
{
	char *data;
	struct Ll_node *next;
} Ll_node;



typedef struct Ll_recorder
{
	int total;

	Ll_node *head;
	Ll_node *tail;
} Ll_recorder;










/* Closing guard macros. */

#endif