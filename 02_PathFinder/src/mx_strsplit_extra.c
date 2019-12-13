#include "libmx.h"

char **mx_strsplit_extra(const char *s, char c) {
    if (!s) return NULL;

    int words = mx_count_words_extra(s, c);
    char **res = malloc((words + 1) * sizeof(char *));
    res[words] = NULL;
    int i = 0;
    int ptr = 0;
    char *word = (char *)s;
    char *tmp = NULL;
    
    
    while (words--) {
        word = mx_strtrim_char(word, c);
        tmp = word;
        ptr = mx_get_char_index(word, c);
        if (ptr == -1)
            res[i] = mx_strdup(word);
        else
            res[i] = mx_strndup(word, ptr);
        i++;
        word += ptr;
        free(tmp);
    }
    return res;
}







-a--a0