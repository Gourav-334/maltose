# PARSER FINITE STATE MACHINE



## 1. Description


This file records the implementation of **parser finite state machine** which parses the assembly instructions, calls binary generator components, then directs the end result to the state handler.



## 2. Algorithm


### 2.1 <u>Steps</u>:

1. Start parsing from the beginning of the linked list(s).
2. Reach a conclusion as per the transitions that occur.
3. For an instruction, store write binary or store error only when endline occurs / nodes end.

---