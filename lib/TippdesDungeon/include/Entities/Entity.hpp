#ifndef Entity_H
#define Entity_H
#include "GameObject.hpp"

namespace Dungeon {

class Entity : public GameObject {
    public:
        Entity(int x, int y, int vx, int vy)
                : GameObject(x, y, vx, vy)
            {}
        
        // Constants
        bool isEntity() const {
            return true;
        }

        bool isWall() const {
            return false;
        }

        bool isPickupable() const {
            return false;
        };

        void update(const InteractionData_t& interactionData);

        ~Entity();
};

}

#endif // Entity_H
