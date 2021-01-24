#ifndef Powerup_H
#define Powerup_H

#include "Collectable.hpp"
#include "../Util/PowerupType.hpp"

namespace Dungeon {
namespace Entities {

class Powerup : public Collectable {
    public:
        Powerup(PowerupType type, int x, int y, int cost, std::function<void(Player*)> powerUpEffect);

        std::pair<bool, CollectableResult_t> tryCollect(Player& player);

        void update(const InteractionData_t& interactionData, const Map* map);

        int getCost();

        PowerupType getType();

        void handleCollision(GameObject& other);

        ~Powerup();

    private:
        int cost;
        PowerupType type;
        std::function<void(Player*)> powerUpEffect;
};

}
}

#endif // Coin_H