/* Including required headers. */

#include "../../include/linked_list/ll_struct.h"
#include "../../include/linked_list/inserter.h"

#include <stdio.h>		// To provide feedback as per chosen mode.
#include <stdlib.h>		// To allocate memory for nodes.
#include <string.h>		// To copy string to certain areas of memory.










/* Inserts a node in front or rear of a linked list. */

bool insert(Ll_recorder *recorder, char *data, bool rear, char *mode)
{
	/* Declaring/defining variables. */

	Ll_node *trav = NULL;
	Ll_node *old_tail = NULL;



	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return false;
	}










	/* Allocating memory space for new node. */

	trav = malloc(sizeof(Ll_node));


	if (trav==NULL)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Problem allocating memory!\n");}
		else if (M==DEBUG) {printf("ERROR :: Memory for node can't be allocated!\n");}

		return false;
	}





	/* Allocating memory space for data at the newly allocated memory space. */

	trav -> data = malloc(sizeof(strlen(data)));



	/* Providing feedback as per the chosen mode. */

	if (trav->data==NULL)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Problem allocating memory!\n");}
		else if (M==DEBUG) {printf("ERROR :: Memory for data can't be allocated!\n");}

		return false;
	}



	/* Filling in the string data. */

	strcpy(trav->data, data);










	/* Providing feedback as per the chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG)
	{
		printf("STAT :: Before operation (rear=%b) :: trav=%p :: head=%p :: tail=%p\n",
			rear, trav, recorder->head, recorder->tail);
	}





	/* Checking if linked list if otherwise empty or not. */

	if (recorder->total==0)
	{
		trav -> next = NULL;
		recorder -> head = trav;
		recorder -> tail = trav;


		/* Providing feedback as per the chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: trav=%p :: head=%p :: tail=%p\n",
				trav, recorder->head, recorder->tail);
		}
	}
	else if (recorder->total>0)
	{
		/* Inserting node as per the requested place of insertion. */

		if (rear==false)
		{
			trav -> next = recorder -> head;
			recorder -> head = trav;


			/* Providing feedback as per the chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG)
			{
				printf("STAT :: After operation :: trav(%p) -> old_head(%p) :: head=%p\n",
					trav, trav->next, recorder->head);
			}
		}
		else if (rear==true)
		{
			old_tail = recorder -> tail;

			recorder -> tail -> next = trav;
			trav -> next = NULL;
			recorder -> tail = trav;


			/* Providing feedback as per the chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG)
			{
				printf("STAT :: After operation :: old_tail(%p) -> trav(%p) -> NULL(%p) :: tail=%p\n",
					old_tail, trav, trav->next, recorder->tail);
			}
		}
	}



	/* Incrementing the count of total nodes. */

	(recorder->total)++;


	/* Providing feedback as per the chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {printf("OK: Insertion successfully performed, now total %d nodes.\n", recorder->total);}
	else if (M==DEBUG) {printf("OK :: Successful insertion :: .total=%d\n", recorder->total);}





	/* Returning 'true' for successful execution. */

	return true;
}