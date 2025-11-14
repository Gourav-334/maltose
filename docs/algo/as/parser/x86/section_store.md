# SECTION STOREHOUSE



## 1. Description


This file documents the implementation for **section storehouse**, which stores details about each major section separately i.e. their starting & ending in filestream.



## 2. Storage Units


```c
Ll_recorder **sec_text;
Ll_recorder **sec_data;
Ll_recorder **sec_bss;
Ll_recorder **sec_rodata;
```

---