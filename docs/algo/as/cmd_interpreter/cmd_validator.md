# COMMAND VALIDATOR



## 1. Description


This file records the step-by-step algorithms in implementation of nano components (functions) for **core command validator**.



## 2. Algorithms


### 2.1 <u>Command Validator</u>:

#### 2.1.1 COMMAND REPRESENTATIONS:-
```sh
<dec-as> <dest_file> <src_file> -<flag1> -<flag2> ... -<flagN>
```
- `<dec-as>` is variable representing assembler binary, or a direct reference to it.
- `<dest_file>` is the path & name given to destination file.
- `<src_file>` is the name & path of source file.
- `<flag1>, `<flag2>, etc, are flags passed in command.
- `...` represents possible commands written between flag `<flag2>` & `<flagN>`.

#### 2.1.2 RULES:-
- 1st argument must be the referrence to assembler's binary file.
- 2nd argument must be the name of destination file.
- 3rd argument must be the name of source (target) file.
- Rest of the arguments (optional) are flags added to it.
- The maximum number of arguments depends directly on total flags.

#### 2.1.3 ALGORITHM:-
1. Check if maximum number of arguments cross the limit.
2. If not, display the error but continue further to know more errors.
3. Store the absolute path to & name for destination file (2nd argument).
4. Check if the provided path is valid or not.
5. If not, display the error but continue further to know more errors.
6. Check if the destination file actually exists (3rd argument).
7. If not, display the error but continue further to know more errors.
8. For remaining arguments, make sure they start with `-`.
9. If not, display the error but continue further to know more errors.
10. Then match them to the registered flags to check if they are valid.
11. If matching, mark the flags to be into action.
12. If not & more flags are further, display error and continue further to know more errors.
13. Also mind checking for duplicacy in flags.

#### 2.1.4 NOTE:-
- Whether some error or vulnerability is found, or something is error-free to pass, acknowledgment is compulsory.
- This nano component leads to the requirement of two file system utility components, namely **new path validator** & **request point locator**.

---
