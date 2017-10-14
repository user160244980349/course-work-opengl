//
// Created by user on 14.10.2017.
//

#include "buffers/ubo.hpp"
#include <glm/gtc/matrix_transform.hpp>

int application::graphics::ubo::create() {

    glGenBuffers(1, &id);

    return 0;
}

int application::graphics::ubo::connect(GLuint program) {

    unsigned int block_index = glGetUniformBlockIndex(program, "shader_data");

    GLuint binding_point_index = 2;

    glBindBufferBase(GL_UNIFORM_BUFFER, binding_point_index, id);
    glUniformBlockBinding(program, block_index, binding_point_index);

    return 0;
}

int application::graphics::ubo::set() {

    struct {
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
        glm::mat4 view = glm::lookAt(
                glm::vec3(3,3,3),
                glm::vec3(0,0,0),
                glm::vec3(0,1,0)
        );
        glm::mat4 model = glm::mat4(1.0f);
    } shader_data;

    glBindBuffer(GL_UNIFORM_BUFFER, id);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(shader_data), &shader_data, GL_DYNAMIC_DRAW);

    return 0;
}

int application::graphics::ubo::update() {

//    glBindBuffer(GL_UNIFORM_BUFFER, id);
//    GLvoid* p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
//    memcpy(p, &shader_data, sizeof(shader_data));
//    glUnmapBuffer(GL_UNIFORM_BUFFER);

    return 0;
}
