#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) return NULL;

    int start = 0;
    int end = mx_strlen(str) - 1;

    for(; mx_isspace(str[start]); start++);
    if (start == end + 1)
        return mx_strnew(0);
    for(; mx_isspace(str[end]); end--);

    char *res = malloc(end - start + 2);
    if (!res) return NULL;

    for (int i = 0; i + start != end + 1; i++)
        res[i] = str[start + i];
    res[end + 1 - start] = '\0';
    return res;
}

// int main() {
//   char *a1 = "   lolkek     hm/lolkek hm/lolkek hm   ";

//   //char *b1 = ;
//   //char *b2 = strndup(a1, c);
//   //printf("kek\n");
//   printf("%s*\n", mx_strtrim(a1));
//   //printf("%zu\n", malloc_size(b2));

//   return 0;
// }
