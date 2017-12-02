//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_GRAPHICS_H
#define OPENGL_GRAPHICS_H

#include <list>
#include <objects/IScene.h>
#include <GL/glcorearb.h>


    class Graphics {
    public:
        static Graphics& getInstance();
        ~Graphics();
        int draw(IScene* scene);

    protected:
        Graphics();
        SDL_Window* _window;
        SDL_GLContext _glContext;
        GLuint _width;
        GLuint _height;
        GLuint _fps;
    };


#endif //OPENGL_GRAPHICS_H
