//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_GRAPHICS_H
#define OPENGL_GRAPHICS_H

#include "IOutput.h"
#include <list>
#include <interfaces/IScene.h>
#include <GL/glcorearb.h>

namespace application::graphics {

    class Graphics : public IOutput {
    public:
        Graphics();
        ~Graphics();
        int prepare(objects::IScene* scene) override;
        int draw(objects::IScene* scene) override;

    protected:
        std::list<objects::IScene*> _observers{};
        SDL_Window* _window;
        SDL_GLContext _glContext;
        GLuint _width;
        GLuint _height;
        GLuint _fps;
    };

}

#endif //OPENGL_GRAPHICS_H
