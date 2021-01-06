#include "FileTextureManager.hpp"
#include "Texture.hpp"

namespace Dungeon {
    FileTextureManager::FileTextureManager(std::string& basePath, int width, int height) {
        this->basePath = basePath;
        this->width = width;
        this->height = height;
    }
}
