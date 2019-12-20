#include "libmx.h"

// Done

int mx_empty_line_num(const char *str) {
    int line_num = 1;
    
    while (*str != '\0') { 
        if (*str != "\n")
            while (*str != "\n" && *str != '\0')
                str++;
        if (*str == "\n") {
            str++;
            line_num++;
            if (*str == "\n")
                return line_num;
        }
    }
    return 0;
}
