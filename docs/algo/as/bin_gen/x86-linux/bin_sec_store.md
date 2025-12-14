# BINARY SECTION STOREHOUSE



## 1. Description


This file documents the implementation of **binary section storehouse**, which stores binary level bytes separate for each section for being later on stitched together.



## 2. Storage Units


### 2.1 <u>Section Storage Units</u>:

```c
uint8_t *sec_null_store;				// Stores contents of NULL section (no use - just convention).
uint8_t *sec_text_store;				// Stores contents of .text section.
uint8_t *sec_rela_text_store;			// Stores contents of .rela.text section.
uint8_t *sec_data_store;				// Stores contents of .data section.
uint8_t *sec_bss_store;					// Stores contents of .bss section.
uint8_t *sec_rodata_store;				// Stores contents of .rodata section.
uint8_t *sec_symtab_store;				// Stores contents of .symtab section.
uint8_t *sec_strtab_store;				// Stores contents of .strtab section.
uint8_t *sec_shstrtab_store;			// Stores contents of .shstrtab section.
uint8_t *sec_comment_store;				// Stores contents of .comment section.
uint8_t *sec_gnu_stack_store;			// Stores contents of .note_gnu-stack section.
uint8_t *sec_debug_store;				// Stores contents of .debug section.
```


### 2.2 <u>Size Counting Units</u>:

```c
size_t sec_null_size;					// Stores contents of NULL section (no use - just convention).
size_t sec_text_size;					// Stores contents of .text section.
size_t sec_rela_text_size;				// Stores contents of .rela.text section.
size_t sec_data_size;					// Stores contents of .data section.
size_t sec_bss_size;					// Stores contents of .bss section.
size_t sec_rodata_size;					// Stores contents of .rodata section.
size_t sec_symtab_size;					// Stores contents of .symtab section.
size_t sec_strtab_size;					// Stores contents of .strtab section.
size_t sec_shstrtab_size;				// Stores contents of .shstrtab section.
size_t sec_comment_size;				// Stores contents of .comment section.
size_t sec_gnu_stack_size;				// Stores contents of .note_gnu-stack section.
size_t sec_debug_size;					// Stores contents of .debug section.
```

---