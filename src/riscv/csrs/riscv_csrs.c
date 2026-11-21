#include <riscv/riscv_xlen.h>
#include <riscv/csrs/riscv_mstatus_csr.h>
#include <csrs_configuration.h> /* Perl csrs configuration */

/* MSTATUS CSR */

__attribute__((always_inline)) static inline riscv_xlen_t 
__read_csr_mstatus(void)
{
    riscv_xlen_t val;
    __asm__ __volatile__("csrr %0, %c1" : "=r"(val) : "i"(__MSTATUS_CSR));
    return val;
}

riscv_xlen_t
read_csr_mstatus(void)
{
    return __read_csr_mstatus();
}

/* MISA CSR */

__attribute__((always_inline)) static inline riscv_xlen_t 
__read_csr_misa(void)
{
    riscv_xlen_t val;
    __asm__ __volatile__("csrr %0, %c1" : "=r"(val) : "i"(__MISA_CSR));
    return val;
}

riscv_xlen_t 
read_csr_misa(void)
{
    return __read_csr_misa();
}
