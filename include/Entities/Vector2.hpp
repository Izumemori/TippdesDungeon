#ifndef Vector2_H
#define Vector2_H

namespace Dungeon {
typedef struct Vector2 {
    float x;
    float y;
    
    Vector2(float x, float y)
        : x(x), y(y)
    {}
} Vector2_t;

}

#endif // Vector2_H