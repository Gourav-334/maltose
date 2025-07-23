# NETWIDE ASSEMBLER



## 0. Description


This file is briefly structured information on the case study about one of the sidely used assembler on Linux - ***NASM (Netwide Assembler)***.



## 1. NASM (Netwide Assembler) Overview


- **NASM** is a standalone assembler written in C.
- Supports the **Intel** syntax.
- Source assembly files have extension of `.asm` or `.nasm`.
- Produced output are in form of `.o`, `.obj`, `.bin`, `.elf`, `.exe`, `.com`, etc.
- Highly portable but specific to **x86/x86_64**.
- Clear & modular design with low dependency on complex toolchains.



## 2. Core Components & Sub-Components


### 2.1 <u>Preprocessor</u>:

- Handles tags like `%macro`, `%define`, `%include`, `%ifdef`, `%assign`, etc.
- These tags might contain more tags in themselves, which are expanded recursively until none is left.
- This whole process is known as ***preprocessing***.


### 2.2 <u>Tokenizer (Lexer)</u>:

- Converts each part of a line into tokens.
- **These parts are -** Mnemonics, labels, constants, registers, operators.
- Output is stream of tokens arranged in lines.


### 2.3 <u>Parser/ Line Handler</u>:

- Detects type of mnemonic, symbol, data types used.
- Output is encoded instruction IR with symbol references.


### 2.4 <u>Symbol Table Manager</u>:

- Tracks global, local & external symbols.
- Checks for correct usage as per the definition.
- Places sections (`.text`, `.data`, etc) at right place.
- Manages relocations for unknown target.
- Output is a symbol table with fixups.

>**<u>NOTE</u>:**
> - **<u>Fixups</u>:** Placeholders (replacers) for relocations.


### 2.5 <u>Instruction Encoder</u>:

- Encoding engine is specific to **x86**/**x64**.
- Encodes the instructions as required.
- Resolves for operand's addressing mode (`modrm`/`sib`/`imm`).
- Calculates size, offsets & fixups in some cases.
- Output is raw machine code, but with unresolved symbols.


### 2.6 <u>Fixup & Relocation Generator</u>:

- Generates fixup entries for external entries, forward jumps & operands.
- Creates relocation metadata for ELF/COFF outputs.
- Output is a list of fixups that will be resolved by the linker.


### 2.7 <u>Output Writer</u>:

- Depending of the format (ELF32, ELF64, COFF, BIN, etc), writes headers, sections contents, symbol tables, relocation tables.
- Output is target specific object/binary file.



## 3. Component Interaction Flow (Linear)


$$ \fbox{Source Code} $$
$$ \downarrow $$
$$ \fbox{Preprocessor} $$
$$ \downarrow $$
$$ \fbox{Tokenizer} $$
$$ \downarrow $$
$$ \fbox{Line Parser} $$
$$ \downarrow $$
$$ \fbox{Encoder} $$
$$ \downarrow $$
$$ \fbox{Fixup Generator} $$
$$ \downarrow $$
$$ \fbox{Output Module} $$



## 4. Binary Format Modules


- NASM has separate back-end modules for each binary format.

|Module|Purpose|
|:-:|:-|
|`output/outelf.c`|ELF writer|
|`output/outbin.c`|Flat binary writer|
|`output/outcoff.c`|COFF format|
|`output/outobj.c`|MS OBJ|



## 5. Advantages & Limitations


### 5.1 <u>Advantages</u>:

- Follows conventions mentioned in CPU manual
- Easier learning curve
- Easy to generate supported format binaries
- Doesn't rely on any third-party dependency
- Low-level developers can precise control over output


### 5.2 <u>Limitations</u>:

- Single-pass assembly requiring complex techniques
- No standard linker integration
- Calling convention & relocation has to be done manually
- No footprints or traces for debugging
- Targets only x86 architecture & not ARM, RISC-V, etc



## 6. Fixups In NASM


- Consider a situation where the label is defined after it is used, as shown below.

```nasm
jmp label        ; Line 1
...
label:           ; Line 2
```

- Now when the line 1 is encountered, a dummy offset will be created for `label`.
- Then when line 2 will be encountered, the offset is immediately fixed.

---