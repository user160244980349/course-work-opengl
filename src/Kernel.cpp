//
// Created by user on 07.10.2017.
//

#include <Kernel.h>


application::Kernel::Kernel(Uint32 width, Uint32 height) {

    _graphics = new graphics::Graphics(width, height);
    _input = new input::ClientInput;
    _scene = new graphics::Scene(_input);
    _frameUpdate = new time::IntervalTimer;

    _input->subscribe(this);

    flow();

}



application::Kernel::~Kernel() {

    delete(_scene);
    delete(_graphics);
    delete(_input);
    delete(_frameUpdate);

}



int application::Kernel::flow() {

    _scene->prepare();

    _frameUpdate->set(0.017);
    _frameUpdate->run();

    while(_running){

        _input->perform();

        if (_frameUpdate->fired) {
            _frameUpdate->reset();

            _scene->draw();
            _graphics->swapWindow();

        }

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

int application::Kernel::update() {
    return 0;
}

