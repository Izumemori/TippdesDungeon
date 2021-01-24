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

    void fillMessage(GameData_t* gameData, std::string message)
    {
        std::istringstream streamMessage(message);
        std::string lineOne;
        std::string lineTwo;
        getline(streamMessage, lineOne);
        getline(streamMessage, lineTwo);

        sprintf(gameData->messageText[0], "%s", lineOne.c_str());
        sprintf(gameData->messageText[1], "%s", lineTwo.c_str());
    }

    void GameManager::loadRandomMap()
    {
        std::vector<std::string> maps = {};
        std::vector<std::string> shops = {};

        for (auto item : std::filesystem::directory_iterator(this->mapBasePath, std::filesystem::directory_options::skip_permission_denied))
        {
            auto stem = item.path().stem().string();

            if (stem.rfind("map", 0) == 0)
                maps.push_back(item.path().string());
            else if (stem.rfind("shop", 0) == 0)
                shops.push_back(item.path().string());

        }

        std::string res;
        if (this->mapCount % 4 == 0)
            res = *select_randomly(shops.begin(), shops.end());
        else 
            res = *select_randomly(maps.begin(), maps.end());

        this->map->objects.clear();
        this->map->fromAscii(res, this->player);
        this->mapCount++;
    }

    void GameManager::next(GameData_t* gameData, const InteractionData_t& interactionData)
    {
        fillMessage(gameData, " \n ");

        if (this->player->getHandler().get() != nullptr)
        {
            if (this->player->getHandler()->handler(interactionData))
                std::unique_ptr<InteractionHandler_t> tmp = std::move(this->player->getHandler());
            else fillMessage(gameData, this->player->getHandler()->message);


            if (this->player->getHandler().get() != nullptr && this->player->getHandler()->shouldLock)
                return;
        }
        
        if (this->player->getMapDone())
        {
            this->player->resetMapDone();
            this->loadRandomMap();
        }

        this->player->update(interactionData, this->map.get());

        for (auto& obj : this->map->objects)
        {
            if (this->player->checkCollision(*obj))
            {
                this->player->handleCollision(*obj);
            }
        }

         this->map->objects.erase(std::remove_if(this->map->objects.begin(),
            this->map->objects.end(), 
            [](std::shared_ptr<Entities::GameObject>& obj) -> bool
                {
                    return obj->getRemovable();
                }
        ), this->map->objects.end()); // Remove entities the player has killed

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

        gameData->damage = this->player->getDamage();
        gameData->health = this->player->getHealth();
        gameData->maxHealth = this->player->getMaxHealth();
        gameData->coins = this->player->getCoins();

        if(this->player->getHealth() <= 0)
        {
            gameData->gameEnd = true;
            gameData->map[player->getPosition().x][player->getPosition().y] = DEAD;
            sprintf(gameData->messageText[0], "You are dead");
            sprintf(gameData->messageText[1], "Coins: %d",
                this->player->getCoins());
        }

        if (this->player->getHandler().get() != nullptr)
            fillMessage(gameData, this->player->getHandler()->message);
    }

    GameManager::~GameManager() 
    {
    }
}
