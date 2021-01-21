#include "../../include/External/TippdesDungeon.hpp"
#include "../../include/Infrastructure/GameManager.hpp"

#include <memory>
#include <sstream>

static std::unique_ptr<Dungeon::GameManager> gameManager;

void init(const char* mapPath)
{
    std::stringstream sstream;
    sstream << mapPath;
    auto path = sstream.str();
    gameManager = std::make_unique<Dungeon::GameManager>(path);
}

void next(GameData_t* gameData, const InteractionData_t& interactionData)
{
    gameManager->next(gameData, interactionData);
}

void end()
{
    gameManager->~GameManager();
}
