#include "pathfinder.h"

void mx_rec_back(t_point *last_point, int start, int **dist, int **d) {
    int near = 0;
    for (; d[last_point -> point][0] - dist[last_point -> point][near] ==
         d[near][0]; near++);
    mx_push_front_point(last_point, near);

    if (near != start)
        mx_rec_back(last_point, start, dist, d);
    else
        return;
    for (; near < ; near++) {
        if (d[last_point -> point][0] - dist[last_point -> point][near] ==
            d[near][0])
    }
}



