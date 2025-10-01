/* Including required headers. */

#include "../../../include/data_structs/linked_list/ll_struct.h"
#include "../../../include/data_structs/linked_list/displayer.h"

#include <stdio.h>		// To display node information on terminal.










/* Displays all nodes of linked list in linear fashion. */

void display_nodes(Ll_recorder *recorder)
{
	/* Variable declarations/definitions. */

	Ll_node *trav = NULL;





	/* Checking if linked list actually has nodes or is empty. */

	if (recorder->total==0) {printf("STAT: The linked list is empty.\n");}
	else
	{
		/* Pointing traverser toward the head of linked list. */

		trav = recorder -> head;



		/* Node display loop. */

		while (trav->next!=NULL)
		{
			printf("STAT: data=\"%s\", trav(%p), next(%p)\n", trav->data, trav, trav->next);
			trav = trav -> next;
		}



		/* Displaying the last node, left after conditional termination from loop. */

		printf("STAT: data=\"%s\", trav(%p), next(%p)\n", trav->data, trav, trav->next);
	}
}