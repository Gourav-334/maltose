# HASH TABLE ENTRY FETCHER



## 1. Description


This file records the implementation for **hash table entry fetcher**, which fetches an entry as per the provides value.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
void *fetch_ht_entry(Ht_recorder *recorder, void *key, char *mode);
```

- `recorder` - Pointer to the recorder of whole hash table.
- `key` - Key of the entry to access.
- `mode` - Chosen mode for feedback by the programmer.
- Returns memory address of the value if found, else `NULL`.


### 2.2 <u>Steps</u>:

1. Check if a correct feedback mode was passed.
2. If key is of string type, sum each of its character & apply the formula `index = sum % bucket`.
3. Else for any other type of key, apply the formula directly `index = key % bucket`.
4. Access the index as per the value obtained for `index`.
5. If there is no entry at that index, return `NULL`.
6. Else if there exist entries(s), keep travelling through them until either value is found, or entries run out.
7. If an entry was found, return its address.
8. Else if none was found, return `NULL`.

---