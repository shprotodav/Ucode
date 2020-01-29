#include "pathfinder.h"

// i - line num; j - symbol num

static void file_validation(int argc, char *argv[], char **file_str);
static void lines_validation(char **lines_arr, int *points_count,
int empty_line_number, char ***data_arr);

char ***mx_validation(int argc, char *argv[],
char ***points_arr, int *points_count) {
    int *lines_count = malloc(sizeof(int) * 1);
	char ***data_arr;
    char **lines_arr;
    char *file_str = NULL;

    file_validation(argc, argv, &file_str);
    *lines_count = mx_count_substr(file_str, "\n") + 1;
    data_arr = malloc(sizeof(char **) * (*lines_count + 1));
    lines_arr = mx_strsplit(file_str, '\n');
    lines_validation(lines_arr, points_count, // Line's check
    mx_empty_line_num(file_str, lines_count), data_arr);
    free(file_str);
    *points_arr = mx_unique_islands(data_arr, points_count);
    free(lines_count);
    mx_del_strarr(&lines_arr);
    return data_arr;
}

static void file_validation(int argc, char *argv[], char **file_str) {
    if (argc != 2)
    	mx_print_error(0, NULL); // Argument's fail
    *file_str = mx_file_to_str(argv[1]);
    if (!(*file_str)) {
        free(*file_str);
    	mx_print_error(1, argv[1]); // File's fail
    }
    if (mx_strlen(*file_str) == 0) {
        free(*file_str);
        mx_print_error(2, argv[1]); // Empty file
    }
}

static void lines_validation(char **lines_arr, int *points_count,
int empty_line_number, char ***data_arr) {
    int j;
    
    if ((*points_count = mx_num_check(lines_arr[0])) == -1)
        mx_print_error(3, "1"); // Line 1 fail
    data_arr[0] = malloc(sizeof(char *) * 3);
    for (int i = 1; lines_arr[i]; i++) { // Line counter
        if (empty_line_number == i)
            mx_print_error(3, mx_itoa(i));
        data_arr[i] = malloc(sizeof(char *) * 3);
        j = 0;
        if (mx_delimeter_validation(&data_arr[i][0], lines_arr[i], 0, &j))
            mx_print_error(3, mx_itoa(i + 1));
        j++;
        if (mx_delimeter_validation(&data_arr[i][1], lines_arr[i], 1, &j))
            mx_print_error(3, mx_itoa(i + 1));
        j++;
        if (mx_delimeter_validation(&data_arr[i][2], lines_arr[i], 2, &j))
            mx_print_error(3, mx_itoa(i + 1));
    }
}
