//
// Created by user on 13.01.2018.
//

#ifndef OPENGL_SKYBOX_H
#define OPENGL_SKYBOX_H


#include <core/Texture.h>
#include <vector>
#include <glm/detail/type_mat4x4.hpp>
#include <core/Vao.h>
#include <core/Vbo.h>

class SkyBox {
public:

    void load(std::string path);

    void prepare(Shader &shader);

    void render(Shader &shader, glm::mat4 cameraView, glm::mat4 projection);

protected:

    std::vector<glm::vec3> _vertices = {
            // positions
            glm::vec3(-1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, -1.0f),
            glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, -1.0f),

            glm::vec3(-1.0f, -1.0f, 1.0f),
            glm::vec3(-1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f),

            glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(1.0f, -1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(1.0f, -1.0f, -1.0f),

            glm::vec3(-1.0f, -1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, -1.0f, 1.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f),

            glm::vec3(-1.0f, 1.0f, -1.0f),
            glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, -1.0f),

            glm::vec3(-1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f),
            glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f),
            glm::vec3(1.0f, -1.0f, 1.0f)
    };

    unsigned int _id;

    Vao _vao;
    Vbo _vbo;

};


#endif //OPENGL_SKYBOX_H
