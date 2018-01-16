//
// Created by user on 16.01.2018.
//

#include <core/OpenGl.h>
#include "core/Fbo.h"

void Fbo::create() {
    OpenGl::getInstance().genFramebuffers(1, &_id);
}

void Fbo::remove() {
    BaseBuffer::remove();
}

void Fbo::bind() {

}

void Fbo::render(GLuint drawStyle, unsigned long long int usedVertices) {

}

void Fbo::render(GLuint drawStyle, unsigned int first, unsigned long long int usedVertices) {

}
