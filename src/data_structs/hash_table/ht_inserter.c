/* Including required headers. */

#include "../../../include/data_structs/hash_table/ht_struct.h"
#include "../../../include/data_structs/hash_table/ht_inserter.h"
#include "../../../include/common_store.h"

#include <stdio.h>			// To provide feedback to user as per chosen mode.
#include <string.h>			// To operate with string type keys & values.
#include <stdlib.h>			// To allocate memory for hash entries.
#include <stdbool.h>		// To use boolean type returns.










/* Inserts an entry into the hash table. */

bool insert_ht_entry(Ht_recorder *recorder, void *key, void *value, char *mode)
{
	/* Variables declarations/definitions. */

	int index;
	long int str_key_len, str_value_len;
	long int sum = 0;
	bool key_exists = true;

	char char_key, char_value;
	char *str_key=NULL, *str_value=NULL;
	short short_key, short_value;
	int int_key, int_value;
	long long_key, long_value;
	float float_key, float_value;
	double double_key, double_value;
	long double long_double_key, long_double_value;

	Ht_entry *entry = NULL;
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





	/* Detecting & casting value to its equivalent type. */

	switch (recorder->value_type)
	{
		case CHARACTER: char_value = *(char*)value; break;
		case STRING: str_value = (char*)value; str_value_len = strlen(str_value); break;
		case INTEGER: int_value = *(int*)value; break;
		case SHORT_INTEGER: short_value = *(short*)value; break;
		case LONG_INTEGER: long_value = *(long*)value; break;
		case FLOAT_POINT: float_value = *(float*)value; break;
		case DOUBLE: double_value = *(double*)value; break;
		case LONG_DOUBLE: long_double_value = *(long double*)value; break;
	}










	/* Allocating memory for the entry & providing feedback as per mode. */

	entry = malloc(sizeof(Ht_entry));


	if (entry==NULL)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Failed to allocate memory for ENTRY!\n");}
		else if (M==DEBUG) {printf("ERROR:%d :: Failed to allocate memory for ENTRY!\n", __LINE__);}

		return false;
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK:%d :: Successfully allocated memory for the ENTRY.\n", __LINE__);}
	}










	/* Allocating memory for the key. */

	switch (recorder->key_type)
	{
		case CHARACTER: entry -> key = malloc(sizeof(char)); break;
		case STRING: entry -> key = malloc(sizeof(char)*(str_key_len+1)); break;
		case SHORT_INTEGER: entry -> key = malloc(sizeof(short)); break;
		case INTEGER: entry -> key = malloc(sizeof(int)); break;
		case LONG_INTEGER: entry -> key = malloc(sizeof(long)); break;
	}





	/* Assigning keys for successful allocation. */

	if (entry->key==NULL)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Failed to allocate memory for KEY!\n");}
		else if (M==DEBUG) {printf("ERROR:%d :: Failed to allocate memory for KEY!\n", __LINE__);}

		return false;
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK:%d :: Successfully allocated memory for the KEY.\n", __LINE__);}
	}





	/* Filling key's value. */

	switch (recorder->key_type)
	{
		case CHARACTER: *(char*)(entry -> key) = char_key; break;
		case STRING: strcpy((char*)(entry -> key), str_key); break;
		case SHORT_INTEGER: *(short*)(entry -> key) = short_key; break;
		case INTEGER: *(int*)(entry -> key) = int_key; break;
		case LONG_INTEGER: *(long*)(entry -> key) = long_key; break;
	}










	/* Allocating memory for the value & filling its value. */

	switch (recorder->value_type)
	{
		case CHARACTER: entry -> value = malloc(sizeof(char)); break;
		case STRING: entry -> value = malloc(sizeof(char)*(str_value_len+1)); break;
		case SHORT_INTEGER: entry -> value = malloc(sizeof(short)); break;
		case INTEGER: entry -> value = malloc(sizeof(int)); break;
		case LONG_INTEGER: entry -> value = malloc(sizeof(long)); break;
		case FLOAT_POINT: entry -> value = malloc(sizeof(float)); break;
		case DOUBLE: entry -> value = malloc(sizeof(double)); break;
		case LONG_DOUBLE: entry -> value = malloc(sizeof(long double)); break;
	}





	/* Assigning values for successful allocation. */

	if (entry->key==NULL)
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Failed to allocate memory for VALUE!\n");}
		else if (M==DEBUG) {printf("ERROR:%d :: Failed to allocate memory for VALUE!\n", __LINE__);}

		return false;
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK:%d :: Successfully allocated memory for the VALUE.\n", __LINE__);}
	}





	/* Allocating memory for the value & filling its value. */

	switch (recorder->value_type)
	{
		case CHARACTER: *(char*)(entry -> value) = char_value; break;
		case STRING: strcpy((char*)(entry->value), str_value); break;
		case SHORT_INTEGER: *(short*)(entry -> value) = short_value; break;
		case INTEGER: *(int*)(entry -> value) = int_value; break;
		case LONG_INTEGER: *(long*)(entry -> value) = long_value; break;
		case FLOAT_POINT: *(float*)(entry -> value) = float_value; break;
		case DOUBLE: *(double*)(entry -> value) = double_value; break;
		case LONG_DOUBLE: *(long double*)(entry -> value) = long_double_value; break;
	}





	/* Pointing the next to NULL for this new entry. */

	entry -> next = NULL;










	/* Resolving index issue & collisions (if any) before inserting safely. */

	trav = recorder -> indices[index];


	if (trav==NULL)
	{
		recorder -> indices[index] = entry;
	}
	else
	{
		trav = recorder -> indices[index];


		while (trav->next!=NULL)
		{
			switch (recorder->key_type)
			{
				case CHARACTER: if(char_key==*(char*)trav->key) {key_exists = false;} break;
				case STRING: if(!strcmp(str_key,(char*)trav->key)) {key_exists = false;} break;
				case SHORT_INTEGER: if(short_key==*(short*)trav->key) {key_exists = false;} break;
				case INTEGER: if(int_key==*(int*)trav->key) {key_exists = false;} break;
				case LONG_INTEGER: if(long_key==*(long*)trav->key) {key_exists = false;} break;
			}



			/* Providing feedback as per chosen mode. */

			if (M==DEV) {}
			else if (M==USER) {}
			else if (M==DEBUG) {printf("STAT:%d :: trav(%p) :: trav->next(%p)\n", __LINE__, trav, trav->next);}

			trav = trav -> next;
		}





		/* Matching the key at last node incase a collision was faced. */

		switch (recorder->key_type)
		{
			case CHARACTER: if(char_key==*(char*)trav->key) {key_exists = false;} break;
			case STRING: if(!strcmp(str_key,(char*)trav->key)) {key_exists = false;} break;
			case SHORT_INTEGER: if(short_key==*(short*)trav->key) {key_exists = false;} break;
			case INTEGER: if(int_key==*(int*)trav->key) {key_exists = false;} break;
			case LONG_INTEGER: if(long_key==*(long*)trav->key) {key_exists = false;} break;
		}





		/* Providing feedback as per the chosen mode. */

		if (key_exists==false)
		{
			if (M==DEV) {}
			else if (M==USER) {printf("ERROR: KEY with passed value already exists!\n");}
			else if (M==DEBUG) {printf("ERROR:%d :: KEY with passed value already exists!\n", __LINE__);}

			return false;
		}



		/* Pointing the next pointer in tail entry of colliding index. */

		trav -> next = entry;
	}










	/* Providing feedback as per chosen mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG)
	{
		printf("OK:%d :: Successful insertion :: entry(%p) :: indices[%d](%p)\n",
			__LINE__, entry, index, recorder->indices[index]);
	}





	/* Returning true if whole insertion operation was successful. */

	return true;
}