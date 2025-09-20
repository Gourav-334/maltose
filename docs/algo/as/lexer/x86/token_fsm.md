# TOKEN FINITE STATE MACHINE



## 1. Description


This file documents implementation for FSM of tokenizer, which categorizes & sub-caterizes tokens into various types. These may also be represented in form of **regular expression** for clearer understanding.



## 2. Representation


### 2.1 <u>Token List</u>:

|Token|Name|Category|Sub-Category|Usage|
|:-:|:-|:-|:-|:-|
|`section`|Section|Block|Section|Defining a block dedicated to a section.|
|`(`|Bracket Opening|Bracket|Opening|Opening a bracket to write something within.|
|`.`|Name Referrer|Dot/Period|-|Referring to a unreserved yet specially available name.|
|`)`|Bracket Closing|Bracket|Closing|CLosing a bracket after writing something within.|


### 2.2 <u>State Diagram</u>:

![State Diagram](./assets/token_fsm1.png)



## 3. Function Declarations


### 3.1 <u>Central Function</u>:

```c
bool token_fsm_main(char *str, unsigned short int start, char *mode);
```

- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.


### 3.2 <u>Part Function</u>:

```c
void token_fsmN(char *str, unsigned short int start, signed short int *state);
```

- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.



## 4. Algorithm


### 4.1 <u>Steps (Central FSM)</u>:

1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Until the string hasn't been read completely, or no mistake is found, keep reading each char.
3. Use the formula `state/10` to know which part of FSM to run.
4. For an invalid state, display error on screen.
5. Also displays message/diagnosis for unknown state.


### 4.2 <u>Steps (Part of FSM)</u>:

1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Change state as per the read symbol (char).



## 5. Details

- All parts of FSM are assembled at central FSM assembly point.
- Central assembler runs on endless loop & switch-cases within which tell which part of FSM to jump in.
- Initially, machine starts with 0th index of string & state `0`.
- The central FSM handler uses formula `state/10` to get the case for next iteration.
- Central FSM stores the global details like state.

---