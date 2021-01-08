#include "../../include/Renderer/Renderer.hpp"

namespace Dungeon {
namespace Renderer {

    Renderer::Renderer(std::shared_ptr<Texture::TextureManager> textureManager, std::shared_ptr<RendererBackend> rendererBackend) noexcept
    {
        this->textureManager = textureManager;
        this->rendererBackend = rendererBackend;
    }

    void Renderer::clear()
    {
        this->rendererBackend->clear();
    }
}
}
