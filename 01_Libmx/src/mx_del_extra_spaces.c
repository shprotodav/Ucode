#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *res;
    char *buf = mx_strnew(mx_strlen(str));
    int k = 0;
    
    for (int i = 0; str[i]; buf[k++] = str[i++])
        if (mx_isspace(str[i])) {
            while (mx_isspace(str[++i]));
            buf[k++] = ' ';
        }
    res = mx_strtrim(buf);
    mx_strdel(&buf);
    return res;
}


// int main() {
//   char *a1 = "   lolkek     hm/lolkek   hm/lolkek hm   ";

//   //char *b1 = ;
//   //char *b2 = strndup(a1, c);
//   //printf("kek\n");
//   printf("%s*\n", mx_del_extra_spaces(a1));
//   //printf("%zu\n", malloc_size(b2));

//   return 0;
// }
