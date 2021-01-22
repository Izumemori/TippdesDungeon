#ifndef Door_H
#define Door_H

#include "GameObject.hpp"

namespace Dungeon {
namespace Entities {

class Door : public GameObject {

    public:
        Door(int x, int y, bool isEntrance = false)
            : GameObject(x, y, 0, 0), isEntrance(isEntrance)
            {}

        bool isEntrance;

        void update(const InteractionData_t& interactionData);

        void handleCollision(GameObject& other);

        ~Door();
};

}
}

#endif // Door_H