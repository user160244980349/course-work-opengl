//
// Created by user on 07.10.2017.
//

#include <Kernel.h>

application::Kernel::Kernel() {

    _graphics = new graphics::Graphics;
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

    _scene->prepare();

    while(_running){

        _input->perform();
        _graphics->draw(_scene);

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
                    _running = false;
                    break;
                default: break;
            }
            break;
        default: break;
    }

    return 0;
}

