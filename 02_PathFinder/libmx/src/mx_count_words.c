#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str) return -1;
    int count = 0;
    
    while (*str != '\0') {  
        if (*str == c) //  Нашли разделитель!
            while (*str == c && *str != '\0')
                str++;
        if (*str != c && *str != '\0') { //  Нашли слово!
            count++;
            while (*str != c && *str != '\0')
                str++;
        }
    }
    return count;
}


// int main() {
//   char a1[] = "   lolkek     hm/lolkek hm/lolkek hm/   ";

//   //char *b1 = ;
//   //char *b2 = strndup(a1, c);
//   //printf("kek\n");
//   printf("%i\n", mx_count_words(a1, ' '));
//   //printf("%zu\n", malloc_size(b2));

//   return 0;
// }
