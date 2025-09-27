# TOKEN FSM STATE HANDLER



## 1. Definition


This file describes implementation of unknown token's **state handler**, which provides feedback & takes action as per the particular final (where machine stops) state.



## 2. Error List


### 2.1 <u>Non-Trap States</u>:

- `0` - ERROR: Token passed can't be empty!
- `1` - ERROR: Sign without a value!
- `[2,3]` - OK: Decimal value detected.
- `4` - OK: Binary value detected.
- `5` - OK: Decimal value detected.
- `6` - OK: Octal value detected.
- `7` - OK: Decimal value detected.
- `8` - ERROR: Float without fraction part passed!
- `9` - OK: Float value detected.
- `10` - ERROR: Incomplete hex value!
- `11` - OK: Hex value detected.
- `12` - ERROR: Incomplete hex value!
- `13` - OK: Hex value detected.
- `14` - OK: An identifier detected.


### 2.2 <u>Dump States</u>:

- `-3` - ERROR: Unwanted character in possibly binary value!
- `-4` - ERROR: Unwanted character in possibly binary value!
- `-5` - ERROR: Unwanted character in possibly octal value!
- `-6` - ERROR: Unwanted character in possibly octal value!
- `-7` - ERROR: Unwanted character in possibly decimal value!
- `-8` - ERROR: Unwanted character in possibly float value!
- `-9` - ERROR: Unwanted character in possibly float value!
- `-10` - ERROR: Unwanted character in possibly hex value!
- `-11` - ERROR: Unwanted character in possibly hex value!
- `-13` - ERROR: Unwanted character in possibly hex value!



## 3. Algorithm


### 3.1 <u>Function</u>:

```c
bool handle_token_fsm_state(signed short int *state, char *str, char *mode);
```

- `state` - The stop state of the FSM.

> **<u>NOTE</u>:**
> - Returns `true` if execution had no issue, else `false`.
> - Also sets state back to `0`.

---