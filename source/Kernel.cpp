//
// Created by user on 07.10.2017.
//

#include <Kernel.h>
#include <input/ClientInput.h>
#include <commands/QuitCommand.h>

Kernel::Kernel() {

    _graphics = new Graphics;
    _input = new ClientInput;
    _scene = new Scene(_input);

    initCommands();

    _input->addCommands(getCommands());

    flow();

}

Kernel::~Kernel() {

    delete(_scene);
    delete(_graphics);
    delete(_input);

}

int Kernel::flow() {

    _scene->prepare();

    while(running){

        _input->perform();
        _graphics->draw(_scene);

    }

    return 0;
}

int Kernel::initCommands() {

    _commands.push_back(new QuitCommand(this));

    return 0;
}

