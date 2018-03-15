#ifndef PIQ_IMPL_INCLUDE_GUARD
#define PIQ_IMPL_INCLUDE_GUARD

#include <piq/version.h>

typedef struct {} *piq_handle_t;

piq_handle_t piq_acquire_type(piq_handle_t object);
piq_handle_t piq_acquire_member(piq_handle_t object, char const *name);

piq_handle_t piq_retain(piq_handle_t handle);

void piq_release(piq_handle_t handle);

_Bool piq_getMember(
    piq_Handle *member,
    piq_Handle const *aggregate,
    char const* memberName,
    piq_Handle *exception);

_Bool piq_setMember(
    piq_Handle const *aggregate,
    char const* memberName,
    piq_Handle const* member,
    piq_Handle *exception);

_Bool piq_call(
    piq_Handle *result,
    piq_Handle const *callable,
    piq_Handle const *argument,
    piq_Handle *exception);

#endif
