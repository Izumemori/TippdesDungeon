#ifndef CollectableResult_H
#define CollectableResult_H

#include <functional>
#include "../Entities/Player.hpp"

namespace Dungeon {

typedef struct CollectableResult {
    int coins;
    int health;
    std::function<void(Entities::Player*)> function;

    CollectableResult(int coins, int health, std::function<void(Entities::Player*)> function)
        : coins(coins), health(health), function(function)
    {}

    CollectableResult(int coins, int health)
        : coins(coins), health(health)
    {}

    CollectableResult()
    {}

} CollectableResult_t;

}

#endif // CollectableResult_H