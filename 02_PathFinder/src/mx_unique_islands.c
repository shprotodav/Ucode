#include "pathfinder.h"

static void is_pcount_bigger(int k, int points_count);
static void is_pcount_lower(int k, int points_count);
static bool is_unique(char **points_arr, char *data_arr);

char **mx_unique_islands(char ***data_arr, int *points_count) {
    char **points_arr = malloc(sizeof(char *) * ((*points_count) + 1));
    

    mx_printstr("points count = ");///////////////
        mx_printint(*points_count);///////////////
        mx_printstr("\n");///////////////



    int k = 0;

    for (int i = 0; i < *points_count + 1; i++)
        points_arr[i] = NULL;
    mx_printstr("8.1\n");///////////////
    for (int i = 0; data_arr[i + 1]; i++) {
        mx_printstr("8.1.1\n");///////////////
        mx_printstr(data_arr[i + 1][0]);///////////////
        mx_printstr("\n");///////////////
        mx_printstr(data_arr[i+1][1]);///////////////
        mx_printstr("\n");///////////////
        mx_printstr(data_arr[i+1][2]);///////////////
        mx_printstr("\n");///////////////
        if (is_unique(points_arr, data_arr[i + 1][0])) {
            is_pcount_bigger(k, *points_count);
            points_arr[k] = mx_strnew(mx_strlen(data_arr[i + 1][0]));
            mx_strcpy(points_arr[k], data_arr[i + 1][0]);
            //points_arr[k] = data_arr[i][0];
            k++;
        }
        mx_printstr("8.1.3\n");///////////////
        if (is_unique(points_arr, data_arr[i + 1][1])) {
            
            is_pcount_bigger(k, *points_count);
            mx_printstr("8.1.4\n");///////////////
            points_arr[k] = mx_strnew(mx_strlen(data_arr[i + 1][1]));
            mx_strcpy(points_arr[k], data_arr[i + 1][1]);
            //points_arr[k] = data_arr[i][1];
            k++;
        }
        mx_printstr("8.2\n");///////////////
    }
    is_pcount_lower(k, *points_count);
    return points_arr;
}

static void is_pcount_bigger(int k, int points_count) {
    if (k + 1 > points_count) {
        mx_print_error(4, NULL);
    }
}

static void is_pcount_lower(int k, int points_count) {
    if (k < points_count) {
        mx_print_error(4, NULL);
    }
}

static bool is_unique(char **points_arr, char *point) {
    mx_printstr("8.1.2\n");///////////////
    bool unique = true;
    mx_printstr("8.1.2.1\n");///////////////
    for (int i = 0; points_arr[i] != NULL; i++) {
        mx_printstr("8.1.2.2\n");///////////////
        mx_printstr(points_arr[i]);///////////////
        mx_printstr("\n");///////////////
        if (mx_strcmp(points_arr[i], point) == 0) {
            mx_printstr("8.1.2.3\n");///////////////
            unique = false;
            break;
        }
    }
    return unique;
}

