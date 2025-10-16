/* Adding header(s) for unit testing. */

#include "../include/data_structs/hash_table/ht_struct.h"
#include "../include/data_structs/hash_table/ht_inserter.h"
#include "../include/common_store.h"

#include <stdio.h>
#include <inttypes.h>



int main(int argc, char **argv)
{
	int key; long int value;


	Ht_recorder my_hash = {.key_type=INTEGER, .value_type=LONG_INTEGER, .indices = {0}};

	key = 1; value = 20; insert_ht_entry(&my_hash, &key, &value, "debug");
	key = 2; value = 40; insert_ht_entry(&my_hash, &key, &value, "debug");
	key = 3; value = 60; insert_ht_entry(&my_hash, &key, &value, "debug");
	key = 4; value = 80; insert_ht_entry(&my_hash, &key, &value, "debug");
	key = 5; value = 100; insert_ht_entry(&my_hash, &key, &value, "debug");
	key = 3; value = 120; insert_ht_entry(&my_hash, &key, &value, "debug");
	key = 515; value = 140; insert_ht_entry(&my_hash, &key, &value, "debug");



	return 0;
}
