/* Including required headers. */

#include "../../../include/data_structs/linked_list/full_remover.h"
#include "../../../include/data_structs/linked_list/remover.h"










/* Removes all nodes from the target linked list. */

void remove_all_nodes(Ll_recorder *recorder, char *mode)
{
	/* Removal loop for linked list. */

	while(recorder->total!=0)
	{
		remove_node(recorder, false, mode);
	}
}