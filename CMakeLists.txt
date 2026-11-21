cmake_minimum_required(VERSION 4.3.4)

project(riscvlib
    VERSION 0.1.0
    LANGUAGES C ASM
)

find_package(Perl REQUIRED)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(TARGET_PROC "generic" CACHE STRING "Processore target")
set(TARGET_XLEN "32"      CACHE STRING "XLEN (32 o 64)")
set_property(CACHE TARGET_XLEN PROPERTY STRINGS "32" "64")

set(CSR_PERL_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/codegen/csrs/csrs.pl")
set(CSR_JSON_FILE   "${CMAKE_CURRENT_SOURCE_DIR}/codegen/csrs/csrs.json")
set(CSR_GEN_DIR     "${CMAKE_CURRENT_BINARY_DIR}/gen")
set(CSR_OUT_HEADER  "${CSR_GEN_DIR}/csrs_configuration.h")

add_custom_command(
    OUTPUT "${CSR_OUT_HEADER}"
    COMMAND "${PERL_EXECUTABLE}" "${CSR_PERL_SCRIPT}"
            --core "${TARGET_PROC}"
            --xlen "${TARGET_XLEN}"
            --in   "${CSR_JSON_FILE}"
            --out  "${CSR_OUT_HEADER}"
    DEPENDS
        "${CSR_PERL_SCRIPT}"
        "${CSR_JSON_FILE}"
    COMMENT "Generazione CSR per ${TARGET_PROC} (XLEN=${TARGET_XLEN})"
    VERBATIM
)

add_custom_target(generate_csrs DEPENDS "${CSR_OUT_HEADER}")

# ------------- Library (STATIC) -------------
add_library(riscvlib STATIC
    src/riscv/csrs/riscv_csrs.c
    src/riscv/csrs/riscv_mstatus_csr.c
)

add_dependencies(riscvlib generate_csrs)

target_include_directories(riscvlib
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_sources(riscvlib
    PUBLIC
        FILE_SET generated_headers
        TYPE HEADERS
        BASE_DIRS "${CSR_GEN_DIR}"
        FILES "${CSR_OUT_HEADER}"
)
# --------------------------------------------

# ------------- Toolchain test -------------
add_library(riscvlib_tests STATIC
    tests/toolchain/lib_test.c
)

target_link_libraries(riscvlib_tests
    PRIVATE
        riscvlib
)
# ------------------------------------------

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
# ----------------------------------------