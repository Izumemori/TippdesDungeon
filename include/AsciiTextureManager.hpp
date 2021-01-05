#ifndef AsciiTextureManager_H
#define AsciiTextureManager_H

#include <iostream>

#include "TextureManager.hpp"

namespace Dungeon {

class AsciiTextureManager : public TextureManager {
    public:
        AsciiTextureManager();

        template <class TObject>
        AsciiTextureManager* registerTile(char symbol)
        {
            this->textures[typeid(TObject)] = std::make_shared<AsciiTexture_t>(symbol);

            return this;
        }
};

}
#endif // AsciiTextureManager_H
