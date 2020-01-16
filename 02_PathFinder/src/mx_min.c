#include "pathfinder.h"

// min (d[a], d[b] + d[c])
int mx_min(int a, int b, int c) {
    if ((a < (b + c) && a >= 0) || b < 0 || c < 0)
        return a;
    else
        return b + c;
}
