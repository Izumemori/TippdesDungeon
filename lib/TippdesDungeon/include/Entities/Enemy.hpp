#ifndef Enemy_H
#define Enemy_H
#include "Entity.hpp"
#include "../Util/EnemyType.hpp"

namespace Dungeon {
namespace Entities {

class Enemy : public Entity {
    public:
        Enemy(EnemyType type, int x, int y, int vx, int vy, int health = 100, int damage = 1, float playerSeekRadius = 5)
                : Entity(x, y, vx, vy, health, damage), playerSeekRadius(playerSeekRadius), type(type)
            {}

        void update(const InteractionData_t& interactionData, const Map* map);

        EnemyType getType()
        {
            return this->type;
        }

        void handleCollision(GameObject& other);

        ~Enemy();

    private:
        Point_t target = Point_t(0, 0);
        float playerSeekRadius;
        EnemyType type;
};

}
}

#endif // Entity_H
