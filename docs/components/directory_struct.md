# DIRECTORY STRUCTURE



## 1. Description


This file explains how the directory is planned to be structured as. These structure will represent each component, with its sub-components within.



## 2. Source Directory


### 2.1 <u>Directory structure</u>:

```
block_parser/
    elf_block_errors.c
    elf_block_fsm.c
    elf_block_warnings.c
data_structs/
    queue/
        clear.c
        count.c
        dequeue.c
        enqueue.c
        peek.c
        queue_struct.c
    stack/
        clear.c
        count.c
        peek.c
        pop.c
        push.c
        stack_struct.c
hazard_detector/
    x86_hazard_detector/
        x86_deadlock_detector.c
        x86_syscall_hazard.c
        x86_thread_safety.c
info_detector/
    arch_detector.c
    mod_detector.c
info_storage/
    elf_info_storage/
        bss_storage.c
        elf_misc_info.c
        elf_offset_data.c
        debug_info_storage.c
        dynsym_storage.c
        elfh_storage.c
        sht_storage.c
        symtab_storage.c
        text_storage.c
    x86_info_storage/
        x86_errors.c
        x86_flag_state.c
        x86_float_stack_state.c
        x86_fpu_state.c
        x86_gpr_state.c
        x86_int_stack_state.c
        x86_section_state.c
        x86_sse_state.c
        x86_symbol_set.c
        x86_vector_state.c
        x86_warnings.c
    common_obj_storage.c
obj_generators/
    elf_obj_generator.c
opcode_selector/
    x86_opcode_selector.c
logger/
    x86_logger/
        x86_time_detector.c
        x86_time_writer.c
logic_parser/
    x86_logic_parser/
        x86_logic_errors.c
        x86_logic_fsm.c
        x86_logic_warnings.c
    tokenizer.c
mem_safety/
    dangling_ptr_detector.c
    mem_leak_detector.c
    warning_generator.c
semantic_parser/
    x86_semantic_parser/
        x86_code_expander.c
        x86_code_simplifier.c
        x86_semantic_fsm.c
        x86_semantic_errors.c
        x86_semantic_warnings.c
utilities/
main.c
```


### 2.2 <u>Types Of Files</u>:

- **<u>Functional files</u>:** Files which are meant to provide functional support to modules.
- **<u>Hybrid files</u>:** Files which are meant to work as both ***storage*** & ***functional*** files.
- **<u>Storage files</u>:** Files which are meant only for store & modify information.

---