#include "../../include/Entities/Coin.hpp"

namespace Dungeon {
namespace Entities {

    Coin::Coin(int x, int y, int value)
        : Collectable(x, y)
    {
        this->value = value;
    }
    
    void Coin::update(const InteractionData_t& interactionData, const Map* map)
    {}

    std::pair<bool, CollectableResult_t> Coin::tryCollect(Player& player)
    {
        return std::pair<bool, CollectableResult_t>(true, CollectableResult_t(this->value, 0));
    }

    int Coin::getValue()
    {
        return this->value;
    }

    void Coin::handleCollision(GameObject& other)
    {
        return;
    }

    Coin::~Coin()
    {

    }
}
}