# CODEBASE



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


### 0.3 <u>Identifier Groupings</u>:

|Group|Explanation Style|
|:-|:-:|
|Function & parameters|One-by-one|
|Variables|Group-wise|
|Structures & unions|Group-wise|
|Macros|Group-wise|

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




### 2.4 <u>Working</u>:



## 3. Command State Handler


### 3.1 <u>Location</u>:


### 3.2 <u>Role</u>:


### 3.3 <u>Identifiers</u>:


### 3.4 <u>Working</u>:



## 4. Command FSM Main


### 4.1 <u>Location</u>:


### 4.2 <u>Role</u>:


### 4.3 <u>Identifiers</u>:


### 4.4 <u>Working</u>:



## 5. Command Validator


### 5.1 <u>Location</u>:


### 5.2 <u>Role</u>:


### 5.3 <u>Identifiers</u>:


### 5.4 <u>Working</u>:

---