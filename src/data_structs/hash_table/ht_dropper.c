/* Including required headers. */

#include "../../../include/data_structs/hash_table/ht_struct.h"
#include "../../../include/data_structs/hash_table/ht_dropper.h"

#include <stdio.h>			// To provide feedback as per chosen mode.
#include <string.h>			// To compare the passed mode of feedback.
#include <stdlib.h>			// To free memory occupied by entries.










/* Drops whole hash table, but retaining blueprint. */

void drop_ht(Ht_recorder *recorder, char *mode)
{
	/* Variables definitions/declarations. */

	Ht_entry *trav = NULL;
	Ht_entry *next = NULL;



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










	/* Entries removal loop. */

	for (int i=0; i<HT_BUCKETS; i++)
	{
		/* If the current index doesn't contain any entry. */

		if (recorder->indices[i]==NULL)
		{
			/* Providing feedback as per chosen mode. */

			if (M==DEV) {}
			else if (M==DEV) {}
			else if (M==DEBUG) {printf("STAT:%d :: indices[%d](%p)\n", __LINE__, i, recorder->indices[i]);}

			continue;
		}





		/* Else if the current index contains atleast 1 entry. */

		else
		{
			trav = recorder -> indices[i];


			while (trav!=NULL)
			{
				next = trav -> next;


				/* Providing feedback as per chosen mode. */

				if (M==DEV) {}
				else if (M==DEV) {}
				else if (M==DEBUG) {printf("STAT:%d :: trav(%p) :: next(%p)\n", __LINE__, trav, next);}


				free(trav);
				trav = next;
			}
		}
	}





	/* Providing feedback as per chosen mode. */

	if (M==DEV) {}
	else if (M==DEV) {printf("STAT: Hash table successfully dropped!\n");}
	else if (M==DEBUG) {printf("STAT:%d :: Hash table successfully dropped!\n", __LINE__);}
}