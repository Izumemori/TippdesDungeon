#include "../lib/TippdesDungeon/include/External/TippdesDungeon.hpp"

#include <unistd.h>
#include <iostream>
#include <curses.h>

void print(GameData_t* gameData, WINDOW* window)
{
    if (gameData == nullptr) return;

    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 15; i++)
        {
            wmove(window, j, i);
            char toPrint = ' ';

            switch (gameData->map[j][i]) {
                case WALL:
                    toPrint = 'X';
                    break;
                
                case ENEMY_0:
                    toPrint = 'E';
                    break;
            }
            
            waddch(window, toPrint);
        }
    }

    wrefresh(window);
}

int main() {

    init();
        
    loadMap("./map_01");

    auto gameData = new GameData_t();

    auto interactionData = InteractionData();

    initscr();
    WINDOW* window = newwin(15, 15, 0, 0);

    while (true) {
        next(gameData, interactionData);
        print(gameData, window);
    
        usleep(1000000);
    }
    return 0;
}
