cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
	../../src/test.c
	../../src/data_structs/linked_list/inserter.c
	../../src/data_structs/linked_list/remover.c
	../../src/data_structs/linked_list/full_remover.c
	../../src/lexer/x86/token_fsm_main.c
	../../src/lexer/x86/fsm_state_handler.c
	../../src/lexer/x86/token_fsm/token_fsm0.c
	../../src/lexer/x86/token_fsm/token_fsm1.c
	../../src/lexer/x86/token_recog.c
	../../src/lexer/x86/token_store.c
	../../src/utils/str_verif/case_ins_match.c
)
