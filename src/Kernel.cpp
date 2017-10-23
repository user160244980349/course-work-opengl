//
// Created by user on 07.10.2017.
//

#include <Kernel.h>
#include <iostream>


application::Kernel::Kernel(Uint32 width, Uint32 height) {

    _graphics = new graphics::Graphics(width, height);
    _input = new input::ClientInput;
    _scene = new graphics::Scene(_input);

    _input->subscribe(this);

    flow();

}



application::Kernel::~Kernel() {

    delete(_scene);
    delete(_graphics);
    delete(_input);

}



int application::Kernel::flow() {

    Uint32 start;
    Uint32 duration;
    Uint32 fps = 1000 / 60;

    _scene->prepare();

    while(_running){

        start = SDL_GetTicks();

        _input->perform();
        _scene->draw();

        duration = SDL_GetTicks() - start;

        if (duration <= fps)
            SDL_Delay(fps - duration);

        _graphics->swapWindow();

    }

    return 0;
}



int application::Kernel::control(SDL_Event event) {

    switch (event.type) {

        case SDL_QUIT:
            _running = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {

                case SDLK_ESCAPE:
                    _graphics->showHideCursor();
                    break;
                default: break;
            }
            break;
        default: break;
    }

    return 0;
}

