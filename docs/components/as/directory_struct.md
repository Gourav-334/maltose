# DIRECTORY STRUCTURE



## 1. Description


This file explains how the directory is planned to be structured as. These structure will represent each component, with its sub-components within.



## 2. Source Directory


### 2.1 <u>Directory structure</u>:

```
cmd_interpreter/
    cmd_errors.c
    cmd_parser.c
    cmd_warnings.c
    file_finder.c
    flag_fsm.c
    flag_suggestor.c
    flag_status.c
data_structs/
    queue/
        clear.c
        count.c
        dequeue.c
        enqueue.c
        peek.c
        struct_def.c
    stack/
        clear.c
        count.c
        peek.c
        pop.c
        push.c
        struct_def.c
hazard_detector/
    x86_hazards/
        deadlock_detector.c
        syscall_hazard.c
        thread_safety.c
info_detector/
    arch_detector.c
    mod_detector.c
info_storage/
    elf_info/
        bss.c
        debug.c
        dynsym.c
        elfh.c
        misc_info.c
        offset_data.c
        sht.c
        symtab.c
        text.c
    x86_info/
        errors.c
        flag_state.c
        float_stack_state.c
        fpu_state.c
        gpr_state.c
        int_stack_state.c
        section_state.c
        sse_state.c
        symbol_set.c
        vector_state.c
        warnings.c
    common_obj_storage.c
    instruction_dissects.c
instruction_refiner/
    x86_instruction_refiner/
        code_expander.c
        code_simplifier.c
obj_generators/
    elf_obj_generator.c
opcode_selector/
    x86_opcode_selector.c
lexer/
    elf_lexer/
        data_sec/
            data_errors.c
            data_fsm.c
            data_warnings.c
        bss_sec/
            bss_errors.c
            bss_fsm.c
            bss_warnings.c
logger/
    log/
        as_log/
            728638761281.log
        cmd_log/
            437811389314.log
    logger.c
    time_detector.c
mem_safety/
    dangling_ptr_detector.c
    mem_leak_detector.c
    warning_generator.c
parser/
    x86_parser/
        elf_parser/
            semantic_errors.c
            semantic_warnings.c
            text_sect_fsm.c
utilities/
main.c
test.c
```


### 2.2 <u>Types Of Files</u>:

- **<u>Functional files</u>:** Files which are meant to provide functional support to modules.
- **<u>Hybrid files</u>:** Files which are meant to work as both ***storage*** & ***functional*** files.
- **<u>Storage files</u>:** Files which are meant only for store & modify information.

---