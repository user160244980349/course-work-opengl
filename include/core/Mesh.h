//
// Created by user on 07.12.2017.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include <core/Vao.h>
#include <core/Vbo.h>
#include <core/Ebo.h>
#include <vector>
#include <interfaces/IMesh.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <objects/SkyBox.h>
#include "Vertex.h"

class Mesh : public IMesh {
public:
    ~Mesh() override;

    void build(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material material) override;

    void prepare(Shader &shader) override;

    void render(Shader &shader, SkyBox &skyBox) override;

protected:

    struct {
        Vao vao;
        Vbo vbo;
        Ebo ebo;
    } _buffers;

    Material _material;
    std::vector<Vertex> _vertices{};
    std::vector<unsigned int> _indices{};

};


#endif //OPENGL_MESH_H
