# FILEPATH VALIDATOR



## 1. Description


This file records step-by-step implementation of path validator, which verifies if a path actually exists or not.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool check_path(char *path, bool exist, char *mode);
```

- `path` is the path with filename which has to be validated.
- `exist` tells if the file currently exists.
- `mode` is passed by programmer as per their practical convenience.


### 2.2 <u>Example Paths</u>:

```sh
/obj/main.o
test/primary/main.o
../../source/filesys/main.o
```


### 2.3 <u>Algorithm</u>:

1. If filename included in passed path already exists, run a read operation.
2. For a failure, do the following.
3. If its dev mode, do nothing.
4. If its user mode, display the error.
5. If its debug mode, display the error.
6. For a success, do the following.
7. If its dev mode, do nothing.
8. If its user mode, display acknowledgment.
9. If its debug mode, display acknowledgment.
10. Else if the filename included will exist later, run a write operation.
11. For a failure, do the following.
12. If its dev mode, do nothing.
13. If its user mode, display the error.
14. If its debug mode, display the error.
15. For a success, do the following.
16. If its dev mode, do nothing.
17. If its user mode, display acknowledgment.
18. If its debug mode, display acknowledgment.


### 2.4 <u>Time Complexity</u>:

$$ T(n)\;=\; $$

---
