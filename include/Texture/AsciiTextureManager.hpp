#ifndef AsciiTextureManager_H
#define AsciiTextureManager_H

#include <iostream>

#include "TextureManager.hpp"

namespace Dungeon {
namespace Texture {

class AsciiTextureManager : public TextureManager {
    public:
        AsciiTextureManager();

        AsciiTextureManager* registerTexture(const std::string& textureId, char symbol);
};

}
}
#endif // AsciiTextureManager_H
