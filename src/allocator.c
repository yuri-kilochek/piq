#include <piq/allocator.h>

#include <stdlib.h>
#include <string.h>

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
                       ptrdiff_t alignment, piq_allocation_flags_t flags)
{
    (void)base;

    _Bool filled_with_zeros = flags & PIQ_FILLED_WITH_ZEROS;

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

piq_allocator_t *const piq_default_allocator = &(piq_allocator_t) {
    .ops = &(piq_allocator_ops_t) {
        .retain = default_retain,
        .release = default_release,
        .allocate = default_allocate,
        .deallocate = default_deallocate,
    },
};
