#include "../../include/Texture/FileTextureManager.hpp"
#include "../../include/Texture/Texture.hpp"

namespace Dungeon {
namespace Texture {
    FileTextureManager::FileTextureManager(std::string& basePath, int width, int height) {
        this->basePath = basePath;
        this->width = width;
        this->height = height;
    }

    FileTextureManager* FileTextureManager::registerTexture(const std::string& textureId, std::string& relativePath) {
        this->textures[textureId] = std::make_shared<FileTexture_t>(this->basePath.append(relativePath), this->width, this->height);
    
        return this;
    }
}
}
