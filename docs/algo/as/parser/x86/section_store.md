# SECTION STOREHOUSE



## 1. Description


This file documents the implementation for **section storehouse**, which stores details about each major section separately i.e. their starting & ending in filestream.



## 2. Storage Units


### 2.1 <u>Pointer Addresses</u>:

```c
uintptr_t *sec_text;
uintptr_t *sec_data;
uintptr_t *sec_bss;
uintptr_t *sec_rodata;
```


### 2.2 <u>Blocks Counter</u>:

```c
long int sec_text_blocks;
long int sec_data_blocks;
long int sec_bss_blocks;
long int sec_rodata_blocks;
```

---