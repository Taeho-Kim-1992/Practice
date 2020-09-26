cmake_minimum_required(VERSION 3.0)

project(dalpu
	VERSION 0.0.0
	DESCRIPTION "Data structure practice"
	LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -static-libasan -fsanitize=address -fsanitize=leak -fsanitize=undefined")
endif()

include_directories(include)

set(SOURCES
	src/linkedList.c)

add_library(data_structure STATIC ${SOURCES})

target_include_directories(data_structure PUBLIC include)

add_subdirectory(app)
