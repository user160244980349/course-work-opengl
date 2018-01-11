//
// Created by user on 07.12.2017.
//

#include <core/Mesh.h>

Mesh::Mesh() {

    _vertices.emplace_back(glm::vec3(1.0f, 1.0f, -1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f, -1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, -1.0f, -1.0f));
    _vertices.emplace_back(glm::vec3(1.0f, -1.0f, -1.0f));

    _vertices.emplace_back(glm::vec3(1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, -1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(1.0f, -1.0f, 1.0f));

    _texCoords.emplace_back(glm::vec2(1.0f, 1.0f));
    _texCoords.emplace_back(glm::vec2(1.0f, 0.0f));
    _texCoords.emplace_back(glm::vec2(0.0f, 0.0f));
    _texCoords.emplace_back(glm::vec2(0.0f, 1.0f));

    _texCoords.emplace_back(glm::vec2(1.0f, 1.0f));
    _texCoords.emplace_back(glm::vec2(1.0f, 0.0f));
    _texCoords.emplace_back(glm::vec2(0.0f, 0.0f));
    _texCoords.emplace_back(glm::vec2(0.0f, 1.0f));

    _indices.emplace_back(0u);
    _indices.emplace_back(3u);
    _indices.emplace_back(1u);
    _indices.emplace_back(1u);
    _indices.emplace_back(3u);
    _indices.emplace_back(2u);

    _indices.emplace_back(2u);
    _indices.emplace_back(5u);
    _indices.emplace_back(1u);
    _indices.emplace_back(6u);
    _indices.emplace_back(5u);
    _indices.emplace_back(2u);

    _indices.emplace_back(5u);
    _indices.emplace_back(7u);
    _indices.emplace_back(4u);
    _indices.emplace_back(6u);
    _indices.emplace_back(7u);
    _indices.emplace_back(5u);

    _indices.emplace_back(0u);
    _indices.emplace_back(4u);
    _indices.emplace_back(3u);
    _indices.emplace_back(3u);
    _indices.emplace_back(4u);
    _indices.emplace_back(7u);

    _indices.emplace_back(2u);
    _indices.emplace_back(7u);
    _indices.emplace_back(6u);
    _indices.emplace_back(3u);
    _indices.emplace_back(7u);
    _indices.emplace_back(2u);

    _indices.emplace_back(1u);
    _indices.emplace_back(4u);
    _indices.emplace_back(0u);
    _indices.emplace_back(5u);
    _indices.emplace_back(4u);
    _indices.emplace_back(1u);

}

void Mesh::prepare(ShaderProgram &shader) {

    _buffers.vao.create();
    _buffers.vao.bind();

    unsigned int portion = 3;
    _buffers.positionsVbo.create();
    _buffers.positionsVbo.set(_vertices.data(), _vertices.size());
    shader.enableAttribute("position");
    _buffers.positionsVbo.attach(shader, "position", portion, portion * sizeof(float));

//    portion = 2;
//    _buffers.texCoordsVbo.create();
//    _buffers.texCoordsVbo.set(_texCoords.data(), _texCoords.size());
//    shader.enableAttribute("UV");
//    _buffers.texCoordsVbo.attach(shader, "UV", portion, portion * sizeof(float));

    _buffers.ebo.create();
    _buffers.ebo.set(_indices.data(), _indices.size());

//    _texture.load("../resources/1.png", GL_TEXTURE_2D);

}

void Mesh::render(ShaderProgram &shader) {
    shader.use();
//    _texture.bind();
    _buffers.vao.render(GL_TRIANGLES, _indices.size());
}

Mesh::~Mesh() {
    _buffers.vao.remove();
    _buffers.positionsVbo.remove();
    _buffers.ebo.remove();
}

void Mesh::setVertices(std::vector<glm::vec3> vertices) {
    _vertices = std::move(vertices);
}

void Mesh::setColors(std::vector<glm::vec3> colors) {
    _colors = std::move(colors);
}

void Mesh::setNormals(std::vector<glm::vec3> normals) {
    _normals = std::move(normals);
}

void Mesh::setTexCoords(std::vector<glm::vec2> texCoords) {
    _texCoords = std::move(texCoords);
}

void Mesh::setTangents(std::vector<glm::vec3> tangents) {
    _tangents = std::move(tangents);
}

void Mesh::setBitangents(std::vector<glm::vec3> bitangents) {
    _bitangents = std::move(bitangents);
}

void Mesh::setIndices(std::vector<unsigned int> indices) {
    _indices = std::move(indices);
}
