#include "libmx.h"



void *mx_realloc(void *ptr, size_t size) {
	if (!ptr)
		return malloc(size);
    
    size_t len = malloc_size(ptr);
    void  *str = NULL;
    
    if (len >= size) {
        return ptr;
    }
    else {
        str = malloc(size);
        str = mx_memcpy(str, ptr, size);
        free(ptr);
        return str;
    }
    return str;
}
// void *mx_realloc(void *ptr, size_t size) {
//     if (!ptr && size) return malloc(size);
    
//     if (size == 0 && ptr) {
//         free(ptr);
//         return NULL;
//     }
//     size_t len = malloc_size(ptr);
//     void *res;

//     if (len > size) {
//         res = malloc(len);
//         if (!res) return NULL;
//         res = mx_memmove(res, ptr, len);
//         free(ptr);
//     } else return ptr;
//     return res;
// }
