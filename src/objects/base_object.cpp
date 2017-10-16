//
// Created by user on 09.10.2017.
//

#include <objects/base_object.hpp>
#include <environment.hpp>
#include "time/timer.hpp"
#include "graphics/shader.hpp"

int application::objects::base_object::prepare() {

    _shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    _shaders.front().use();

    _vertices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    _vertices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    _vertices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    _vertices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    _vertices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    _order.emplace_back(1u);
    _order.emplace_back(3u);
    _order.emplace_back(0u);
    _order.emplace_back(1u);
    _order.emplace_back(3u);
    _order.emplace_back(2u);

    _order.emplace_back(2u);
    _order.emplace_back(5u);
    _order.emplace_back(1u);
    _order.emplace_back(2u);
    _order.emplace_back(5u);
    _order.emplace_back(6u);

    _order.emplace_back(5u);
    _order.emplace_back(7u);
    _order.emplace_back(4u);
    _order.emplace_back(5u);
    _order.emplace_back(7u);
    _order.emplace_back(6u);

    _order.emplace_back(3u);
    _order.emplace_back(4u);
    _order.emplace_back(0u);
    _order.emplace_back(3u);
    _order.emplace_back(4u);
    _order.emplace_back(7u);

    _order.emplace_back(2u);
    _order.emplace_back(7u);
    _order.emplace_back(6u);
    _order.emplace_back(2u);
    _order.emplace_back(7u);
    _order.emplace_back(3u);

    _order.emplace_back(1u);
    _order.emplace_back(4u);
    _order.emplace_back(0u);
    _order.emplace_back(1u);
    _order.emplace_back(4u);
    _order.emplace_back(5u);

    _buffers.vao.create();
    _buffers.vao.bind();

    _buffers.vbo.create();
    _buffers.vbo.set(_vertices.data(), (GLuint)_vertices.size());

    _buffers.ebo.create();
    _buffers.ebo.set(_order.data(), (GLuint)_order.size());

    _buffers.ubo.create();
    _buffers.ubo.set((GLvoid*)&_transform, sizeof(_transform));
    _buffers.ubo.connect(_shaders.front().shader_program_id);

    return 0;
}



int application::objects::base_object::draw() {

    rotate();
    _buffers.vao.bind(GL_TRIANGLES, (GLuint)_order.size());

    return 0;
}



int application::objects::base_object::rotate() {

    _transform.model = glm::rotate(_transform.model, glm::radians(sinf(environment::world_time.time/1000.0f)*3.14f), glm::vec3(0.0f, 1.0f, 0.0f));
    _buffers.ubo.update((GLvoid*)&_transform, sizeof(_transform));

    return 0;
}
