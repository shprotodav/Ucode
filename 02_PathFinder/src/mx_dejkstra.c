#include "pathfinder.h"

void mx_dejkstra(int **dist, int points_count, t_path ***path_arr) {
    int **d = malloc(sizeof(int *) * points_count); // [][0]dist,[][1]fl
    int **br_flags = malloc(sizeof(int) * points_count);
    int index_min;
    int min = -1;
    t_point *fin_point;

    for (int i = 0; i < points_count; i++)
        d[i] = malloc(sizeof(int) * 2);
    for (int i = 0; i < points_count; i++)
        br_flags[i] = malloc(sizeof(int) * points_count);
    
    for (int start = 0; start < points_count - 1; start++) { // перечисление стартовых
        for (int i = 0; i < points_count; i++) // обнуление d[][0] мин расстояний
            if (i == start) {
                d[i][0] = 0;
                d[i][1] = 2; // стартовая точка
            }
            else {
                d[i][0] = -1;
                d[i][1] = 0;
            }
                

        for (int y = start, j = 0; j < points_count; y = index_min, j++) { // дейкстра
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

        for (int fin = start + 1; fin < points_count; fin++) {
            if (fin != start) {
                //path_arr[start][fin] = mx_create_path(fin);
                fin_point = mx_create_point(fin);
                mx_rec_back(fin_point, path_arr[start][fin], dist, d);

                /*for (int near = 0; near < points_count; near++) {
                    if (dist[][near] != -1 ////////) {
                        if (d[fin][0] - dist[fin][near] == d[near][0]) {
                            
                        }
                    }
                }*/
            }
        }
    }
    

    
}
