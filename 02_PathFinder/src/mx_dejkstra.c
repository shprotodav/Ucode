#include "pathfinder.h"

void mx_dejkstra(int **dist, int *start_fin,
char **points_arr, int points_count) {
    int **d = malloc(sizeof(int) * points_count); // [][0]dist,[][1]fl
    int **br_flags = malloc(sizeof(int) * points_count);
    int index_min;
    int min = -1;

    for (int i = 0; i < points_count; i++)
        d[i] = malloc(sizeof(int) * 2);
    for (int i = 0; i < points_count; i++)
        br_flags[i] = malloc(sizeof(int) * points_count);
    for (int i = 0; i < points_count; i++)
        if (i == start_fin[0])
            d[i][0] = 0;
        else
            d[i][0] = -1;
    for (int y = start_fin[0]; ; y = index_min) {
        min = -1;
        for (int i = 0; i < points_count; i++)
            if (d[i][1] != 1) {
                d[i][0] = mx_min(d[i][0], d[y][0], dist[y][i]);
                if (d[i][0] < min || min < 0) {
                    min = d[i][0];
                    index_min = i;
                }
            }    
        d[y][1] = 1;
        
    }
}
