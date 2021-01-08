#include "../../include/Texture/TextureManager.hpp"

namespace Dungeon {
namespace Texture {
    TextureManager::TextureManager() noexcept
    {
        this->textures = std::unordered_map<std::string, std::shared_ptr<Texture_t>>();
    }

    TextureManager::~TextureManager()
    {
        this->textures.clear();
    }

    std::shared_ptr<Texture_t> TextureManager::getTexture(std::string& texture_id)
    {
        return this->textures[texture_id];
    }
}
}
