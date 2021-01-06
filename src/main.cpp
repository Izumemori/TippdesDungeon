#include "AsciiTextureManager.hpp"

#include "GameObject.hpp"

int main() {
    std::unique_ptr<Dungeon::TextureManager> textureManager = std::make_unique<Dungeon::AsciiTextureManager>();

    ((Dungeon::AsciiTextureManager*)textureManager.get())->registerTile<Dungeon::GameObject>('h');

    auto texture = textureManager->getTexture<Dungeon::GameObject>();

    if (dynamic_cast<AsciiTexture_t*>(texture.get()) != nullptr)
    {
        std::cout << ((AsciiTexture_t*)texture.get())->symbol << std::endl;
    }

    return 0;
}
