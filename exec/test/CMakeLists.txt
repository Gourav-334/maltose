cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
	../../src/test.c
	../../src/utils/str_ops/push_alloc.c
	../../src/utils/file_sys/path_valid.c
)
