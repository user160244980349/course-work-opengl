#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H


#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};


#endif //OPENGL_VERTEX_H
