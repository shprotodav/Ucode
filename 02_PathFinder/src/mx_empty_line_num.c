#include "pathfinder.h"

int mx_empty_line_num(const char *str, int *lines_count) {
    int line_num = 1;
    
    while (*str != '\0') { 
        if (*str != '\n')
            while (*str != '\n' && *str != '\0')
                str++;
        if (*str == '\n') {
            str++;
            line_num++;
            *lines_count = line_num + 1;
            if (*str == '\n')
                return line_num;
        }
    }
    *lines_count = line_num + 1;
    return 0;
}
