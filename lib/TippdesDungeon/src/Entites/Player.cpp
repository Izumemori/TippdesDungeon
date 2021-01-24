#include "../../include/Entities/Player.hpp"
#include "../../include/Entities/Collectable.hpp"
#include "../../include/Entities/Door.hpp"
#include "../../include/Entities/Enemy.hpp"
#include "../../include/Entities/Powerup.hpp"

#include <iostream>
#include <sstream>

namespace Dungeon {
namespace Entities {

    void Player::update(const InteractionData_t& interactionData, const Map* map)
    {
        this->velocity.x = 0;
        this->velocity.y = 0;

        switch (interactionData.input)
        {
            case 'w':
                this->velocity.x -= 1;
                break;

            case 's':
                this->velocity.x += 1;
                break;

            case 'a':
                this->velocity.y -= 1;
                break;

            case 'd':
                this->velocity.y += 1;
                break;
        }

        this->position.x += this->velocity.x;
        this->position.y += this->velocity.y;
    }

    void Player::moveTo(int x, int y)
    {
        this->position.x = x;
        this->position.y = y;
    }

    void Player::handleCollision(GameObject& other)
    {
        Collectable* collectable;
        if ((collectable = dynamic_cast<Collectable*>(&other)) != nullptr)
        {
            Powerup* powerup;
            if ((powerup = dynamic_cast<Powerup*>(collectable)) != nullptr)
            {
                std::string text = "";
                std::function<bool(const InteractionData_t&)> handler;

                auto res = powerup->tryCollect(*this);
                std::stringstream ss;

                bool shouldLock = false;

                if (res.first)
                {
                    ss << "Press E to buy for " << powerup->getCost() << " Coins\n"
                       << "Press C to cancel";

                    shouldLock = true;
                    handler = [res, this, powerup](const InteractionData_t& interaction) -> bool {
                        if (interaction.input == 'e' || interaction.input == 'E')
                        {
                            res.second.function(this);

                            this->coins += res.second.coins;
                            powerup->setRemovable();
                            
                            return true;
                        }
                        else if (interaction.input == 'c' || interaction.input == 'C')
                        {
                            return true;
                        }
                        
                        return false;
                    };
                }
                else
                {
                    ss << "This item is too expensive!\n"
                       << "You're " << (powerup->getCost() - this->coins) << " Coins short!";
                    handler = [](const InteractionData_t& data){ return true; };
                }

                text = ss.str();

                this->handler = std::make_unique<InteractionHandler_t>(text, handler, shouldLock);
            }
            else
            {
                auto res = collectable->tryCollect(*this);

                if (res.first)
                {
                    collectable->setRemovable();
                    this->coins += res.second.coins;
                    this->health += res.second.health;

                    this->health = std::min(this->maxHealth, this->health);

                    return;
                }
            }
            
        }

        Door* door;
        if ((door = dynamic_cast<Door*>(&other)) != nullptr)
        {
            if (!door->getClosed())
            {
                this->handler = std::make_unique<InteractionHandler_t>("Press E to leave the room.", 
                    [this](const InteractionData_t& data) -> bool
                    {
                        if (data.input == 'e' || data.input == 'E')
                        {
                            this->mapDone = true;
                        }

                        return true;
                    });
            }
            else
            {
                this->handler = std::make_unique<InteractionHandler_t>("This door is locked.", 
                    [this](const InteractionData_t& data) -> bool { return true; });
            }
        }

        Enemy* entity;
        if ((entity = dynamic_cast<Enemy*>(&other)) != nullptr)
        {
            entity->doDamage(this->damage);

            if (entity->getHealth() <= 0)
            {
                entity->setRemovable();
                return;
            }
        }

        GameObject::handleCollision(other);
    }

    Player::~Player()
    {

    }
}
}