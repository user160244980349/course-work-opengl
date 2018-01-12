//
// Created by user on 13.10.2017.
//

#include <core/OpenGl.h>
#include <iostream>
#include "core/Vbo.h"

void Vbo::create() {
    OpenGl::getInstance().genBuffers(1, &_id);
}

void Vbo::set(void *data, unsigned int long long size) {
    OpenGl::getInstance().bindBuffer(GL_ARRAY_BUFFER, _id);
    OpenGl::getInstance().bufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Vbo::attach(Shader shader, std::string attribName, unsigned int count, unsigned int size, void *offset) {
    auto attribLocation = static_cast<unsigned int>(OpenGl::getInstance().getAttribLocation(shader.getId(),
                                                                                            attribName.c_str()));
    OpenGl::getInstance().vertexAttribPointer(attribLocation, count, GL_FLOAT, GL_FALSE, size,
                                              offset);
}

void Vbo::remove() {
    OpenGl::getInstance().deleteBuffers(1, &_id);
}
