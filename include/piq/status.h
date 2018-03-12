#ifndef PIQ_IMPL_INCLUDE_GUARD_STATUS
#define PIQ_IMPL_INCLUDE_GUARD_STATUS

#include <limits.h>

typedef enum piq_status {
    PIQ_IMPL_STATUS_STRUT = LONG_MAX,
} piq_status_t;

static 
piq_status_t const PIQ_OK = 0;

static 
piq_status_t const PIQ_INCOMPATIBLE = 1;

static 
piq_status_t const PIQ_ALLOCATOR_FAILED = 2;

#endif
