#include <riscv/riscv_xlen.h>
#include <csrs_configuration.h>

int lib_test(void)
{
    riscv_xlen_t value = 0U;
    return (int)value;
}