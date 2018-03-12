#ifndef PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR
#define PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR

#include <stddef.h>

typedef struct piq_allocator piq_allocator_t;

typedef struct piq_allocator_ops {
    void (*retain)(piq_allocator_t *allocator);
    void (*release)(piq_allocator_t *allocator);

    void *(*allocate)(piq_allocator_t *allocator, ptrdiff_t *size,
                      ptrdiff_t alignment, _Bool filled_with_zeros);
    void (*deallocate)(piq_allocator_t *allocator, void *ptr, ptrdiff_t size,
                       ptrdiff_t alignment);
} piq_allocator_ops_t;

struct piq_allocator {
    piq_allocator_ops_t const *const ops;
};

static inline
void piq_retain_allocator(piq_allocator_t *allocator) {
    allocator->ops->retain(allocator);
}

static inline
void piq_release_allocator(piq_allocator_t *allocator) {
    allocator->ops->release(allocator);
}

static inline
void *piq_allocate(piq_allocator_t *allocator, ptrdiff_t *size,
                   ptrdiff_t alignment, _Bool filled_with_zeros)
{
    return allocator->ops->allocate(allocator, size, alignment,
                                    filled_with_zeros);
}

static inline
void piq_deallocate(piq_allocator_t *allocator, void *ptr, ptrdiff_t size,
                    ptrdiff_t alignment)
{
    allocator->ops->deallocate(allocator, ptr, size, alignment);
}

extern
piq_allocator_t *const piq_default_allocator;

#endif
