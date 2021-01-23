#include "../../include/Infrastructure/Map.hpp"

#include "../../include/Entities/Enemy.hpp"
#include "../../include/Entities/Wall.hpp"
#include "../../include/Entities/Player.hpp"
#include "../../include/Entities/Coin.hpp"
#include "../../include/Entities/Door.hpp"
#include "../../include/Entities/Potion.hpp"

#include <fstream>
#include <iostream>
#include <cmath>

namespace Dungeon {
    void Map::fromAscii(std::string& mapPath, std::shared_ptr<Entities::Player>& player)
    {
        this->player = player;
        this->objects = {};
        std::ifstream file(mapPath);

        file.unsetf(std::ios_base::skipws);

        // TODO: dynamic length
        for (int i = 0; i < 15; i++) 
        {
            for (int j = 0; j < 15; j++)
            {
                char curr;
                file >> curr;
                if (curr == '\n' || curr == '\r')
                    file >> curr;

                std::shared_ptr<Entities::GameObject> currObj;

                switch (curr)
                {
                    case '#':
                        currObj = std::make_shared<Entities::Wall>(i, j, 0, 0);
                        break;

                    case 'E':
                        currObj = std::make_shared<Entities::Enemy>(i, j, 1, 1);
                        break;

                    case 'P':
                        this->player->moveTo(i, j);
                        break;
                    
                    case 'C':
                        switch (rand() % 5)
                        {
                            case 0:
                            case 1:
                                currObj = std::make_shared<Entities::Potion>(i, j, std::max(5, rand() % 15));
                                break;

                            default:
                                currObj = std::make_shared<Entities::Coin>(i, j, std::max(10, rand() % 100)); // TODO: Randomize coins
                                break;
                        }
                        break;

                    case '*':
                    case '+':
                        currObj = std::make_shared<Entities::Door>(i, j, curr == '+');
                        break;

                    default:
                        continue;
                }

                if (currObj.get() != nullptr)
                    this->objects.push_back(std::move(currObj));
            }
        }
    }

    Map::Map()
    {
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                prevMap[i][j] = NO_CHANGE;
    }

    std::array<std::array<int, 15>, 15> Map::diffArray(std::array<std::array<int, 15>, 15> inArray)
    {
        std::array<std::array<int, 15>, 15> outArray;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                outArray[i][j] = NO_CHANGE;

        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                if(inArray[i][j] != prevMap[i][j]) {
                    outArray[i][j] = inArray[i][j];
                }
            }
        }
        prevMap = inArray;

        return outArray;
    }

    std::array<std::array<int, 15>, 15> Map::toArray(int x, int y, int maxX, int maxY)
    {
        std::array<std::array<int, 15>, 15> array;

        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                array[i][j] = FLOOR;

        for (auto& obj : this->objects)
        {
            if (obj == nullptr) continue;
            
            if (obj->getPosition().x > maxX || obj->getPosition().y > maxY
                || obj->getPosition().x < x || obj->getPosition().y < y) continue;
            
            int id = NO_CHANGE;

            if (dynamic_cast<Entities::Wall*>(obj.get()) != nullptr)
                id = WALL;

            if (dynamic_cast<Entities::Enemy*>(obj.get()) != nullptr)
                id = ENEMY_0;

            if (dynamic_cast<Entities::Potion*>(obj.get()) != nullptr)
                id = POTION_0;

            Entities::Coin* coin = nullptr;
            if ((coin = dynamic_cast<Entities::Coin*>(obj.get())) != nullptr)
                id = (coin->getValue() >= 50) ? COIN_1 : COIN_0;

            Entities::Door* door = nullptr;
            if ((door = dynamic_cast<Entities::Door*>(obj.get())) != nullptr)
                id = door->getClosed() ? DOOR_CLOSED : DOOR;

            array[obj->getPosition().x][obj->getPosition().y] = id;
        }

        array[player->getPosition().x][player->getPosition().y] = PLAYER;

        return diffArray(array);
    }

    Map::~Map()
    {
    }

}
