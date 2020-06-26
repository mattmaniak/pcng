#include <iostream>

#include "generator.h"

int main(int argc, char **argv) {
    std::cout << generator::generateMessage() << std::endl;
    return 0;
}