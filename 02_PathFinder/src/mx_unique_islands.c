#include "pathfinder.h"

static void is_pcount_bigger(int k, int points_count);
static void is_pcount_lower(int k, int points_count);
static bool is_unique(char **points_arr, char *data_arr);

char **mx_unique_islands(char ***data_arr, int *points_count) {
    char **points_arr = malloc(sizeof(char *) * ((*points_count) + 1));
    int k = 0;

    for (int i = 0; i < *points_count + 1; i++)
        points_arr[i] = NULL;
    for (int i = 0; data_arr[i + 1]; i++) {
        for (int j = 0; j < 2; j++) {
            if (is_unique(points_arr, data_arr[i + 1][j])) {
                is_pcount_bigger(k, *points_count);
                points_arr[k] = mx_strnew(mx_strlen(data_arr[i + 1][j]));
                mx_strcpy(points_arr[k], data_arr[i + 1][j]);
                k++;
            }
        }
    }
    is_pcount_lower(k, *points_count);
    return points_arr;
}

static void is_pcount_bigger(int k, int points_count) {
    if (k + 1 > points_count)
        mx_print_error(4, NULL);
}

static void is_pcount_lower(int k, int points_count) {
    if (k < points_count)
        mx_print_error(4, NULL);
}

static bool is_unique(char **points_arr, char *point) {
    bool unique = true;

    for (int i = 0; points_arr[i] != NULL; i++) {
        if (mx_strcmp(points_arr[i], point) == 0) {
            unique = false;
            break;
        }
    }
    return unique;
}
