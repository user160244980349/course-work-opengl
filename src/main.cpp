
#include <cstdlib>
#include "Kernel.h"

int main(int argc, char **argv){

    application::Kernel instance(atoi(argv[1]), atoi(argv[2]));

    return 0;
}