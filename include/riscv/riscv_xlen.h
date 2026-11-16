#ifndef RISCV_XLEN_H
#define RISCV_XLEN_H

#include <stdint.h>

#ifndef __riscv_xlen
    #error "Unable to determ RISC-V XLEN"
#endif /* __riscv_xlen */

#if __riscv_xlen == 32

typedef uint32_t riscv_xlen_t;
#define RISCV_XLEN 32

#elif __riscv_xlen == 64

typedef uint64_t riscv_xlen_t;
#define RISCV_XLEN 64

#else
    #error "Unsupported RISC-V XLEN"
#endif /* __riscv_xlen */

#endif /* RISCV_XLEN_H */