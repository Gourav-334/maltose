# SECTION STOREHOUSE



## 1. Description


This file documents the implementation for **section storehouse**, which stores details about each major section separately i.e. their starting & ending in filestream.



## 2. Storage Units


```c
long int **sec_text;
long int **sec_data;
long int **sec_bss;
long int **sec_rodata;
```

---