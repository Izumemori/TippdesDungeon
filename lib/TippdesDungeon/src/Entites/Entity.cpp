#include "../../include/Entities/Entity.hpp"

namespace Dungeon {
namespace Entities {

    void Entity::update(const InteractionData_t& interactionData) {

        this->position->x += this->velocity->x;
        this->position->y += this->velocity->y;
        
        // TODO
    }

    void Entity::handleCollision(GameObject& other)
    {
        GameObject::handleCollision(other);
    }

    Entity::~Entity() {
        // TODO
    }
}
}