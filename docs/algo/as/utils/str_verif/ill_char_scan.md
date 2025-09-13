# ILLEGAL CHARACTER SCANNER



## 1. Description


This file records the step-by-step implementation of the illegal character scanner, which checks if there is presence of any unwanted character in a given string.



## 2. Implementation


### 2.1 <u>Function</u>:

```c
bool scan_ill_chars(char *str, long int len, char *ill_chars, char *mode);
```

- `str` is the string that programmer is passing for scanning.
- `len` is the length of the target string, passed for memory security reasons.
- `mode` allows programmer to choose convenient practical mode for them.


### 2.2 <u>Algorithm</u>:

0. Check if the mode passed doesn't exist, continue only if valid.
1. Start scanning from first character of the string.
2. Keep scanning each character linearly until the end.
3. Whenever a legal character is found, do the following.
4. For dev mode, do nothing.
5. For user mode, do nothing.
6. For debug mode, acknowledge the correctness of character.
7. Whenever an illegal character is found, do the following.
8. For dev mode, simply return true & break from function.
9. For user mode, push the illegal character into trash.
10. For debug mode, point it out on a line.
11. When scanning of all characters is complete, do the following.
12. For dev mode, return false if no illegal character was encountered.
13. For user mode, if there were illegal characters found, display them.
14. For debug mode, tell the total number of illegal characters found.


### 2.3 <u>Time Complexity</u>:

- **Best case -** $O(1)$ due to return at first encounter itself (if found at 0th index).
- **Average case -** $O(n.m)$ for matching each character of target string with illegal character set.
- **Worst case -** $O(n.m)$ Same reason as for the **average case**.

---
