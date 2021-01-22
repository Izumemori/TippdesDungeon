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
        
        bool getMapDone()
        {
            return this->mapDone;
        }

        void resetMapDone()
        {
            this->mapDone = false;
        }

        int getCoins()
        {
            return this->coins;
        }

        int getHealth()
        {
            return this->health;
        }

        ~Player();

        private:
            bool mapDone = false;
            int coins = 0;
            int health = 0;
};

}
}

#endif // Player_H