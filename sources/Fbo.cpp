#include "../include/core/OpenGl.h"
#include "../include/core/ShadowMap.h"

void Fbo::create() {
    OpenGl::getInstance().genFramebuffers(1, &_id);
}

void Fbo::remove() {
    BaseBuffer::remove();
}

void Fbo::bind(unsigned int map) {
    OpenGl::getInstance().bindFramebuffer(GL_FRAMEBUFFER, _id);
    OpenGl::getInstance().framebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, map, 0);
}

void Fbo::unbind() {
    OpenGl::getInstance().bindFramebuffer(GL_FRAMEBUFFER, 0);
}

unsigned int Fbo::getId() {
    return _id;
}
