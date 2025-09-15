# PUSH ALLOCATER



## 1. Description


This file records the step-by-step implementation of the push allocator, which safely pushes characters to string dynamically.



## 2. Implementation


### 2.1 <u>Function</u>:

```c
void push_alloc(char *str, char c, char *mode);
```

- `str` is the string on which operation has to be done.
- `c` is the character we want to append at the end of the string.
- `mode` allows programmer to choose convenient practical mode for them.


### 2.2 <u>Algorithm</u>:

1. Check which mode is being used.
2. For a valid mode, assign the correct enumeration value.
3. And for an invalid mode passed, return from the function with error.
4. Check if the character pointer (string) is pointing to NULL.
5. If pointing, allocate 1 byte of empty memory & set string length to 1.
6. Provide feedback as per the mode.
7. Check for possible error during allocation of memory.
8. Then provide feedback as per the mode.
9. Reallocate 1 byte of memory to string, assign 2nd last byte the target character & last one as NULL terminator.
10. Then again provide feedback as per the mode.


### 2.3 <u>Time Complexity</u>:

- **Best case -** $O(1)$ if the string is empty & thus `strlen()` isn't used.
- **Average case -** $O(n)$ for most cases where a character is added to existing string.
- **Worst case -** $O(n)$ Same reason as for the **average case**.

---
