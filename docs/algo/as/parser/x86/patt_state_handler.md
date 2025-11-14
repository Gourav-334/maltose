# PATTERN FSM STATE HANDLER



## 1. Description

This file records the implementation of **pattern FSM state handler**, which handles the stop/end state of the **pattern finder FSM**.



## 2. Error List


### 2.1 <u>Non-Trap States</u>:

- `0`: No section found in whole code!
- `1`: Expected `(` after `section` but missing!
- `2`: Expected section name after `(` but missing!
- `3`: Expected `)` name after section name but missing!
- `4`: Expected `{` after `)` but missing!
- `5`: Expected change of line after `{` but missing!
- `6`: Expected `}` after section code but missing!



### 2.2 <u>Trap States</u>:

- `-1`: Expected `(` after `section` but something else written!
- `-2`: Expected section name after `(` but something else written!
- `-3`: Expected `)` name after section name but something else written!
- `-4`: Expected `{` after `)` but something else written!
- `-5`: Expected change of line after `{` but something else written!
- `-7`: Expected `}` after section code but something else written!



## 3. Algorithm


### 3.1 <u>Function</u>:

```c
bool handle_patt_fsm_state(
	signed short int *state,
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *subcateg_ptr, Ll_node *type_ptr,
	char *mode
);		// Decides what to do with final state of FSM.
```

---