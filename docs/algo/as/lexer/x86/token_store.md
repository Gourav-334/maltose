# TOKEN STOREHOUSE



## 1. Description


This file documents the implementation of **token storehouse**, which stores the structures, which hold tokens within them during lexical analysis. Reason for separate storage unit is for increasing accessibility.



## 2. Structure Instances


```c
Ll_recorder token = {.total=0, .head=NULL, .tail=NULL};
Ll_recorder categ = {.total=0, .head=NULL, .tail=NULL};
Ll_recorder sub_categ = {.total=0, .head=NULL, .tail=NULL};
Ll_recorder type = {.total=0, .head=NULL, .tail=NULL};
```

---