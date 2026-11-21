#ifndef RISCV_MISA_H
#define RISCV_MISA_H

#include <riscv/riscv_xlen.h>
#include <csrs_configuration.h>
#include <stdbool.h>

__attribute__((always_inline)) static inline bool
__misa_is_implemented(riscv_xlen_t misa);

__attribute__((always_inline)) static inline riscv_mxl_t
__misa_get_mxl(riscv_xlen_t misa);

__attribute__((always_inline)) static inline riscv_xlen_t
__misa_get_extensions(riscv_xlen_t misa);

__attribute__((always_inline)) static inline bool
__misa_has_extension(riscv_xlen_t misa, riscv_xlen_t ext_mask);

__attribute__((always_inline)) static inline bool
__misa_is_rv32e(riscv_xlen_t misa);

__attribute__((always_inline)) static inline bool
__misa_has_supervisor_mode(riscv_xlen_t misa);

__attribute__((always_inline)) static inline bool
__misa_has_user_mode(riscv_xlen_t misa);


bool
misa_is_implemented(riscv_xlen_t misa);

riscv_mxl_t
misa_get_mxl(riscv_xlen_t misa);

riscv_xlen_t
misa_get_extensions(riscv_xlen_t misa);

bool
misa_has_extension(riscv_xlen_t misa, riscv_xlen_t ext_mask);

bool
misa_is_rv32e(riscv_xlen_t misa);

bool
misa_has_supervisor_mode(riscv_xlen_t misa);

bool
misa_has_user_mode(riscv_xlen_t misa);

#endif /* RISCV_MISA_H */