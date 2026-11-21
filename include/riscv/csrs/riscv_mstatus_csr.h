#ifndef RISCV_MSTATUS_H
#define RISCV_MSTATUS_H

#include <riscv/riscv_xlen.h>
#include <csrs_configuration.h>
#include <stdbool.h>


__attribute__((always_inline)) static inline riscv_priv_mode_t
__mstatus_get_mpp(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline riscv_ext_state_t
__mstatus_get_vs(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline riscv_ext_state_t
__mstatus_get_fs(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline riscv_ext_state_t
__mstatus_get_xs(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline bool
__mstatus_is_sd_set(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline bool
__mstatus_is_mie_enabled(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline bool
__mstatus_is_mpie_set(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline bool
__mstatus_is_sie_enabled(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline bool
__mstatus_is_spie_set(riscv_xlen_t mstatus);

__attribute__((always_inline)) static inline bool
__mstatus_is_mprv_enabled(riscv_xlen_t mstatus);


__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mpp(riscv_xlen_t mstatus, riscv_priv_mode_t mode);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_vs(riscv_xlen_t mstatus, riscv_ext_state_t state);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_fs(riscv_xlen_t mstatus, riscv_ext_state_t state);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_xs(riscv_xlen_t mstatus, riscv_ext_state_t state);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mie(riscv_xlen_t mstatus, bool enable);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mpie(riscv_xlen_t mstatus, bool enable);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_sie(riscv_xlen_t mstatus, bool enable);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_spie(riscv_xlen_t mstatus, bool enable);

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mprv(riscv_xlen_t mstatus, bool enable);


riscv_priv_mode_t
mstatus_get_mpp(riscv_xlen_t mstatus);

riscv_ext_state_t
mstatus_get_vs(riscv_xlen_t mstatus);

riscv_ext_state_t
mstatus_get_fs(riscv_xlen_t mstatus);

riscv_ext_state_t
mstatus_get_xs(riscv_xlen_t mstatus);

bool
mstatus_is_sd_set(riscv_xlen_t mstatus);

bool
mstatus_is_mie_enabled(riscv_xlen_t mstatus);

bool
mstatus_is_mpie_set(riscv_xlen_t mstatus);

bool
mstatus_is_sie_enabled(riscv_xlen_t mstatus);

bool
mstatus_is_spie_set(riscv_xlen_t mstatus);

bool
mstatus_is_mprv_enabled(riscv_xlen_t mstatus);


riscv_xlen_t
mstatus_set_mpp(riscv_xlen_t mstatus, riscv_priv_mode_t mode);

riscv_xlen_t
mstatus_set_vs(riscv_xlen_t mstatus, riscv_ext_state_t state);

riscv_xlen_t
mstatus_set_fs(riscv_xlen_t mstatus, riscv_ext_state_t state);

riscv_xlen_t
mstatus_set_xs(riscv_xlen_t mstatus, riscv_ext_state_t state);

riscv_xlen_t
mstatus_set_mie(riscv_xlen_t mstatus, bool enable);

riscv_xlen_t
mstatus_set_mpie(riscv_xlen_t mstatus, bool enable);

riscv_xlen_t
mstatus_set_sie(riscv_xlen_t mstatus, bool enable);

riscv_xlen_t
mstatus_set_spie(riscv_xlen_t mstatus, bool enable);

riscv_xlen_t
mstatus_set_mprv(riscv_xlen_t mstatus, bool enable);

#endif /* RISCV_MSTATUS_H */