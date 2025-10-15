/* Including guards to avoid multiple inclusion. */

#ifndef HT_INSERTER_H
	#define HT_INSERTER_H





/* Including required headers. */

#include "ht_struct.h"

#include <stdbool.h>		// For returning a boolean value from function.










/* Declaring functions. */

bool insert_ht_entry(Ht_recorder *recorder, void *key, void *value, char *mode);		// Inserts an entry into the hash table.










/* Closing guards. */

#endif