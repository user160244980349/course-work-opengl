//
// Created by user on 15.10.2017.
//

#include <objects/drawable.h>
#include <environment.h>
#include "objects/one_sheet_hyperboloid.h"

int application::objects::one_sheet_hyperboloid::prepare() {

    float a = 25.0;
    float b = 25.0;
    float c = 25.0;

    _transform.model = glm::scale(_transform.model, glm::vec3(0.02f, 0.02f, 0.02f));

    _shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    _shaders.front().use();


    for (int z = -100; z < 100; z++) {
        for (int y = -100; y < 100; y++) {
            float f = function_x(y, a, z, b, c);
            _vertices.emplace_back(graphics::vertex_3d{glm::vec4(f, y, z, 1.0f),
                                                       glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
            _vertices.emplace_back(graphics::vertex_3d{glm::vec4(-f, y, z, 1.0f),
                                                       glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
        }
    }

    for (int x = -100; x < 100; x++) {
        for (int z = -100; z < 100; z++) {
            float f = function_y(x, a, z, b, c);
            _vertices.emplace_back(graphics::vertex_3d{glm::vec4(x, f, z, 1.0f),
                                                       glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
            _vertices.emplace_back(graphics::vertex_3d{glm::vec4(x, -f, z, 1.0f),
                                                       glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
        }
    }

    for (int y = -100; y < 100; y++) {
        for (int x = -100; x < 100; x++) {
            float f = function_z(x, a, y, b, c);
            _vertices.emplace_back(graphics::vertex_3d{glm::vec4(x, y, f, 1.0f),
                                                       glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
            _vertices.emplace_back(graphics::vertex_3d{glm::vec4(x, y, -f, 1.0f),
                                                       glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
        }
    }

    for (GLuint i = 0u; i < _vertices.size(); i++)
        _order.emplace_back(i);

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



int application::objects::one_sheet_hyperboloid::draw() {

    glPointSize(2);
    rotate();
    _buffers.vao.bind(GL_POINTS, (GLuint)_order.size());

    return 0;
}



int application::objects::one_sheet_hyperboloid::rotate() {

    _transform.model = glm::rotate(_transform.model, glm::radians(sinf(environment::world_time.time/1000.0f)*3.14f), glm::vec3(0.0f, 1.0f, 0.0f));
    _buffers.ubo.update((GLvoid*)&_transform, sizeof(_transform));

    return 0;
}



float application::objects::one_sheet_hyperboloid::function_x(float y, float a,
                                                           float z, float c, float b) {

    return sqrtf((1.0 - (y*y) / (a*a) + (z*z) / (c*c)) * (b*b));
}



float application::objects::one_sheet_hyperboloid::function_y(float x, float a,
                                                           float z, float c, float b) {

    return sqrtf((1.0 - (x*x) / (a*a) + (z*z) / (c*c)) * (b*b));
}



float application::objects::one_sheet_hyperboloid::function_z(float x, float a,
                                                           float y, float c, float b) {

    return sqrtf((-1.0 + (x*x) / (a*a) + (y*y) / (c*c)) * (b*b));
}
