#ifndef TippdesDungeon_H
#define TippdesDungeon_H

#include "../ID.hpp"

typedef struct GameData {
    int map[15][15];
    char statsText[50];
    bool gameEnd = false;
} GameData_t;

typedef struct InteractionData {
    char input;
} InteractionData_t;

extern "C" {
    void init(const char* mapPath);

    void next(GameData_t* gameData, const InteractionData_t& interactionData);

    void end();
}

#endif // TippdesDungeon_H

