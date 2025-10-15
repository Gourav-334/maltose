# HASH TABLE ENTRY INSERTER



## 1. Description


This file describes the implementation details for the **hash table entry inserter**.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool insert_ht_entry(Ht_recorder *recorder, void *key, void *value, char *mode);
```

- `recorder` - Pointer to the recorder instance that contains all hash table information.
- `key` - The key for a hash table entry.
- `value` - The value for a hash table entry.


### 2.2 <u>Steps</u>:

1. Check if a correct feedback mode was passed.
2. Check if the recorder represents the right key & value types.
3. As per the key & value types, perform casting & do the following.
4. For string apply the formula `value % buckets` for each character.
5. And for rest of the data types, apply a single `value % buckets` for the whole value.
6. Know the insertion index for the applied formula.
7. Check if the pointer at index is `NULL` or not.
8. If `NULL`, Allocate the memory for the hash entry structure & fill all the data.
9. Else keep going to next connected entry until there is none left.
10. After reaching that point (last node), allocate a new hash entry & assign to this node's next pointer.
11. Then allocate the memory for the new entry & fill all the details.
12. Now if everything goes fine, return a boolean `true` value.

---