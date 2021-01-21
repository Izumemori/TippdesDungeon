#include "../../include/Entities/Player.hpp"
#include "../../include/Entities/Collectable.hpp"

#include <iostream>

namespace Dungeon {

    void Player::update(const InteractionData_t& interactionData)
    {
        this->velocity->x = 0;
        this->velocity->y = 0;

        switch (interactionData.input)
        {
            case 'w':
                this->velocity->x -= 1;
                break;

            case 's':
                this->velocity->x += 1;
                break;

            case 'a':
                this->velocity->y -= 1;
                break;

            case 'd':
                this->velocity->y += 1;
                break;
        }

        this->position->x += this->velocity->x;
        this->position->y += this->velocity->y;
    }

    void Player::handleCollision(GameObject& other)
    {
        Collectable* collectable;

        if ((collectable = dynamic_cast<Collectable*>(&other)) != nullptr)
        {
            auto res = collectable->tryCollect(*this);

            if (res.first)
            {
                collectable->removable = true;

                // TODO: collect
            }
            
        }

        GameObject::handleCollision(other);
    }

    Player::~Player()
    {

    }
}