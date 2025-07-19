# COMMUNITY STANDARDS


## **0. Introduction**

- There is nothing like strict standards.
- Based on architectural conventions & historical practices.


## **1. Instruction Set Architecture (ISA)**

- Most assembler developing teams follow ***Intel*** & ***AMD*** documentations.
- They define how the operands, opcodes & their way of execution must be.
- An assembler must be capable of generating code for each mode.
- These modes are **real mode**, **protected mode** & **long mode**.
- The availability of registers & addressing modes vary as per mode.


## **2. Assembly Language Syntax**

- Historically two main syntax styles have been used heavily, ***Intel syntax*** & ***AT&T syntax***.

### Intel syntax:
```asm
; opcode destination, source
mov rax, 4
```

### AT&T syntax:
```gas
# opcode source, destination
movq $4, %rax
```

- Read more about differences [here](https://imada.sdu.dk/u/kslarsen/dm546/Material/IntelnATT.htm).


## **3. Assembler Directives (Pseudo-ops)**

- Directives are the instructions native to assembler & not strict to the processor.
- These instructions can vary assembler to assembler with their syntaxes.


## **4. Macro**

- Similar to functions in compilers & interpreters, macros are reusable blocks of code.
- These can be recalled with parameters.
- Macros are often defined with ending & starting point.

```gas
.macro
    # Some code
.endm
```


## **5. Object File Format**

- Assemblers convert assembly code to object files.
- Object files are used for linking, creating executable or even libraries.
- These formats include ELF, COFF, Mach-O & OMF etc.
- **<u>ELF</u>:** Executable & Linkable Format, used on UNIX-like systems.
- **<u>COFF & PE</u>:** Common Object File Format & Portable Executable, common on Windows.
- **<u>Mach-O</u>:** Used particularly by MacOS.
- **<u>Object Module Format</u>:** Was used by DOS & OS/2, being obsolete.


## **6. Calling Convention**

- Logical backend working might vary platform-to-platform.
- Logical in the sense is its way of working on system components like stack, registers & memory etc.
- Though not strict, recommended for high interoperability.


## **7. Documentation & Community Practices**

- For programmers using assembly, commenting is highly encouraged to explain the processes.
- Also there is strong emphasis on consistent indentation & code layout.
- Moreover, **"standard"** is adhering to common practices in the target platform & community.

---
