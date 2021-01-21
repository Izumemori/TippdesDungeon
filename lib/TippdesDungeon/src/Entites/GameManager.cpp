#include "../../include/Entities/GameManager.hpp"
#include "../../include/Entities/GameTime.hpp"

#include <iostream>

namespace Dungeon {

    GameManager::GameManager()
    {
        this->previousGameData = nullptr;
        this->map = std::make_unique<Map>();
    }

    void GameManager::loadMap(std::string& mapPath)
    {
        this->map->fromAscii(mapPath);
    }

    void GameManager::next(GameData_t* gameData, const InteractionData_t& interactionData)
    {
        for (auto obj : this->map->objects)
        {
            obj->update(interactionData);
            
            for (auto obj2 : this->map->objects)
            {
                if (obj->checkCollision(*obj2))
                {
                    obj->handleCollision(*obj2);
                }
            }
        }

        auto map = this->map->toArray(0, 0, 15, 15);

        for (int i = 0; i < 15; i++)
        {
            for (int y = 0; y < 15; y++)
            {
                gameData->map[i][y] = map[i][y];
            }
        }
    }

    GameManager::~GameManager() 
    {
    }
}
