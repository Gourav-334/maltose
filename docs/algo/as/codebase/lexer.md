# DATA STRUCTURES



## 0. Before Reading


### 0.1 <u>Reference Places</u>:

- **n.1 Location:** Inspect directories in `src/`
- **n.2 Role:** Inspect algorithm & source code
- **n.3 Identifiers:** Inspect algorithm & source code
- **n.4 Working:** Inspect algorithm
- **n.5 Side-note:** Inspect algorithm

>**<u>NOTE</u>:** Some sections could be absent/null if their explanations are not applicable.


### 0.2 <u>Order Of Writing</u>:

|Sno.|File Name|Sub-Component Name|
|:-:|:-|:-|
|1|`code_cleanser.c`|Code Cleanser|
|2|`fsm_state_handler.c`|Token FSM State Handler|
|3|`token_fsmN.c`|Token FSM Part|
|4|`token_fsm_main.c`|Token FSM Main|
|5|`token_recog.c`|Token Recognizer|
|6|`token_store.c`|Token Storehouse|


### 0.3 <u>Role Explanation</u>:

For role, explain the use of particular program and also what they return (if not of type `void`).


### 0.4 <u>Identifier Groupings</u>:

|Sno|Group|Explanation Style|
|:-:|:-|:-:|
|1|Function & parameters|One-by-one|
|2|Macros|Group-wise|
|3|Structures & unions|One-by-one|
|4|Variables|Group-wise|

>**<u>NOTE</u>:** Groups for each sub-sections (*HEADER*, *SOURCE (GLOBAL)*, *SOURCE (LOCAL)*) are separated.



## 1. Code Cleanser


### 1.1 <u>Location</u>:

```sh
src/lexer/x86/code_cleanser.c
```


### 1.2 <u>Role</u>:

- `code_cleanser.c` cleanses the raw user code into simpler, more stable form for easier analysis by assembler.
- For example, some register names could be written in uppercase or lowercase, but all are converted to lowercase.


### 1.3 <u>Identifier</u>:

#### **1.3.1 HEADER**
```c
void cleanse_code(char *fstream, char *mode);
```
- `fstream` - File stream from target assembly code.
- `mode` - Programmer chosen mode for feedback.

#### **1.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **1.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
enum State{TERMN, DELI, NDELI} S;
```
- `State` - Tells what category a recently read character belongs to.
- `TERMN` - Terminator
- `DELI` - Delimiter
- `NDELI` - Non-delimeter
```c
char *charstr = NULL;
char *stack = NULL;
char *deli = " `~!@#$%^&*()-=+[{]}\\|;:\'\",<>/?\t\0";
char termn = '\n';
long int charstr_len = 1 + 1;
```
- `charstr` - 2-byte string with first character as last read character, and second byte as string terminator
- `stack` - Stores the characters in unit token that is being read
- `deli` - String containing all possible delimiters that could occur
- `termn` - Terminator character
- `charstr_len` - String length of character string


### 1.4 <u>Working</u>:

1. Check if the passed mode is valid or not.
2. Set the count of row & column as `0` & `0`.
3. Start reading the filestream.
4. If reading for the first time, set the state as per the first character.
5. If a character encountered is terminator, call token recognizer to recognize endline.
6. Else if a character encountered is delimiter & not special (`;`, `'`, `"`), keep pushing to stack until a terminator, non-delimeter or EOF occurs.
7. When terminator, non-delimeter or EOF appears, pass the stack for token recognition.
8. If recognized, good. Else pop a character the end & try again.
9. Keep trying until either it is accepted, or the stack becomes empty.
10. If stack becomes empty, display lexing error on screen.
11. Else if the character is special delimiter, depending on the character encountered, do the following.
12. If character is `;`, keep passing through the characters until EOF or endline occurs.
13. Else if character is `'` or `"`, keep pushing everything to stack until it reappears again or EOF is reached.
14. Then add a character/string node in linked list with the same data in stack.
15. After that, continue from the point of acception.
16. Else if a character encountered is non-delimiter, keep pushing to stack until a terminator, delimiter or EOF appears.
17. When a terminator, delimiter or EOF appears, pass the stack for token recognition.
18. If the end is reached but stack isn't empty, do the following as per the state.
19. For a delimiter, follow from step `6` to `15`.
20. For a non-delimiter, directly pass it to the token recognizer.


### 1.5 <u>Side-Node</u>:

- Column and row counts are critical part of the objective.



## 2. Token FSM State Handler


### 2.1 <u>Location</u>:

```sh
src/lexer/x86/fsm_state_handler.c
```


### 2.2 <u>Role</u>:

- `fsm_state_handler.c` decides what to do as per the stop/final state of the FSM.
- Returns if final state was accept state or not as `bool`.


### 2.3 <u>Identifier</u>:

#### **2.3.1 HEADER**
```c
bool handle_token_fsm_state(signed short int *state, char *str, char *mode);
```
- `state` - The stop state of the FSM.
- `str` - String tape to run through FSM.
- `mode` - Programmer chosen mode for feedback.

#### **2.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **2.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
bool func_ret = true;
```
- `func_ret` - Value of function that has to be returned.


### 2.4 <u>Working</u>:

$$ NULL $$


### 2.5 <u>Side-Node</u>:

- It also sets state back to `0`.



## 3. Token FSM Part


### 3.1 <u>Location</u>:

```sh
src/lexer/x86/token_fsm/token_fsmN.c
```


### 3.2 <u>Role</u>:

- `token_fsmN.c` is one of the many parts of single large FSM which determines the type of token.


### 3.3 <u>Identifier</u>:

#### **3.3.1 HEADER**
```c
void token_fsmN(char *str, unsigned short int start, signed short int *state);
```
- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.

#### **3.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **3.3.3 SOURCE (LOCAL)**
$$ NULL $$


### 3.4 <u>Working</u>:

1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Change state as per the read symbol (char).


### 3.5 <u>Side-Node</u>:

$$ NULL $$



## 4. Token FSM Main


### 4.1 <u>Location</u>:

```sh
src/lexer/x86/token_fsm_main.c
```


### 4.2 <u>Role</u>:

- `token_fsm_main.c` is the assembly point for `token_fsmN.c` series codes, and `fsm_state_handler.c`.
- Returns `true` if final state is an accept state.


### 4.3 <u>Identifier</u>:

#### **4.3.1 HEADER**
```c
bool token_fsm_main(char *str, unsigned short int start, char *mode);
```
- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.
- `point` - Point in line from where the message has to be called out.
- `row` - Current row in the stage.
- `column` - Current column in the stage.
- `mode` - Programmer chosen mode for feedback.

#### **4.3.2 SOURCE (GLOBAL)**

#### **4.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
str_len = strlen(str);
signed short int state = 0;
```
- `str_len` - Length of target string
- `state` - State that will change as per flow of automata


### 4.4 <u>Working</u>:

1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Until the string hasn't been read completely, or no mistake is found, keep reading each char.
3. Use the formula `state/10` to know which part of FSM to run.
4. For an invalid state, display error on screen.
5. Also displays message/diagnosis for unknown state.


### 4.5 <u>Side-Node</u>:

$$ NULL $$



## 5. Token Recognizer


### 5.1 <u>Location</u>:

```sh
src/lexer/x86/token_recog.c
```


### 5.2 <u>Role</u>:

- `token_recog.c` - Recognizes the passed token by matching through predefined possibilities.
- Returns `true` if the token matches to any of the given possibilities.


### 5.3 <u>Identifier</u>:

#### **5.3.1 HEADER**
```c
bool token_recog(char *str);
```
- `str` - The token to be checked.

#### **5.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **5.3.3 SOURCE (LOCAL)**
$$ NULL $$


### 5.4 <u>Working</u>:

1. Simply go through all the conditional statements.
2. For a matching condition, certain details need to be pushed into the record.


### 5.5 <u>Side-Node</u>:

$$ NULL $$



## 6. Token Storehouse


### 6.1 <u>Location</u>:

```sh
src/lexer/x86/token_store.c
```


### 6.2 <u>Role</u>:

- `token_store.c` works as a token storehouse and stores details about each token fetched from code.
- It makes use of multiple linked lists to stores different details about each token in same sequence.
- Meaning index of for a given token's two different details would be same in their respective linked lists.


### 6.3 <u>Identifier</u>:

#### **6.3.1 HEADER**
$$ NULL $$

#### **6.3.2 SOURCE (GLOBAL)**
```c
extern Ll_recorder token;
extern Ll_recorder categ;
extern Ll_recorder sub_categ;
extern Ll_recorder type;
```
- `token` - Stores the cleansed value of tokens.
- `categ` - Stores the category of tokens.
- `sub_categ` - Stores the sub-categories of tokens.
- `type` - Stores the type or super sub-category of a token.

#### **6.3.3 SOURCE (LOCAL)**
$$ NULL $$


### 6.4 <u>Working</u>:

$$ NULL $$


### 6.5 <u>Side-Node</u>:

$$ NULL $$

---