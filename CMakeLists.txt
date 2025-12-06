cmake_minimum_required(VERSION 3.10)
project(AI_DSA_CHATBOT)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Build DSA source files into a static library so other targets can link to it.
file(GLOB_RECURSE DSA_SOURCES "${CMAKE_SOURCE_DIR}/src/dsa/*.cpp")
add_library(dsa STATIC ${DSA_SOURCES})
target_include_directories(dsa PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Build the chatbot executable (main entry) and link against the dsa library.
set(MAIN_SRC "${CMAKE_SOURCE_DIR}/src/main.cpp")
if(EXISTS ${MAIN_SRC})
	add_executable(chatbot ${MAIN_SRC})
	target_link_libraries(chatbot PRIVATE dsa)
endif()

# If there's a workspace-level tests directory (one level up), add each test
# as an executable that links the dsa library. This allows building tests
# from within the CMake project directory using the same include root.
set(WORKSPACE_TESTS_DIR "${CMAKE_SOURCE_DIR}/../tests")
if(EXISTS ${WORKSPACE_TESTS_DIR})
	file(GLOB TEST_SOURCES "${WORKSPACE_TESTS_DIR}/*.cpp")
	foreach(test_src ${TEST_SOURCES})
		get_filename_component(test_name ${test_src} NAME_WE)
		add_executable(${test_name} ${test_src})
		target_include_directories(${test_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
		target_link_libraries(${test_name} PRIVATE dsa)
	endforeach()
endif()
