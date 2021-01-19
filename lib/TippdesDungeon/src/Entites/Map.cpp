#include "../../include/Entities/Map.hpp"

namespace Dungeon {
    Map Map::fromAscii(std::string& mapPath)
    {
        // TODO: load map
    
        return Map();
    }

    Map::Map()
    {
    }
    Map::Map(std::vector<GameObject*>& objects)
    {
        this->objects = objects;
    }

    std::array<std::array<int, 15>, 15> Map::toArray(int x, int y, int maxX, int maxY)
    {
        // TODO
    }

    Map::~Map()
    {
        for (auto obj : this->objects)
            delete obj;
    }

}
