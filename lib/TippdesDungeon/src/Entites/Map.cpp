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

    Map::~Map()
    {
        for (auto obj : this->objects)
            delete obj;
    }

}
