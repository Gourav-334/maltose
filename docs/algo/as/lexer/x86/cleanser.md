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
2. Keep pushing characters into a buffer until a delimeter appears or file ends.
3. If a delimeter appears or file ends & the buffer is not empty, check the token with FSM.
4. If token is written correctly, push it to token stack with metadata & empty the buffer.
5. Else if the token if found in incorrect form, display error on screen.
6. After the file reaches its end, end the process.


### 2.3 <u>Time Complexity</u>:

- **Best case -** $O(1)$ due to only one byte being present for best case scenario.
- **Average case -** $O(n)$ for $n$ bytes being there (unknown quanitity).
- **Worst case -** $O(n)$ Same reason as for the **average case**.

---