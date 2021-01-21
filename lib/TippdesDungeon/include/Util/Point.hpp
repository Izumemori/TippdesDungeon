#ifndef Point_H
#define Point_H

#include <cstdint>

namespace Dungeon {

typedef struct Point {
    int32_t x;
    int32_t y;

    Point(int32_t x, int32_t y)
        : x(x), y(y)
    {}
} Point_t;

}

#endif // Point_H
