cmake_minimum_required (VERSION 2.6)
project (Demo)

aux_source_directory(. DIR_SRCS)

add_executable(demo ${DIR_SRCS})