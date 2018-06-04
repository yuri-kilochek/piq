#include <piq/error.h>

#include <stddef.h>

char const *piq_describe_error(piq_error_t error) {
    switch (error) {
        case                     0: return "";
        case PIQ_ALLOCATION_FAILED: return "allocation failed";
        case      piq_error_t('~'): return "https://youtu.be/wwWC9tqOBVQ";
        default                   : return NULL;
    }
}
