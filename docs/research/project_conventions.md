# PROJECT CONVENTIONS



## 0. Note For Readers


- Each section starting from **1** describes type of place to apply convention.
- The examples given for any type might or might not have identical name with any entity associated with this project.



## 1. Directories


### 1.1 <u>Description</u>:

- Directories are, and must be named descriptively but shortly.
- This means that certain terms which are expected to be very obvious to contributors be written in abbreviation.
- However, this excludes certain root directories which are named as per community standards (eg., `src/`).


### 1.2 <u>Examples</u>:

|Sno.|Meaning|Naming|Note|
|:-:|:-:|:-:|:-|
|1.2.1|Testing directory|`test`|Named as per community standards.|
|1.2.2|Researched information|`research`|Name is descriptive enough to understand intent.|
|1.2.3|Dynamic ELF generator|`dyn_elf_generator`|Dynamic is popularly named as `dyn`, so shortened.|



## 2. Files


### 2.1 <u>Description</u>:

- Just like directories, files must be named descriptively but shortly.
- Which means that certain terms which are expected to be very obvious to contributors be written in abbreviation.
- But some exceptions might be found in `test/` directory, being mostly test subjects which are not functional to project but used for rapid prototyping.


### 2.2 <u>Examples</u>:

|Sno.|Meaning|Naming|Note|
|:-:|:-:|:-:|:-|
|2.2.1|Signal Trap|`signal_trap.c`|Meaning itself is short & simple.|
|2.2.2|Context-free grammar parser|`cfg_parser.c`|Context-free grammar is popularly shortened to CFG.|



## 3. Guides


### 3.1 <u>Description</u>:

- Guides are those files which provide basic information about the project, contributors, licensing or directory navigation etc.
- These are not directly related to technical details of the project, but used for reader-friendliness & legal standing.
- Guides are named as per the default **GitHub** naming convention.


### 3.2 <u>Examples</u>:

|Sno.|Meaning|Naming|Note|
|:-:|:-:|:-:|:-|
|3.2.1|Readme/manual|`README.md`|These readme files are found in almost directories for users to know about current directory.|
|3.2.2|Licensing information|`LICENSE`|Project particular license is found in root directory, while dependency licenses are grouped separately.|
|3.2.3|Ethical considerations|`ETHICS.md`|Not a legal binding but clear declaration of author's intentions & moral boundary.|



## 4. Documentation


### 4.1 <u>Description</u>:

- Documentation is done in a particular structured way.
- Take this file itself for example, you might be noticing the structure which it follows for boxing sections.
- And these are written in markdown (`.md`) form for convenience of readers.
- When a any entity has its own sub-entities, the lines between each sub-entity reduces by 1.
- These entities follow a number that represents it.


### 4.2 <u>Examples</u>:

|Sno.|Meaning|Naming|Note|
|:-:|:-:|:-:|:-|
|4.2.1|Title|`# PROJECT CONVENTIONS`|Written with H1 header & in full uppercase.|
|4.2.2|Section|`## 5. Symbol Naming`|`5.` represents the entity & first letter of each term is always uppercase.|
|4.2.3|Sub-section|`### 4.1 Description`|Because description is sub-entity for its section as entity, `4.1` uniquely identifies this.|
|4.2.4|Scoped section|`#### 1.3.2 GOOD EXAMPLE:-`|After the identifier, written with all uppercase with `:-` at the end.|



## 5. Symbol Naming


### 5.1 <u>Description</u>:

- Just like directories, symbols must be named descriptively but shortly.
- Which means that certain terms which are expected to be very obvious to contributors be written in abbreviation.
- This ensures that neither the programmer gets confused about the symbol in future, neither the readers feel it cryptic or even too large.


### 2.2 <u>Examples</u>:

|Sno.|Meaning|Naming|Note|
|:-:|:-:|:-:|:-|
|5.2.1|Finite state machine's current state|`cur_fsm_state`|Finite state machines are abbreviated as FSM.|
|5.2.2|Symbol tables pointer|`symtab_ptr`|Symbol table are often identified with `.symtab` section & pointers are famously abbreviated as `ptr`.|
|5.2.3|OS's single page size|`PAGE_SIZE`|Some important mathematical records are written as macros, where their names are full uppercase.|



## 6. Generated Dependencies


### 6.1 <u>Description</u>:

- Generated dependencies are functional & intregral part of third-party tools.
- Making changes to its related file or directory naming can be hazardoues without precise information.
- They must be usually left as it is unless some real need arises, and so be done with reference to tool's original manual.

---