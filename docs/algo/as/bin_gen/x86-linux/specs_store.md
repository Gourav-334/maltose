# SPECIFICATIONS STOREHOUSE



## 1. Description


This file documents the implementation of **specification storehouse** which stores file-critical information (code file, ELF binary, platform & hardware) & specification of the user's computer system.



## 2. Instances & Variables


### 2.1 <u>Structural Instances</u>:

```c
Elf64_Ehdr elf_header;						// Stores ELF header information.
Elf64_Shdr sec_header[TOTAL_SEC];			// Stores section header information.
Elf64_Sym *symtab;							// Stores contagious symbol tables.
Elf64_Rel *rel_data;						// Stores contagious relocation data.
```


### 2.2 <u>Variables/Constants</u>:

```c
int sym_count;			// Counts the total number of symbols registered.
```

---