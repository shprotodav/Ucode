#include "pathfinder.h"

static lines_validation(char **lines_arr, int *lines_count,
int empty_line_number, char ***data_arr) {
    int j;

    if ((*lines_count = mx_num_check(lines_arr[0])) == -1)
        mx_print_error(3, "1");
    for (int i = 0; lines_arr[i]; i++) {
        for (j = 0; lines_arr[i][j] != '-'; j++)
            while (mx_isalpha(lines_arr[i][j])) 
                j++;
            if (lines_arr[i][j] == '-')
                break;

    }
}

char ***mx_validation(int argc, char *argv[], int *lines_count) {
	char **lines_arr;
    char *file_str;
    char ***data_arr;

    if (argc != 2)
    	mx_print_error(0, NULL);
    if (!(file_str = mx_file_to_str(argv[1]))) {
        free(file_str);
    	mx_print_error(1, argv[1]);
    }
    if (mx_strlen(file_str) == 0) {
        free(file_str);
        mx_print_error(2, argv[1]);
    }
    lines_arr = mx_strsplit(file_str, '\n');
    lines_validation(lines_arr, &lines_count,
    mx_empty_line_num(file_str), &data_arr);
    free(file_str);
    return data_arr;
}

