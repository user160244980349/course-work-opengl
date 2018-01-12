//
// Created by user on 07.12.2017.
//

#ifndef OPENGL_CUBEMESH_H
#define OPENGL_CUBEMESH_H


#include <core/Vao.h>
#include <core/Vbo.h>
#include <core/Ebo.h>
#include <vector>
#include <interfaces/IMesh.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "Vertex.h"

class Mesh : public IMesh {
public:
    ~Mesh() override;

    void build(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

    void prepare(ShaderProgram &shader) override;

    void render(ShaderProgram &shader) override;

protected:

    struct {
        Vao vao;
        Vbo vbo;
        Ebo ebo;
    } _buffers;

    struct {
        unsigned int diffuse;
        unsigned int specular;
    } _maps;

    std::vector<Vertex> _vertices{};
    std::vector<unsigned int> _indices{};

};


#endif //OPENGL_CUBEMESH_H
