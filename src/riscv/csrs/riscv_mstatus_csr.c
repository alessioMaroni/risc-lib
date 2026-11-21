#include <riscv/csrs/riscv_mstatus_csr.h>

__attribute__((always_inline)) static inline riscv_priv_mode_t
__mstatus_get_mpp(riscv_xlen_t mstatus)
{
    riscv_priv_mode_t mode;
    riscv_xlen_t raw = (mstatus & MSTATUS_MPP_MASK) >> MSTATUS_MPP_SHIFT;

    switch (raw)
    {
        case 0x0U:
            mode = PRIV_USER;
            break;
        case 0x1U:
            mode = PRIV_SUPERVISOR;
            break;
        case 0x3U:
            mode = PRIV_MACHINE;
            break;
        default:
            mode = PRIV_USER; /* 0x2 reserved */
            break;
    }

    return mode;
}

__attribute__((always_inline)) static inline riscv_ext_state_t
__mstatus_get_vs(riscv_xlen_t mstatus)
{
    riscv_ext_state_t state;
    riscv_xlen_t raw = (mstatus & MSTATUS_VS_MASK) >> MSTATUS_VS_SHIFT;

    switch (raw)
    {
        case 0x0U:
            state = EXT_STATE_OFF;
            break;
        case 0x1U:
            state = EXT_STATE_INITIAL;
            break;
        case 0x2U:
            state = EXT_STATE_CLEAN;
            break;
        default:
            state = EXT_STATE_DIRTY; /* 0x3U */
            break;
    }

    return state;
}

__attribute__((always_inline)) static inline riscv_ext_state_t
__mstatus_get_fs(riscv_xlen_t mstatus)
{
    riscv_ext_state_t state;
    riscv_xlen_t raw = (mstatus & MSTATUS_FS_MASK) >> MSTATUS_FS_SHIFT;

    switch (raw)
    {
        case 0x0U:
            state = EXT_STATE_OFF;
            break;
        case 0x1U:
            state = EXT_STATE_INITIAL;
            break;
        case 0x2U:
            state = EXT_STATE_CLEAN;
            break;
        default:
            state = EXT_STATE_DIRTY; /* 0x3U */
            break;
    }

    return state;
}

__attribute__((always_inline)) static inline riscv_ext_state_t
__mstatus_get_xs(riscv_xlen_t mstatus)
{
    riscv_ext_state_t state;
    riscv_xlen_t raw = (mstatus & MSTATUS_XS_MASK) >> MSTATUS_XS_SHIFT;

    switch (raw)
    {
        case 0x0U:
            state = EXT_STATE_OFF;
            break;
        case 0x1U:
            state = EXT_STATE_INITIAL;
            break;
        case 0x2U:
            state = EXT_STATE_CLEAN;
            break;
        default:
            state = EXT_STATE_DIRTY; /* 0x3U */
            break;
    }

    return state;
}

__attribute__((always_inline)) static inline bool
__mstatus_is_sd_set(riscv_xlen_t mstatus)
{
    return ((mstatus & MSTATUS_SD_MASK) != (riscv_xlen_t)0U);
}

/* ===================================== */

riscv_priv_mode_t
mstatus_get_mpp(riscv_xlen_t mstatus)
{
    return __mstatus_get_mpp(mstatus);
}

riscv_ext_state_t
mstatus_get_vs(riscv_xlen_t mstatus)
{
    return __mstatus_get_vs(mstatus);
}

riscv_ext_state_t
mstatus_get_fs(riscv_xlen_t mstatus)
{
    return __mstatus_get_fs(mstatus);
}

riscv_ext_state_t
mstatus_get_xs(riscv_xlen_t mstatus)
{
    return __mstatus_get_xs(mstatus);
}

bool
mstatus_is_sd_set(riscv_xlen_t mstatus)
{
    return __mstatus_is_sd_set(mstatus);
}