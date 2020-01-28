#include "pathfinder.h"

// i - line num; j - symbol num

static bool delimeter_validation(char **data_arr,
char *lines_arr, int col_num, int *j);
static void lines_validation(char **lines_arr, int *points_count,
int empty_line_number, char ***data_arr);

char ***mx_validation(int argc, char *argv[], char ***points_arr, int *points_count) {
    int *lines_count = malloc(sizeof(int) * 1);
	char ***data_arr;
    char **lines_arr;
    char *file_str;
    //mx_printstr("2\n");///////////////

    if (argc != 2)
    	mx_print_error(0, NULL); // Argument's fail
    //mx_printstr("3\n");///////////////
    file_str = mx_file_to_str(argv[1]);
    //mx_printstr("3.1\n");///////////////
    if (!(file_str)) {
        free(file_str);
    	mx_print_error(1, argv[1]); // File's fail
    }
    //mx_printstr("4\n");///////////////
    if (mx_strlen(file_str) == 0) {
        free(file_str);
        mx_print_error(2, argv[1]); // Empty file
    }
    //mx_printstr("5\n\n");///////////////
    //mx_printstr(file_str);///////////////
    *lines_count = mx_count_substr(file_str, "\n") + 1;
    //mx_printstr("\n6\nlines count = ");///////////////
    //mx_printint(*lines_count);///////////////
    data_arr = malloc(sizeof(char **) * (*lines_count)); //------------------------- 1
    lines_arr = mx_strsplit(file_str, '\n');
    //mx_printstr("\n7\n");///////////////
    lines_validation(lines_arr, points_count, // Line's check
    mx_empty_line_num(file_str, lines_count), data_arr);
    //mx_printstr("8\n");///////////////
    free(file_str);
    *points_arr = mx_unique_islands(data_arr, points_count);
    //mx_printstr("9\n");///////////////

    //mx_printstr("10\n");///////////////
    free(lines_count);
    //lines_count = NULL;
    mx_del_strarr(&lines_arr);
    return data_arr;
}

static bool delimeter_validation(char **data_arr,
char *lines_arr, int col_num, int *j) {
    int k = 0;
    
    if (col_num == 0 || col_num == 1) {
        for (k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++);
        *data_arr = mx_strnew(k); // ------------------------------------------- 3
        /*
        mx_printstr("\nk = ");///////////////
        mx_printint(k);///////////////
        mx_printstr("\nj = ");///////////////
        mx_printint(*j);///////////////
        //mx_printstr("\nbuf = ");///////////////
        //mx_printstr(*data_arr);///////////////
        */
        
        for (*j -= k, k = 0; mx_isalpha(lines_arr[*j]); (*j)++, k++)
            (*data_arr)[k] = lines_arr[*j];
            /*
        mx_printstr("\nbuf = ");///////////////
        mx_printstr(*data_arr);///////////////
        mx_printstr("\n");///////////////
        */
        //(*j)--;
        if ((col_num == 0 && (lines_arr[*j] != '-' || j == 0 )) ||
        (col_num == 1 && (lines_arr[*j] != ',' || lines_arr[*j - 1] == '-'))){
            //mx_printstr("7.6/1-2\n");///////////////
            return true;
        }
            
    }
    else {
        for (k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++);
        *data_arr = mx_strnew(k);

/*
        mx_printstr("\nk = ");///////////////
        mx_printint(k);///////////////
        mx_printstr("\nj = ");///////////////
        mx_printint(*j);///////////////
        mx_printstr("\nbuf = ");///////////////
*/
        for (*j -= k, k = 0; mx_isdigit(lines_arr[*j]); (*j)++, k++)
            (*data_arr)[k] = lines_arr[*j];
/*
        mx_printstr(*data_arr);///////////////
        mx_printstr("\n");///////////////
*/
        //(*j)++;
        if (lines_arr[*j] != 0 || lines_arr[*j - 1] == ',') {
            /*
            mx_printstr("\nj = ");///////////////
            mx_printint(*j);///////////////
            */
            mx_printchar(lines_arr[*j - 1]);
            mx_printchar(lines_arr[*j]);
            return true;
        }
            
    }
    return false;
}

static void lines_validation(char **lines_arr, int *points_count,
int empty_line_number, char ***data_arr) {
    int j;
    //mx_printstr("7.0.1\n");///////////////
    if ((*points_count = mx_num_check(lines_arr[0])) == -1)
        mx_print_error(3, "1"); // Line 1 fail
    //mx_printstr("7.1\n");///////////////
    data_arr[0] = malloc(sizeof(char *) * 3);
    for (int i = 1; lines_arr[i]; i++) { // Line counter
        //mx_printstr("7.2\n");///////////////
        if (empty_line_number == i)
            mx_print_error(3, mx_itoa(i));
        //mx_printstr("7.3\n");///////////////
        data_arr[i] = malloc(sizeof(char *) * 3); //-------------------------------------- 2
        j = 0;
        //mx_printstr("7.4\n");///////////////
        if (delimeter_validation(&data_arr[i][0], lines_arr[i], 0, &j))
            mx_print_error(3, mx_itoa(i + 1));
        j++;
        //mx_printstr("7.5\n");///////////////
        if (delimeter_validation(&data_arr[i][1], lines_arr[i], 1, &j))
            mx_print_error(3, mx_itoa(i + 1));
        j++;
        //mx_printstr("7.6\n");///////////////
        if (delimeter_validation(&data_arr[i][2], lines_arr[i], 2, &j))
            mx_print_error(3, mx_itoa(i + 1));
            
        //mx_printstr("7.7\n");///////////////
        //mx_printstr(data_arr[i][0]);///////////////
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


