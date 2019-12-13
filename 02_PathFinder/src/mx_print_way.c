#include "pathfinder.h"

static void print_path(char *first_point, char *second_point) {
	mx_printstr("Path: ");
	mx_printstr(first_point);
	mx_printstr(" -> ");
	mx_printstr(second_point);
	mx_printstr("\n");
}

static void print_route() {
	mx_printstr("Route: ");
	mx_printstr();
	for () {
		mx_printstr(" -> ");
		mx_printstr();
	}
	mx_printstr("\n");
}

static void print_distance() {
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

void mx_print_way(int error, char *message){
	mx_printstr("========================================\n");

	print_path();
	print_route();
	print_distance();

	mx_printstr("========================================\n");
}

