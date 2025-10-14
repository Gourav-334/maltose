cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g")


add_executable(test
	../../src/test.c
	../../src/parser/x86/register_store.c
	# ../../src/data_structs/linked_list/inserter.c
	# ../../src/data_structs/linked_list/remover.c
	# ../../src/data_structs/linked_list/full_remover.c
	# ../../src/data_structs/linked_list/displayer.c
	# ../../src/lexer/x86/token_fsm_main.c
	# ../../src/lexer/x86/fsm_state_handler.c
	# ../../src/lexer/x86/token_fsm/token_fsm0.c
	# ../../src/lexer/x86/token_fsm/token_fsm1.c
	# ../../src/lexer/x86/token_fsm/token_fsm2.c
	# ../../src/lexer/x86/token_recog.c
	# ../../src/lexer/x86/token_store.c
	# ../../src/lexer/x86/code_cleanser.c
	# ../../src/manuals/audit_msng.c
	# ../../src/utils/str_verif/case_ins_match.c
	# ../../src/utils/str_verif/ill_char_scan.c
	# ../../src/utils/str_ops/push_alloc.c
	# ../../src/utils/str_ops/pop_dealloc.c
	# ../../src/file_loader.c
	# ../../src/common_store.c
)
