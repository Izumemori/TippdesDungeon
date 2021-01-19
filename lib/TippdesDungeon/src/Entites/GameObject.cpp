#include "../../include/Entities/GameObject.hpp"
#include <cmath>

namespace Dungeon {
    GameObject::GameObject(const int id, int x, int y, float vx, float vy, int width, int height)
    {
        this->position = std::make_unique<Point_t>(x, y);
        this->velocity = std::make_unique<Vector2_t>(vx, vy);

        this->width = width;
        this->height = height;
        this->id = id;
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
        float x1Min = this->position->x;
        float x1Max = this->position->x + this->width;
        float y1Min = this->position->y;
        float y1Max = this->position->y + this->height;

        
        float x2Min = other.getPosition().x;
        float x2Max = other.getPosition().x + other.getWidth();
        float y2Min = other.getPosition().y;
        float y2Max = other.getPosition().y + other.getHeight();

        if (x1Max < x2Min || x1Min > x2Max) return false;
        if (y1Max < y2Min || y1Min > y2Max) return false;

        return true;
    }

    int GameObject::getId()
    {
        return this->id;
    }

    void GameObject::handleCollision(GameObject& other) {
        if (&other == this) return;

        //TODO: better algorithm
        
        this->velocity->x *= -1;
        this->velocity->y *= -1;
    }

    GameObject::~GameObject()
    {
        // TODO
    }
}
