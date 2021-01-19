#include <vector>
#include <chrono>
#include <unistd.h>

#include "../include/Renderer/ConsoleRendererBackend.hpp"
#include "../include/Renderer/Renderer.hpp"

#include "../include/Entities/GameTime.hpp"
#include "../include/Entities/GameObject.hpp"
#include "../include/Entities/Entity.hpp"
#include "../include/Entities/Wall.hpp"

#include "../include/Texture/AsciiTextureManager.hpp"

const std::string WALL_TEXTURE = "WALL_TEXTURE";
const std::string ENTITY_TEXTURE = "ENTITY_TEXTURE";

int main() {
    std::shared_ptr<Dungeon::Texture::TextureManager> textureManager = std::make_shared<Dungeon::Texture::AsciiTextureManager>();

    ((Dungeon::Texture::AsciiTextureManager*)textureManager.get())->registerTexture(WALL_TEXTURE, 'x')
        ->registerTexture(ENTITY_TEXTURE, 'y');

    std::shared_ptr<Dungeon::Renderer::RendererBackend> rendererBackend = std::make_shared<Dungeon::Renderer::ConsoleRendererBackend>();
    std::unique_ptr<Dungeon::Renderer::Renderer> renderer = std::make_unique<Dungeon::Renderer::Renderer>(textureManager, rendererBackend);

    std::vector<Dungeon::GameObject*> objects { 
        new Dungeon::Wall(WALL_TEXTURE, 0, 0, 0, 0, 1, 1),
        new Dungeon::Entity(ENTITY_TEXTURE, 1, 0, 5.0f, 0, 1, 1),
        new Dungeon::Wall(WALL_TEXTURE, 5, 0, 0, 0, 1, 1) };

    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    Dungeon::GameTime_t gameTime(0);

    while (true)
    {
        renderer->clear();

        begin = std::chrono::high_resolution_clock::now();

        for (auto& obj : objects)
        {

            for (auto& obj2 : objects) {
                if (obj->checkCollision(*obj2))
                {
                    obj->handleCollision(*obj2);
                }
            }

            obj->update(gameTime);

            renderer->draw(*obj);
        }
        
        usleep(10000);

        end = std::chrono::high_resolution_clock::now();

        auto timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        gameTime = Dungeon::GameTime_t(timeElapsed);
    }

    return 0;
}
