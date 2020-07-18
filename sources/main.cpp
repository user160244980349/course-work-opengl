
#include "../include/core/Graphics.h"
#include "../include/core/Kernel.h"

int main(int argc, char **argv) {

    Graphics::getInstance();
    Kernel::getInstance().prepare();
    Kernel::getInstance().run();

    return 0;
}
