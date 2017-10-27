//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <SDL.h>
#include <input/ClientInput.h>
#include <graphics/Scene.h>
#include <graphics/Graphics.h>

namespace application {

    class Kernel : public input::IControlable {
    public:
        Kernel(int width, int height);
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
