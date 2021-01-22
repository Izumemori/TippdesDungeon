#ifndef Map_H
#define Map_H

#include "../Entities/GameObject.hpp"
#include "../Entities/Player.hpp"

#include <vector>

namespace Dungeon {
class Map {
    public:
        Map();
        void fromAscii(std::string& data, std::shared_ptr<Entities::Player>& player);
        std::vector<std::shared_ptr<Entities::GameObject>> objects;
        std::shared_ptr<Entities::Player> player;
        std::array<std::array<int, 15>, 15> toArray(int x, int y, int maxX, int maxY);
        ~Map();
    private:
        std::array<std::array<int, 15>, 15> prevMap;
        std::array<std::array<int, 15>, 15> diffArray(std::array<std::array<int, 15>, 15>);
};

}

#endif // Map_H
