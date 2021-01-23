#include "../../include/Infrastructure/GameManager.hpp"
#include "../../include/Entities/Player.hpp"
#include "../../include/Util/Utils.hpp"

#include <iostream>
#include <algorithm>
#include <filesystem>

namespace Dungeon {

    GameManager::GameManager(std::string& mapPath)
    {
        this->mapBasePath = mapPath;
        this->previousGameData = nullptr;
        this->map = std::make_unique<Map>();
        this->player = std::make_shared<Entities::Player>();
    
        this->loadRandomMap();
    }

    void GameManager::loadRandomMap()
    {
        std::vector<std::string> maps = {};

        for (auto item : std::filesystem::directory_iterator(this->mapBasePath, std::filesystem::directory_options::skip_permission_denied))
        {
            if (item.path().stem().string().rfind("map", 0) == 0)
            {
                maps.push_back(item.path().string());
            }
        }

        auto res = *select_randomly(maps.begin(), maps.end());
        
        this->map->objects.clear();
        this->map->fromAscii(res, this->player);
    }

    void GameManager::next(GameData_t* gameData, const InteractionData_t& interactionData)
    {
        if (this->player->getMapDone() && interactionData.input == 'e')
        {
            this->player->resetMapDone();
            this->loadRandomMap();
        }
        else if (this->player->getMapDone() && interactionData.input != 'e')
        {
            return;
        }

        this->player->update(interactionData, this->map.get());

        for (auto& obj : this->map->objects)
        {
            if (this->player->checkCollision(*obj))
            {
                this->player->handleCollision(*obj);
            }
        }
    
        for (auto& obj : this->map->objects)
        {
            obj->update(interactionData, this->map.get());

            if (obj->checkCollision(*this->player))
            {
                obj->handleCollision(*player);
            }

            for (auto& obj2 : this->map->objects)
            {
                if (obj->checkCollision(*obj2))
                {
                    obj->handleCollision(*obj2);
                }
            }
        }

        this->map->objects.erase(std::remove_if(this->map->objects.begin(),
            this->map->objects.end(), 
            [](std::shared_ptr<Entities::GameObject>& obj) -> bool
                {
                    return obj->getRemovable();
                }
        ), this->map->objects.end());

        auto map = this->map->toArray(0, 0, 15, 15);

        for (int i = 0; i < 15; i++)
        {
            for (int y = 0; y < 15; y++)
            {
                gameData->map[i][y] = map[i][y];
            }
        }

        if (this->player->getMapDone())
        {
            sprintf(gameData->statsText, "Press %s to continue", "E");
            return;
        }

        sprintf(gameData->statsText, "Health: %d Coins: %d",
            this->player->getHealth(),
            this->player->getCoins());

        if(this->player->getHealth() <= 0)
        {
            gameData->gameEnd = true;
            gameData->map[player->getPosition().x][player->getPosition().y] = DEAD;
            sprintf(gameData->statsText, "You are dead, Coins: %d",
                this->player->getCoins());
        }
    }

    GameManager::~GameManager() 
    {
    }
}
