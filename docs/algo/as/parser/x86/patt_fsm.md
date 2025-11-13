# PATTERN FINDER



## 1. Description


This file records the implementation of **pattern finder**, which looks for section blocks & marks their starting & ending (for each instance) as checkpoint.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool pattern_fsm();
```


### 2.2 <u>Pattern To Find</u>:

```asm
section ( .sec_name )
{
	; Code
}
```

1. Check through FSM for the pattern shown above.
2. Mark starting and ending at **state 6 & 7** for each section.
2. For a known section encountered, detect it & add its starting and ending point to respective variable.
3. Otherwise display error for an unknown section.
4. Also there must be at least one `.text` section, if nothing else.


### 2.3 <u>State Diagram</u>:

![Pattern Finder FSM](./assets/patt_find_fsm.png)

---