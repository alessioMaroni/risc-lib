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

__attribute__((always_inline)) static inline bool
__mstatus_is_mie_enabled(riscv_xlen_t mstatus)
{
    return ((mstatus & MSTATUS_MIE_MASK) != (riscv_xlen_t)0U);
}

__attribute__((always_inline)) static inline bool
__mstatus_is_mpie_set(riscv_xlen_t mstatus)
{
    return ((mstatus & MSTATUS_MPIE_MASK) != (riscv_xlen_t)0U);
}

__attribute__((always_inline)) static inline bool
__mstatus_is_sie_enabled(riscv_xlen_t mstatus)
{
    return ((mstatus & MSTATUS_SIE_MASK) != (riscv_xlen_t)0U);
}

__attribute__((always_inline)) static inline bool
__mstatus_is_spie_set(riscv_xlen_t mstatus)
{
    return ((mstatus & MSTATUS_SPIE_MASK) != (riscv_xlen_t)0U);
}

__attribute__((always_inline)) static inline bool
__mstatus_is_mprv_enabled(riscv_xlen_t mstatus)
{
    return ((mstatus & MSTATUS_MPRV_MASK) != (riscv_xlen_t)0U);
}


__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mpp(riscv_xlen_t mstatus, riscv_priv_mode_t mode)
{
    riscv_xlen_t encoded = ((riscv_xlen_t)mode << MSTATUS_MPP_SHIFT) & MSTATUS_MPP_MASK;
    return ((mstatus & ~MSTATUS_MPP_MASK) | encoded);
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_vs(riscv_xlen_t mstatus, riscv_ext_state_t state)
{
    riscv_xlen_t encoded = ((riscv_xlen_t)state << MSTATUS_VS_SHIFT) & MSTATUS_VS_MASK;
    return ((mstatus & ~MSTATUS_VS_MASK) | encoded);
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_fs(riscv_xlen_t mstatus, riscv_ext_state_t state)
{
    riscv_xlen_t encoded = ((riscv_xlen_t)state << MSTATUS_FS_SHIFT) & MSTATUS_FS_MASK;
    return ((mstatus & ~MSTATUS_FS_MASK) | encoded);
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_xs(riscv_xlen_t mstatus, riscv_ext_state_t state)
{
    riscv_xlen_t encoded = ((riscv_xlen_t)state << MSTATUS_XS_SHIFT) & MSTATUS_XS_MASK;
    return ((mstatus & ~MSTATUS_XS_MASK) | encoded);
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mie(riscv_xlen_t mstatus, bool enable)
{
    riscv_xlen_t updated;

    if (enable)
    {
        updated = (mstatus | MSTATUS_MIE_MASK);
    }
    else
    {
        updated = (mstatus & ~MSTATUS_MIE_MASK);
    }

    return updated;
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mpie(riscv_xlen_t mstatus, bool enable)
{
    riscv_xlen_t updated;

    if (enable)
    {
        updated = (mstatus | MSTATUS_MPIE_MASK);
    }
    else
    {
        updated = (mstatus & ~MSTATUS_MPIE_MASK);
    }

    return updated;
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_sie(riscv_xlen_t mstatus, bool enable)
{
    riscv_xlen_t updated;

    if (enable)
    {
        updated = (mstatus | MSTATUS_SIE_MASK);
    }
    else
    {
        updated = (mstatus & ~MSTATUS_SIE_MASK);
    }

    return updated;
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_spie(riscv_xlen_t mstatus, bool enable)
{
    riscv_xlen_t updated;

    if (enable)
    {
        updated = (mstatus | MSTATUS_SPIE_MASK);
    }
    else
    {
        updated = (mstatus & ~MSTATUS_SPIE_MASK);
    }

    return updated;
}

__attribute__((always_inline)) static inline riscv_xlen_t
__mstatus_set_mprv(riscv_xlen_t mstatus, bool enable)
{
    riscv_xlen_t updated;

    if (enable)
    {
        updated = (mstatus | MSTATUS_MPRV_MASK);
    }
    else
    {
        updated = (mstatus & ~MSTATUS_MPRV_MASK);
    }

    return updated;
}


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

bool
mstatus_is_mie_enabled(riscv_xlen_t mstatus)
{
    return __mstatus_is_mie_enabled(mstatus);
}

bool
mstatus_is_mpie_set(riscv_xlen_t mstatus)
{
    return __mstatus_is_mpie_set(mstatus);
}

bool
mstatus_is_sie_enabled(riscv_xlen_t mstatus)
{
    return __mstatus_is_sie_enabled(mstatus);
}

bool
mstatus_is_spie_set(riscv_xlen_t mstatus)
{
    return __mstatus_is_spie_set(mstatus);
}

bool
mstatus_is_mprv_enabled(riscv_xlen_t mstatus)
{
    return __mstatus_is_mprv_enabled(mstatus);
}


riscv_xlen_t
mstatus_set_mpp(riscv_xlen_t mstatus, riscv_priv_mode_t mode)
{
    return __mstatus_set_mpp(mstatus, mode);
}

riscv_xlen_t
mstatus_set_vs(riscv_xlen_t mstatus, riscv_ext_state_t state)
{
    return __mstatus_set_vs(mstatus, state);
}

riscv_xlen_t
mstatus_set_fs(riscv_xlen_t mstatus, riscv_ext_state_t state)
{
    return __mstatus_set_fs(mstatus, state);
}

riscv_xlen_t
mstatus_set_xs(riscv_xlen_t mstatus, riscv_ext_state_t state)
{
    return __mstatus_set_xs(mstatus, state);
}

riscv_xlen_t
mstatus_set_mie(riscv_xlen_t mstatus, bool enable)
{
    return __mstatus_set_mie(mstatus, enable);
}

riscv_xlen_t
mstatus_set_mpie(riscv_xlen_t mstatus, bool enable)
{
    return __mstatus_set_mpie(mstatus, enable);
}

riscv_xlen_t
mstatus_set_sie(riscv_xlen_t mstatus, bool enable)
{
    return __mstatus_set_sie(mstatus, enable);
}

riscv_xlen_t
mstatus_set_spie(riscv_xlen_t mstatus, bool enable)
{
    return __mstatus_set_spie(mstatus, enable);
}

riscv_xlen_t
mstatus_set_mprv(riscv_xlen_t mstatus, bool enable)
{
    return __mstatus_set_mprv(mstatus, enable);
}