#include "pathfinder.h"

static void col_01(char **data_arr, char *lines_arr, int *j);
static void col_2(char **data_arr, char *lines_arr, int *j);

bool mx_delimeter_validation(char **data_arr,
char *lines_arr, int col_num, int *j) {
    if (col_num == 0 || col_num == 1) {
        col_01(data_arr, lines_arr, j);
        if ((col_num == 0 && (lines_arr[*j] != '-' || j == 0 )) ||
            (col_num == 1 && (lines_arr[*j] != ','
            || lines_arr[*j - 1] == '-'))) {
            return true;
        }
            
    }
    else {
        col_2(data_arr, lines_arr, j);
        if (lines_arr[*j] != 0 || lines_arr[*j - 1] == ',') {
            mx_printchar(lines_arr[*j - 1]);
            mx_printchar(lines_arr[*j]);
            return true;
        }
    }
    return false;
}

static void col_01(char **data_arr, char *lines_arr, int *j) {
    int k = 0;

    for (k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++);
    *data_arr = mx_strnew(k);
    for (*j -= k, k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++)
        (*data_arr)[k] = lines_arr[*j];
}

static void col_2(char **data_arr, char *lines_arr, int *j) {
    int k = 0;

    for (k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++);
    *data_arr = mx_strnew(k);
    for (*j -= k, k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++)
        (*data_arr)[k] = lines_arr[*j];
}
