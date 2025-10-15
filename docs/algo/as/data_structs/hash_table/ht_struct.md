# HASH TABLE STRUCTURE



## 1. Description


This file defines the implementation details for **hash table's structure**.



## 2. Structures


### 2.1 <u>Hash Table Recorder</u>:

```c
typedef struct Ht_recorder
{
	short int key_type;
	short int value_type;
	struct Ht_entry *indices[HT_BUCKETS];
} Ht_recorder;
```

- `HT_BUCKETS` - The number of buckets for hashing process (`256` expected).
- `indices` - Array of pointers to first hash entry at each index (\[`0`,`255`\]).


### 2.2 <u>Hash Table Entry</u>

```c
typedef struct Ht_entry
{
	void *key;
	void *value;
	struct Ht_entry *next;
} Ht_entry;
```

- `key` - Unique key for the value.
- `value` - Value for a unique key.
- `next` - Pointer to the next hash entry in same index.

---