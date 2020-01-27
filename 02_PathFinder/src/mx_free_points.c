#include "pathfinder.h"

void mx_free_points(t_point **head) {
    t_point *pointer = (*head);

    for (; (*head)->next != NULL; *head = pointer) {
        pointer = (*head)->next;
        free(*head);
    }
    free(*head);
    pointer = NULL;
    *head = NULL;
}
