#ifndef Player_H
#define Player_H

#include "Entity.hpp"
#include "../Util/InteractionHandler.hpp"
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

        std::unique_ptr<InteractionHandler_t>& getHandler()
        {
            return this->handler;
        }

        void addHealth(int amount)
        {
            this->health += amount;
            this->health = std::min(this->health, this->maxHealth);
        }

        void addMaxHealth(int amount)
        {
            this->maxHealth += amount;
        }

        void addDamage(int amount)
        {
            this->damage += amount;
        }

        ~Player();

        private:
            bool mapDone = false;
            std::unique_ptr<InteractionHandler_t> handler;
            int coins = 0;
};

}
}

#endif // Player_H