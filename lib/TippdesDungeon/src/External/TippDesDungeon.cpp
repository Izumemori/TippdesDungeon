#include "../../include/External/TippdesDungeon.hpp"

#include "../../include/Entities/GameManager.hpp"

#include <memory>
#include <sstream>

static std::unique_ptr<Dungeon::GameManager> gameManager;

void init()
{
    gameManager = std::make_unique<Dungeon::GameManager>();
}

void loadMap(const char* path)
{
    std::stringstream sstream;
    sstream << path;
    auto mapPath = sstream.str();
    gameManager->loadMap(mapPath);
}

void next(GameData_t* gameData, const InteractionData_t& interactionData)
{
    gameManager->next(gameData, interactionData);
}

void end()
{
    gameManager->~GameManager();
}
