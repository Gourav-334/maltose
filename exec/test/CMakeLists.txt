cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
	../../src/test.c
	../../src/cmd_interpreter/cmd_valid.c
	../../src/cmd_interpreter/fsm_state_handler.c
	../../src/cmd_interpreter/flag_status.c
	../../src/cmd_interpreter/cmd_fsm_main.c
	../../src/cmd_interpreter/cmd_fsm/cmd_fsm0.c
	../../src/cmd_interpreter/cmd_fsm/cmd_fsm1.c
	../../src/manuals/cmd_help.c
	../../src/utils/str_verif/ill_char_scan.c
	../../src/utils/str_ops/push_alloc.c
	../../src/utils/file_sys/path_valid.c
)
