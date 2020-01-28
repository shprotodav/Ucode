#include "pathfinder.h"

void del_int2arr(int ***arr);
void del_path_arr(t_path ****path_arr);

void mx_freesher(char ****data_arr, char ***points_arr,
int ***dist, t_path ****path_arr) {
    
    mx_del_strarr(*data_arr);

    
    mx_del_strarr(points_arr);
    del_int2arr(dist);

    return;
    del_path_arr(path_arr);
    
    free(*data_arr);
}

void del_int2arr(int ***arr) {
    int **p = *arr;
    
    while (*p) {
        free(*p);
        *p = NULL;
        p++;
    }
    free(*arr);
    *arr = NULL;
}

void del_path_arr(t_path ****path_arr) {
    t_path *pointer = NULL;

    for (int i = 0; (*path_arr)[i]; i++) {
        for (int j = 0; (*path_arr)[i][j]; j++){
            pointer = (*path_arr)[i][j];

            for (; (*path_arr[i][j])->next != NULL; (*path_arr)[i][j] = pointer) {
                pointer = (*path_arr)[i][j]->next;
                free(path_arr[i][j]);
            }
            free(path_arr[i][j]);
            pointer = NULL;
            path_arr[i][j] = NULL;
        }
    }
}
