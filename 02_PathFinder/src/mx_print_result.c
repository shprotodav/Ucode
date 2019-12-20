#include "pathfinder.h"

// Done
static void print_path(char *first_point, char *second_point) {
	mx_printstr("Path: ");
	mx_printstr(first_point);
	mx_printstr(" -> ");
	mx_printstr(second_point);
	mx_printstr("\n");
}

// Done
static void print_route(char **points_arr, int **result_arr, int result_len) {
	mx_printstr("Route: ");
	mx_printstr(points_arr[result_arr[0][0]]);
	for (int i = 1; i < result_len; i++) {
		mx_printstr(" -> ");
		mx_printstr(points_arr[result_arr[0][i]]);
	}
	mx_printstr("\n");
}

//
static void print_distance(char **points_arr, int **result_arr, int result_len) {
	mx_printstr("Distance: ");
	mx_printint(result_arr[1][1]);
	if (result_len > 2) {
		for (int i = 2; i < result_len; i++) {
		mx_printstr(" + ");
		mx_printint(result_arr[1][i]);
		}
		mx_printstr(" = ");
		mx_printint();
	}
	
	mx_printstr("\n");
}

// Done
void mx_print_result(char **points_arr, int **result_arr, int result_len) {
	mx_printstr("========================================\n");
	print_path(points_arr[result_arr[0][0]],
	points_arr[result_arr[0][result_len]]);
	print_route(&points_arr, &result_arr, result_len);
	print_distance(&points_arr, &result_arr, result_len);
	mx_printstr("========================================\n");
}

