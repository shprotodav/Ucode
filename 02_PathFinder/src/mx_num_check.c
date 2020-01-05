#include "pathfinder.h"

// Done

int *mx_num_check(char *str) {
    int i = 0;
    int number = 0;

    for (; mx_isdigit(str[i]); i++)
        number = number * 10 + (str[i] - 48);
    if (i != 0 && str[i] == '\0')
        return number;
    else
        return -1; // Line 1 fail 
}
