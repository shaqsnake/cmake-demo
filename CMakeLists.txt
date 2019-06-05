cmake_minimum_required (VERSION 2.6)

# Project info
project(Demo)

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