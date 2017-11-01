//
// Created by user on 07.10.2017.
//

#include <Kernel.h>
#include <input/ClientInput.h>
#include <commands/QuitCommand.h>

application::Kernel::Kernel() {

    _graphics = new graphics::Graphics;
    _input = new input::ClientInput;
    _scene = new graphics::Scene(_input);

    initCommands();

    _input->addCommands(getCommands());

    flow();

}

application::Kernel::~Kernel() {

    delete(_scene);
    delete(_graphics);
    delete(_input);

}

int application::Kernel::flow() {

    _scene->prepare();

    while(running){

        _input->perform();
        _graphics->draw(_scene);

    }

    return 0;
}

int application::Kernel::initCommands() {

    _commands.push_back(new commands::QuitCommand(this));

    return 0;
}

