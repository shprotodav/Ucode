#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned long len = mx_strlen(s1);
    if (len > n) len = n;
    return mx_strncpy(mx_strnew(len), s1, len);
}


// int main() {
//   char a1[] = "lolkek hm/lolkek hm/lolkek hm/";
//   int c = 100;
//   char *b1 = mx_strndup(a1, c);
//   char *b2 = strndup(a1, c);
//   printf("kek\n");
//   printf("%zu\n", malloc_size(b1));
//   printf("%zu\n", malloc_size(b2));
//   return 0;
// }

