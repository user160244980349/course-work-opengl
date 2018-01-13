//
// Created by user on 12.01.2018.
//

#include <SDL2/SDL_image.h>
#include <core/OpenGl.h>
#include <iostream>
#include "core/Texture.h"

void Texture::load(std::string path, std::string name) {

    _name = name;

    OpenGl::getInstance().genTextures(1, &_id);

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);
    SDL_Surface *_texture = IMG_Load(path.c_str());
    GLenum format;

    if (_texture) {
        switch (_texture->format->BytesPerPixel) {
            default:
                format = GL_RED;
                break;

            case 2:
                format = GL_RG;
                break;

            case 3:
                if (_texture->format->Rmask == 0x000000ff)
                    format = GL_RGB;
                else
                    format = GL_BGR;
                break;

            case 4:
                if (_texture->format->Rmask == 0x000000ff)
                    format = GL_RGBA;
                else
                    format = GL_BGRA;
                break;
        }

        OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
        OpenGl::getInstance().texImage2D(GL_TEXTURE_2D, 0, format, _texture->w, _texture->h, 0, format,
                                         GL_UNSIGNED_BYTE, _texture->pixels);
        OpenGl::getInstance().generateMipmap(GL_TEXTURE_2D);

        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        SDL_FreeSurface(_texture);
    } else
        std::cerr << "texture bitten" << std::endl;

    IMG_Quit();
}

void Texture::bind(Shader shader, unsigned int block) {
    OpenGl::getInstance().activeTexture(GL_TEXTURE0 + block);
    shader.setUniform(_name, block);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
}

Texture::~Texture() {

}
