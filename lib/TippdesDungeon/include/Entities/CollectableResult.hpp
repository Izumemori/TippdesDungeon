#ifndef CollectableResult_H
#define CollectableResult_H

namespace Dungeon {

typedef struct CollectableResult {
    int Coins;

    CollectableResult(int coins)
        : Coins(coins)
        {}

} CollectableResult_t;

}

#endif // CollectableResult_H