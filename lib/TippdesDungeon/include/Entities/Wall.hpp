#ifndef Wall_H
#define Wall_H

#include "GameObject.hpp"
namespace Dungeon {
namespace Entities {

class Wall : public GameObject {

    public:
        Wall(int x, int y, int vx, int vy)
            : GameObject(x, y, vx, vy)
        {}

        void update(const InteractionData_t& interactionData, const Map* map);
        
        ~Wall();
};

}
}

#endif // Wall_H
