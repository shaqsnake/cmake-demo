cmake_minimum_required (VERSION 2.6)

# Project info
project(Demo)

# Version
set (Demo_VERSION_MAJOR 0)
set (Demo_VERSION_MINOR 1)

# Check func exists
include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(sqrt HAVE_SQRT)

# Add config file
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

option (USE_MYMATH "Use provided math implementation" ON)

if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory (math)  
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunc)
endif (USE_MYMATH)

# Search all source code, and store them in a varialbe DIR_SRCS.
aux_source_directory(. DIR_SRCS)

# Specify the executable target
add_executable(demo ${DIR_SRCS})

# Link libs
target_link_libraries(demo ${EXTRA_LIBS})

# Install path
install(TARGETS demo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)

# Test
enable_testing()

add_test(test_run demo 2)

add_test(test_usage demo)
set_tests_properties(test_usage 
    PROPERTIES PASS_REGULAR_EXPRESSION ".* number")

macro (do_test arg result)
    add_test(test_${arg} demo ${arg})
    set_tests_properties(test_${arg} 
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test(2 "is 1.41421")
do_test(4 "is 2")
do_test(8 "is 2.82843")