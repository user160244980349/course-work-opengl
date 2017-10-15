
#include <cstdlib>
#include "kernel.hpp"

int main(int argc, char **argv){

    application::kernel instance(atoi(argv[1]), atoi(argv[2]));

    return 0;
}