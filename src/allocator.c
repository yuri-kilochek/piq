#include <piq/allocator.h>

#include <stdbool.h>
#include <stdalign.h>
#include <stdlib.h>
#include <string.h>

struct type {
    struct piq_allocator base;
};

static
void retain(struct piq_allocator *base) {
    (void)base;
}

static
void release(struct piq_allocator *base) {
    (void)base;
}

static
void *allocate(struct piq_allocator *base, ptrdiff_t size, ptrdiff_t alignment,
               bool fill_with_zeros)
{
    (void)base;

    void *ptr;
    if (fill_with_zeros && alignment <= (ptrdiff_t)alignof(max_align_t)) {
        ptr = calloc(size, 1);
    } else {
        ptr = aligned_alloc(alignment, size);
        if (fill_with_zeros && ptr) { memset(ptr, 0, size); }
    }
    return ptr;
}

static
void deallocate(struct piq_allocator *base, void *ptr, ptrdiff_t size,
                ptrdiff_t alignment)
{
    (void)base;
    (void)size;
    (void)alignment;

    free(ptr);
}

static
struct piq_allocator_ops const ops = {
    .retain = retain,
    .release = release,
    .allocate = allocate,
    .deallocate = deallocate,
};

static
struct type instance = {
    .base.ops = &ops,
};

struct piq_allocator *piq_acquire_default_allocator(void) {
    return (void*)&instance;
}
