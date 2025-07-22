# GNU ASSEMBLER



## 0. Description


This file is briefly structured information on the case study performed on one of most popular assembler - ***GNU "GAS" Assembler***.



## 1. GAS (GNU Assembler) Overview


- **GAS** is part of the `binutils`, and converts source files (`s`/`S`) into object files (`.o`) for formats like **ELF**, **COFF**, **a.out**, etc.
- It is multi-architectural & the backend assembler for **GCC** (GNU Compiler Collection) .



## 2. Core Components & Sub-Components


### 2.1 <u>Frontend (Lexer + Parser)</u>:

- The frontend reads & tokenizes the source assembly code.
- Role for each sub-component is mentioned in the table below, as per order of their roles.

|Sno.|Sub-Component|Responsibility|
|:-:|:-:|:-|
|1|Source reader|Reads whole source code character-by-character.|
|2|Lexer/scanner|Breaks input into tokens like opcodes, labels, registers, directives, constants, etc.|
|3|Macro expander|Expands expansions like `.macro`, `.irp`, `.rept`, etc.|
|4|Preprocessor|Handles conditional macros like `ifdef`, `.else`, etc.|

- After these components have performed their roles, the output is preprocessed code.


### 2.2 <u>Parser & Grammar Validator</u>:

- Parses instructions using architecture-specific grammar rule.
- Architecture-specific grammar are written in files named in pattern of `tc-<arch>.c`.
- Converts mnemonics (`mov`, `add`, `jmp`, etc) into opcodes & operands.
- Checks for correctness in register & operand type.
- Final output are partially processed instructions, i.e. immediate representation (IR).


### 2.3 <u>Symbol Table Manager</u>:

- Tracks labels, externals, globals, constants, etc.
- Manages relocations for undefined symbols.
- Symbols are assigned sections.
- Final output is a symbol table, containing types, bindings, addresses, etc.


### 2.4 <u>Section Manager</u>

- Handles all sections like `.text`, `.bss`, `.data`, `.rodata`, etc.
- Aligns (to 32-bit, 64-bit, etc) sections as per the architecture.
- Manages customly created sections in form `.section .<mydata>`.
- Output is a memory-mapped layout of all sections.


### 2.5 <u>Instruction Encoder</u>:

- Makes use of `tc-<arch>.c` & `macro-op.c` files.
- Encodes the instructions containing registers, immediates & addressing modes.
- Calculates offsets & fixups.
- Output is machine instructions with relocation entries.

>**<u>NOTE</u>:**
> - **<u>Fixups</u>:** Placeholders (replacers) for relocations.


### 2.6 <u>Relocation Handler</u>:

- Relocation handler is used for unresolved symbols.
- And these relocations are target-specific, for example `R_X86_64_PC32`.
- Segments like `.rel.text` & `.rela.text` are created.
- Output are relocation tables.


### 2.7 <u>Output Writer (Object File Generator)</u>:

- Fills all headers, tables & sections of ELF.
- **For example -** ELF headers, section headers, symbol tables, relocation sections.
- Output object files are written with an extension of `.o`.



## 3. Component Interaction Flow (Linear)


$$ \fbox{Source Code} $$
$$ \downarrow $$
$$ \fbox{Preprocessor + Macro Expander} $$
$$ \downarrow $$
$$ \fbox{Lexer} $$
$$ \downarrow $$
$$ \fbox{Parser} $$
$$ \downarrow $$
$$ \fbox{Instruction IR} $$
$$ \downarrow $$
$$ \fbox{Symbol Resolution} $$
$$ \downarrow $$
$$ \fbox{Machine Code Encoding} $$
$$ \downarrow $$
$$ \fbox{Generate Required Relocations} $$
$$ \downarrow $$
$$ \fbox{Source Code} $$
$$ \downarrow $$
$$ \fbox{ELF Section Organization} $$
$$ \downarrow $$
$$ \fbox{Final Object File} $$



## 4. Advantages & Limitations


### 4.1 <u>Advantages</u>:

- Multi-architectural due to `tc-<arch>.c` files
- Relocation-ready with linker, whether static or dynamic
- Macros allow user made abstractions
- Carefully controls symbols, alignments & sections


### 4.2 <u>Limitations</u>:

- Tightly coupled components
- Cryptic error messages
- No use of **Context-Free Grammar (CFG)**
- Low scalability
- Requires complete re-invention for different format
- No line encoding preview feature



## 5. Key Binutils Files


|File|Responsibility|
|:-:|:-|
|`as.c`|Entry point of GAS|
|`read.c`|Core input parsing|
|`write.c`|Writes object file|
|`symbols.c`| Symbol management|
|`frags.c`|Instruction fragments & layout|
|`config/tc-<arch>.c`| Architecture-specific encoding logic|
|`output-file.c`|ELF/COFF output generator|
|`expr.c`|Expression evaluation (e.g., arithmetic)|
|`macro.c`|Macro handling|



## 6. Sections v/s Segments


|Aspect|Section (`.text`, `.data`)| Segment (LOAD, DYNAMIC)|
|:-|:-|:-|
|Defined by|Assembler|Linker/Loader|
|Purpose|Organize **code/data logically**| Define **memory layout** at runtime|
|Stored in|Section headers (ELF `.shdr`)| Program headers (ELF `.phdr`)|
|Granularity|Fine (per-function, per-constant)|Coarse (per-page, per-protection)|
|Loader sees?|No|Yes|

---