//
// Created by user on 07.12.2017.
//

#include <core/Mesh.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <math.h>
#include <core/OpenGl.h>


void Mesh::prepare(ShaderProgram &shader) {

    unsigned int portion;

    _buffers.vao.create();
    _buffers.vao.bind();

    _buffers.vbo.create();
    _buffers.vbo.set(_vertices.data(), _vertices.size() * sizeof(Vertex));

    portion = 3;
    shader.enableAttribute("position");
    _buffers.vbo.attach(shader, "position", portion, sizeof(Vertex), (void *) offsetof(Vertex, position));

    portion = 3;
    shader.enableAttribute("normal");
    _buffers.vbo.attach(shader, "normal", portion, sizeof(Vertex), (void *) offsetof(Vertex, normal));

    portion = 2;
    shader.enableAttribute("uv");
    _buffers.vbo.attach(shader, "uv", portion, sizeof(Vertex), (void *) offsetof(Vertex, uv));

    portion = 3;
    shader.enableAttribute("tangent");
    _buffers.vbo.attach(shader, "tangent", portion, sizeof(Vertex), (void *) offsetof(Vertex, tangent));

    portion = 3;
    shader.enableAttribute("bitangent");
    _buffers.vbo.attach(shader, "bitangent", portion, sizeof(Vertex), (void *) offsetof(Vertex, bitangent));

    _buffers.ebo.create();
    _buffers.ebo.set(_indices.data(), _indices.size());

    // load textures (we now use a utility function to keep the code more organized)
    // -----------------------------------------------------------------------------
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);
    SDL_Surface *diffuseMap = IMG_Load(
            "../resources/models/CHR_SAS_Smoke/textures/Blood_orchid/CHR_SAS_Smoke_Legs_DiffuseMap.tga");
    SDL_Surface *specularMap = IMG_Load(
            "../resources/models/CHR_SAS_Smoke/textures/Blood_orchid/CHR_SAS_Smoke_Legs_DiffuseMap.tga");


    OpenGl::getInstance().genTextures(1, &_maps.diffuse);
    OpenGl::getInstance().genTextures(1, &_maps.specular);

    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _maps.diffuse);
    OpenGl::getInstance().texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, diffuseMap->w, diffuseMap->h, 0, GL_RGBA,
                                     GL_UNSIGNED_BYTE, diffuseMap->pixels);
    OpenGl::getInstance().generateMipmap(GL_TEXTURE_2D);

    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _maps.specular);
    OpenGl::getInstance().texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, specularMap->w, specularMap->h, 0, GL_RGBA,
                                     GL_UNSIGNED_BYTE, specularMap->pixels);
    OpenGl::getInstance().generateMipmap(GL_TEXTURE_2D);

    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(diffuseMap);
    SDL_FreeSurface(specularMap);
}

void Mesh::render(ShaderProgram &shader) {
    shader.use();

    shader.setUniform("light.position", glm::vec3(0.0f));
    shader.setUniform("light.ambient", glm::vec3(0.8f));
    shader.setUniform("light.diffuse", glm::vec3(1.0f));
    shader.setUniform("light.specular", glm::vec3(1.0f));

    shader.setUniform("material.diffuse", 0);
    shader.setUniform("material.specular", 1);
    shader.setUniform("material.shininess", 64.0f);

    // bind diffuse map
    OpenGl::getInstance().activeTexture(GL_TEXTURE0);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _maps.diffuse);

    // bind specular map
    OpenGl::getInstance().activeTexture(GL_TEXTURE1);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _maps.specular);

    _buffers.vao.render(GL_TRIANGLES, _indices.size());

}

Mesh::~Mesh() {
    _buffers.vao.remove();
    _buffers.vbo.remove();
    _buffers.ebo.remove();
}

void Mesh::build(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
    _vertices = std::move(vertices);
    _indices = std::move(indices);
}
