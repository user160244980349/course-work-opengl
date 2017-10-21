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
#include <test/ClientInput.h>
#include <test/Scene.h>
#include <test/Graphics.h>
#include <test/KeyLogger.h>

#endif

#include "GL/glew.h"

namespace application {

    class Kernel : public test::ObserverInterface {
    public:
        Kernel(Uint32 width, Uint32 height);
        ~Kernel();

    protected:

        bool _running;
        application::test::Graphics* _graphics;
        application::test::ClientInputInterface* _input;
        application::test::Scene* _scene;

        int flow();
        int update(SDL_Event event) override;
    };

}

#endif //OPENGL_APPLICATION_H
