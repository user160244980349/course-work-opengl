#include "../include/core/OpenGl.h"
#include "../include/core/Ebo.h"

void Ebo::create() {
    OpenGl::getInstance().genBuffers(1, &_id);
}

void Ebo::set(void *indices, unsigned long long int size) {
    OpenGl::getInstance().bindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    OpenGl::getInstance().bufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, indices, GL_STATIC_DRAW);
}

void Ebo::remove() {
    OpenGl::getInstance().deleteBuffers(1, &_id);
}
