# CODE CLEANSER



## 1. Description


This file explains implementation of code cleanser, which cleanses the code into simpler form for further analysis by assembler.



## 2. Algorithm


### 2.1 <u>Functions</u>:

```c
void cleanse(char *fstream, char *mode);
```


### 2.2 <u>Steps</u>:

1. Start reading the filestream byte-by-byte.
2. As per the first byte, take the default state as delimiter or non-delimiter or skipper.
3. If current state is delimiter, keep pushing until a non-delimeter, skipper or EOF appears.
4. As per which of the 3 appeared, change the state & check the token in buffer if not empty.
5. Else if current state is non-delimeter, keep pushing until a delimeter, skipper or EOF appears.
6. As per which of the 3 appeared, change the state & check the token in buffer if not empty.
7. Else if current state is skipper, keep skipping until a delimeter, non-delimeter or EOF appears.
8. As per which of the 3 appeared, change the state & check the token in buffer if not empty.
9. Else if EOF was encountered, halt the process.


### 2.3 <u>Time Complexity</u>:

- **Best case -** $O(1)$ due to only one byte being present for best case scenario.
- **Average case -** $O(n)$ for $n$ bytes being there (unknown quanitity).
- **Worst case -** $O(n)$ Same reason as for the **average case**.

---