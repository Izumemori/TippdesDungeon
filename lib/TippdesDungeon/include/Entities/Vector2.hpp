#ifndef Vector2_H
#define Vector2_H

#include <cstdint>

namespace Dungeon {
typedef struct Vector2 {
    int32_t x;
    int32_t y;
    
    Vector2(int32_t x, int32_t y)
        : x(x), y(y)
    {}
} Vector2_t;

}

#endif // Vector2_H
