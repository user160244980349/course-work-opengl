//
// Created by user on 12.01.2018.
//

#ifndef OPENGL_ITEXTURE_H
#define OPENGL_ITEXTURE_H


#include <core/Shader.h>

class ITexture {
public:

    virtual ~ITexture() = default;

    virtual void load(std::string path, std::string name) {};

    virtual void bind(Shader shader, unsigned int block) {};

};


#endif //OPENGL_ITEXTURE_H
