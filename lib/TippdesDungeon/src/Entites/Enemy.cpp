#include "../../include/Entities/Enemy.hpp"
#include "../../include/Entities/Player.hpp"

namespace Dungeon {
namespace Entities {

    void Enemy::update(const InteractionData_t& interactionData) {

        this->position.x += this->velocity.x;
        this->position.y += this->velocity.y;
        
        // TODO
    }

    void Enemy::handleCollision(GameObject& other)
    {
        Player* player = nullptr;

        if (player = dynamic_cast<Player*>(&other))
        {
            player->doDamage(this->damage);
        }

        GameObject::handleCollision(other);
    }

    Enemy::~Enemy() {
        // TODO
    }
}
}