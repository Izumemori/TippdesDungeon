#ifndef GameObject_H
#define GameObject_H

#include <memory>

#include "../Util/Point.hpp"
#include "../Util/Vector2.hpp"
#include "../ID.hpp"
#include "../External/TippdesDungeon.hpp"

namespace Dungeon {
namespace Entities {

class GameObject {
    public:
        GameObject(int x, int y, int vx, int vy);

        int getWidth();
        int getHeight();

        Vector2_t& getVelocity();
        Point_t& getPosition();


        virtual void update(const InteractionData_t& interactionData) = 0;
        virtual bool checkCollision(GameObject& other);
        virtual void handleCollision(GameObject& other);

        bool getRemovable()
        {
            return this->removable;
        }

        void setRemovable()
        {
            this->removable = true;
        }

        virtual ~GameObject();
    protected:
        int width = 1;
        int height = 1;
        bool removable = false;

        Vector2_t velocity = Vector2_t(0, 0);
        Point_t position = Point_t(0, 0);
};

}
}

#endif // GameObject_H
