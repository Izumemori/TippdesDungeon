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
                case NO_CHANGE:
                    continue;
                    break;

                case WALL:
                    toPrint = 'X';
                    break;
                
                case ENEMY_0:
                    toPrint = 'B';
                    break;

                case ENEMY_1:
                    toPrint = 'S';
                    break;

                case ENEMY_2:
                    toPrint = 'G';
                    break;

                case DEAD:
                case PLAYER:
                    toPrint = 'P';
                    break;

                case COIN_0:
                    toPrint = 'c';
                    break;

                case COIN_1:
                    toPrint = 'C';
                    break;
                
                case DOOR_CLOSED:
                    toPrint = '+';
                    break;

                case DOOR:
                    toPrint = '*';
                    break;
                
                case POTION_0:
                    toPrint = 'p';
                    break;

                case SWORD:
                    toPrint = 's';
                    break;
                
                case HEART:
                    toPrint = 'h';
                    break;
            }
            
            waddch(window, toPrint);
        }
    }

    wmove(window, 17, 5);
    waddstr(window, gameData->messageText[0]);

    wrefresh(window);
}

int main() {

    init("../../maps/");
        
    auto gameData = new GameData_t();

    auto interactionData = InteractionData();

    initscr();
    WINDOW* window = newwin(16, 20, 0, 0);


    while (true) {
        //nodelay(window, true);

        next(gameData, interactionData);
        print(gameData, window);

        interactionData.input = wgetch(window);
        //usleep(100000);
    }
    return 0;
}
