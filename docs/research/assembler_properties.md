# ASSEMBLER PROPERTIES


## **1. Properties Of An Assembler**

1. Assembly to machine code translation
2. One-to-one mapping with machine codes (mostly)
3. Handling labels & memory locations
4. Support for directives/psudo-ops
5. Representing operands in machine code
6. Error detection & reporting (optional)
7. Generation of object files
8. Preprocessing of macros (optional)
9. Support for conditional macros


## **2. Mistaken Properties Of Assembler**

- Linker is used for linking multiple object files & resolving memory addresses, not assembler.
- Debugger is responsible for inspecting codes for debugging purpose, not assembler.
- Compiler compiles high-level languages into assembly code or machine code, while assemblers convert assembly code to machine code.
- Though assemblers are specific to processor architectures, they do interact with operating system heavily.
- Assemblers are responsible for accurate instruction translation, while optimization is done by compilers.
- Multi-platform assemblers require compilation on each platform, which is the **"portable"** part, but the generated binaries are specific to platform.
- Assemblers work at a very low-level where memory has to be managed manually, meaning **"no garbage collection"**.


## **3. Not Properties Of Assemblers**

1. Executing machine code (processor does)
2. Direct use of **Graphical User Interface**
3. Direct network communication
4. Complex file system operations

---