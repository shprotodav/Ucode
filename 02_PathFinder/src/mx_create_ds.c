#include "pathfinder.h"

static void set_D0(int ***dist, char ***data_arr,
char **points_arr, int points_count);

void mx_create_ds(int ***dist, char ***data_arr,
char **points_arr, int points_count) {
    *dist = malloc(sizeof(int *) * points_count);
    for (int i = 0; i < points_count; i++)
        (*dist)[i] = malloc(sizeof(int) * points_count);
    set_D0(dist, data_arr, points_arr, points_count);
    mx_matrix_mirror(dist, points_count);
}

static void set_D0(int ***dist, char ***data_arr,
char **points_arr, int points_count) {
    for (int i = 0; i < points_count; i++) {
        for (int j = i; j < points_count; j++) {
            (*dist)[i][j] = -1;
            for (int k = 1; data_arr[k]; k++) {
                if (i == j) {
                    (*dist)[i][j] = 0;
                    break;
                }
                if ((mx_strcmp(points_arr[i], data_arr[k][0]) == 0 &&
                    mx_strcmp(points_arr[j], data_arr[k][1]) == 0) ||
                    (mx_strcmp(points_arr[i], data_arr[k][1]) == 0 &&
                    mx_strcmp(points_arr[j], data_arr[k][0]) == 0))
                {
                    (*dist)[i][j] = mx_atoi(data_arr[k][2]);
                    break;
                }
            }
        } 
    }
}


