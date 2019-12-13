#include "pathfinder.h"

void mx_create_ds(int **D, int **S, char **data_arr, int n) {
    // D = malloc(sizeof(int **) * (n));
    // for (int i = 0; i < n; i++) {
    D = malloc(sizeof(int *) * (n));
    for (int j = 0; j < n; j++)
        D[j] = malloc(j * sizeof(int));
    // }
    S = malloc(sizeof(int *) * (n - 1));
    for (int j = 0; j < n - 1; j++)
        S[j] = malloc(j + 1) * sizeof(int));
    
    
}

