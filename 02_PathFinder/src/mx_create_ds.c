#include "pathfinder.h"

void mx_create_ds(int **D, int **S, char **data_arr, int points_count) {
    D = malloc(sizeof(int **) * points_count);
    for (int i = 0; i < points_count; i++)
        D[i] = malloc(sizeof(int *) * points_count);
    S = malloc(sizeof(int **) * points_count);
    for (int i = 0; i < points_count; i++)
        S[i] = malloc(sizeof(int *) * points_count);
}

