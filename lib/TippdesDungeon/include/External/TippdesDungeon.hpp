#ifndef TippdesDungeon_H
#define TippdesDungeon_H

#include "../ID.hpp"

typedef struct GameData {
    int* map[15][15];
} GameData_t;

typedef struct InteractionData {
    char input;
} InteractionData_t;

extern "C" {
    void init();

    void loadMap(char* map);

    void next(GameData_t* gameData, const InteractionData_t& interactionData);

    void end();
}

#endif // TippdesDungeon_H

