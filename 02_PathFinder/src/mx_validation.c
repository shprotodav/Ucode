#include "pathfinder.h"

// i - line num; j - symbol num

static bool delimeter_validation(char *data_arr, char *lines_arr, int col_num, int *j) {
    int k = 0;

    if (col_num == 0 || col_num == 1) {
        for (k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++);
        data_arr = mx_strnew(k);
        for (*j -= k, k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++)
            data_arr[k] = lines_arr[*j];
        if (col_num == 0 && (lines_arr[*j] != '-' || j == 0 ) ||
        col_num == 1 && (lines_arr[*j] != ',' || lines_arr[*j - 1] == '-'))
            return true;
    }
    else {
        for (k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++);
        data_arr = mx_strnew(k);
        for (*j -= k, k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++)
            data_arr[k] = lines_arr[*j];
        if (lines_arr[*j] != '\0' || lines_arr[*j - 1] != ',')
            return true;
    }
    return false;
}

static void lines_validation(char **lines_arr, int *lines_count,
int empty_line_number, char ***data_arr) {
    int j;

    if ((*lines_count = mx_num_check(lines_arr[0])) == -1)
        mx_print_error(3, "1"); // Line 1 fail
    for (int i = 1; lines_arr[i]; i++) { // Line counter
        if (empty_line_number == i)
            mx_print_error(3, mx_itoa(i));
        data_arr[i] = malloc(sizeof(char *) * 3);
        j = 0;
        if (delimeter_validation(data_arr[i][0], lines_arr[i], 0, &j))
            mx_print_error(3, mx_itoa(i));
        j++;
        if (delimeter_validation(data_arr[i][1], lines_arr[i], 1, &j))
            mx_print_error(3, mx_itoa(i));
        j++;
        if (delimeter_validation(data_arr[i][2], lines_arr[i], 2, &j))
            mx_print_error(3, mx_itoa(i));
    }
}

// Result arr: 
// [pointA] [pointB] [pointC]
// [lenA-B] [lenB-C] [total_lenA-C]
// result_len = 3

// Data arr:
// [pointA] [pointB] [way]
// [pointC] [pointD] [way]
// .
// .
// .

char ***mx_validation(int argc, char *argv[]) {
    int *lines_count;
	char ***data_arr;
    char **lines_arr;
    char *file_str;

    if (argc != 2)
    	mx_print_error(0, NULL); // Argument's fail
    if (!(file_str = mx_file_to_str(argv[1]))) {
        free(file_str);
    	mx_print_error(1, argv[1]); // File's fail
    }
    if (mx_strlen(file_str) == 0) {
        free(file_str);
        mx_print_error(2, argv[1]); // Empty file
    }
    *lines_count = mx_count_substr(file_str, "\n");
    data_arr = malloc(sizeof(char **) * (*lines_count));
    lines_arr = mx_strsplit(&file_str, '\n');
    lines_validation(lines_arr, &lines_count, // Line's check
    mx_empty_line_num(&file_str, &lines_count), &data_arr);
    free(&file_str);
    return data_arr;
}

