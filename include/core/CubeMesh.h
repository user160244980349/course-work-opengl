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

class CubeMesh : public IMesh {
public:
    CubeMesh();

    ~CubeMesh() override;

    void prepare(ShaderProgram &shader) override;

    void render(ShaderProgram &shader) override;

protected:

    struct {
        Vao vao;
        Vbo positionsVbo;
//        Vbo normalsVbo;
//        Vbo texCoordsVbo;
//        Vbo tangentsVbo;
//        Vbo bitangentsVbo;
        Ebo ebo;
    } _buffers;

    std::vector<glm::vec3> _vertices{};
    std::vector<unsigned int> _indices{};
};


#endif //OPENGL_CUBEMESH_H
