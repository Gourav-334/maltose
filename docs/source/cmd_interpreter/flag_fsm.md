# Flags' Finite State Machine



## 1. Description


This file defines the FSM (Finite State Machine) which interprets & suggests closest flag to substitute wrong ones that were request.



## 2. Algorithm


### 2.1 <u>Sample commands</u>:

```sh
./main src.asm -obj dest.o
./main src.asm -log -obj -deb dest.o
```


### 2.2 <u>Possible errors</u>:

- Source file doesn't exist.
- Source file has different extension.
- Destination file has different extension.
- Flag(s) don't exist.
- Flag(s) don't have `-` before their name(s).

---