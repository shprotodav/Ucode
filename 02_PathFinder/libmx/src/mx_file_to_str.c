#include "libmx.h"

/*
char *mx_file_to_str(const char *file) {
    char buf[1024];
    char *res;
    char *tmp;
    int n;
    int fd = open(file, O_RDONLY);

    if (fd < 0) return NULL;
    while ((n = read(fd, buf, sizeof (buf) - 1)) > 0) {
        buf[n] = '\0';
        tmp = res;
        res = mx_strjoin(res, buf);
        free(tmp);
    }
    close(fd);
    return res;
}*/

char *mx_file_to_str(const char *file){
	if (!file)
		return NULL;
	int fd = open(file, 'r'), len = 0, buf_size = 64, size = 0;
	char *rez;
	if (fd < 0)
		return NULL;
	for (char buf[buf_size]; (size = read(fd, &buf, buf_size)) > 0; len += size);
	close(fd);
	if (size < 0)
		return NULL;
	fd = open(file, 'r');
	if (fd < 0)
		return NULL;
	rez = mx_strnew(len);
	if (rez)
		size = read(fd, rez, len);
	close(fd);
	return (size < 0) ? NULL : rez;
}
