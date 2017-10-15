//
// Created by user on 09.10.2017.
//

#include <objects/base_object.hpp>
#include "time/timer.hpp"

int application::objects::base_object::prepare() {

    shaders.push_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    shaders.front().use();

    vertices.push_back(graphics::vertex_3d{glm::vec4( 1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    vertices.push_back(graphics::vertex_3d{glm::vec4(-1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    vertices.push_back(graphics::vertex_3d{glm::vec4(-1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    vertices.push_back(graphics::vertex_3d{glm::vec4( 1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    vertices.push_back(graphics::vertex_3d{glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    vertices.push_back(graphics::vertex_3d{glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    vertices.push_back(graphics::vertex_3d{glm::vec4(-1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    vertices.push_back(graphics::vertex_3d{glm::vec4( 1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    order.push_back(1u);
    order.push_back(3u);
    order.push_back(0u);
    order.push_back(1u);
    order.push_back(3u);
    order.push_back(2u);

    order.push_back(2u);
    order.push_back(5u);
    order.push_back(1u);
    order.push_back(2u);
    order.push_back(5u);
    order.push_back(6u);

    order.push_back(5u);
    order.push_back(7u);
    order.push_back(4u);
    order.push_back(5u);
    order.push_back(7u);
    order.push_back(6u);

    order.push_back(3u);
    order.push_back(4u);
    order.push_back(0u);
    order.push_back(3u);
    order.push_back(4u);
    order.push_back(7u);

    order.push_back(2u);
    order.push_back(7u);
    order.push_back(6u);
    order.push_back(2u);
    order.push_back(7u);
    order.push_back(3u);

    order.push_back(1u);
    order.push_back(4u);
    order.push_back(0u);
    order.push_back(1u);
    order.push_back(4u);
    order.push_back(5u);

    buffers.vao.create();
    buffers.vao.bind();

    buffers.vbo.create();
    buffers.vbo.set(vertices.data());

    buffers.ebo.create();
    buffers.ebo.set(order.data(), order.size());

    buffers.ubo.create();
    buffers.ubo.set((GLvoid*)&transform, sizeof(transform));
    buffers.ubo.connect(shaders.front().shader_variables.shader_program);

    return 0;
}

int application::objects::base_object::draw() {

    rotate();
    buffers.vao.bind(GL_TRIANGLES, order.size());

    return 0;
}

int application::objects::base_object::rotate() {

    transform.model = glm::rotate(transform.model, glm::radians(sinf(time::world_time->time/1000.0f)*3.14f), glm::vec3(0.0f, 1.0f, 0.0f));
    buffers.ubo.update((GLvoid*)&transform, sizeof(transform));

    return 0;
}
