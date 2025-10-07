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
4. If current state is delimiter, keep pushing until a non-delimeter, or terminator appears.
5. As per which of the 3 appeared to break flow, change the state.
6. Else if current state is non-delimeter, keep pushing until a delimeter or terminator appears.
7. As per which of the 3 appeared, change the state & check the token in buffer if not empty before pushing.
8. Else if current state is terminator, keep skipping until a delimeter or non-delimeter appears.
9. As per which of the 3 appeared, change the state & check the token in buffer if not empty before pushing.


### 2.3 <u>Steps (Addition)</u>:

1. Pass the delimeter token in buffer to FSM if not empty before pushing.
2. Until the token isn't accepted by FSM or the buffer doesn't become empty, keep popping characters from end.
3. Move the filestream pointer back to the place after the last accepted/rejected token.
4. When the loop is on final iteration, check for the token verification & continue loop if required.

---