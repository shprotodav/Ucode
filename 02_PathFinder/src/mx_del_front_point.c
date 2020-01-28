#include "pathfinder.h"

void mx_del_front_point(t_point **head) {
    t_point *pointer;

    if (head == NULL || *head == NULL)
        return;
    pointer = (*head)->next;
    free(*head);
    *head = pointer;
}

