cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
	../../src/test.c
	../../src/cmd_interpreter/cmd_fsm_main.c
	../../src/cmd_interpreter/cmd_fsm/cmd_fsm0.c
	../../src/cmd_interpreter/cmd_fsm/cmd_fsm1.c
)
