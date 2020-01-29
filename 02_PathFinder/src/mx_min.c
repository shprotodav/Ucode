#include "pathfinder.h"

int mx_min(int a, int b, int c) {
    if ((a < (b + c) && a >= 0) || b < 0 || c < 0) 
        return a; // min (d[a], d[b] + d[c])
    else
        return b + c;
}
