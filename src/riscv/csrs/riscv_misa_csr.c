#include <riscv/csrs/riscv_misa_csr.h>

__attribute__((always_inline)) static inline bool
__misa_is_implemented(riscv_xlen_t misa)
{
    return (misa != (riscv_xlen_t)0U);
}

__attribute__((always_inline)) static inline riscv_mxl_t
__misa_get_mxl(riscv_xlen_t misa)
{
    riscv_mxl_t mxl;
    riscv_xlen_t raw = (misa & MISA_MXL_MASK) >> MISA_MXL_SHIFT;

    switch (raw)
    {
        case 0x1U:
            mxl = MXL_32;
            break;
        case 0x2U:
            mxl = MXL_64;
            break;
        default:
            mxl = MXL_RESERVED; /* 0x3 reserved or 0x0 if misa unimplemented */
            break;
    }

    return mxl;
}

__attribute__((always_inline)) static inline riscv_xlen_t
__misa_get_extensions(riscv_xlen_t misa)
{
    return ((misa & MISA_EXTENSIONS_MASK) >> MISA_EXTENSIONS_SHIFT);
}

__attribute__((always_inline)) static inline bool
__misa_has_extension(riscv_xlen_t misa, riscv_xlen_t ext_mask)
{
    riscv_xlen_t masked_ext = ext_mask & MISA_EXTENSIONS_MASK;
    return ((masked_ext != (riscv_xlen_t)0U) && ((misa & masked_ext) == masked_ext));
}

__attribute__((always_inline)) static inline bool
__misa_is_rv32e(riscv_xlen_t misa)
{
    return __misa_has_extension(misa, MISA_EXT_E_MASK);
}

__attribute__((always_inline)) static inline bool
__misa_has_supervisor_mode(riscv_xlen_t misa)
{
    return __misa_has_extension(misa, MISA_EXT_S_MASK);
}

__attribute__((always_inline)) static inline bool
__misa_has_user_mode(riscv_xlen_t misa)
{
    return __misa_has_extension(misa, MISA_EXT_U_MASK);
}


bool
misa_is_implemented(riscv_xlen_t misa)
{
    return __misa_is_implemented(misa);
}

riscv_mxl_t
misa_get_mxl(riscv_xlen_t misa)
{
    return __misa_get_mxl(misa);
}

riscv_xlen_t
misa_get_extensions(riscv_xlen_t misa)
{
    return __misa_get_extensions(misa);
}

bool
misa_has_extension(riscv_xlen_t misa, riscv_xlen_t ext_mask)
{
    return __misa_has_extension(misa, ext_mask);
}

bool
misa_is_rv32e(riscv_xlen_t misa)
{
    return __misa_is_rv32e(misa);
}

bool
misa_has_supervisor_mode(riscv_xlen_t misa)
{
    return __misa_has_supervisor_mode(misa);
}

bool
misa_has_user_mode(riscv_xlen_t misa)
{
    return __misa_has_user_mode(misa);
}