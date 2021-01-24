#ifndef InteractionHandler_H
#define InteractionHandler_H

#include <functional>
#include <iostream>
#include "../External/TippdesDungeon.hpp"

namespace Dungeon {

    typedef struct InteractionHandler {
        std::string message;
        std::function<bool(const InteractionData_t&)> handler;

        InteractionHandler(std::string message, std::function<bool(const InteractionData_t&)> handler)
            : message(message), handler(handler)
        {}
    } InteractionHandler_t;
}

#endif // InteractionHandler_H