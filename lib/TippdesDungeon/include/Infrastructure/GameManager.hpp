#ifndef GameManager_H
#define GameManager_H

#include "../External/TippdesDungeon.hpp"
#include "Map.hpp"
#include "../Entities/Player.hpp"
#include <memory>
#include <string>

namespace Dungeon {

class GameManager {
    public:
        GameManager(std::string& mapPath);
        void loadRandomMap();
        void next(GameData_t* gameData, const InteractionData_t& InteractionData);
        ~GameManager();

    private:
        std::unique_ptr<GameData_t> previousGameData;
        std::unique_ptr<Map> map;
        std::shared_ptr<Entities::Player> player;
        std::string mapBasePath;
        int mapCount = 0;
};

}

#endif // GameManager_H
