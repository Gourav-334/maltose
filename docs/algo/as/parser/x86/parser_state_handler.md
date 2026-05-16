# PATTERN FSM STATE HANDLER



## 1. Description

This file records the implementation of **parser FSM state handler**, which handles the stop/end state of the **parser FSM**.



## 2. Error List


### 2.1 <u>Non-Trap States</u>:

- `0`: ?



### 2.2 <u>Trap States</u>:

- `-1`: ?



## 3. Algorithm


### 3.1 <u>Function</u>:

```c
bool handle_parser_fsm_state(
	signed short int *state,
	Ll_node *token_ptr, Ll_node *categ_ptr, Ll_node *subcateg_ptr, Ll_node *type_ptr,
	char *mode
);		// Decides what to do with final state of FSM.
```

---