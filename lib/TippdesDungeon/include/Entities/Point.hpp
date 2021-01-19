#ifndef Point_H
#define Point_H

namespace Dungeon {

typedef struct Point {
    float x;
    float y;

    Point(float x, float y)
        : x(x), y(y)
    {}
} Point_t;

}

#endif // Point_H
