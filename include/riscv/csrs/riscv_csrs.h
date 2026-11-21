#ifndef RISCV_CSRS_H
#define RISCV_CSRS_H

#include <riscv/riscv_xlen.h>
#include <riscv/csrs/riscv_mstatus_csr.h>

__attribute__((always_inline)) static inline riscv_xlen_t 
__read_csr_mstatus(void);

riscv_xlen_t 
read_csr_mstatus(void);

#endif /* RISCV_CSRS_H */