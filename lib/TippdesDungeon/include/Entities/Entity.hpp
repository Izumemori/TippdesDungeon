#ifndef Entity_H
#define Entity_H
#include "GameObject.hpp"

namespace Dungeon {
namespace Entities {

class Entity : public GameObject {
    public:
        Entity(int x, int y, int vx, int vy)
                : GameObject(x, y, vx, vy)
            {}

        void update(const InteractionData_t& interactionData);

        virtual void handleCollision(GameObject& other);

        ~Entity();
};

}
}

#endif // Entity_H
