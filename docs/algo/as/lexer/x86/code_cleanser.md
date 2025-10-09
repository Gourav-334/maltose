# CODE CLEANSER



## 1. Description


This file explains implementation of code cleanser, which cleanses the code into simpler form for further analysis by assembler.



## 2. Algorithm


### 2.1 <u>Functions</u>:

```c
void cleanse_code(char *fstream, char *mode);
```


### 2.2 <u>Steps (v2.0.0)</u>:

1. Check if the passed mode is valid or not.
2. Set the count of row & column as `0` & `0`.
3. Start reading the filestream.
4. If reading for the first time, set the state as per the first character.
5. If a character encountered is terminator, call token recognizer to recognize endline.
6. Else if a character encountered is delimiter & not special (';', '\'', '\"'), keep pushing to stack until a terminator, non-delimeter or EOF occurs.
7. When terminator, non-delimeter or EOF appears, pass the stack for token recognition.
8. If recognized, good. Else pop a character the end & try again.
9. Keep trying until either it is accepted, or the stack becomes empty.
10. If stack becomes empty, display lexing error on screen.
11. Else if the character is special delimiter, depending on the character encountered, do the following.
12. If character is ';', keep passing through the characters until EOF or endline occurs.
13. Else if character is '\'' or '\"', keep pushing everything to stack until it reappears again or EOF is reached.
14. Then add a character/string node in linked list with the same data in stack.
15. After that, continue from the point of acception.
16. Else if a character encountered is non-delimiter, keep pushing to stack until a terminator, delimiter or EOF appears.
17. When a terminator, delimiter or EOF appears, pass the stack for token recognition.
18. If the end is reached but stack isn't empty, do the following as per the state.
19. For a delimiter, follow from step `6` to `15`.
20. For a non-delimiter, directly pass it to the token recognizer.


### 2.3 <u>Cautions</u>:

- Take care of the row & column count.
- Remember to set up debug information informers everywhere.

---