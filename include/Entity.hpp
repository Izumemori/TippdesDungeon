#ifndef Entity_H
#define Entity_H
#include "GameObject.hpp"

namespace Dungeon {

class Entity : public GameObject {
    // Constants
    inline bool isEntity() const {
        return true;
    }

    inline bool isWall() const {
        return false;
    }
};

}

#endif // Entity_H
