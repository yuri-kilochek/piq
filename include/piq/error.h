#ifndef PIQ_IMPL_INCLUDE_GUARD_ERROR
#define PIQ_IMPL_INCLUDE_GUARD_ERROR

#if __cplusplus
extern "C" {
#endif

typedef unsigned int piq_error_t;

#define PIQ_ALLOCATION_FAILED 1u

char const *piq_describe_error(piq_error_t error);

#if __cplusplus
} // extern "C"
#endif

#endif
