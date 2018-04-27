#include <piq/error.h>

#include <stddef.h>

char const *piq_describe_error(piq_error_t error) {
    switch (error) {
        case                     0: return "";
        case PIQ_ALLOCATION_FAILED: return "allocation failed";
        default                   : return NULL;
    }
}
