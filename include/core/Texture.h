#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H


#include <SDL_surface.h>

#include "Shader.h"
#include "../interfaces/ITexture.h"

class Texture : public ITexture {
public:
    Texture() = default;
    ~Texture();
    void load(std::string path, std::string name) override;
    void bind(Shader shader, unsigned int block) override;

protected:
    unsigned int _id;
    std::string _name;
};


#endif //OPENGL_TEXTURE_H
