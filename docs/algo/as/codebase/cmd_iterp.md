# COMMAND INTERPRETER MANUAL



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
|1|`flag_status.c`|Flag Status Storehouse|
|2|`cmd_fsmN.c`|Command FSM Parts|
|3|`fsm_state_handler.c`|Command State Handler|
|4|`cmd_fsm_main.c`|Command FSM Main|
|5|`cmd_valid.c`|Command Validator|


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



## 1. Flag Status Storehouse


### 1.1 <u>Location</u>:

```sh
src/cmd_interp/flag_status.c
```


### 1.2 <u>Role</u>:

- `flag_status.c` stores instances of structures, each representing a flag.
- These flags are same flags which were added by user in command to assembler.


### 1.3 <u>Identifiers</u>:

#### **1.3.1 HEADER**
```c
struct Flag {
	char *subtype;
	bool status;
};
```
- `Flag` - Structure containing details about the particular flag.
- `subtype` - Sometimes a flag might have a subtype, stored here.
- `status` - Tells if the flag was requested or not.

#### **1.3.2 SOURCE (GLOBAL)**
```c
struct Flag flag_deb = {.subtype=NULL, .status=false};
struct Flag flag_dev = {.subtype=NULL, .status=false};
struct Flag flag_log = {.subtype=NULL, .status=false};
struct Flag flag_mod = {.subtype=NULL, .status=false};
struct Flag flag_nwr = {.subtype=NULL, .status=false};
struct Flag flag_help = {.subtype=NULL, .status=false};
```
- `flag_deb` - Structure instance containing details about **debugging flag**.
- `flag_dev` - Structure instance containing details about **developer flag**.
- `flag_log` - Structure instance containing details about **log flag**.
- `flag_mod` - Structure instance containing details about **mode flag**.
- `flag_nwr` - Structure instance containing details about **no warning flag**.
- `flag_help` - Structure instance containing details about **help flag**.

#### **1.3.3 SOURCE (LOCAL)**
$$ NULL $$


### 1.4 <u>Working</u>:

$$ NULL $$


### 1.5 <u>Side-Note</u>:

$$ NULL $$



## 2. Command FSM Parts


### 2.1 <u>Location</u>:

```sh
src/cmd_interp/cmd_fsm/cmd_fsmN.c
```

- `N` is a whole number.


### 2.2 <u>Role</u>:

- `cmd_fsmN.c` are parts of unit FSM designed to process user's commands to assembler.
- Its work is limited to processing the command to an end state, and not declare its validity.


### 2.3 <u>Identifiers</u>:

#### **2.3.1 HEADER**
```c
void cmd_fsmN(char *str, unsigned short int start, signed short int *state);
```
- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.

#### **2.3.2 SOURCE (LOCAL)**
$$ NULL $$

#### **2.3.3 SOURCE (LOCAL)**
$$ NULL $$


### 2.4 <u>Working</u>:
1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Change state as per the read symbol (`char`).


### 1.5 <u>Side-Note</u>:

$$ NULL $$



## 3. Command State Handler


### 3.1 <u>Location</u>:

```sh
src/cmd_interp/fsm_state_handler.c
```


### 3.2 <u>Role</u>:

- `fsm_state_handler.c` contains switch-cases where cases are chosen as per the end state of the command FSM.
- This comes into play only after the FSM syntax tape has ended.
- Command state handler may or may not redirect the flow of program to somewhere else.
- Returns `true` if final state was an accept state, `false` otherwise.


### 3.3 <u>Identifiers</u>:

#### **3.3.1 HEADER**
```c
bool handle_fsm_state(signed short int *state, char *flag, char *mode);
```
- `state` - The stop state of the FSM.
- `flag` - Flag passed by user to assembler, and being processed by FSM.
- `mode` - Mode chosen by programmer for functions to run on.

#### **3.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **3.3.3 SOURCE (LOCAL)**
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
- `func_ret` - Tells if the FSM's end state is accept state or not.


### 3.4 <u>Working</u>:

$$ NULL $$


### 3.5 <u>Side-Note</u>:

- Positive state values represent working FSM states.
- Negative state values represent dump states.



## 4. Command FSM Main


### 4.1 <u>Location</u>:

```c
src/cmd_interp/cmd_fsm_main.c
```


### 4.2 <u>Role</u>:

- `cmd_fsm_main.c` is the assembly point for all parts of command FSMs represented as `cmd_fsmN.c` series.
- Also it assembles the FSM state handler, placed below the string verifier through FSM.


### 4.3 <u>Identifiers</u>:

#### **4.3.1 HEADER**
```c
bool cmd_fsm_main(char *str, unsigned short int start, char *mode);
```
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.

#### **4.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **4.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
long int str_len = strlen(str);
signed short int state = 0;
```
- `str_len` - Length of string tape passed to FSM.
- `state` - Global state variable passed to all FSM parts.


### 4.4 <u>Working</u>:

$$ NULL $$


### 4.5 <u>Side-Note</u>:

- Contains the global state information in **source (local)** which influences each FSM parts by being passed to them.



## 5. Command Validator


### 5.1 <u>Location</u>:

```c
src/cmd_interp/cmd_valid.c
```


### 5.2 <u>Role</u>:

- `cmd_valid.c` defines the rules for passing arguments to the assembler, in following form.
```sh
<dec-as> <dest_file> <src_file> -<flag1> -<flag2> ... -<flagN>
```
- Returns `true` if commands to assembler follow rules correctly, `false` if rules are broken.


### 5.3 <u>Identifiers</u>:

#### **5.3.1 HEADER**
```c
bool cmd_validator(int argc, char *argv[], char *mode);
```
- `argc` - Count of arguments passed to assembler.
- `argv` - Array of arguments passed to assembler as strings.
- `mode` - Mode chosen by programmer for functions to run on.

#### **5.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **5.3.3 SOURCE (LOCAL)**
```c
bool func_ret = true;
```
- `func_ret` - Tells if rules of command to assembler were broken.


### 5.4 <u>Working</u>:

1. For just one argument, tell user to pass the source & destination.
2. For two, tell to pass destination.
3. And then check if limit is over maximum.
4. If not, check if the source path is valid or not (2nd argument).
5. If not, still continue further to know more errors.
6. Check if the destination file actually exists (3rd argument).
7. If not, still continue further to know more errors.
8. For remaining arguments, make sure they start with -.
9. If not, still continue further to know more errors.
10. Then match them to the registered flags to check if they are valid.
11. If matching & not duplicate (check both separately), mark the flags to be into action.
12. If not & more flags are further, still continue further to know more errors.


### 5.5 <u>Side-Note</u>:

- This program (`cmd_valid.c`) is assembly point for rest of the command interpreter components.

---