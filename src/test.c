/* Adding header(s) for unit testing. */

#include "../include/parser/x86/label_store.h"
#include "../include/data_structs/hash_table/ht_struct.h"
#include "../include/data_structs/hash_table/ht_inserter.h"
#include "../include/data_structs/hash_table/ht_fetcher.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	char *key="my_tbl", *value="array", *findit="my_bl";

	insert_ht_entry(&labels, key, value, "dev");

	if (fetch_ht_entry(&labels, findit, "dev")==NULL) {printf("STAT: It's NULL.\n");}
	else {printf("STAT: It exists.\n");}


	return 0;
}