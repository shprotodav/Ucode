#include "pathfinder.h"

void mx_matrix_mirror(int **matrix) {
    for (int i = 1; matrix[i]; i++)
        for (int j = 0; j < i; j++) {
            matrix[i][j] = matrix[j][i];
}
