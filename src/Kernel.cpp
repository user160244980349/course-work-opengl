//
// Created by user on 07.10.2017.
//

#include <Kernel.h>
#include <input/KeyLogger.h>


application::Kernel::Kernel(Uint32 width, Uint32 height) {

    _graphics = new graphics::Graphics(width, height);
    _input = new input::ClientInput();
    _scene = new graphics::Scene(nullptr);

    _input->subscribe(this);

    flow();

}



application::Kernel::~Kernel() {

    delete(_scene);
    delete(_input);
    delete(_graphics);

}



int application::Kernel::flow() {

    _scene->prepare();

    while(_running){

        _input->perform();
        _scene->draw();
        _graphics->swapWindow();

    }

    return 0;
}



int application::Kernel::update(SDL_Event event) {

    controlResponse(event);

    return 0;
}

int application::Kernel::controlResponse(SDL_Event event) {

    static bool ctrl_pressed;
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LCTRL)
        ctrl_pressed = true;

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LCTRL)
        ctrl_pressed = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q && ctrl_pressed || event.type == SDL_QUIT)
        _running = false;

    return 0;
}

