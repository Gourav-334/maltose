/* Including guard to avoid multiple inclusions. */

#ifndef LL_STRUCT_H
	#define LL_STRUCT_H










/* Declaring structures. */

typedef struct Ll_node			// Represents a single/unit node in linked list.
{
	char *data;					// Value stored in the node.
	struct Ll_node *next;		// Address of the next node in series.
} Ll_node;





typedef struct Ll_recorder		// Records all the information about the linked list.
{
	int total;					// Total number of nodes in the linked list.

	Ll_node *head;				// Address of the head node.
	Ll_node *tail;				// Address of the tail node.
} Ll_recorder;










/* Closing guard macros. */

#endif