#ifndef Player_H
#define Player_H

#include "GameObject.hpp"

namespace Dungeon {
namespace Entities {

class Player : public GameObject {
    public:
        Player()
            : Player(0, 0)
            {}
        Player(int x, int y)
            : GameObject(x, y, 0, 0)
            {}

        void update(const InteractionData_t& interactionData);

        void moveTo(int x, int y);

        void handleCollision(GameObject& other);

        ~Player();

        bool mapDone = false;
        int coins;
        int health;
};

}
}

#endif // Player_H