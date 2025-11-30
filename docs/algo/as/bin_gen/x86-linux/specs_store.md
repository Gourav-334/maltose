# SPECIFICATIONS STOREHOUSE



## 1. Description


This file documents the implementation of **specification storehouse** which stores file-critical information (code file, platform & hardware) specification of the user's computer system.



## 2. Structure Instances


```c
Elf64_Ehdr elf_header;			// Stores ELF header information.
Elf64_Phdr prog_header;			// Stores program header information.
Elf64_Shdr sec_header;			// Stores section header information.
```

---