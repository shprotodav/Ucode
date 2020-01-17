#include "pathfinder.h"

void mx_push_back_path(t_path **list, int point_num) {
    t_path *new = mx_create_path(point_num);

    if (*list == NULL)
        *list = new;
    else {
        t_path *last = *list;
        while(last->next != NULL)
            last = last->next;
        last->next = new;
    }
}
