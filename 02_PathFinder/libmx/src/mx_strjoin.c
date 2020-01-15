#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    if (s2 == NULL)
        return mx_strdup(s1);
    return mx_strcat(mx_strcpy(mx_strnew(mx_strlen(s1) + mx_strlen(s2)), s1), s2);
}


// int main() {
//   //char *a1 = "   lolkek     hm/lolkek hm/lolkek hm   ";

//   char b1[] = "123";
//   char b2[] = "567";
//   //printf("kek\n");
//   char *b3 = mx_strjoin(b1,b2);
//   printf("%s*\n", b3);
//   //printf("%s*\n", mx_strdup(b1));
//   //printf("%zu\n", malloc_size(b2));
//   mx_leaks();

//   return 0;
// }
