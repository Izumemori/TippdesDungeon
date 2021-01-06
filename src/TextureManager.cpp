#include "TextureManager.hpp"

namespace Dungeon {
    TextureManager::TextureManager() noexcept
    {
        this->textures = std::unordered_map<std::type_index, std::shared_ptr<Texture_t>>();
    }

    TextureManager::~TextureManager()
    {
        this->textures.clear();
    }
}
