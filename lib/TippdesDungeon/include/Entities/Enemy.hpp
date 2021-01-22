#ifndef Enemy_H
#define Enemy_H
#include "Entity.hpp"

namespace Dungeon {
namespace Entities {

class Enemy : public Entity {
    public:
        Enemy(int x, int y, int vx, int vy, int health = 100, int damage = 10)
                : Entity(x, y, vx, vy, health, damage)
            {}

        void update(const InteractionData_t& interactionData);

        void handleCollision(GameObject& other);

        ~Enemy();
};

}
}

#endif // Entity_H
