#ifndef PIQ_IMPL_INCLUDE_GUARD_OBJECT
#define PIQ_IMPL_INCLUDE_GUARD_OBJECT

typedef struct piq_object piq_object_t;

piq_handle_t piq_duplicate(piq_machine_t *machine, piq_object_t handle);

void piq_release(piq_handle_t handle);

#endif
