# OBJECT FILES V/S EXECUTABLES


## **1. Object Files**

- Object files are immediate representation, not the final binary output.
- Contains data & variables but not loaded into memory yet, which can be relocated if issue in loading.
- Contains symbol table which has all information about the variables & data elements being used.
- It also contains relocation information that might be required by linker to resolve conflicting names across imported libraries.
- The objects files only are the input to the linker.


## **2. Executables**

- Executables are the final binary product are assembling & linking. This binary file is run by loader (part of OS).
- Also the symbolic references resolved by linker now have their absolute addresses. Thus it no more has any relocation information.
- It contains the memory address from where the program will execute.
- Complete program with everything in it, though it might rely on external static or dynamic libraries.

---
