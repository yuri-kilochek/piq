#ifndef PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR
#define PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR

#include <stddef.h>
#include <assert.h>

typedef struct piq_allocator piq_allocator_t;

typedef struct {
    void (*retain)(piq_allocator_t *allocator);
    void (*release)(piq_allocator_t *allocator);

    void *(*allocate)(piq_allocator_t *allocator, ptrdiff_t *size,
                      ptrdiff_t alignment, _Bool fill_with_zeros);
    void (*deallocate)(piq_allocator_t *allocator, void *ptr, ptrdiff_t size,
                       ptrdiff_t alignment);
} piq_allocator_ops_t;

struct piq_allocator {
    piq_allocator_ops_t const *const ops;
};

piq_allocator_t *piq_get_default_allocator(void);

static inline
void piq_retain_allocator(piq_allocator_t *allocator) {
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->retain);
    allocator->ops->retain(allocator);
}

static inline
void piq_release_allocator(piq_allocator_t *allocator) {
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->release);
    allocator->ops->release(allocator);
}

static inline
void *piq_allocate(piq_allocator_t *allocator, ptrdiff_t *size,
                   ptrdiff_t alignment, _Bool fill_with_zeros)
{
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->allocate);
    return allocator->ops->allocate(allocator, size, alignment,
                                    fill_with_zeros);
}

static inline
void piq_deallocate(piq_allocator_t *allocator, void *ptr, ptrdiff_t size,
                    ptrdiff_t alignment)
{
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->deallocate);
    allocator->ops->deallocate(allocator, ptr, size, alignment);
}

#endif
