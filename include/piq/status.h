#ifndef PIQ_IMPL_INCLUDE_GUARD_STATUS
#define PIQ_IMPL_INCLUDE_GUARD_STATUS

#include <stdint.h>

#if __cplusplus
extern "C" {
#endif

typedef uint_least32_t piq_status_t;

#define PIQ_OK                (UINT32_C(0))
#define PIQ_INCOMPATIBLE      (UINT32_C(1))
#define PIQ_ALLOCATION_FAILED (UINT32_C(2))

#if __cplusplus
} // extern "C"
#endif

#endif
