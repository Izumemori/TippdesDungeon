#ifndef Entity_H
#define Entity_H
#include "GameObject.hpp"

namespace Dungeon {
namespace Entities {

class Entity : public GameObject {
    public:
        Entity(int x, int y, int vx, int vy, int health = 100, int damage = 10)
                : GameObject(x, y, vx, vy), health(health), damage(damage), maxHealth(health)
            {}

        virtual void update(const InteractionData_t& interactionData, const Map* map) = 0;

        virtual void handleCollision(GameObject& other) = 0;

        int getHealth()
        {
            return this->health;
        }

        int getMaxHealth()
        {
            return this->maxHealth;
        }

        int getDamage()
        {
            return this->damage;
        }

        void doDamage(int damage)
        {
            this->health -= damage;
            this->health = std::max(this->health, 0);
        }
    
    protected:
        int health;
        int maxHealth;
        int damage;
};

}
}

#endif // Entity_H
