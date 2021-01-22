#include "../../include/Entities/Door.hpp"
namespace Dungeon {
namespace Entities {

    void Door::update(const InteractionData_t& interactionData, const Map* map)
    {
    }

    void Door::handleCollision(GameObject& other)
    {
        GameObject::handleCollision(other);
    }

    Door::~Door()
    {
        
    }

}
}
