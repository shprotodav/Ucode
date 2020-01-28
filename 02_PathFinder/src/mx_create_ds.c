#include "pathfinder.h"

static void set_D0(int ***dist, char ***data_arr,
char **points_arr, int points_count);

void mx_create_ds(int ***dist, char ***data_arr,
char **points_arr, int points_count) {
    //mx_printstr("13.1\n");///////////////
    *dist = malloc(sizeof(int *) * points_count);
    //mx_printstr("13.2\n");///////////////
    for (int i = 0; i < points_count; i++)
        (*dist)[i] = malloc(sizeof(int) * points_count);
    //mx_printstr("13.3\n");///////////////
    set_D0(dist, data_arr, points_arr, points_count);
    //mx_printstr("13.4\n");///////////////
    mx_matrix_mirror(dist, points_count);
    //mx_printstr("13.5\n");///////////////
}

static void set_D0(int ***dist, char ***data_arr,
char **points_arr, int points_count) {
    //mx_printstr("13.3.1\n");///////////////
    for (int i = 0; i < points_count; i++) {
        //mx_printstr("i = ");///////////////
        //mx_printint(i);///////////////
        for (int j = i; j < points_count; j++) {
            //mx_printstr("13.3.1-n-n-1\n");///////////////
            //mx_printstr("j = ");///////////////
            //mx_printint(j);///////////////
            (*dist)[i][j] = -1;
            //mx_printstr("13.3.1-n-n-2\n");///////////////
            for (int k = 1; data_arr[k]; k++) {
                //mx_printstr("13.3.1-n-n-n-1\n");///////////////
                
                if (i == j) {
                    (*dist)[i][j] = 0;
                    //mx_printstr("\n0\n");///////////////
                    break;
                }

                if (i == j) {
                    (*dist)[i][j] = 0;
                    //mx_printstr("\n0\n");///////////////
                    break;
                }
                /*
                mx_printstr("k = ");///////////////
                mx_printint(k);///////////////
                //mx_printstr("13.3.1-n-n-n-2\n");///////////////
                mx_printstr("\n points\n");///////////////
                mx_printstr(points_arr[i]);///////////////
                mx_printstr(points_arr[j]);///////////////
                mx_printstr("\n data\n");///////////////
                mx_printstr(data_arr[k][0]);///////////////
                mx_printstr(data_arr[k][1]);///////////////
                mx_printstr("\n");///////////////
                */





                if ((mx_strcmp(points_arr[i], data_arr[k][0]) == 0 &&
                    mx_strcmp(points_arr[j], data_arr[k][1]) == 0) ||

                    (mx_strcmp(points_arr[i], data_arr[k][1]) == 0 &&
                    mx_strcmp(points_arr[j], data_arr[k][0]) == 0))
                {
                    
                    (*dist)[i][j] = mx_atoi(data_arr[k][2]);
                    /*
                    mx_printstr("\n");///////////////
                    mx_printint((*dist)[i][j]);///////////////
                    mx_printstr("\n");///////////////
                    */
                    break;
                }
                //mx_printstr("13.3.1-n-n-n-4\n");///////////////
            }
/*
            ///////
            if ((*dist)[i][j] == -1)
                mx_printstr("\n-1\n");///////////////

            //////
            */
        }
        
    }
/*
    ///////
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++)
                mx_printint((*dist)[i][j]);///////////////
        mx_printstr("\n");///////////////
    }
    ///////
    */
}


