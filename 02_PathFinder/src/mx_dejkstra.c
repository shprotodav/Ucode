#include "pathfinder.h"

void mx_dejkstra(int **dist, int points_count, t_path ****path_arr) {
    int **d = malloc(sizeof(int *) * (points_count + 1)); // [][0]dist,[][1]fl
    //int **br_flags = malloc(sizeof(int *) * (points_count +1));
    int index_min;
    int min = -1;
    t_point *fin_point;
mx_printstr("points count = ");///////////////
        mx_printint(points_count);///////////////
        mx_printstr("\n");///////////////
    mx_printstr("14.1\n");///////////////


    

    for (int i = 0; i < points_count; i++)
        d[i] = malloc(sizeof(int) * 2);
    mx_printstr("14.2\n");///////////////



/*
    for (int i = 0; i < points_count; i++)
        br_flags[i] = malloc(sizeof(int) * points_count);
    mx_printstr("14.3\n");///////////////
    */

    for (int start = 0; start < points_count - 1; start++) { // перечисление стартовых
        mx_printstr("dejkstra start = ");///////////////
        mx_printint(start);///////////////
        mx_printstr("\n");///////////////



        for (int i = 0; i < points_count; i++) // обнуление d[][0] мин расстояний
            if (i == start) {
                d[i][0] = 0;
                d[i][1] = 2; // стартовая точка
            }
            else {
                d[i][0] = -1;
                d[i][1] = 0;
            }
        mx_printstr("14.3.1\n");///////////////





        for (int y = start, j = 0; j < points_count; j++) { // дейкстра
            min = -1;
            for (int i = 0; i < points_count; i++) {
                if (d[i][1] == 0) {
                    d[i][0] = mx_min(d[i][0], d[y][0], dist[y][i]);
                    if (((d[i][0] < min && d[i][0] > 0) || min < 0) && i != y) {
                        min = d[i][0];
                        index_min = i;
                    }
                }   
            }
            d[index_min][1] = 1;
            y = index_min;
        }
        d[start][1] = 2;

        //////////
        mx_printstr("++++++++++++++ check d: ");///////////////
        for (int i = 0; i < points_count; i++) {
            
            mx_printint(d[i][0]);///////////////
            mx_printstr(" ");///////////////
        }
        mx_printstr("\n");///////////////
        //////////




        //mx_printstr("14.3.2\n");///////////////

        for (int fin = start + 1; fin < points_count; fin++) {
            mx_printstr("dejkstra fin = ");///////////////
            mx_printint(fin);///////////////
            mx_printstr("\n");///////////////
            if (fin != start) {
                //mx_printstr("14.3.2.1\n");///////////////
                //path_arr[start][fin] = mx_create_path(fin);
                fin_point = mx_create_point(fin);

                mx_printstr("************* start point: ");///////////////
                mx_printint(start);///////////////
                mx_printstr("\n************* fin point: ");///////////////
                mx_printint(fin_point->point);///////////////
                mx_printstr("\n");///////////////

                //mx_printstr("14.3.2.2\n");///////////////
                mx_rec_back(&fin_point, &((*path_arr)[start][fin]), dist, &d);
                //mx_printstr("14.3.2.3\n");///////////////
                mx_free_points(&fin_point);
                /*for (int near = 0; near < points_count; near++) {
                    if (dist[][near] != -1 ////////) {
                        if (d[fin][0] - dist[fin][near] == d[near][0]) {
                            
                        }
                    }
                }*/
            }
        }
        mx_printstr("14.3.3\n");///////////////
    }
    


/////////////////
int **p = d;
    
    while (*p) {
        free(*p);
        *p = NULL;
        p++;
    }
    free(d);
/////////////////

    
}
