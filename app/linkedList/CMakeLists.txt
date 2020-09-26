set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
add_executable(singly_linked_list
	main.c)
target_link_libraries(singly_linked_list data_structure)
