# HASH TABLE DROPPER



## 1. Description


This file describes the implementation of **hash table dropper**, which erases whole hash table from the memory, except its blueprint.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
void drop_ht(Ht_recorder *recorder, char *mode);
```

- `recorder` - Pointer to target hash table recorder.
- `mode` - Feedback mode chosen by the programmer.


### 2.2 <u>Steps</u>:

0. Check if a correct feedback mode was chosen.
1. Start from the first index.
2. If null, skip.
3. Else, point to the first entry.
4. Save its next address & erase it.
5. Then move to next entry.
6. Keep doing this until all the nodes from this entry is erased.
7. Then move to next index & repeat the same.
8. Keep doing this until all the indices have been cleaned.

---