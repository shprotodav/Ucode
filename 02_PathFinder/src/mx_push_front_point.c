#include "pathfinder.h"

void mx_push_front_point(t_point **list, int point_num) {   
    t_point *point = mx_create_point(point_num);
    
    point->next = *list;
    *list = point;
}
