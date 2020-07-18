#ifndef OPENGL_ITEXTURE_H
#define OPENGL_ITEXTURE_H


#include "../core/Shader.h"

class ITexture {
public:
    virtual ~ITexture() = default;
    virtual void load(std::string path, std::string name) = 0;
    virtual void bind(Shader shader, unsigned int block) = 0;
};


#endif //OPENGL_ITEXTURE_H
