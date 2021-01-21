#include "../../include/Entities/GameObject.hpp"
#include "../../include/Entities/Wall.hpp"
#include <cmath>

namespace Dungeon {
    GameObject::GameObject(int x, int y, int vx, int vy)
    {
        this->position = std::make_unique<Point_t>(x, y);
        this->velocity = std::make_unique<Vector2_t>(vx, vy);
    }

    int GameObject::getHeight()
    {
        return this->height;
    }

    int GameObject::getWidth()
    {
        return this->width;
    }

    Vector2_t& GameObject::getVelocity()
    {
        return *this->velocity;
    }

    Point_t& GameObject::getPosition()
    {
        return *this->position;
    }

    bool GameObject::checkCollision(GameObject& other)
    {
        // TODO: redo these calculations
        return this->position->x == other.getPosition().x
            && this->position->y == other.getPosition().y;
    }

    void GameObject::handleCollision(GameObject& other) {
        if (&other == this) return;

        //TODO: better algorithm
        
        this->position->x -= this->velocity->x;
        this->position->y -= this->velocity->y;

        this->velocity->x *= -1;
        this->velocity->y *= -1;
    }

    GameObject::~GameObject()
    {
        // TODO
    }
}
