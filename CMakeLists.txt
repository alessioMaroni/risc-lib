cmake_minimum_required(VERSION 4.3.4)

project(riscvlib
    VERSION 0.1.0
    LANGUAGES C ASM
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(riscvlib INTERFACE)

target_include_directories(riscvlib
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add_library(riscvlib 
#   STATIC
#       # C files
# )
# target_include_directories(riscvlib
#     PUBLIC
#         ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

# ------------- Toolchan test -------------
add_library(riscvlib_tests STATIC
    tests/toolchain/lib_test.c
)
target_link_libraries(riscvlib_tests
    PRIVATE
        riscvlib
)
# -----------------------------------------

# ------------- Library Test -------------
add_executable(riscvlib_app
    tests/lib/start.s
    tests/lib/main.c
)

target_link_libraries(riscvlib_app
    PRIVATE
        riscvlib
)

target_link_options(riscvlib_app
    PRIVATE
        -nostdlib
        -T${CMAKE_CURRENT_SOURCE_DIR}/tests/lib/linker.ld
)
#-----------------------------------------