#include "pathfinder.h"

static bool is_unique(char **points_arr, char *data_arr);

char **mx_unique_islands(char ***data_arr, int *lines_count) {
    char **points_arr = malloc(sizeof(char *) * (*lines_count) * 2);
    int k = 0;
    mx_printstr("8.1\n");///////////////
    for (int i = 0; data_arr[i + 1]; i++) {
        mx_printstr("8.1.1\n");///////////////
        //mx_printstr(data_arr[i + 1][0]);///////////////
        mx_printstr("\n");///////////////
        mx_printstr(data_arr[i+1][1]);///////////////
        mx_printstr("\n");///////////////
        mx_printstr(data_arr[i+1][2]);///////////////
        mx_printstr("\n");///////////////
        if (is_unique(points_arr, data_arr[i + 1][0])) {
            points_arr[k] = mx_strnew(mx_strlen(data_arr[i + 1][0]));
            mx_strcpy(points_arr[k], data_arr[i + 1][0]);
            //points_arr[k] = data_arr[i][0];
            k++;
        }
        if (is_unique(points_arr, data_arr[i + 1][1])) {
            points_arr[k] = mx_strnew(mx_strlen(data_arr[i + 1][1]));
            mx_strcpy(points_arr[k], data_arr[i + 1][1]);
            //points_arr[k] = data_arr[i][1];
            k++;
        }
        mx_printstr("8.2\n");///////////////
    }
    return points_arr;
}

static bool is_unique(char **points_arr, char *point) {
    mx_printstr("8.1.2\n");///////////////
    bool unique = true;
    
    for (int i = 0; points_arr[i]; i++) {
        if (mx_strcmp(points_arr[i], point) == 0) {
            unique = false;
            break;
        }
    }
    return unique;
}

