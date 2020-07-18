#include "../include/core/UserInput.h"
#include "../include/core/Graphics.h"
#include "../include/core/Kernel.h"
#include "../include/commands/QuitCommand.h"

void Kernel::prepare() {
    UserInput::getInstance().addCommand(new QuitCommand());
};

void Kernel::run() {
    _running = true;
    _scene.prepare();

    while (_running) {
        UserInput::getInstance().perform();
        _scene.update();
        Graphics::getInstance().render(_scene);
    }

}

void Kernel::stop() {
    _running = false;
}

Kernel &Kernel::getInstance() {
    static Kernel instance;
    return instance;
}

Kernel::Kernel() = default;
