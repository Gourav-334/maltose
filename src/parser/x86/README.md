# README


## 1. Description

This directory contains all the available parser component source codes for x86 family processors.


## 2. Directory Structure

- `assets/` - Stores assets that indirectly affect the corresponding documentation for this directory.
- `parser_fsm/` - Stores source code for each part of the whole parser FSM.
- `patt_fsm/` - Stores source code for each part of the whole pattern finding FSM.
- `label_store` - Stores all the instructional tokens, and their details.
- `parser_fsm_main.c` - Source code for assembly point of parser FSM parts & state handler.
- `parser_state_handler.c` - Source code for parser FSM state handler.
- `patt_fsm_main.c` - Source code for assembly point of pattern FSM parts & state handler.
- `patt_state_handler.c` - Source code for pattern FSM state handler.
- `register_store.c` - Contains source code for storehouse of all registers & hardware units.
- `section_store.c` - Contains source code for each major section's each checkpoint.

---