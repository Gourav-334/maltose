# DIRECTORY STRUCTURE



## 1. Description


This file explains how the directory is planned to be structured as. These structure will represent each component, with its sub-components within.



## 2. Source Directory


### 2.1 <u>Directory structure</u>:

```
bin_generator/
    elf/
        generator.c
        sec_merger.c
        specs_assign.c
        specs_extract.c
        specs_store.c
        file_writer.c
cmd_interpreter/
    err_log.c
    flag_status.c
    fsm.c
    warn_log.c
data_structs/
    linked_list/
        insert.c
        dequeue.c
        length.c
        peek.c
        pop.c
        struct.c
lexer/
    x86/
        err_log.c
        fsm.c
        token_store.c
        tokenizer.c
        warn_log.c
parser/
    x86/
        err_log.c
        fsm.c
        label_store.c
        pattern_find.c
        register_store.c
        sec_merger.c
        sec_store.c
        warn_log.c
utils/
    file_sys/
        path_valid.c
    str_ops/
	push_alloc.c
    str_verif/
        ill_char_scan.c
    log_writer.c
file_reader.c
main.c
test.c
```

>**<u>NOTE</u>:**
> - Some extendable files might be named as `filename{n}.c` where `{n}` is a natural number.
> - For example, a **finite state machine** with a lot of states might be divided into multiple source files.


### 2.2 <u>Types Of Files</u>:

- **<u>Functional files</u>:** Files which are meant to provide functional support to modules.
- **<u>Hybrid files</u>:** Files which are meant to work as both ***storage*** & ***functional*** files.
- **<u>Storage files</u>:** Files which are meant only for store & modify information.

---
