//
// Created by user on 21.10.2017.
//


#include <objects/Cube.h>
#include <SDL2/SDL_timer.h>

Cube::~Cube() {
    _buffers.vao.remove();
    _buffers.vbo.remove();
    _buffers.ebo.remove();
}

Cube::Cube() : BaseObject() {

    _shaderProgram.compileShader("../resource/shaders/FirstVertex.glsl", VERTEX);
    _shaderProgram.compileShader("../resource/shaders/FirstFragment.glsl", FRAGMENT);
    _shaderProgram.link();

    _vertices.emplace_back(glm::vec3( 1.0f, 1.0f,-1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f,-1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f,-1.0f,-1.0f));
    _vertices.emplace_back(glm::vec3( 1.0f,-1.0f,-1.0f));

    _vertices.emplace_back(glm::vec3( 1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f,-1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3( 1.0f,-1.0f, 1.0f));

    _order.emplace_back(0u);
    _order.emplace_back(3u);
    _order.emplace_back(1u);
    _order.emplace_back(1u);
    _order.emplace_back(3u);
    _order.emplace_back(2u);

    _order.emplace_back(2u);
    _order.emplace_back(5u);
    _order.emplace_back(1u);
    _order.emplace_back(6u);
    _order.emplace_back(5u);
    _order.emplace_back(2u);

    _order.emplace_back(5u);
    _order.emplace_back(7u);
    _order.emplace_back(4u);
    _order.emplace_back(6u);
    _order.emplace_back(7u);
    _order.emplace_back(5u);

    _order.emplace_back(0u);
    _order.emplace_back(4u);
    _order.emplace_back(3u);
    _order.emplace_back(3u);
    _order.emplace_back(4u);
    _order.emplace_back(7u);

    _order.emplace_back(2u);
    _order.emplace_back(7u);
    _order.emplace_back(6u);
    _order.emplace_back(3u);
    _order.emplace_back(7u);
    _order.emplace_back(2u);

    _order.emplace_back(1u);
    _order.emplace_back(4u);
    _order.emplace_back(0u);
    _order.emplace_back(5u);
    _order.emplace_back(4u);
    _order.emplace_back(1u);

    _buffers.vao.create();
    _buffers.vao.bind();

    _buffers.vbo.create();
    _buffers.vbo.set(_vertices.data(), static_cast<GLuint>(_vertices.size()));

    _buffers.ebo.create();
    _buffers.ebo.set(_order.data(), static_cast<GLuint>(_order.size()));
}

void Cube::draw(ICamera &camera) {
    _shaderProgram.use();
    camera.display(_shaderProgram);
    _shaderProgram.setUniform("model", _transform.model);
    _buffers.vao.bind(GL_TRIANGLES, static_cast<GLuint>(_order.size()));
}

void Cube::update() {
    _transform.model = glm::rotate(_transform.model, 0.05f, glm::vec3(0.0f, 1.0f, 0.0f));
    _transform.model = glm::translate(_transform.model, glm::vec3(0.0f, sinf((SDL_GetTicks() + _id) * 0.005f) * 0.5f, 0.0f));
}

void Cube::translate(glm::vec3 position) {
    _transform.model = glm::translate(_transform.model, position);
}

