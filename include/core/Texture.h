//
// Created by user on 12.01.2018.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H


#include <SDL2/SDL_surface.h>
#include <interfaces/ITexture.h>
#include "Shader.h"

class Texture : public ITexture {
public:

    Texture() = default;

    ~Texture();

    void load(std::string path, std::string name, unsigned int index) override;

    void bind(Shader shader, unsigned int block) override;

protected:
    std::string _bindName;
    unsigned int _id;
    unsigned int _index;
    std::string _name;

};


#endif //OPENGL_TEXTURE_H