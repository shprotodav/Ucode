#include "pathfinder.h"

int *mx_get_pcount(char **points_arr) {
    int *pcount = NULL;

    *pcount = 0;
    for (int i = 0; points_arr[i]; i++)
        (*pcount)++;
    return pcount;
}




