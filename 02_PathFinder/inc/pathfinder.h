#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>
#include "libmx/inc/libmx.h"

typedef struct s_point {
    int point;
    struct s_point *next;
} t_point;

typedef struct s_path {
    struct s_point *start;
    struct s_path *next;
} t_path;

int main(int argc, char **argv);
void mx_create_ds(int ***dist, char ***data_arr,
char **points_arr, int points_count);
t_path *mx_create_path(int point_num);
t_point *mx_create_point(int point_num);
void mx_dejkstra(int **dist, int points_count, t_path ****path_arr);
void mx_del_front_point(t_point **head);
void mx_dub_path(t_path **list, t_point **old);
int mx_empty_line_num(const char *str, int *lines_count);
/*void mx_freesher(char ****data_arr, char ***points_arr,
int ***dist, t_path ****path_arr);*/
void mx_free_points(t_point **head);
int *mx_get_pcount(char **points_arr);
void mx_matrix_mirror(int ***matrix, int points_count);
int mx_min(int a, int b, int c);
int mx_num_check(char *str);
void mx_print_error(int error, char *message);
void mx_print_result(char **points_arr,
t_point *points, int **dist, int *s_f);
void mx_push_back_path(t_path **list, int point_num);
void mx_push_back_point(t_point **list, int point_num);
void mx_push_front_point(t_point **list, int point_num);
void mx_rec_back(t_point **last, t_path **path_cell, int **dist, int ***d);
char **mx_unique_islands(char ***data_arr, int *lines_count);
char ***mx_validation(int argc, char *argv[], char ***points_arr);

#endif

