#ifndef FileTextureManager_H
#define FileTextureManager_H

#include <iostream>
#include <string>

#include "TextureManager.hpp"

namespace Dungeon {
namespace Texture {

class FileTextureManager : public TextureManager {
    public:
        FileTextureManager(std::string& basePath, int width, int height);
        
        FileTextureManager* registerTexture(const std::string& textureId, std::string& relativePath);
    private:
        std::string basePath;
        int width;
        int height;
};

}
}

#endif // FileTextureManager_H
