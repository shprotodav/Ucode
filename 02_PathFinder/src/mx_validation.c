#include "pathfinder.h"

// i - line num; j - symbol num

static bool delimeter_validation(char *data_arr,
char *lines_arr, int col_num, int *j);
static void lines_validation(char **lines_arr, int *lines_count,
int empty_line_number, char ***data_arr);

char ***mx_validation(int argc, char *argv[], char **points_arr) {
    int *lines_count = malloc(sizeof(int) * 1);
	char ***data_arr;
    char **lines_arr;
    char *file_str;
    mx_printstr("2\n");///////////////

    if (argc != 2)
    	mx_print_error(0, NULL); // Argument's fail
    mx_printstr("3\n");///////////////
    file_str = mx_file_to_str(argv[1]);
    mx_printstr("3.1\n");///////////////
    if (!(file_str)) {
        free(file_str);
    	mx_print_error(1, argv[1]); // File's fail
    }
    mx_printstr("4\n");///////////////
    if (mx_strlen(file_str) == 0) {
        free(file_str);
        mx_print_error(2, argv[1]); // Empty file
    }
    mx_printstr("5\n\n");///////////////
    mx_printstr(file_str);///////////////
    *lines_count = mx_count_substr(file_str, "\n") + 1;
    mx_printstr("\n6\nlines count = ");///////////////
    mx_printint(*lines_count);///////////////
    data_arr = malloc(sizeof(char **) * (*lines_count));
    lines_arr = mx_strsplit(file_str, '\n');
    mx_printstr("\n7\n");///////////////
    lines_validation(lines_arr, lines_count, // Line's check
    mx_empty_line_num(file_str, lines_count), data_arr);
    mx_printstr("8\n");///////////////
    free(file_str);
    points_arr = mx_unique_islands(data_arr, lines_count);
    mx_printstr("9\n");///////////////
    return data_arr;
}

static bool delimeter_validation(char *data_arr,
char *lines_arr, int col_num, int *j) {
    int k = 0;
    
    if (col_num == 0 || col_num == 1) {
        for (k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++);
        data_arr = mx_strnew(k);
        mx_printstr("\n");///////////////
        mx_printint(k);///////////////
        mx_printstr("\n");///////////////
        mx_printint(*j);///////////////
        mx_printstr("\n");///////////////
        
        for (*j -= k, k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++)
            data_arr[k] = lines_arr[*j];
        mx_printstr(data_arr);///////////////
        mx_printstr("\n");///////////////
        //(*j)--;
        if ((col_num == 0 && (lines_arr[*j] != '-' || j == 0 )) ||
        (col_num == 1 && (lines_arr[*j] != ',' || lines_arr[*j - 1] == '-')))
            return true;
    }
    else {
        for (k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++);
        data_arr = mx_strnew(k);
        mx_printstr("\n");///////////////
        mx_printint(k);///////////////
        mx_printstr("\n");///////////////
        mx_printint(*j);///////////////
        mx_printstr("\n");///////////////
        for (*j -= k, k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++)
            data_arr[k] = lines_arr[*j];
        mx_printstr(data_arr);///////////////
        mx_printstr("\n");///////////////
        (*j)++;
        if (lines_arr[*j] != '\n' || lines_arr[*j - 1] == ',')
            return true;
    }
    return false;
}

static void lines_validation(char **lines_arr, int *lines_count,
int empty_line_number, char ***data_arr) {
    int j;

    if ((*lines_count = mx_num_check(lines_arr[0])) == -1)
        mx_print_error(3, "1"); // Line 1 fail
    mx_printstr("7.1\n");///////////////
    for (int i = 1; lines_arr[i]; i++) { // Line counter
        mx_printstr("7.2\n");///////////////
        if (empty_line_number == i)
            mx_print_error(3, mx_itoa(i + 1));
        mx_printstr("7.3\n");///////////////
        data_arr[i] = malloc(sizeof(char *) * 3);
        j = 0;
        mx_printstr("7.4\n");///////////////
        if (delimeter_validation(data_arr[i][0], lines_arr[i], 0, &j))
            mx_print_error(3, mx_itoa(i + 1));
        j++;
        mx_printstr("7.5\n");///////////////
        if (delimeter_validation(data_arr[i][1], lines_arr[i], 1, &j))
            mx_print_error(3, mx_itoa(i + 1));
        j++;
        mx_printstr("7.6\n");///////////////
        if (delimeter_validation(data_arr[i][2], lines_arr[i], 2, &j))
            mx_print_error(3, mx_itoa(i + 1));
            
        mx_printstr("7.7\n");///////////////
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


