#ifndef CollectableResult_H
#define CollectableResult_H

namespace Dungeon {

typedef struct CollectableResult {
    int coins;
    int health;

    CollectableResult(int coins, int health)
        : coins(coins), health(health)
        {}

} CollectableResult_t;

}

#endif // CollectableResult_H