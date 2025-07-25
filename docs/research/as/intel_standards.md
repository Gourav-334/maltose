# INTEL STANDARDS


## **0. Introduction**

- The standards by followed by software developers using ***Intel*** processors are set are from **Intel 64 and IA-32 Architecture Software Developer's Manual**.
- It describes how opcodes are defined, how operands are specified & behaviour of each instrruction.


## **1. Opcode Definition**

- Intel's manual shows machine code representation (in hexadecimal) for each opcode.
- It also discusses various prefixes & their effects on the behaviour of each opcode.
- These prefixes hint about how machine codes are encoded.
- Some special opcodes are there like **ModR/M** (Mode Register/Memory) & **SIB** (Scale Index Base).
- These special opcodes define what kind of operands to use with them, with correct addressing modes.
- Moreover, digit encodings are also mentioned in the manual.


## **2. Operand Specification**

- Manual describes various kind of operands which includes **registers**, **memory**, **immediate value** & **implied operands**.
- Registers can be **general-purpose**, **segment**, **special-purpose** & **floating-point**.
- Addressing modes include **direct**, **indirect**, **base-displacement**, **scaled-index** etc.
- There is limit for immediate operands, depending on other details of that instruction.
- Some of the notations used are `(r)` for read, `(w)` for right & `(r/w)` for read & write.


## **3. Instruction Behaviour**

- The operation section describes how the execution of an instruction goes step-by-step with data flow, calculations & flag modifications (`EFALGS`/`RFLAGS`).
- There are exceptions like **invalid opcode**, **general protection fault**, **page fault** etc.
- The instruction behaviour varies from one operating mode to another.
- Operating modes include **protection mode**, **real-address mode** & **virtual-8086 mode** behaviour.
- However, explanation of timing & clock cycles have been reduced in recent documentations by Intel.

---