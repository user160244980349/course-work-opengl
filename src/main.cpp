
#include <cstdlib>
#include <test/ClientInput.h>
#include "kernel.h"
#include "test/KeyLogger.h"

int main(int argc, char **argv){

    application::kernel instance(atoi(argv[1]), atoi(argv[2]));

    return 0;
}