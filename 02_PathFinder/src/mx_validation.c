#include "pathfinder.h"

static lines_validation(char *data_arr, int *count, int empty_line) {
    if ((*count = mx_num_check(data_arr[0])) == -1)
        mx_print_error(3, "1");
    
}

char **mx_validation(int argc, char *argv[], int *count, ) {
	char **data_arr, *file_str;

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
    data_arr = mx_strsplit(file_str, '\n');
    lines_validation(data_arr, count, mx_empty_line(file_str));
    free(file_str);
    return data_arr;
}

