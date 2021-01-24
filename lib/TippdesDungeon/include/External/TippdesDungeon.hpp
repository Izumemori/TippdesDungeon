#ifndef TippdesDungeon_H
#define TippdesDungeon_H

#include "../ID.hpp"

typedef struct GameData {
    int map[15][15];
    char messageText[2][50];
    int health;
    int maxHealth;
    int damage;
    int coins;
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

