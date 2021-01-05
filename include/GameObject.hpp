#ifndef GameObject_H
#define GameObject_H

#include <typeinfo>
#include "GameTime.hpp"

namespace Dungeon {

class GameObject {
    public:
        virtual bool isEntity() const = 0;
        virtual bool isPickupable() const = 0;
        virtual bool isWall() const = 0;
        virtual void update(GameTime_t& gameTime) = 0;
        virtual void checkCollision(GameObject& other) = 0;
};

}

#endif // GameObject_H
