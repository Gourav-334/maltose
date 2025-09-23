cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
	../../src/test.c
	../../src/lexer/x86/token_fsm_main.c
	../../src/lexer/x86/token_fsm/token_fsm0.c
	../../src/lexer/x86/token_fsm/token_fsm1.c
)
