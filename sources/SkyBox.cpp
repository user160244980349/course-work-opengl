//
// Created by user on 13.01.2018.
//

#include <core/OpenGl.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "objects/SkyBox.h"

void SkyBox::load() {
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

    int i = 0;


    std::vector<std::string> _names({
                                            "../resources/skybox/front.jpg",
                                            "../resources/skybox/back.jpg",
                                            "../resources/skybox/topr.jpg",
                                            "../resources/skybox/bottomr.jpg",
                                            "../resources/skybox/right.jpg",
                                            "../resources/skybox/left.jpg"
                                    });

    OpenGl::getInstance().genTextures(1, &_id);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_CUBE_MAP, _id);

    for (auto &name : _names) {

        unsigned int id;
        OpenGl::getInstance().genTextures(1, &id);

        SDL_Surface *_texture = IMG_Load(name.c_str());
        GLenum format;

        if (_texture) {
            switch (_texture->format->BytesPerPixel) {
                default:
                    format = GL_RED;
                    break;

                case 2:
                    format = GL_RG;
                    break;

                case 3:
                    if (_texture->format->Rmask == 0x000000ff)
                        format = GL_RGB;
                    else
                        format = GL_BGR;
                    break;

                case 4:
                    if (_texture->format->Rmask == 0x000000ff)
                        format = GL_RGBA;
                    else
                        format = GL_BGRA;
                    break;
            }

            OpenGl::getInstance().texImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, format, _texture->w, _texture->h,
                                             0, format,
                                             GL_UNSIGNED_BYTE, _texture->pixels);

            SDL_FreeSurface(_texture);
        } else
            std::cerr << "texture bitten" << std::endl;
    }

    OpenGl::getInstance().texParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    IMG_Quit();

}

void SkyBox::prepare(Shader &shader) {

    shader.use();
    _vao.create();
    _vao.bind();
    _vbo.create();
    _vbo.allocate(_vertices.data(), _vertices.size() * sizeof(glm::vec3));
    shader.enableAttribute("position");
    _vbo.attach(shader, "position", 3, sizeof(glm::vec3), static_cast<void *>(nullptr));

}

void SkyBox::render(Shader &shader, ICamera &camera) {

    OpenGl::getInstance().depthFunc(GL_LEQUAL);
    shader.use();
    glm::mat4 view = glm::mat4(glm::mat3(camera.getView()));
    shader.setUniform("view", view);
    shader.setUniform("projection", camera.getProjection());
    shader.setUniform("skybox", 0);

    OpenGl::getInstance().activeTexture(GL_TEXTURE0);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_CUBE_MAP, _id);
    _vao.render(GL_TRIANGLES, 0, 36);
    OpenGl::getInstance().depthFunc(GL_LESS);

}
