#include <cmath>

#include "../../include/Entities/Enemy.hpp"
#include "../../include/Entities/Player.hpp"
#include "../../include/Infrastructure/Map.hpp"

namespace Dungeon {
namespace Entities {

    void Enemy::update(const InteractionData_t& interactionData, const Map* map)
    {
        float diffX = map->player->getPosition().x - (float)this->position.x;
        float diffY = map->player->getPosition().y - (float)this->position.y;
        float square = diffX * diffX + diffY * diffY;

        if (square <= this->playerSeekRadius)
        {
            this->target = map->player->getPosition();
        }

        diffX = this->target.x - (float)this->position.x;
        diffY = this->target.y - (float)this->position.y;

        this->velocity.x = diffX < 1 ? (diffX < 0 ? -1 : 0) : 1;
        this->velocity.y = diffY < 1 ? (diffY < 0 ? -1 : 0) : 1;

        this->position.x += this->velocity.x;
        this->position.y += this->velocity.y;
    }

    void Enemy::handleCollision(GameObject& other)
    {
        Player* player = dynamic_cast<Player*>(&other);

        if (player != nullptr)
        {
            player->doDamage(this->damage);
        }
        else
        { 
            this->target = Point_t(
                this->position.x + 
                    ((rand() % 5) * (rand() % 10) > 5 ? 1 : -1), 
                this->position.y + 
                    ((rand() % 5) * (rand() % 10) > 5 ? 1 : -1));
        }

        GameObject::handleCollision(other);
    }

    Enemy::~Enemy() {
        // TODO
    }
}
}