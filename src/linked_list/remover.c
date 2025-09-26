/* Including required headers. */

#include "../../include/linked_list/remover.h"

#include <stdio.h>			// To provide feedback as per chosen mode.
#include <stdlib.h>			// To free memory spaces.
#include <string.h>			// To compare string for passed mode.










/* Removes a node from front or rear in linked list. */

void remove_node(Ll_recorder *recorder, bool rear, char *mode)
{
	/* Declaring/defining variables. */

	Ll_node *trav = NULL;



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










	/* Taking action as per the number of nodes. */

	if (recorder->total==0)
	{
		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {printf("WARN: Linked list is already empty.\n");}
		else if (M==DEBUG) {printf("WARN :: Linked list is already empty.\n");}
	}
	else
	{
		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT :: Total %d nodes present in linked list.\n", recorder->total);
			printf("STAT :: Before removal (rear=%b) :: head(%p) -> next(%p) :: tail(%p) -> next(%p)\n",
				rear, recorder->head, recorder->head->next, recorder->tail, recorder->tail->next);
		}





		/* If nodes are present in the liked list currently. */

		if (recorder->total==1)
		{
			trav = recorder -> head;
			free(trav);

			recorder -> head = NULL;
			recorder -> tail = NULL;



			/* Providing feedback as per chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG)
			{
				printf("STAT :: After removal :: head=%p :: tail=%p\n",
					recorder->head, recorder->tail);
			}
		}
		else if (recorder->total>1)
		{
			trav = recorder -> head;


			/* Removing as per the chosen area of removal. */

			if (rear==false)
			{
				recorder -> head = recorder -> head -> next;
				free(trav);
			}
			else if (rear==true)
			{
				while(trav->next->next != NULL) {trav = trav -> next;}

				recorder -> tail = trav;
				trav = trav -> next;

				free(trav);

				recorder -> tail -> next = NULL;
			}



			/* Providing feedback as per chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG)
			{
				printf("STAT :: After removal :: head(%p) -> next(%p) :: tail(%p) -> next(%p)\n",
					recorder->head, recorder->head->next, recorder->tail, recorder->tail->next);
			}
		}





		/* Decrementing the total number of nodes for successful operation. */

		(recorder->total)--;



		/* Providing feedback as per chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {printf("OK: Node has been successfully removed!\n");}
		else if (M==DEBUG)
		{
			printf("STAT :: Total %d nodes present in linked list.\n", recorder->total);
			printf("OK :: Node has been successfully removed!\n");
		}
	}
}