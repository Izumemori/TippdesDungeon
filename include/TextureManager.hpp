#ifndef TextureManager_H
#define TextureManager_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>

#include "GameObject.hpp"
#include "Texture.hpp"

namespace Dungeon {

class TextureManager {
    public:
        TextureManager() noexcept;

        template<class TObject>
        std::shared_ptr<Texture> getTexture()
        {
            return this->textures[typeid(TObject)];
        }

        virtual ~TextureManager() = 0;
    protected:
        std::unordered_map<std::type_index, std::shared_ptr<Texture>> textures;
};

}
#endif // TextureManager_H
