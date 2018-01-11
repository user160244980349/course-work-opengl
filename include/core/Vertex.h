//
// Created by user on 11.01.2018.
//

#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H


#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};


#endif //OPENGL_VERTEX_H
