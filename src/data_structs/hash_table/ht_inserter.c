/* Including required headers. */

#include "../../../include/data_structs/hash_table/ht_struct.h"
#include "../../../include/data_structs/hash_table/ht_inserter.h"
#include "../../../include/common_store.h"

#include <stdio.h>			// To provide feedback to user as per chosen mode.










/* Inserts an entry into the hash table. */

bool insert_ht_entry(Ht_recorder *recorder, void *key, void *value, char *mode)
{
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





	/* Checking if key type for this hash table is correct. */

	if (recorder->key_type>=CHARACTER && recorder->key_type<=LONG_INTEGER)
}