#ifndef Texture_H
#define Texture_H

#include <iostream>

typedef struct Texture {
    virtual ~Texture() = 0;
} Texture_t;

typedef struct FileTexture : public Texture {
    std::string& relativePath;
    int width;
    int height;

    FileTexture(std::string& relativePath, int width, int height) 
        : relativePath(relativePath), width(width), height(height)
    {}
} FileTexture_t;

typedef struct AsciiTexture : public Texture {
    char symbol;

    AsciiTexture(char symbol) : symbol(symbol)
    {}
} AsciiTexture_t;

#endif //Texture_H
