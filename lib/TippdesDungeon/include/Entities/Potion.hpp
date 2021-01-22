#ifndef Potion_H
#define Potion_H

#include "Collectable.hpp"

namespace Dungeon {
namespace Entities {

class Potion : public Collectable {
    public:
        Potion(int x, int y, int value);

        std::pair<bool, CollectableResult_t> tryCollect(Player& player);

        void update(const InteractionData_t& interactionData);

        void handleCollision(GameObject& other);

        ~Potion();

    private:
        int value;
};

}
}

#endif // Potion_H