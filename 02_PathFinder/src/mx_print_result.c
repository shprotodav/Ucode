#include "pathfinder.h"

static void print_path(char *first_point, char *second_point);
static void print_route(char **points_arr, t_point *points);
static void print_distance(int **dist, t_point *points);

void mx_print_result(char **points_arr,
t_point *points, int **dist, int *s_f) {
	mx_printstr("========================================\n");
	print_path(points_arr[s_f[0]], points_arr[s_f[1]]);
	print_route(points_arr, points);
	print_distance(dist, points);
	mx_printstr("========================================\n");
}

static void print_path(char *first_point, char *second_point) {
	mx_printstr("Path: ");
	mx_printstr(first_point);
	mx_printstr(" -> ");
	mx_printstr(second_point);
	mx_printstr("\n");
}

static void print_route(char **points_arr, t_point *points) {
	mx_printstr("Route: ");
	mx_printstr(points_arr[points->point]);
	for (t_point *p = points; p->next; p = p->next) {
		mx_printstr(" -> ");
		mx_printstr(points_arr[p->next->point]);
	}
	mx_printstr("\n");
}

static void print_distance(int **dist, t_point *points) {
	int sum;

	mx_printstr("Distance: ");
	mx_printint(dist[points->point][points->next->point]);
	sum = dist[points->point][points->next->point];
	if (points->next->next) {
		for (t_point *p = points->next; p->next; p = p->next) {
			mx_printstr(" + ");
			mx_printint(dist[points->point][points->next->point]);
			sum += dist[points->point][points->next->point];
		}
		mx_printstr(" = ");
		mx_printint(sum);
	}
	mx_printstr("\n");
}
