//
// Created by user on 11.01.2018.
//

#include <glm/vec3.hpp>
#include <iostream>
#include <core/Model.h>
#include <core/OpenGl.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include "core/ModelLoader.h"


Model ModelLoader::load(std::string path) {

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenUVCoords | aiProcess_FlipUVs |
                                                   aiProcess_GenNormals);

    if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        exit(0);
    }

    _directory = path.substr(0, path.find_last_of('/'));
    sceneBypass(scene->mRootNode, scene);

    Model newModel;
    newModel.build(_meshes);
    _meshes.clear();

    return newModel;
}

void ModelLoader::sceneBypass(aiNode *node, const aiScene *scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(buildMesh(mesh));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        sceneBypass(node->mChildren[i], scene);
    }
}

Mesh ModelLoader::buildMesh(aiMesh *mesh) {

    std::vector<Vertex> vertices{};
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        // position
        if (mesh->HasPositions())
            vertex.position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);

        // normal
        if (mesh->HasNormals())
            vertex.normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

        // texture coords
        if (mesh->HasTextureCoords(0))
            vertex.uv = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        else
            vertex.uv = glm::vec2(0.0f, 0.0f);

        if (mesh->HasTangentsAndBitangents()) {
            // tangent
            vertex.tangent = glm::vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z);
            // bitangent
            vertex.bitangent = glm::vec3(mesh->mBitangents[i].x, mesh->mBitangents[i].y, mesh->mBitangents[i].z);
        }

        vertices.push_back(vertex);
    }

    // indices
    std::vector<unsigned int> indices{};
    if (mesh->HasFaces()) {
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }
    }

    Mesh newMesh;
    newMesh.build(vertices, indices);

    return newMesh;
}

ModelLoader &ModelLoader::getInstacne() {
    static ModelLoader instance;
    return instance;
}

unsigned int ModelLoader::loadTexture(const char *path, const std::string &directory, bool gamma) {
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int id;
    OpenGl::getInstance().genTextures(1, &id);

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);
    SDL_Surface *texture = IMG_Load(directory.c_str());

    if (texture) {

        OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, id);
        OpenGl::getInstance().texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->w, texture->h, 0, GL_RGBA,
                                         GL_UNSIGNED_BYTE, texture->pixels);
        OpenGl::getInstance().generateMipmap(GL_TEXTURE_2D);

        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    } else
        std::cout << "Texture failed to load at path: " << path << std::endl;

    SDL_FreeSurface(texture);
    IMG_Quit();

    return id;
}

ModelLoader::ModelLoader() = default;
