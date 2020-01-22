#include "pathfinder.h"

void mx_rec_back(t_point *last, t_path *path_arr, int **dist, int **d) {
    int near = 0;
    int start = get_start(d);


    for (; d[last->point][0] - dist[last->point][near] !=
         d[near][0]; near++);
    mx_push_front_point(&last, near);

    if (near == start) {
        mx_dub_path(last);
        return;
    }  
    else
        mx_rec_back(last, start, dist, d);
    near++;
    mx_del_front_point(&last);
    for (; d[near][0]; near++) {
        if (d[last->point][0] - dist[last->point][near] ==
            d[near][0]) {

            }
    }
}

int get_start(int **d) {
    int start;

    for (start = 0; d[start][1] != 2; start ++);
    return start;
}

