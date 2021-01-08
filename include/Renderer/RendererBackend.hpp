#ifndef RendererBackend_H
#define RendererBackend_H

#include "../Entities/Point.hpp"
#include "../Texture/Texture.hpp"

namespace Dungeon {
namespace Renderer {

class RendererBackend {
    public:
        virtual void render(Texture::Texture_t& texture, Point_t& point) = 0;
        virtual void clear() = 0;
};

}
}

#endif // RendererBackend_H
