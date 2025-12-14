# PARSER FINITE STATE MACHINE



## 1. Description


This file records the implementation of **parser finite state machine** which parses the assembly instructions, calls binary generator components, then directs the end result to the state handler.



## 2. Algorithm


### 2.1 <u>Steps</u>:

1. Start parsing from the beginning of the linked list(s).
2. Reach a conclusion as per the transitions that occur.
3. For an instruction, store write binary or store error only when endline occurs / nodes end.



## 3. Side Notes


### 3.1 <u>Parts Of ELF Object</u>:

- ELF header
- Section header
- Section data
- String tables


### 3.2 <u>GNU Section Ordering</u>:

- `NULL` (index `0`)
- `.text`
- `.rela.text`
- `.data`
- `.bss`
- `.rodata`
- `.symtab`
- `.strtab`
- `.shstrtab`
- `.comment`
- `.note.GNU-stack`
- `.debug_*` (index `11`)


### 3.3 <u>Parsing Verification Checks</u>:

1. **Correctness**
2. **Availability**
3. **Position**
4. **Legality**

---