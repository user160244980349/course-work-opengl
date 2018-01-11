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

    void render() override;

protected:

    struct {
        Vao vao;
        Vbo vbo;
        Ebo ebo;
    } _buffers;

    std::vector<glm::vec3> _vertices{};
    std::vector<unsigned int> _order{};
};


#endif //OPENGL_CUBEMESH_H
