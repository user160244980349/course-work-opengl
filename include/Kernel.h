//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H


#ifdef __linux__

#include <SDL2/SDL.h>

#elif _WIN32

#include <SDL.h>

#endif

#include "GL/glew.h"
#include <input/ClientInput.h>
#include <graphics/Scene.h>
#include <graphics/Graphics.h>

namespace application {

    class Kernel : public input::IControlable {
    public:
        Kernel(Uint32 width, Uint32 height);
        ~Kernel();

    protected:

        bool _running;
        graphics::Graphics* _graphics;
        input::IInput* _input;
        graphics::Scene* _scene;

        int flow();
        int control(SDL_Event event) override;
    };

}

#endif //OPENGL_APPLICATION_H
