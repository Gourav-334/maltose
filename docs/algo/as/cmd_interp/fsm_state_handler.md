# COMMAND FSM STATE HANDLER



## 1. Definition


This file describes implementation of command interpreter's **state handler**, which provides feedback & takes action as per the particular final (where machine stops) state.



## 2. Error List


### 2.1 <u>Non-Trap States</u>:

- `0` - ERROR: Flag passed can't be empty!
- `[1,2]` - ERROR: No flag named X exists! Did you meant '-deb' or '-dev'?
- `3` - OK: Flag '-deb' is now active.
- `4` - OK: Flag '-dev' is now active.
- `[5,6]` - ERROR: No flag named X exists! Did you meant '-log'?
- `7` - OK: Flag '-log' is now active.
- `[8,9]` - ERROR: No flag named X exists! Did you meant '-mod'?
- `10` - OK: Flag '-mod' is now active.
- `[11,12]` - ERROR: No flag named X exists! Did you meant '-nwr'?
- `13` - OK: Flag '-nwr' is now active.


### 2.2 <u>Dump States</u>:

- `-1` - ERROR: No flag named X exists!
- `-2` - ERROR: No flag named X exists! Did you meant '-deb'?
- `-3` - ERROR: No flag named X exists! Did you meant '-dev'?
- `-4` - ERROR: No flag named X exists! Did you meant '-log'?
- `-5` - ERROR: No flag named X exists! Did you meant '-mod'?
- `-6` - ERROR: No flag named X exists! Did you meant '-nwr'?



## 3. Algorithm


### 3.1 <u>Function</u>:

```c
bool handle_fsm_state(signed short int *state, char *flag, char *mode);
```

- `state` - The stop state of the FSM.

> **<u>NOTE</u>:**
> - Returns `true` if execution had no issue, else `false`.
> - Also sets state back to `0`.

---