#ifndef TextureManager_H
#define TextureManager_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>

#include "Texture.hpp"

namespace Dungeon {
namespace Texture {

class TextureManager {
    public:
        TextureManager() noexcept;

        std::shared_ptr<Texture> getTexture(std::string& texture_id);

        virtual ~TextureManager() = 0;
    protected:
        std::unordered_map<std::string, std::shared_ptr<Texture_t>> textures;
};

}
}
#endif // TextureManager_H
