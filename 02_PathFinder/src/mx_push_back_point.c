#include "pathfinder.h"

void mx_push_back_point(t_point **list, int point_num) {
    t_point *new = mx_create_point(point_num);
    t_point *last = *list;
    
    if (*list == NULL)
        *list = new;
    else {
        while(last->next != NULL)
            last = last->next;
        last->next = new;
    }
}
