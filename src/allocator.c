#include <piq/allocator.h>

#include <stdlib.h>
#include <string.h>

typedef struct default_ {
    piq_allocator_t base;
} default_t;

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
                       ptrdiff_t alignment, _Bool filled_with_zeros)
{
    (void)base;

    void *ptr;
    if (filled_with_zeros && alignment <= (ptrdiff_t)_Alignof(max_align_t)) {
        ptr = calloc(*size, 1);
    } else {
        ptr = aligned_alloc(alignment, *size);
        if (filled_with_zeros && ptr) { memset(ptr, 0, *size); }
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
default_t default_ = {
    .base.ops = &default_ops,
};

piq_allocator_t *piq_get_default_allocator(void) {
    return (void*)&default_;
}
