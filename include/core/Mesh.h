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
#include "Texture.h"

class Mesh : public IMesh {
public:
    Mesh();

    ~Mesh() override;

    void prepare(ShaderProgram &shader) override;

    void render(ShaderProgram &shader) override;

    void setVertices(std::vector<glm::vec3> vertices);

    void setColors(std::vector<glm::vec3> colors);

    void setNormals(std::vector<glm::vec3> normals);

    void setTexCoords(std::vector<glm::vec2> texCoords);

    void setTangents(std::vector<glm::vec3> tangents);

    void setBitangents(std::vector<glm::vec3> bitangents);

    void setIndices(std::vector<unsigned int> indices);

protected:

    struct {
        Vao vao;
        Vbo positionsVbo;
        Vbo colorsVbo;
        Vbo normalsVbo;
        Vbo texCoordsVbo;
        Vbo tangentsVbo;
        Vbo bitangentsVbo;
        Ebo ebo;
    } _buffers;

    std::vector<glm::vec3> _vertices{};
    std::vector<glm::vec3> _colors{};
    std::vector<glm::vec3> _normals{};
    std::vector<glm::vec2> _texCoords{};
    std::vector<glm::vec3> _tangents{};
    std::vector<glm::vec3> _bitangents{};
    std::vector<unsigned int> _indices{};

    Texture _texture;

};


#endif //OPENGL_CUBEMESH_H
