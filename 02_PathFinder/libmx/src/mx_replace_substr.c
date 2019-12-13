#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;
    
    int sub_count = mx_count_substr(str, sub);
    int sub_len = mx_strlen(sub);

    char *result = mx_strnew(mx_strlen(str) + sub_count * (mx_strlen(replace) - sub_len));

    for (int index = 0; sub_count--; str += index + sub_len) {
        index = mx_get_substr_index(str, sub); // Find index of next sub
        mx_strcat(result, mx_strndup(str, index)); // Add other text before sub
        mx_strcat(result, replace); // Add 1 replace text
    }
    mx_strcat(result, str); // Add text after all subs
    return result;
}


// int main() {
//     char *a1 = mx_replace_substr("McDonaldsMcDonaldsMcDonaldsMcDonaldsMcDonaldsMcDonald   sMcDonaldsMcDonaldsMcDonaldsMcDonalds", "alds", "uts"); 
//     char *a2 = mx_replace_substr("Ururu turu", "ru", "ta"); 
//     mx_printstr(a1);
//     mx_printn();
//     mx_printstr(a2);
//     return 0;
// }

