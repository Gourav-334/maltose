# CODE CLEANSER



## 1. Description


This file explains implementation of code cleanser, which cleanses the code into simpler form for further analysis by assembler.



## 2. Algorithm


### 2.1 <u>Functions</u>:

```c
void cleanse_code(char *fstream, char *mode);
```


### 2.2 <u>Steps</u>:

1. Check if the passed mode is valid or not.
2. Start reading the filestream byte-by-byte.
3. As per the first byte, take the default state as delimiter or non-delimiter or terminator.
4. If current state is delimiter, keep pushing until a non-delimeter, or terminator.
5. As per which of the 3 appeared, change the state & check the token in buffer if not empty before pushing.
6. Else if current state is non-delimeter, keep pushing until a delimeter or terminator.
7. As per which of the 3 appeared, change the state & check the token in buffer if not empty before pushing.
8. Else if current state is terminator, keep skipping until a delimeter or non-delimeter.
9. As per which of the 3 appeared, change the state & check the token in buffer if not empty before pushing.

---