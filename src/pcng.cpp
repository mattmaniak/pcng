#include <iostream>

#include "pcng.h"

int main(int argc, char **argv)
{
    Generator generator;
    std::cout << generator.generateName(loader::load(loader::prefix),
                                        loader::load(loader::suffix))
              << std::endl;
    return 0;
}