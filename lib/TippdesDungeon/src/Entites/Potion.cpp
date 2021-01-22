#include "../../include/Entities/Potion.hpp"

namespace Dungeon {
namespace Entities {

    Potion::Potion(int x, int y, int value)
        : Collectable(x, y)
    {
        this->value = value;
    }
    
    void Potion::update(const InteractionData_t& interactionData)
    {}

    std::pair<bool, CollectableResult_t> Potion::tryCollect(Player& player)
    {
        return std::pair<bool, CollectableResult_t>(true, CollectableResult_t(this->value));
    }

    void Potion::handleCollision(GameObject& other)
    {
        return;
    }

    Potion::~Potion()
    {

    }
}
}