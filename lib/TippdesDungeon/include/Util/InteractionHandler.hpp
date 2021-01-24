#ifndef InteractionHandler_H
#define InteractionHandler_H

#include <functional>
#include <iostream>
#include "../External/TippdesDungeon.hpp"

namespace Dungeon {

    typedef struct InteractionHandler {
        std::string message;
        bool shouldLock;
        std::function<bool(const InteractionData_t&)> handler;

        InteractionHandler(std::string message, std::function<bool(const InteractionData_t&)> handler, bool shouldLock = false)
            : message(message), handler(handler), shouldLock(shouldLock)
        {}
    } InteractionHandler_t;
}

#endif // InteractionHandler_H