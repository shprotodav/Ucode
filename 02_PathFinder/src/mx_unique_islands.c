#include "pathfinder.h"

char **mx_unique_islands(char ***data_arr, int *lines_count) {
    char **points_arr = malloc(sizeof(char **) * (*lines_count));
    int k = 0;

    for (int i = 0; data_arr[i]; i++) {
        if (is_unique(points_arr, data_arr[i][0])) {
            points_arr[k] = data_arr[i][0];
            k++;
        }
        if (is_unique(points_arr, data_arr[i][1])) {
            points_arr[k] = data_arr[i][1];
            k++;
        }
    }
    return points_arr;
}

static bool is_unique(char **points_arr, char *data_arr) {
    bool unique = true;

    for (int i = 0; points_arr[i]; i++) {
        if (mx_strcmp(points_arr[i], data_arr) == 0) {
            unique = false;
            break;
        }
    }
    return unique;
}

