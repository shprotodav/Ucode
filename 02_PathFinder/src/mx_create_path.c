#include "pathfinder.h"

t_path *mx_create_path(int point_num) {
    t_path *path = malloc(sizeof(t_path));

    path->start = mx_create_point(point_num);
    path->next = NULL;
    return path;
}
