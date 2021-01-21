#ifndef Player_H
#define Player_H

#include "GameObject.hpp"

namespace Dungeon {

class Player : public GameObject {
    public:
        Player(int x, int y)
            : GameObject(x, y, 0, 0)
            {}

        bool isEntity() const
        {
            return false;
        }

        bool isPickupable() const 
        {
            return false;
        }

        bool isWall() const
        {
            return false;
        }

        void update(const InteractionData_t& interactionData);

        void handleCollision(GameObject& other);

        ~Player();
};

}

#endif // Player_H