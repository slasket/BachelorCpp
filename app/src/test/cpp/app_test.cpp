/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include "app.h"
#include <cassert>

//test methods
int main() {
    BachelorCpp::Greeter greeter;
    assert(greeter.greeting().compare("Hello, World!") == 0);

    BachelorCpp::Freader freader;
    assert(freader.readFile().compare("0")==0);


    return 0;

}
