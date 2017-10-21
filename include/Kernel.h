//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H


#ifdef __linux__
#include <SDL2/SDL.h>
#include <objects/one_sheet_hyperboloid.h>
#include <objects/base_object.h>
#include <objects/bicameral_hyperboloid.h>
#include <time/interval_timer.h>

#elif _WIN32

#include <SDL.h>
#include <input/ClientInput.h>
#include <graphics/Scene.h>
#include <graphics/Graphics.h>
#include <Interfaces&Abstractions/ControlableInterface.h>
#include <time/IntervalTimer.h>

#endif

#include "GL/glew.h"

namespace application {

    class Kernel : public input::ControlableInterface {
    public:
        Kernel(Uint32 width, Uint32 height);
        ~Kernel();

    protected:

        bool _running;
        graphics::Graphics* _graphics;
        input::ClientInputInterface* _input;
        graphics::Scene* _scene;
        time::IntervalTimer* _frameUpdate;

        int flow();
        int update(SDL_Event event) override;
        int controlResponse(SDL_Event event) override;
    };

}

#endif //OPENGL_APPLICATION_H
