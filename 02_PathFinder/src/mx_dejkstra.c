#include "pathfinder.h"

static void refresh(int start, int **d);
static void loop(int **dist, t_path ****path_arr, int **d);
static void algorythm(int **dist, int **d, int start);

void mx_dejkstra(int **dist, int points_count, t_path ****path_arr) {
    int **d = malloc(sizeof(int *) * (points_count + 1)); // [][0]dist,[][1]fl
    int **p = d;

    for (int i = 0; i < points_count; i++)
        d[i] = malloc(sizeof(int) * 2);
    loop(dist, path_arr, d);
    while (*p) {
        free(*p);
        *p = NULL;
        p++;
    }
    free(d);
    d = NULL;
}

static void refresh(int start, int **d) {
    for (int i = 0; d[i]; i++) {
        if (i == start) {
            d[i][0] = 0;
            d[i][1] = 2; // start point
        }
        else {
            d[i][0] = -1;
            d[i][1] = 0;
        }
    }
}

static void loop(int **dist, t_path ****path_arr, int **d) {
    t_point *fin_point;

    for (int start = 0; d[start + 1]; start++) {
        algorythm(dist, d, start);
        d[start][1] = 2;
        for (int fin = start + 1; d[fin]; fin++) {
            if (fin != start) {
                fin_point = mx_create_point(fin);
                mx_rec_back(&fin_point, &((*path_arr)[start][fin]), dist, &d);
                mx_free_points(&fin_point);
            }
        }
    }
}

static void algorythm(int **dist, int **d, int start) {
    int index_min;
    int min = -1;

    refresh(start, d);
    for (int y = start, j = 0; d[j]; j++) { // dejkstra
        min = -1;
        for (int i = 0; d[i]; i++) {
            if (d[i][1] == 0) {
                d[i][0] = mx_min(d[i][0], d[y][0], dist[y][i]);
                if (((d[i][0] < min && d[i][0] > 0) || min < 0) && i != y) {
                    min = d[i][0];
                    index_min = i;
                }
            }   
        }
        d[index_min][1] = 1;
        y = index_min;
    }
}
