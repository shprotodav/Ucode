#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>

typedef struct s_path {
    t_point *start;
    t_path *next;
} t_path;

typedef struct s_point {
    int point;
    t_point *next;
} t_point;


#endif

