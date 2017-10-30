//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <SDL2/SDL.h>
#include <graphics/Scene.h>
#include <graphics/Graphics.h>
#include <input/AControlable.h>
#include <interfaces/IInput.h>

namespace application {

    class Kernel : public input::AControlable {
    public:
        bool running;

        Kernel();
        int initCommands() override;
        ~Kernel();


    protected:
        graphics::Graphics* _graphics;
        input::IInput* _input;
        graphics::Scene* _scene;

        int flow();
    };

}

#endif //OPENGL_APPLICATION_H
