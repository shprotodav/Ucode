#include "pathfinder.h"

int get_start(int ***d);

void mx_rec_back(t_point **last, t_path **path_cell, int **dist, int ***d) {
    int near = 0;
    int start = get_start(d);

    for (; (*d)[near]; near++) {
        if ((*d)[(*last)->point][0] - dist[(*last)->point][near]
            == (*d)[near][0] && (*last)->point != near
            && dist[(*last)->point][near] != -1) {
            mx_push_front_point(last, near);
            if (near == start)
                mx_dub_path(path_cell, last);
            else
                mx_rec_back(last, path_cell, dist, d);
            mx_del_front_point(last);
        }
    }
}

int get_start(int ***d) {
    int start;
    for (start = 0; (*d)[start][1] != 2 && (*d)[start]; start++);
    return start;
}
