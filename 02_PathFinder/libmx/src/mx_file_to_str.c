#include "libmx.h"

char *mx_file_to_str(const char *file){
	int fd;
	int len = 0;
	int b_size = 64;
	int size = 0;
	char *rez;

	if (!file)
		return NULL;
	fd = open(file, 'r');
	if (fd < 0)
		return NULL;
	for (char buf[b_size]; (size = read(fd, &buf, b_size)) > 0; len += size);
	close(fd);
	if (size < 0)
		return NULL;
	fd = open(file, 'r');
	if (fd < 0)
		return NULL;
	rez = mx_strnew(len);
	size = rez ? read(fd, rez, len) : size;
	close(fd);
	return (size < 0) ? NULL : rez;
}
