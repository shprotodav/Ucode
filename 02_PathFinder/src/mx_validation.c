#include "pathfinder.h"

static lines_validation(char **lines_arr, int *lines_count,
int empty_line_number, char ***data_arr) {
    int j;

    if ((*lines_count = mx_num_check(lines_arr[0])) == -1)
        mx_print_error(3, "1"); // Line 1 fail
    for (int i = 0; lines_arr[i]; i++) { // Line counter
        if (empty_line_number == i)
            mx_print_error(3, mx_itoa(i));
        j = 0;
        for (; mx_isalpha(lines_arr[i][j]); j++);
        if (lines_arr[i][j] == '-' && j != 0)
            for (int k = 0; k < j; k++)
                data_arr[i][0][k] = lines_arr[i][k];
        else
            mx_print_error(3, mx_itoa(i)); // Line [i] fail
        j++;
        for (; mx_isalpha(lines_arr[i][j]); j++);
        if (lines_arr[i][j] == ',' && lines_arr[i][j - 1] != '-')
            for (int k = 0; k < j; k++)
                data_arr[i][0][k] = lines_arr[i][k];
        else
            mx_print_error(3, mx_itoa(i)); // Line [i] fail
        



        mx_print_error(3, mx_itoa(i)); // Line [i] fail
    }
}

char ***mx_validation(int argc, char *argv[], int *lines_count) {
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
    lines_arr = mx_strsplit(file_str, '\n');
    lines_validation(lines_arr, &lines_count,
    mx_empty_line_num(file_str), &data_arr); // Line's check
    free(file_str);
    return data_arr;
}

