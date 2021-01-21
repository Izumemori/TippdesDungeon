#include "../../include/Entities/Map.hpp"
#include "../../include/Entities/Entity.hpp"
#include "../../include/Entities/Wall.hpp"

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

                GameObject* currObj = nullptr;

                switch (curr)
                {
                    case '#':
                        currObj = new Dungeon::Wall(i, j, 0, 0);
                        break;

                    case 'E':
                        currObj = new Dungeon::Entity(i, j, 1, 1);
                        break;
                }

                if (currObj != nullptr) {
                    this->objects.push_back(currObj);
                }

            }
        }
    }

    Map::Map()
    {
    }

    std::array<std::array<int, 15>, 15> Map::toArray(int x, int y, int maxX, int maxY)
    {
        std::array<std::array<int, 15>, 15> array;

        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                array[i][j] = 0;

        // TODO: respect arguments
        for (auto obj : this->objects)
        {
            if (obj == nullptr) continue;

            int id = NO_CHANGE;

            if (dynamic_cast<Wall*>(obj) != nullptr)
                id = WALL;

            if (dynamic_cast<Entity*>(obj) != nullptr)
                id = ENEMY_0;

            if ((int)obj->getPosition().x > 14 || (int)obj->getPosition().y > 14) continue;

            array[(int)obj->getPosition().x][(int)obj->getPosition().y] = id;
        }

        return array;
    }

    Map::~Map()
    {
        for (auto obj : this->objects)
            delete obj;
    }

}
