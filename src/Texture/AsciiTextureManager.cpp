#include "../../include/Texture/AsciiTextureManager.hpp"

namespace Dungeon {
namespace Texture {
    AsciiTextureManager::AsciiTextureManager()
    {}

    AsciiTextureManager* AsciiTextureManager::registerTexture(const std::string& textureId, char symbol) {
        this->textures[textureId] = std::make_shared<AsciiTexture_t>(symbol);
    
        return this;
    }
}
}
