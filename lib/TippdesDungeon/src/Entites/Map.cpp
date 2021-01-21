#include "../../include/Entities/Map.hpp"
#include "../../include/Entities/Entity.hpp"
#include "../../include/Entities/Wall.hpp"
#include "../../include/Entities/Player.hpp"
#include "../../include/Entities/Coin.hpp"

#include <fstream>
#include <iostream>

namespace Dungeon {
    void Map::fromAscii(std::string& mapPath)
    {
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

                std::shared_ptr<GameObject> currObj;

                switch (curr)
                {
                    case '#':
                        currObj = std::make_shared<Dungeon::Wall>(i, j, 0, 0);
                        break;

                    case 'E':
                        currObj = std::make_shared<Dungeon::Entity>(i, j, 1, 1);
                        break;

                    case 'P':
                        currObj = std::make_shared<Dungeon::Player>(i, j);
                        break;
                    
                    case 'C':
                        currObj = std::make_shared<Dungeon::Coin>(i, j, 50);
                        break;

                    default:
                        continue;
                }

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

            if (dynamic_cast<Wall*>(obj.get()) != nullptr)
                id = WALL;

            if (dynamic_cast<Entity*>(obj.get()) != nullptr)
                id = ENEMY_0;

            if (dynamic_cast<Player*>(obj.get()) != nullptr)
                id = PLAYER;

            if (dynamic_cast<Coin*>(obj.get()) != nullptr)
                id = COIN_0;

            array[obj->getPosition().x][obj->getPosition().y] = id;
        }

        return diffArray(array);
    }

    Map::~Map()
    {
    }

}
