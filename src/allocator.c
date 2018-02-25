#include <piq/allocator.h>

#include <stdbool.h>
#include <stdalign.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    piq_allocator_t base;
} default_type_t;

static
void default_retain(piq_allocator_t *base) {
    (void)base;
}

static
void default_release(piq_allocator_t *base) {
    (void)base;
}

static
void *default_allocate(piq_allocator_t *base, ptrdiff_t *size,
                       ptrdiff_t alignment, bool fill_with_zeros)
{
    (void)base;

    assert(size);

    void *ptr;
    if (fill_with_zeros && alignment <= (ptrdiff_t)alignof(max_align_t)) {
        ptr = calloc(*size, 1);
    } else {
        ptr = aligned_alloc(alignment, *size);
        if (fill_with_zeros && ptr) { memset(ptr, 0, *size); }
    }
    return ptr;
}

static
void default_deallocate(piq_allocator_t *base, void *ptr, ptrdiff_t size,
                        ptrdiff_t alignment)
{
    (void)base;
    (void)size;
    (void)alignment;

    free(ptr);
}

static
piq_allocator_ops_t const default_ops = {
    .retain = default_retain,
    .release = default_release,
    .allocate = default_allocate,
    .deallocate = default_deallocate,
};

static
default_type_t default_instance = {
    .base.ops = &default_ops,
};

piq_allocator_t *piq_get_default_allocator(void) {
    return (void*)&default_instance;
}
