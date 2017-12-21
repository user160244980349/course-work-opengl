//
// Created by user on 07.12.2017.
//

#ifndef OPENGL_CUBEMESH_H
#define OPENGL_CUBEMESH_H


#include <graphics/Vao.h>
#include <graphics/Vbo.h>
#include <graphics/Ebo.h>
#include <vector>
#include <interfaces/IMesh.h>

class CubeMesh : public IMesh {
public:
    CubeMesh();
    ~CubeMesh();
    void render() override;

protected:

    struct {
        Vao vao;
        Vbo vbo;
        Ebo ebo;
    } _buffers;

    std::vector <glm::vec3> _vertices{};
    std::vector <unsigned int> _order{};
};


#endif //OPENGL_CUBEMESH_H
