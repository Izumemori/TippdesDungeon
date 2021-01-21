#ifndef Collectable_H
#define Collectable_H

#include "GameObject.hpp"
#include "Player.hpp"
#include "CollectableResult.hpp"

namespace Dungeon {

class Collectable : public GameObject {

    public:
        Collectable(int x, int y)
            : GameObject(x, y, 0, 0)
            {}

        bool isEntity() const
        {
            return false;
        }

        bool isPickupable() const 
        {
            return true;
        }

        bool isWall() const
        {
            return false;
        }

        virtual std::pair<bool, CollectableResult_t> tryCollect(Player& player) = 0;

        virtual void handleCollision(GameObject& other) = 0;
};

}

#endif // Collectable_H