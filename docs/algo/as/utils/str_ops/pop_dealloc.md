# POP DEALLOCATOR



## 1. Description


This file describes the implementation of **pop deallocator**, which deallocates/pops characters in string from the end.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
void pop_dealloc(char **str, char *mode);
```

- `str` - String passed to make operations on.
- `mode` - Programmer chosen mode for feedback.


### 2.2 <u>Steps</u>:

1. Check if a valid mode was passed to the function.
2. Check if the string passed is empty or not.
3. If empty, return error.
4. Else reallocate the string with one byte less.
5. Check if the byte was deallocated or not.
6. Set the expelled byte as `0`.

---