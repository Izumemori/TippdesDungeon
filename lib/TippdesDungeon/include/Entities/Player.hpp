#ifndef Player_H
#define Player_H

#include "Entity.hpp"

namespace Dungeon {
namespace Entities {

class Player : public Entity {
    public:
        Player()
            : Player(0, 0)
            {}
        Player(int x, int y)
            : Entity(x, y, 0, 0, 100, 50)
            {}

        void update(const InteractionData_t& interactionData, const Map* map);
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

        ~Player();

        private:
            bool mapDone = false;
            int coins = 0;
};

}
}

#endif // Player_H