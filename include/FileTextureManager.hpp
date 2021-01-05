#ifndef FileTextureManager_H
#define FileTextureManager_H

#include <iostream>
#include <string>

#include "TextureManager.hpp"

namespace Dungeon {

class FileTextureManager : public TextureManager {
    public:
        FileTextureManager(std::string& basePath, int width, int height);
        
        template<class TObject>
        FileTextureManager* registerTile(std::string& relativePath) {
            this->textures[typeid(TObject)] = std::make_shared<FileTexture_t>(relativePath, this->width, this->height);     
        
            return this;
      
        }
    private:
        std::string basePath;
        int width;
        int height;
};

}

#endif // FileTextureManager_H
