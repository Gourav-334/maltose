# COMMAND VALIDATOR



## 1. Description


This file records the step-by-step algorithms in implementation of nano components (functions) for **core command validator**.



## 2. Command Representation


```sh
<dec-as> <dest_file> <src_file> -<flag1> -<flag2> ... -<flagN>
```

- `<dec-as>` is variable representing assembler binary, or a direct reference to it.
- `<dest_file>` is the path & name given to destination file.
- `<src_file>` is the name & path of source file.
- `<flag1>, <flag2>`, etc, are flags passed in command.
- `...` represents possible commands written between flag `<flag2>` & `<flagN>`.



## 3. Rules Of Function


- 1st argument must be the referrence to assembler's binary file.
- 2nd argument must be the name of destination file.
- 3rd argument must be the name of source (target) file.
- Rest of the arguments (optional) are flags added to it.
- The maximum number of arguments depends directly on total flags.



## 4. Algorithm


### 4.1 <u>Function</u>:

```c
bool cmd_validator(int argc, char *argv[], char *mode);
```


### 4.2 <u>Steps</u>:

1. For just one argument, tell user to pass the source & destination.
2. For two, tell to pass destination.
3. And then check if limit is over maximum.
4. If not, check if the source path is valid or not (2nd argument).
5. If not, still continue further to know more errors.
6. Check if the destination file actually exists (3rd argument).
7. If not, still continue further to know more errors.
8. For remaining arguments, make sure they start with `-`.
9. If not, still continue further to know more errors.
10. Then match them to the registered flags to check if they are valid.
11. If matching & not duplicate (check both separately), mark the flags to be into action.
12. If not & more flags are further, still continue further to know more errors.


### 4.3 <u>Time Complexity</u>:

- **Best case -** $O(1)$ due to return at first encounter itself (if found at 0th index).
- **Average case -** $O(n.m)$ for matching each character of target string with illegal character set.
- **Worst case -** $O(n.m)$ Same reason as for the **average case**.

---
