/* Including required headers. */

#include "../../../include/data_structs/hash_table/ht_struct.h"
#include "../../../include/data_structs/hash_table/ht_fetcher.h"
#include "../../../include/common_store.h"

#include <stdio.h>			// To provide feedback as per chosen mode.
#include <stdbool.h>		// To use boolean type variables.
#include <string.h>			// To operate on string type variables/constants.










/* Fetches an entry from hash table. */

void *fetch_ht_entry(Ht_recorder *recorder, void *key, char *mode)
{
	/* Variables declarations/definitions. */

	int index;
	long int str_key_len;
	long int sum = 0;
	bool key_exists = true;

	char char_key;
	char *str_key=NULL;
	short short_key;
	int int_key;
	long long_key;
	float float_key;
	double double_key;
	long double long_double_key;

	Ht_entry *trav = NULL;



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
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK:%d :: Known data type code %d used for KEY.\n", __LINE__, recorder->key_type);}
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Unknown data type code %d used for KEY!\n", recorder->key_type);}
		else if (M==DEBUG) {printf("ERROR:%d :: Unknown data type code %d used for KEY!\n", __LINE__, recorder->key_type);}

		return false;
	}



	/* Checking if value type for this hash table is correct. */

	if (recorder->value_type>=CHARACTER && recorder->value_type<=LONG_DOUBLE)
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK:%d :: Known data type code %d used for VALUE.\n", __LINE__, recorder->value_type);}
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Unknown data type code %d used for VALUE!\n", recorder->value_type);}
		else if (M==DEBUG) {printf("ERROR:%d :: Unknown data type code %d used for VALUE!\n", __LINE__, recorder->value_type);}
		
		return false;
	}










	/* Applying hashing algorithm formula. */

	if (recorder->key_type==STRING)
	{
		/* Defining/declaring required variables for hashing a string. */

		str_key = (char*)key;
		str_key_len = strlen(str_key);



		/* The hashing loop (if a string key). */

		for (int i=0; i<str_key_len; i++)
		{
			sum += *(str_key + i);


			/* Providing feedback as chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG)
			{
				printf("STAT :: str_key=\"%s\" :: str_key[%d]=%d :: sum=%ld\n", str_key, i, *(str_key + i), sum);
			}
		}


		/* Hashing (Index = Sum % Total buckets) */

		index = sum % HT_BUCKETS;
	}
	else
	{
		/* Detecting & casting key to its equivalent type. */

		switch (recorder->key_type)
		{
			case CHARACTER: char_key = *(char*)key; index = char_key % HT_BUCKETS; break;
			case INTEGER: int_key = *(int*)key; index = int_key % HT_BUCKETS; break;
			case SHORT_INTEGER: short_key = *(short*)key; index = short_key % HT_BUCKETS; break;
			case LONG_INTEGER: long_key = *(long*)key; index = long_key % HT_BUCKETS; break;
		}



		/* Providing feedback as chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("STAT:%d :: index=%d :: HT_BUCKETS=%d\n", __LINE__, index, HT_BUCKETS);}
	}










	/* Searching for the entry from index. */

	if (recorder->indices[index]==NULL)
	{
		/* Providing feedback as chosen mode. */

		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: No KEY with passed value doesn\'t exists!\n");}
		else if (M==DEBUG) {printf("ERROR:%d :: No KEY with passed value doesn\'t exists!\n", __LINE__);}

		return NULL;
	}
	else
	{
		trav = recorder -> indices[index];


		switch (recorder->key_type)
		{
			case CHARACTER:

				while (!(trav->next==NULL || *(char*)trav->key==char_key))
				{
					trav = trav -> next;
				}

				if (*(char*)trav->key!=char_key) {key_exists = false;}


				break;



			case STRING:

				while (!(trav->next==NULL || !strcmp((char*)trav->key, str_key)))
				{
					trav = trav -> next;
				}

				if (strcmp((char*)trav->key, str_key)) {key_exists = false;}


				break;



			case SHORT_INTEGER:

				while (!(trav->next==NULL || *(short*)trav->key==short_key))
				{
					trav = trav -> next;
				}

				if (*(short*)trav->key!=short_key) {key_exists = false;}


				break;



			case INTEGER:

				while (!(trav->next==NULL || *(int*)trav->key==int_key))
				{
					trav = trav -> next;
				}

				if (*(int*)trav->key!=int_key) {key_exists = false;}


				break;



			case LONG_INTEGER:

				while (!(trav->next==NULL || *(long*)trav->key==long_key))
				{
					trav = trav -> next;
				}

				if (*(long*)trav->key!=long_key) {key_exists = false;}


				break;
		}





		/* Checking if entry was found or not. */

		if (key_exists==false)
		{
			/* Providing feedback as chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {printf("ERROR: No KEY with passed value doesn\'t exists!\n");}
			else if (M==DEBUG) {printf("ERROR:%d :: No KEY with passed value doesn\'t exists!\n", __LINE__);}

			return NULL;
		}
		else if (key_exists==true)
		{
			/* Providing feedback as chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {printf("OK: KEY with passed value exists.\n");}
			else if (M==DEBUG) {printf("OK:%d :: KEY exists :: trav(%p) :: next(%p)\n", __LINE__, trav, trav->next);}

			return trav->value;
		}
	}
}