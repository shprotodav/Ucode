#include "pathfinder.h"

t_point *mx_create_point(int point_num) {
    t_point *point = malloc(sizeof(t_point));
    
    point->point = point_num;
    point->point = NULL;
    return point;
}
