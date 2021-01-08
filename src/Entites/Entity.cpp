#include "../../include/Entities/Entity.hpp"

namespace Dungeon {
    void Entity::update(GameTime_t& gameTime) {

        this->position->x += this->velocity->x * gameTime.elapsedTimeMs/1000.0f;
        this->position->y += this->velocity->y * gameTime.elapsedTimeMs/1000.0f;
        
        // Todo
    }
}
