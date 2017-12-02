//
// Created by user on 07.10.2017.
//

#include <Kernel.h>
#include <commands/QuitCommand.h>
#include <graphics/OpenGl.h>

Kernel::Kernel() {
    Graphics::getInstance();
    ClientInput::getInstance().addCommand(new QuitCommand);
};

int Kernel::run() {

    _scene = new Scene();

    while(_running){
        ClientInput::getInstance().perform();
        Graphics::getInstance().draw(_scene);
    }
    delete(_scene);

    return 0;
}

int Kernel::stop() {
    _running = false;
}

Kernel &Kernel::getInstance() {
    static Kernel instance;
    return instance;
}

