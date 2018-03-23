#ifndef PIQ_IMPL_INCLUDE_GUARD_CONTEXT
#define PIQ_IMPL_INCLUDE_GUARD_CONTEXT

#include <piq/allocator.h>
#include <piq/status.h>

#if __cplusplus
extern "C" {
#endif

typedef struct piq_impl_context piq_context_t;

typedef struct piq_impl_context_params {
    piq_allocator_t *allocator;
} piq_context_params_t;

piq_status_t piq_create_context(piq_context_t **context,
                                piq_context_params_t const *params);

void piq_retain_context(piq_context_t *context);

void piq_release_context(piq_context_t *context);

piq_allocator_t *piq_get_allocator(piq_context_t *context);

piq_handle_t piq_acquire_global_c(piq_context_t *context, char const* name);
void piq_set_global_c(piq_context_t *context, char const* name,
                      piq_handle_t value);

// special result type?
piq_status_t piq_invoke(piq_context_t *context,
                        piq_handle_t *result,
                        piq_handle_t *exception,
                        piq_handle_t procedure,
                        piq_handle_t argument);

#if __cplusplus
} // extern "C"
#endif

#endif
