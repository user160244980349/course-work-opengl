//
// Created by user on 11.01.2018.
//

#ifndef OPENGL_MODELLOADER_H
#define OPENGL_MODELLOADER_H


#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"
#include <vector>

class ModelLoader {
public:
    Model load(std::string path);

protected:
    std::vector<Mesh> _meshes;
    std::string _directory;

    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
//    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
//    unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma);

};


#endif //OPENGL_MODELLOADER_H
