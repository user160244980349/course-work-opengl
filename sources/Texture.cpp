//
// Created by user on 11.01.2018.
//

#include <SDL2/SDL_image.h>
#include <core/OpenGl.h>
#include <iostream>
#include "core/Texture.h"

unsigned int Texture::_id = 0;
std::string Texture::_path = "";

void Texture::load(std::string path, unsigned int type) {
    if (_path == path)
        return;
    _path = path;

    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *image = IMG_Load(path.c_str());

    OpenGl::getInstance().genTextures(1, &_id);
    OpenGl::getInstance().bindTexture(type, _id);

    OpenGl::getInstance().texImage2D(type, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
    OpenGl::getInstance().generateMipmap(type);

    OpenGl::getInstance().texParameteri(type, GL_TEXTURE_WRAP_R, GL_REPEAT);
    OpenGl::getInstance().texParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    OpenGl::getInstance().texParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
    OpenGl::getInstance().texParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    OpenGl::getInstance().texParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(image);
    IMG_Quit();
}

void Texture::bind() {
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
}
