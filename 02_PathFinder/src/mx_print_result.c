#include "pathfinder.h"

static void print_path(char *first_point, char *second_point) {
	mx_printstr("Path: ");
	mx_printstr(first_point);
	mx_printstr(" -> ");
	mx_printstr(second_point);
	mx_printstr("\n");
}

static void print_route(char **points_arr, int ***result_arr, int result_len) {
	mx_printstr("Route: ");
	mx_printstr();
	for () {
		mx_printstr(" -> ");
		mx_printstr();
	}
	mx_printstr("\n");
}

static void print_distance(char **points_arr, int ***result_arr, int result_len) {
	mx_printstr("Distance: ");
	if () {
		for () {
		mx_printstr(" + ");
		mx_printstr();
		}
		mx_printstr(" = ");
	}
	mx_printstr();
	mx_printstr("\n");
}

void mx_print_result(char **points_arr, int ***result_arr, int result_len) {
	mx_printstr("========================================\n");
	print_path(points_arr[result_arr[0][0]],
	points_arr[result_arr[0][result_len]]);
	print_route(&points_arr, &result_arr);
	print_distance(&points_arr, &result_arr);
	mx_printstr("========================================\n");
}

