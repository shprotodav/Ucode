#include "pathfinder.h"

void mx_dub_path(t_path **list, t_point *old) {
    t_path *new = mx_create_path(old->point);
    t_path *last = *list;

    for (t_point *p = old->next; p->next; p = p->next)
        mx_push_back_point(&new->start, old->point);
    while(last->next != NULL)
        last = last->next;
    last->next = new;
}
