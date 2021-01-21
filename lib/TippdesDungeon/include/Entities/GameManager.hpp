#ifndef GameManager_H
#define GameManager_H

#include "../External/TippdesDungeon.hpp"
#include "../Entities/Map.hpp"

#include <memory>

namespace Dungeon {

class GameManager {
    public:
        GameManager();
        void loadMap(std::string& mapPath);
        void next(GameData_t* gameData, const InteractionData_t& InteractionData);
        ~GameManager();

    private:
        std::unique_ptr<GameData_t> previousGameData;
        std::unique_ptr<Map> map;
};

}

#endif // GameManager_H
