#ifndef RISCV_MSTATUS_H
#define RISCV_MSTATUS_H

#include <riscv/riscv_xlen.h>
#include <stdbool.h>

/* Previous Privilege Mode (MPP) */
#define MSTATUS_MPP_SHIFT 11U
#define MSTATUS_MPP_MASK  ((riscv_xlen_t)0x3U << MSTATUS_MPP_SHIFT)

typedef enum
{
    PRIV_USER       = 0x0, /* 00: User Mode */
    PRIV_SUPERVISOR = 0x1, /* 01: Supervisor Mode */
    /* 0x2 reserved */
    PRIV_MACHINE    = 0x3  /* 11: Machine Mode */
} riscv_priv_mode_t;

/* Vector Extension State (VS) */
#define MSTATUS_VS_SHIFT  9U
#define MSTATUS_VS_MASK   ((riscv_xlen_t)0x3U << MSTATUS_VS_SHIFT)

/* Floating-Point Extension State (FS) */
#define MSTATUS_FS_SHIFT  13U
#define MSTATUS_FS_MASK   ((riscv_xlen_t)0x3U << MSTATUS_FS_SHIFT)

/* User Extension State (XS) */
#define MSTATUS_XS_SHIFT  15U
#define MSTATUS_XS_MASK   ((riscv_xlen_t)0x3U << MSTATUS_XS_SHIFT)

typedef enum
{
    EXT_STATE_OFF     = 0x0, /* 00: Off */
    EXT_STATE_INITIAL = 0x1, /* 01: Initialized */
    EXT_STATE_CLEAN   = 0x2, /* 10: Clean */
    EXT_STATE_DIRTY   = 0x3  /* 11: Dirty */
} riscv_ext_state_t;

/* State Dirty Summary (SD) */
#if RISCV_XLEN == 64
    #define MSTATUS_SD_SHIFT 63U
#elif RISCV_XLEN == 32
    #define MSTATUS_SD_SHIFT 31U
#endif /* RISCV_XLEN */

#define MSTATUS_SD_MASK   ((riscv_xlen_t)1U << MSTATUS_SD_SHIFT)

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

#endif /* RISCV_MSTATUS_H */