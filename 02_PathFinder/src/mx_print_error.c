#include "pathfinder.h"

// 0 - usage: ./pathfinder [filename];
// 1 - error: file [filename] does not exist;
// 2 - error: file [filename] is empty;
// 3 - error: line [line_value] is not valid;
// 4 - error: invalid number of islands.

void mx_print_error(int error, char *message) {
	char *text1[] = {
	"usage: ./pathfinder [filename]", // error 0
	"error: file ", // error 1
	"error: file ", // error 2
	"error: line ", // error 3
	"error: invalid number of islands"}; // error 4
    char *text2[] = {
	"\n", // error 0
	" does not exist\n", // error 1
	" is empty\n", // error 2
	" is not valid\n", // error 3
	"\n"}; // error 4

	write(2, text1[error], mx_strlen(text1[error]));
	if (message)
		write(2, message, mx_strlen(message));
	write(2, text2[error], mx_strlen(text2[error]));
	//system("leaks -q pathfinder");
	exit(1);
}

