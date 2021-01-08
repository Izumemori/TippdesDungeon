#ifndef GameObject_H
#define GameObject_H

#include <memory>

#include "../Texture/TextureManager.hpp"

#include "GameTime.hpp"
#include "Point.hpp"
#include "Vector2.hpp"

namespace Dungeon {

class GameObject {
    public:
        GameObject(const std::string& textureId, int x = 0, int y = 0, float vx = 0.0f, float vy = 0.0f, int width = 0, int height = 0);

        int getWidth();
        int getHeight();

        Vector2_t& getVelocity();
        Point_t& getPosition();
        std::string& getTextureId();        

        virtual bool isEntity() const = 0;
        virtual bool isPickupable() const = 0;
        virtual bool isWall() const = 0;
        virtual void update(GameTime_t& gameTime) = 0;
        virtual bool checkCollision(GameObject& other);
        virtual void handleCollision(GameObject& other);

    protected:
        int width;
        int height;

        std::string textureId;
        std::unique_ptr<Vector2_t> velocity;
        std::unique_ptr<Point_t> position;
};

}

#endif // GameObject_H
