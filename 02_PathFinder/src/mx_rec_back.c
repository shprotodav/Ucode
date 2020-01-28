#include "pathfinder.h"

int get_start(int ***d);

void mx_rec_back(t_point **last, t_path **path_cell, int **dist, int ***d) {
    //mx_printstr("back-1\n");///////////////
    int near = 0;
    int start = get_start(d);


    //mx_printstr("check start : ");///////////////
    //mx_printint(start);///////////////
    //mx_printstr("\nback-2\n");///////////////

    for (; (*d)[near]; near++) {
        /*
        mx_printstr("NEAR ======== ");///////////////
        mx_printint(near);///////////////
        mx_printstr("\n");///////////////
        */

        if ((*d)[(*last)->point][0] - dist[(*last)->point][near] == (*d)[near][0] &&
        (*last)->point != near && dist[(*last)->point][near] != -1) {
            
            
            
            
            mx_push_front_point(last, near);
/*
            ///////////////
            mx_printstr("------------ point way: ");///////////////
            for (t_point *p = *last; p != NULL; p = p->next){
                mx_printint(p->point);///////////////
                mx_printstr(" ");///////////////
            }
            mx_printstr("\n");///////////////
            //////////////
*/
            
            if (near == start) {
                mx_dub_path(path_cell, last);
/*
                ///////////////
                mx_printstr("/////////////// WAY: ");///////////////
                for (t_point *p = (*path_cell)->start; p != NULL; p = p->next){
                    mx_printint(p->point);///////////////
                    mx_printstr(" ");///////////////
                }
                mx_printstr("\n");///////////////
                //////////////
                */


                //mx_del_front_point(last);
                //return;
            }  
            else {
                mx_rec_back(last, path_cell, dist, d);
            }
                
            mx_del_front_point(last);
/*
            ///////////////
            mx_printstr("------------ point way    DEL: ");///////////////
            for (t_point *p = *last; p != NULL; p = p->next){
                mx_printint(p->point);///////////////
                mx_printstr(" ");///////////////
            }
            mx_printstr("\n");///////////////
            //////////////
            mx_printstr("NEAR = ");///////////////
            mx_printint(near);///////////////
            mx_printstr("\n");///////////////
            //////////////
            */
        }
    }
}

int get_start(int ***d) {
    int start;
    //mx_printstr("back-1.1\n");///////////////
    for (start = 0; (*d)[start][1] != 2 && (*d)[start]; start++);
    return start;
}

/*
void mx_rec_back(t_point *last, t_path *path_cell, int **dist, int **d) {
    int near = 0;
    int start = get_start(d);


    for (; d[last->point][0] - dist[last->point][near] !=
         d[near][0]; near++);
    mx_push_front_point(&last, near);

    if (near == start) {
        mx_dub_path(&path_cell, last);
        return;
    }  
    else
        mx_rec_back(last, path_cell, dist, d);
    near++;
    mx_del_front_point(&last);
    for (; d[near][0]; near++) {
        if (d[last->point][0] - dist[last->point][near] ==
            d[near][0]) {
                mx_rec_back(last, path_cell, dist, d);
            }
    }
}
*/
