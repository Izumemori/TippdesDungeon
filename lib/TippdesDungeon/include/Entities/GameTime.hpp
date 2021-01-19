#ifndef GameTime_H
#define GameTime_H

#include <cstdint>

namespace Dungeon {
    typedef struct GameTime {
        uint64_t elapsedTimeMs;

        GameTime(uint64_t elapsedTimeMs)
            : elapsedTimeMs(elapsedTimeMs)
            {}
            
    } GameTime_t;
}

#endif // GameTime_H
