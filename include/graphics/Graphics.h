//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_GRAPHICS_H
#define OPENGL_GRAPHICS_H

#include <list>
#include <GL/glcorearb.h>
#include <objects/Scene.h>


class Graphics {
    public:
        ~Graphics();
        static Graphics& getInstance();
        void render(Scene &scene);

    protected:
        Graphics();
        SDL_Window* _window;
        SDL_GLContext _glContext;
        unsigned int _width;
        unsigned int _height;
        unsigned int _fps;
    };


#endif //OPENGL_GRAPHICS_H
