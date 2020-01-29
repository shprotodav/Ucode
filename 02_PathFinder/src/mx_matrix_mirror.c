#include "pathfinder.h"

void mx_matrix_mirror(int ***matrix, int points_count) {
    for (int i = 0; i < points_count - 1; i++){
        for (int j = i + 1; j < points_count; j++)
            (*matrix)[j][i] = (*matrix)[i][j];
    }
}
