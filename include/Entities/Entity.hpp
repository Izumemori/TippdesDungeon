#ifndef Entity_H
#define Entity_H
#include "GameObject.hpp"

namespace Dungeon {

class Entity : public GameObject {
    public:
        Entity(const std::string& textureId, int x = 0, int y = 0, float vx = 0.0f, float vy = 0.0f, int width = 0, int height = 0)
                : GameObject(textureId, x, y, vx, vy, width, height)
            {}
        
        // Constants
        bool isEntity() const {
            return true;
        }

        bool isWall() const {
            return false;
        }

        bool isPickupable() const {
            return false;
        };

        void update(GameTime_t& gameTime);
};

}

#endif // Entity_H
