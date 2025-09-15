# FILEPATH VALIDATOR



## 1. Description


This file records step-by-step implementation of path validator, which verifies if a path actually exists or not.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool check_path(char *path, bool exist, char *mode);
```

- `path` is the path with filename which has to be validated.
- `exist` tells if the filename (if included) currently exists.
- `mode` is passed by programmer as per their practical convenience.


### 2.2 <u>Example Paths</u>:

```sh
/obj/main.o
test/primary/main.o
../../source/filesys/main.o
```


### 2.3 <u>Algorithm</u>:

1. Check if right mode is passed in argument.
2. Check if the passed path doesn't include file's name, thus `/`.
3. If so, append a custom file name to it & assume that this file must exist in future.
4. If filename included in passed path should already exists, run a read operation.
5. For a success or failure, write feedback as per the mode.
6. Else if the filename included must exist later, run a read operation.
7. For a success or failure, write feedback as per the mode.
8. If file wasn't read, run a write operation.
9. For a success or failure, write feedback as per the mode.
10. If was a success, delete the file back.


### 2.4 <u>Time Complexity</u>:

- **Best case -** $O(1)$ due to return at first encounter itself (if found at 0th index).
- **Average case -** $O(n.m)$ for matching each character of target string with illegal character set.
- **Worst case -** $O(n.m)$ Same reason as for the **average case**.

---
