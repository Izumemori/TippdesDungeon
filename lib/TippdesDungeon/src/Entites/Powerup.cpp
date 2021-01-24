#include "../../include/Entities/Powerup.hpp"

namespace Dungeon {
namespace Entities {

    Powerup::Powerup(PowerupType type, int x, int y, int cost, std::function<void(Player*)> powerUpEffect)
        : Collectable(x, y)
    {
        this->cost = cost;
        this->powerUpEffect = powerUpEffect;
        this->type = type;
    }
    
    void Powerup::update(const InteractionData_t& interactionData, const Map* map)
    {}

    std::pair<bool, CollectableResult_t> Powerup::tryCollect(Player& player)
    {
        if (player.getCoins() < this->cost) return std::pair<bool, CollectableResult_t>(false, CollectableResult_t());

        return std::pair<bool, CollectableResult_t>(true, CollectableResult_t(this->cost * -1, 0, this->powerUpEffect));
    }

    int Powerup::getCost()
    {
        return this->cost;
    }

    PowerupType Powerup::getType()
    {
        return this->type;
    }

    void Powerup::handleCollision(GameObject& other)
    {
        return;
    }

    Powerup::~Powerup()
    {

    }
}
}