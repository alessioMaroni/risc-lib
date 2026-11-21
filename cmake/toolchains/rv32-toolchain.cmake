set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR riscv32)

find_program(RISCV_GCC NAMES riscv64-linux-gnu-gcc riscv-none-elf-gcc riscv64-unknown-elf-gcc riscv32-unknown-elf-gcc REQUIRED)
set(CMAKE_C_COMPILER ${RISCV_GCC})
set(CMAKE_ASM_COMPILER ${RISCV_GCC})

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(RV32_FLAGS "-march=rv32imac_zicsr -mabi=ilp32")
set(CMAKE_C_FLAGS_INIT "${RV32_FLAGS} -ffreestanding")
set(CMAKE_ASM_FLAGS_INIT "${RV32_FLAGS}")