cmake_minimum_required(VERSION 3.10)
project(AS1_UNIT_TESTING C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
	../../src/test.c
	../../src/file_loader.c
)
