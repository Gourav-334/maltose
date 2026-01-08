# CODEBASE



## 1. Flag Status Storehouse


### 1.1 <u>Location</u>:

```sh
cmd_interp/flag_status.c
```


### 1.2 <u>Role</u>:

- `flag_status.c` stores instances of structures, each representing a flag.
- These flags are same flags which were added by user in command to assembler.


### 1.3 <u>Identifiers</u>:

```c
struct Flag {
	char *subtype;
	bool status;
};
```
- `subtype` - Sometimes a flag might have a subtype, stored here.
- `status` - Tells if the flag was requested or not.


### 1.4 <u>Working</u>:



## 2. Command FSM Parts


### 2.1 <u>Location</u>:

```sh
cmd_interp/cmd_fsm/cmd_fsmN.c
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