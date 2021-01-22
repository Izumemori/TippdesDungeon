#ifndef Coin_H
#define Coin_H

#include "Collectable.hpp"

namespace Dungeon {
namespace Entities {

class Coin : public Collectable {
    public:
        Coin(int x, int y, int value);

        std::pair<bool, CollectableResult_t> tryCollect(Player& player);

        void update(const InteractionData_t& interactionData);

        void handleCollision(GameObject& other);

        ~Coin();

    private:
        int value;
};

}
}

#endif // Coin_H