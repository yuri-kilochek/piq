#ifndef PIQ_IMPL_INCLUDE_GUARD_STATUS
#define PIQ_IMPL_INCLUDE_GUARD_STATUS

#include <stdint.h>

#if __cplusplus
extern "C" {
#endif

typedef int_least32_t piq_status_t;

#define PIQ_OK                (INT32_C(0))
#define PIQ_ALLOCATION_FAILED (INT32_C(1))

#if __cplusplus
} // extern "C"
#endif

#endif
