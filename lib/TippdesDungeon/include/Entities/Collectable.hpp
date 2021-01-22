#ifndef Collectable_H
#define Collectable_H

#include "GameObject.hpp"
#include "Player.hpp"
#include "../Infrastructure/CollectableResult.hpp"

namespace Dungeon {
namespace Entities {

class Collectable : public GameObject {

    public:
        Collectable(int x, int y)
            : GameObject(x, y, 0, 0)
            {}

        virtual std::pair<bool, CollectableResult_t> tryCollect(Player& player) = 0;

        virtual void handleCollision(GameObject& other) = 0;
};

}
}

#endif // Collectable_H