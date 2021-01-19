#ifndef Wall_H
#define Wall_H

#include "GameObject.hpp"

namespace Dungeon {

class Wall : public GameObject {

    public:
        Wall(int x = 0, int y = 0, float vx = 0.0f, float vy = 0.0f, int width = 0, int height = 0)
            : GameObject(WALL, x, y, vx, vy, width, height)
        {}

        // Constants 
        bool isEntity() const
        {
        return false;
        }

        bool isPickupable() const
        {
            return false;
        }
    
        bool isWall() const
        {
            return true;
        }

        void update(GameTime_t& gameTime);
        
        ~Wall();
};

}

#endif // Wall_H
