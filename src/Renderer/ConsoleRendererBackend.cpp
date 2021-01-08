#include "../../include/Renderer/ConsoleRendererBackend.hpp"

#include <curses.h>

namespace Dungeon {
namespace Renderer {

    ConsoleRendererBackend::ConsoleRendererBackend()
    {
        initscr();
        this->window = newwin(20, 20, 3, 3);
    }

    void ConsoleRendererBackend::render(Texture::Texture_t& texture, Point_t& position)
    {
        if (dynamic_cast<Texture::AsciiTexture_t*>(&texture) == nullptr)
        {
            throw std::runtime_error("Function \"render\" of \"ConsoleRendererBackend\" can only operate on Textures of type \"AsciiTexture_t\" and its derivitive types");
        }
        
        auto& asciiTexture = *reinterpret_cast<Texture::AsciiTexture_t*>(&texture);
    
        wmove(this->window, (int)position.x, (int)position.y);
        waddch(this->window, asciiTexture.symbol);

        wrefresh(this->window);
    }

    void ConsoleRendererBackend::clear()
    {
        wclear(this->window);
    }

    ConsoleRendererBackend::~ConsoleRendererBackend()
    {
        delwin(this->window);
        endwin();
    }

}
}
