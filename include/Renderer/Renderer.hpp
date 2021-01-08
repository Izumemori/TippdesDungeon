#ifndef Renderer_H
#define Renderer_H

#include <memory>

#include "RendererBackend.hpp"
#include "../Texture/TextureManager.hpp"
#include "../Entities/GameObject.hpp"
#include "../Entities/Point.hpp"

namespace Dungeon {
namespace Renderer {

class Renderer {
    public:
        Renderer(std::shared_ptr<Texture::TextureManager> textureManager, std::shared_ptr<RendererBackend> rendererBackend) noexcept;

        template<class TObject>
        void draw(TObject& object)
        {
            static_assert(std::is_base_of<GameObject, TObject>(), "Invalid type passed to \"Renderer::draw\"");

            auto texture = this->textureManager->getTexture(static_cast<GameObject*>(&object)->getTextureId());
        
            this->rendererBackend->render(*texture.get(), object.getPosition());
        }
        
        void clear();

    protected:
        std::shared_ptr<Texture::TextureManager> textureManager;
        std::shared_ptr<RendererBackend> rendererBackend;
};

}
}

#endif // Renderer_H
