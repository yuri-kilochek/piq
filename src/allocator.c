#include <piq/allocator.h>

#include <stdbool.h>
#include <stdalign.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    piq_allocator_t base;
} default_type_t;

static
void retain(piq_allocator_t *base) {
    (void)base;
}

static
void release(piq_allocator_t *base) {
    (void)base;
}

static
void *allocate(piq_allocator_t *base, ptrdiff_t size, ptrdiff_t alignment,
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
void deallocate(piq_allocator_t *base, void *ptr, ptrdiff_t size,
                ptrdiff_t alignment)
{
    (void)base;
    (void)size;
    (void)alignment;

    free(ptr);
}

static
piq_allocator_ops_t const ops = {
    .retain = retain,
    .release = release,
    .allocate = allocate,
    .deallocate = deallocate,
};

static
default_type_t default_instance = {
    .base.ops = &ops,
};

piq_allocator_t *piq_get_default_allocator(void) {
    return (void*)&default_instance;
}
