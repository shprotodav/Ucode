#include "pathfinder.h"

static void print_out(char **points_arr, int **dist,
t_path ***path_arr, int points_count);

int main(int argc, char **argv) {
    char **points_arr = NULL;
    int *points_count = malloc(sizeof(int));
    char ***data_arr = mx_validation(argc, argv, &points_arr, points_count);
    int **dist = NULL;
    t_path ***path_arr = malloc(sizeof(t_path **) * (*points_count + 1));

    for (int i = 0; i < *points_count; i++) {
        path_arr[i] = malloc(sizeof(t_path *) * (*points_count + 1));
        for (int j = 0; j < *points_count; j++)
            path_arr[i][j] = NULL;
    }
    mx_create_ds(&dist, data_arr, points_arr, *points_count);
    mx_dejkstra(dist, *points_count, &path_arr);
    print_out(points_arr, dist, path_arr, *points_count);
    return 0;
}

static void print_out(char **points_arr, int **dist,
t_path ***path_arr, int points_count) {
    int *s_f = malloc(sizeof(int) * (2)); // start_fin

    for (s_f[0] = 0; s_f[0] < points_count - 1; s_f[0]++) {
        for (s_f[1] = s_f[0] + 1; s_f[1] < points_count; s_f[1]++) {
            for (t_path *p = path_arr[s_f[0]][s_f[1]]; p; p = p->next) {
                mx_print_result(points_arr, p->start, dist, s_f);
            }
        }
    }
    free(s_f);
    s_f = NULL;
}



