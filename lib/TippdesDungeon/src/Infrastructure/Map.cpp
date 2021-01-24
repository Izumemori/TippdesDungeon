#include "../../include/Infrastructure/Map.hpp"
#include "../../include/Util/PowerupType.hpp"
#include "../../include/Util/EnemyType.hpp"

#include "../../include/Entities/Enemy.hpp"
#include "../../include/Entities/Wall.hpp"
#include "../../include/Entities/Player.hpp"
#include "../../include/Entities/Coin.hpp"
#include "../../include/Entities/Door.hpp"
#include "../../include/Entities/Potion.hpp"
#include "../../include/Entities/Powerup.hpp"

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
                        {
                        int health = 100;
                        int damage = 1;
                        float playerSeekRadius = 0;
                        EnemyType type = EnemyType::Blob;
                        
                        switch (rand() % 9)
                        {
                            // blob
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                                health = 50;
                                damage = 5;
                                playerSeekRadius = 0;
                                type = EnemyType::Blob;
                                break;

                            // snake
                            case 4:
                            case 5:
                            case 6:
                                health = 100;
                                damage = 2;
                                playerSeekRadius = 4;
                                type = EnemyType::Snake;
                                break;

                            // ghost
                            case 7:
                            case 8:
                                health = 50;
                                damage = 1;
                                playerSeekRadius = 9;
                                type = EnemyType::Ghost;
                                break;
                                
                        }

                        currObj = std::make_shared<Entities::Enemy>(type, i, j, 1, 1, health, damage, playerSeekRadius);
                        }
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

                    case 'p':
                    {
                        std::function<void(Entities::Player*)> effect;
                        PowerupType type;
                        int cost = 0;
                        switch (rand() % 2)
                        {
                            // damage up/sword
                            case 0:
                                type = PowerupType::Sword;
                                cost = 100;
                                effect = [](Entities::Player* p){
                                    p ->addDamage(10);
                                };
                                break;
                            
                            case 1:
                                type = PowerupType::Heart;
                                cost = 50;
                                effect = [](Entities::Player* p){
                                    p->addMaxHealth(10);
                                };
                                break;

                        }

                        currObj = std::make_shared<Entities::Powerup>(type, i, j, cost, effect);
                    }
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

            Entities::Enemy* enemy = nullptr;
            if ((enemy = dynamic_cast<Entities::Enemy*>(obj.get())) != nullptr)
            {
                switch (enemy->getType())
                {
                    case EnemyType::Blob:
                        id = ENEMY_0;
                        break;
                    case EnemyType::Snake:
                        id = ENEMY_1;
                        break;
                    case EnemyType::Ghost:
                        id = ENEMY_2;
                        break;
                }
            }

            if (dynamic_cast<Entities::Potion*>(obj.get()) != nullptr)
                id = POTION_0;

            Entities::Coin* coin = nullptr;
            if ((coin = dynamic_cast<Entities::Coin*>(obj.get())) != nullptr)
                id = (coin->getValue() >= 50) ? COIN_1 : COIN_0;

            Entities::Door* door = nullptr;
            if ((door = dynamic_cast<Entities::Door*>(obj.get())) != nullptr)
                id = door->getClosed() ? DOOR_CLOSED : DOOR;

            Entities::Powerup* powerup = nullptr;
            if ((powerup = dynamic_cast<Entities::Powerup*>(obj.get())) != nullptr)
            {
                switch (powerup->getType())
                {
                    case PowerupType::Sword:
                        id = SWORD;
                        break;
                    case PowerupType::Heart:
                        id = HEART;
                        break;
                }
            }

            array[obj->getPosition().x][obj->getPosition().y] = id;
        }

        array[player->getPosition().x][player->getPosition().y] = PLAYER;

        return diffArray(array);
    }

    Map::~Map()
    {
    }

}
