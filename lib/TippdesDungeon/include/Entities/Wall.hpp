#ifndef Wall_H
#define Wall_H

#include "GameObject.hpp"

namespace Dungeon {

class Wall : public GameObject {

    public:
        Wall(int x, int y, int vx, int vy)
            : GameObject(x, y, vx, vy)
        {
            this->removable = false;
        }

        // Constants 
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
            return true;
        }

        void update(const InteractionData_t& interactionData);
        
        ~Wall();
};

}

#endif // Wall_H
