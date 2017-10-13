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
        glm::vec4 color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
        // Проекционная матрица : 45&deg; поле обзора, 4:3 соотношение сторон, диапазон : 0.1 юнит <-> 100 юнитов
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
        // Матрица камеры
        glm::mat4 view       = glm::lookAt(
                glm::vec3(4,3,3), // Камера находится в мировых координатах (4,3,3)
                glm::vec3(0,0,0), // И направлена в начало координат
                glm::vec3(0,1,0)  // "Голова" находится сверху
        );
        // Матрица модели : единичная матрица (Модель находится в начале координат)
        glm::mat4 model      = glm::mat4(1.0f);  // Индивидуально для каждой модели
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
