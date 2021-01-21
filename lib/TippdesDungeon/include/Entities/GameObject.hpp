#ifndef GameObject_H
#define GameObject_H

#include <memory>

#include "GameTime.hpp"
#include "Point.hpp"
#include "Vector2.hpp"
#include "../ID.hpp"
#include "../External/TippdesDungeon.hpp"

namespace Dungeon {

class GameObject {
    public:
        GameObject(int x, int y, int vx, int vy);

        int getWidth();
        int getHeight();

        Vector2_t& getVelocity();
        Point_t& getPosition();

        virtual bool isEntity() const = 0;
        virtual bool isPickupable() const = 0;
        virtual bool isWall() const = 0;
        virtual void update(const InteractionData_t& interactionData) = 0;
        virtual bool checkCollision(GameObject& other);
        virtual void handleCollision(GameObject& other);

        virtual ~GameObject();
    protected:
        int width = 1;
        int height = 1;

        std::unique_ptr<Vector2_t> velocity;
        std::unique_ptr<Point_t> position;
};

}

#endif // GameObject_H
