//
// Created by user on 21.10.2017.
//


#include <objects/Cube.h>
#include <SDL_timer.h>

int application::objects::Cube::prepare() {

    _shaders.emplace_back(graphics::Shader(
            "../src/shaders/FirstVertex.glsl",
            "../src/shaders/FirstFragment.glsl")
    );

    _shaders.front().use();

    _vertices.emplace_back(graphics::Vertex3d{glm::vec4( 1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::Vertex3d{glm::vec4(-1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::Vertex3d{glm::vec4(-1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    _vertices.emplace_back(graphics::Vertex3d{glm::vec4( 1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    _vertices.emplace_back(graphics::Vertex3d{glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::Vertex3d{glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::Vertex3d{glm::vec4(-1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    _vertices.emplace_back(graphics::Vertex3d{glm::vec4( 1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

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

    _buffers.ubo.create();
    _buffers.ubo.set(static_cast<GLvoid*>(&_transform), sizeof(_transform));
    _buffers.ubo.connect(_shaders.front().shaderProgramId, TRANSFORM_BIND_INDEX, "object");

    return 0;
}

int application::objects::Cube::draw() {

//    _transform.model = glm::rotate(_transform.model, 0.05f, glm::vec3(0.0f, 1.0f, 0.0f));
//    _transform.model = glm::translate(_transform.model, glm::vec3(0.0f, sinf(SDL_GetTicks() * 0.005f) * 0.1f, 0.0f));
//    _buffers.ubo.update(static_cast<GLvoid*>(&_transform), sizeof(_transform));
    _buffers.vao.bind(GL_TRIANGLES, static_cast<GLuint>(_order.size()));

    return 0;
}

int application::objects::Cube::setCamera(application::objects::ICamera *camera) {

    camera->use(_shaders.front().shaderProgramId);

    return 0;
}
