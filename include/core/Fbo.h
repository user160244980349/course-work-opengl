#ifndef OPENGL_FBO_H
#define OPENGL_FBO_H


#include "BaseBuffer.h"

class Fbo : public BaseBuffer {
public:
    void create() override;
    void remove() override;
    void bind(unsigned int map);
    void unbind();
    virtual unsigned int getId();
};


#endif //OPENGL_FBO_H
