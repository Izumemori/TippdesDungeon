#ifndef ConsoleRendererBackend_H
#define ConsoleRendererBackend_H

#include <memory>
#include <curses.h>

#include "RendererBackend.hpp"

namespace Dungeon {
namespace Renderer {

class ConsoleRendererBackend : public RendererBackend {

    public:
        ConsoleRendererBackend();
        void render(Texture::Texture_t& texture, Point_t& point);
        void clear();
        ~ConsoleRendererBackend();
    protected:
        WINDOW* window;

};

}
}

#endif // ConsoleRendererBackend_H
