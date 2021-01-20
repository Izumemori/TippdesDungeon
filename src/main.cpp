#include "../lib/TippdesDungeon/include/External/TippdesDungeon.hpp"

#include <iostream>

int main() {

    init();
        
    loadMap("./map_01");

    auto gameData = new GameData_t();

    auto interactionData = InteractionData();

    next(gameData, interactionData);

    for (auto arr : gameData->map)
    {
        for (int i = 0; i < 15; i++)
        {
            char toPrint = ' ';

            switch (arr[i]) {
                case WALL:
                    toPrint = 'X';
                    break;
                
                case ENEMY_0:
                    toPrint = 'E';
                    break;
            }

            std::cout << toPrint;
        }

        std::cout << std::endl;
    }

    std::cin.get();

    return 0;
}
