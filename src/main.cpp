
#include <cstdlib>
#include <test/observer.h>
#include <test/notifier.h>
#include <test/test_notifier.h>
#include <test/test_observer.h>
#include "kernel.h"

int main(int argc, char **argv){

    application::kernel instance(atoi(argv[1]), atoi(argv[2]));

//    application::observer* obs1 = new application::test_observer;
//    application::observer* obs2 = new application::test_observer;
//    application::observer* obs3 = new application::test_observer;
//
//    application::test_notifier not1;
//
//    not1.add(obs1);
//    not1.add(obs2);
//    not1.add(obs3);
//
//    not1.send_to_all(3);
//    not1.send_to_all(2);
//
//    not1.remove(obs2);
//
//    not1.send_to_all(1);

    return 0;
}