#ifndef PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR
#define PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR

#include <stddef.h>
#include <assert.h>

struct piq_allocator;

struct piq_allocator_ops {
    void (*retain)(struct piq_allocator *allocator);
    void (*release)(struct piq_allocator *allocator);

    void *(*allocate)(struct piq_allocator *allocator, ptrdiff_t size,
                      ptrdiff_t alignment, _Bool fill_with_zeros);
    void (*deallocate)(struct piq_allocator *allocator, void *ptr,
                       ptrdiff_t size, ptrdiff_t alignment);
};

struct piq_allocator {
    struct piq_allocator_ops const *const ops;
};

struct piq_allocator *piq_acquire_default_allocator(void);

static inline
void piq_retain_allocator(struct piq_allocator *allocator) {
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->retain);
    allocator->ops->retain(allocator);
}

static inline
void piq_release_allocator(struct piq_allocator *allocator) {
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->release);
    allocator->ops->release(allocator);
}

static inline
void *piq_allocate(struct piq_allocator *allocator, ptrdiff_t size,
                   ptrdiff_t alignment, _Bool fill_with_zeros)
{
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->allocate);
    return allocator->ops->allocate(allocator, size, alignment,
                                    fill_with_zeros);
}

static inline
void piq_deallocate(struct piq_allocator *allocator, void *ptr, ptrdiff_t size,
                    ptrdiff_t alignment)
{
    assert(allocator);
    assert(allocator->ops);
    assert(allocator->ops->deallocate);
    allocator->ops->deallocate(allocator, ptr, size, alignment);
}

#endif
