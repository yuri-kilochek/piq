#ifndef PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR
#define PIQ_IMPL_INCLUDE_GUARD_ALLOCATOR

#include <stdint.h>
#include <stddef.h>

#if __cplusplus
extern "C" {
#endif

typedef uint_least32_t piq_allocation_flags_t;

#define PIQ_FILLED_WITH_ZEROS (UINT32_C(0x00000001))

typedef struct piq_impl_allocator piq_allocator_t;

typedef struct piq_impl_allocator_ops {
    void (*retain)(piq_allocator_t *allocator);
    void (*release)(piq_allocator_t *allocator);

    void *(*allocate)(piq_allocator_t *allocator, ptrdiff_t *size,
                      ptrdiff_t alignment, piq_allocation_flags_t flags);
    void (*deallocate)(piq_allocator_t *allocator, void *ptr, ptrdiff_t size,
                       ptrdiff_t alignment);
} piq_allocator_ops_t;

struct piq_impl_allocator {
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
                   ptrdiff_t alignment, piq_allocation_flags_t flags)
{ return allocator->ops->allocate(allocator, size, alignment, flags); }

static inline
void piq_deallocate(piq_allocator_t *allocator, void *ptr, ptrdiff_t size,
                    ptrdiff_t alignment)
{ allocator->ops->deallocate(allocator, ptr, size, alignment); }

extern
piq_allocator_t *const piq_default_allocator;

#if __cplusplus
} // extern "C"
#endif

#endif
