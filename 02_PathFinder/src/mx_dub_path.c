#include "pathfinder.h"

void mx_dub_path(t_path **list, t_point *old) {
    t_path *new = mx_create_path(old->point);
    t_path *last = *list;

    for (t_point *p = old->next; p->next; p = p->next) // copy of points
        mx_push_back_point(&new->start, old->point);
    if (*list == NULL)
        *list = new;
    else {
        while(last->next != NULL)
        last = last->next;
        last->next = new;
    }
}
