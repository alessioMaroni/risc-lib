set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR riscv32)

set(CMAKE_C_COMPILER /percorso/del/tuo/riscv-none-elf-gcc)
set(CMAKE_ASM_COMPILER /percorso/del/tuo/riscv-none-elf-gcc)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(RV32_FLAGS "-march=rv32imac -mabi=ilp32")
set(CMAKE_C_FLAGS_INIT "-march=rv32imac -mabi=ilp32 -ffreestanding")
set(CMAKE_ASM_FLAGS_INIT "${RV32_FLAGS}")