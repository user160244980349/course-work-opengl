//
// Created by user on 09.10.2017.
//

#include <objects/base_object.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <graphics/shader.hpp>

int application::objects::base_object::prepare() {

    shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    shaders.front().use();


    verices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f, 1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f,-1.0f,-1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    verices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4(-1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4( 1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});


    order.emplace_back(0u);
    order.emplace_back(1u);
    order.emplace_back(2u);

    order.emplace_back(2u);
    order.emplace_back(3u);
    order.emplace_back(0u);


    buffers.vao.create();
    buffers.vao.bind();

    buffers.vbo.create();
    buffers.vbo.set(verices.data());

    buffers.ebo.create();
    buffers.ebo.set(order.data());

    buffers.ubo.create();
    buffers.ubo.set();
    buffers.ubo.connect(shaders.front().shader_variables.shader_program);

    return 0;
}

int application::objects::base_object::draw() {

    glPointSize(6.0f);
    buffers.ubo.update();
    buffers.vao.bind(GL_TRIANGLES, order.size());

    return 0;
}