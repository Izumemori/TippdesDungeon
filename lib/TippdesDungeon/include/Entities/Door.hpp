#ifndef Door_H
#define Door_H

#include "GameObject.hpp"

namespace Dungeon {
namespace Entities {

class Door : public GameObject {

    public:
        Door(int x, int y, bool isClosed = false)
            : GameObject(x, y, 0, 0), isClosed(isClosed)
            {}


        void update(const InteractionData_t& interactionData, const Map* map);
        void handleCollision(GameObject& other);
        bool getClosed()
        {
            return this->isClosed;
        }

        ~Door();
    private:
        bool isClosed;
};

}
}

#endif // Door_H