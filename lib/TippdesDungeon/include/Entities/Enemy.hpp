#ifndef Enemy_H
#define Enemy_H
#include "Entity.hpp"

namespace Dungeon {
namespace Entities {

class Enemy : public Entity {
    public:
        Enemy(int x, int y, int vx, int vy, int health = 100, int damage = 1)
                : Entity(x, y, vx, vy, health, damage)
            {}

        void update(const InteractionData_t& interactionData, const Map* map);

        void handleCollision(GameObject& other);

        ~Enemy();

    private:
        Point_t target = Point_t(0, 0);
};

}
}

#endif // Entity_H
