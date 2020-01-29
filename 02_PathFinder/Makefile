NAME = pathfinder

INC = pathfinder.h

INCI = inc/pathfinder.h

SRC = main.c\
	mx_create_ds.c\
	mx_create_path.c\
	mx_create_point.c\
	mx_dejkstra.c\
	mx_delimeter_validation.c\
	mx_del_front_point.c\
	mx_dub_path.c\
	mx_empty_line_num.c\
	mx_free_points.c\
	mx_get_pcount.c\
	mx_matrix_mirror.c\
	mx_min.c\
	mx_num_check.c\
	mx_print_error.c\
	mx_print_result.c\
	mx_push_back_path.c\
	mx_push_back_point.c\
	mx_push_front_point.c\
	mx_rec_back.c\
	mx_unique_islands.c\
	mx_validation.c

SRCS = $(addprefix src/, main.c\
	mx_create_ds.c\
	mx_create_path.c\
	mx_create_point.c\
	mx_dejkstra.c\
	mx_delimeter_validation.c\
	mx_del_front_point.c\
	mx_dub_path.c\
	mx_empty_line_num.c\
	mx_free_points.c\
	mx_get_pcount.c\
	mx_matrix_mirror.c\
	mx_min.c\
	mx_num_check.c\
	mx_print_error.c\
	mx_print_result.c\
	mx_push_back_path.c\
	mx_push_back_point.c\
	mx_push_front_point.c\
	mx_rec_back.c\
	mx_unique_islands.c\
	mx_validation.c)

OBJ = main.o\
	mx_create_ds.o\
	mx_create_path.o\
	mx_create_point.o\
	mx_dejkstra.o\
	mx_delimeter_validation.o\
	mx_del_front_point.o\
	mx_dub_path.o\
	mx_empty_line_num.o\
	mx_free_points.o\
	mx_get_pcount.o\
	mx_matrix_mirror.o\
	mx_min.o\
	mx_num_check.o\
	mx_print_error.o\
	mx_print_result.o\
	mx_push_back_path.o\
	mx_push_back_point.o\
	mx_push_front_point.o\
	mx_rec_back.o\
	mx_unique_islands.o\
	mx_validation.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@mkdir -p obj
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mv $(OBJ) ./obj

uninstall:
	@make uninstall -C libmx
	@rm -rf $(NAME)

clean:
	@make clean -C libmx
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf $(OBJ)
	@rm -rf ./obj
reinstall: uninstall all
