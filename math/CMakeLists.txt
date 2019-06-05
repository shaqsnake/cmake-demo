aux_source_directory(. DIR_LIB_SRCS)

add_library(MathFunc ${DIR_LIB_SRCS})

# Specify install path of MathFunc lib
install(TARGETS MathFunc DESTINATION bin)
install(FILES MathFunc.hpp DESTINATION include)