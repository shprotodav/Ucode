#include "pathfinder.h"

void mx_create_ds(int **D, int **S, char ***data_arr, int points_count) {
    D = malloc(sizeof(int **) * points_count);
    for (int i = 0; i < points_count; i++)
        D[i] = malloc(sizeof(int *) * points_count);
    S = malloc(sizeof(int **) * points_count);
    for (int i = 0; i < points_count; i++)
        S[i] = malloc(sizeof(int *) * points_count);
        
    set_D0(D, data_arr, points_count);
    set_S0(S, points_count);
    mx_matrix_mirror(D);


}

static void set_D0(int **D, char ***data_arr, int points_count) {
    for (int i = 0; i < points_count; i++) {
        for (int j = i; j < points_count; j++) {
            D[i][j] = -1;
            for (int k = 0; data_arr[k]; k++) {
                if (i == j) {
                    D[i][j] = -2;
                    break;
                }
                if (mx_strcmp(points_arr[i], data_arr[k][0]) == 0 &&
                    mx_strcmp(points_arr[j], data_arr[k][1]) == 0 ||
                    mx_strcmp(points_arr[i], data_arr[k][1]) == 0 &&
                    mx_strcmp(points_arr[j], data_arr[k][0]))
                {
                    D[i][j] = mx_atoi(data_arr[k][2]);
                    break;
                }
            }
        }
    }
}

static void set_S0(int **S, int points_count) {
    for (int i = 0; i < points_count; i++) {
        for (int j = 0; j < points_count; j++) {
            if (i == j)
                S[i][j] = -2;
            else
                S[i][j] = j;
        }
    }
}
