/* Adding header(s) for unit testing. */

#include "../include/data_structs/hash_table/ht_struct.h"
#include "../include/data_structs/hash_table/ht_inserter.h"
#include "../include/data_structs/hash_table/ht_fetcher.h"
#include "../include/data_structs/hash_table/ht_dropper.h"
#include "../include/common_store.h"

#include <stdio.h>
#include <inttypes.h>



int main(int argc, char **argv)
{
	int key; int value;


	Ht_recorder my_hash = {.key_type=INTEGER, .value_type=INTEGER, .indices={0}};

	key = 1; value = 20; insert_ht_entry(&my_hash, &key, &value, "dev");
	key = 2; value = 40; insert_ht_entry(&my_hash, &key, &value, "dev");
	key = 3; value = 60; insert_ht_entry(&my_hash, &key, &value, "dev");
	key = 4; value = 80; insert_ht_entry(&my_hash, &key, &value, "dev");
	key = 5; value = 100; insert_ht_entry(&my_hash, &key, &value, "dev");
	key = 3; value = 120; insert_ht_entry(&my_hash, &key, &value, "dev");
	key = 257; value = 140; insert_ht_entry(&my_hash, &key, &value, "dev");

	key = 2; printf("KEY=%d, VALUE=%d\n", key, *(int*)fetch_ht_entry(&my_hash, &key, "dev"));
	key = 4; printf("KEY=%d, VALUE=%d\n", key, *(int*)fetch_ht_entry(&my_hash, &key, "dev"));
	key = 3; printf("KEY=%d, VALUE=%d\n", key, *(int*)fetch_ht_entry(&my_hash, &key, "dev"));

	drop_ht(&my_hash, "debug");



	return 0;
}
