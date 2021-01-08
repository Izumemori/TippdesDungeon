#ifndef Texture_H
#define Texture_H

#include <iostream>

namespace Dungeon {
namespace Texture {

typedef struct Texture {
    virtual ~Texture() = 0;
} Texture_t;

typedef struct FileTexture : public Texture {
    std::string& path;
    int width;
    int height;

    FileTexture(std::string& path, int width, int height) 
        : path(path), width(width), height(height)
    {}
} FileTexture_t;

typedef struct AsciiTexture : public Texture {
    char symbol;

    AsciiTexture(char symbol) : symbol(symbol)
    {}
} AsciiTexture_t;

}
}
#endif //Texture_H
