#ifndef CollectableResult_H
#define CollectableResult_H

namespace Dungeon {

typedef struct CollectableResult {
    int coins;

    CollectableResult(int coins)
        : coins(coins)
        {}

} CollectableResult_t;

}

#endif // CollectableResult_H