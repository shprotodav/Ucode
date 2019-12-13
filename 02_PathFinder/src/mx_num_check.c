#include "pathfinder.h"

int *mx_num_check(char *str) {
    int i = 0;
    int number = 0;

    while (mx_isdigit(str[i])) { 
        number = number * 10 + (str[i] - 48);
        i++;
    }
    if (i != 0 && str[i] == 0)
        return number;
    else
        return -1;
}

