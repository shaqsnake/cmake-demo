cmake_minimum_required (VERSION 2.6)

# Project info
project (Demo)

# Search all source code, and store them in a varialbe DIR_SRCS.
aux_source_directory(. DIR_SRCS)

# Add math subdir
add_subdirectory(math)

# Specify the executable target
add_executable(demo ${DIR_SRCS})

# Link libs
target_link_libraries(demo MathFunc)