# SPECIFICATIONS ASSIGNER



## 1. Description


This file documents the implementation of the **specification assigner**, which extracts platform and hardware information from the host system, and sets ELF fields accordingly for binary generation.



## 2. Function


```c
bool assign_specs(void);
```



## 3. Information To Extract


### 3.1 <u>ELF Header</u>:

- Magic numbers
- File type
- Target ISA code
- ELF format version
- Entry point virtual address
- Program header table's offset
- Section header table's offset
- Architecture specific flags
- ELF header size
- Program header entry size
- Number of program header entries
- Section header entry size
- Number of section header entries
- Section header string index


### 3.4 <u>Segment Header</u>:

- Offset of section name in `.shstrtab`
- Section type
- Flags
- Virtual address
- Sections offset in file
- Section size
- Link to other section
- Extra info
- Alignment constraints
- Size of each entry if section is table



## 4. Responsibilities For Other Components


- Initializing section headers
- Writing symbol table
- Handling string symbol table
- Writing section header string index
- Counting bytes in each section

---