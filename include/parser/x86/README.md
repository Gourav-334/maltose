# README


## 1. Description

This directory contains all the available parser component header codes for x86 family of processors.


## 2. Directory Structure

- `parser_fsm/` - Stores header code for each part of the whole parser FSM.
- `patt_fsm/` - Stores header code for each part of the whole pattern finding FSM.
- `label_store.h` - Stores all the instructional tokens, and their details.
- `parser_fsm_main.h` - header code for assembly point of parser FSM parts & state handler.
- `parser_state_handler.h` - header code for parser FSM state handler.
- `patt_fsm_main.h` - header code for assembly point of pattern FSM parts & state handler.
- `patt_state_handler.h` - header code for pattern FSM state handler.
- `register_store.h` - Contains header code for storehouse of all registers & hardware units.
- `section_store.h` - Contains header code for each major section's each checkpoint.

---