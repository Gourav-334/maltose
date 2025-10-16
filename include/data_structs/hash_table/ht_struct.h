/* Including guards to avoid multiple inclusions. */

#ifndef HT_STRUCT_H
	#define HT_STRUCT_H

#define HT_BUCKETS 256










/* Declaring structures. */

typedef struct Ht_entry			// Represents a single entry in the hash table.
{
	void *key;					// Pointer to key of a particular entry.
	void *value;				// Pointer to value of a particular entry.
	struct Ht_entry *next;		// Pointer to next entry in index (if any).
} Ht_entry;





typedef struct Ht_recorder				// Records everything about the hash table.
{
	short int key_type;					// Numeric representation of key type.
	short int value_type;				// Numeric representation of value type.
	Ht_entry *indices[HT_BUCKETS];		// Array of pointers to first entry of each index.
} Ht_recorder;










/* Closing guard macros. */

#endif