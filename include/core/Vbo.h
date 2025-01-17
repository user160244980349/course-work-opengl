#ifndef OPENGL_VBO_H
#define OPENGL_VBO_H


#include <glm/vec3.hpp>

#include "Shader.h"
#include "BaseBuffer.h"

class Vbo : public BaseBuffer {
public:
    void create() override;
    void allocate(void *data, unsigned int long long size);
    void attach(Shader shader, std::string attribName, unsigned int count, unsigned int size, void *offset);
    void remove() override;

private:
    unsigned int long long _size;
    void *_data;
};


#endif //OPENGL_VBO_H
