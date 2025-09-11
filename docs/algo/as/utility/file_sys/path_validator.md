# FILEPATH VALIDATOR



## 1. Description


This file records step-by-step algorithms in implementation of path validator, which verifies if a path exists or not.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool check_path(char *path, bool exist);
```

- `path` is the path with filename which has to be validated.
- `exist` tells if the file currently exists.


### 2.2 <u>Example Paths</u>:

```sh
/obj/main.o
test/primary/main.o
../../source/filesys/main.o
```


### 2.3 <u>Algorithm</u>:

1. If filename included in passed path already exists, run a read operation.
2. For a failure, display the error.
3. Else if the filename included will exist later, run a write operation.
4. For a failure, display the error.

---
